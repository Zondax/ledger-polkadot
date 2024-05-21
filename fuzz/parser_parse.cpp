#include <cassert>
#include <cstdint>
#include <cstdio>

#include "parser.h"

#ifdef NDEBUG
#error "This fuzz target won't work correctly with NDEBUG defined, which will cause asserts to be eliminated"
#endif

using std::size_t;

char PARSER_KEY[16384];
char PARSER_VALUE[16384];

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    parser_tx_t txObj = {0};
    parser_error_t rc = parser_unexpected_error;

    rc = parser_parse(&txObj, data, size, size / 3);
    if (rc != parser_ok) {
        return 0;
    }

    rc = parser_validate(&txObj);
    if (rc != parser_ok) {
        return 0;
    }

    uint8_t num_items = 0;
    rc = parser_getNumItems(&txObj, &num_items);
    if (rc != parser_ok) {
        (void)fprintf(stderr, "error in parser_getNumItems: %s\n", parser_getErrorDescription(rc));
        assert(false);
    }

    ui_field_t uiFields = {.displayIdx = 0,
                           .outKey = PARSER_KEY,
                           .outKeyLen = sizeof(PARSER_KEY),
                           .outVal = PARSER_VALUE,
                           .outValLen = sizeof(PARSER_VALUE),
                           .pageIdx = 0,
                           .pageCount = NULL};

    for (uint8_t i = 0; i < num_items; i += 1) {
        uint8_t page_idx = 0;
        uint8_t page_count = 1;

        uiFields.displayIdx = i;
        uiFields.pageIdx = 0;
        uiFields.pageCount = &page_count;
        while (uiFields.pageIdx < *uiFields.pageCount) {
            rc = parser_getItem(&txObj, &uiFields);

            (void)fprintf(stderr, "%s = %s\n", PARSER_KEY, PARSER_VALUE);

            if (rc != parser_ok) {
                (void)fprintf(stderr, "error getting item %u at page index %u: %s\n", (unsigned)i, (unsigned)page_idx,
                              parser_getErrorDescription(rc));
                assert(false);
            }

            page_idx += 1;
        }
    }

    return 0;
}
