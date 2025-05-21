#include <cassert>
#include <cstdint>
#include <cstdio>

#include "metadata_parser.h"
#include "metadata_types.h"
#include "parser_common.h"
#include "parser_impl.h"
#include "substrate_types.h"

#ifdef NDEBUG
#error "This fuzz target won't work correctly with NDEBUG defined, which will cause asserts to be eliminated"
#endif

using std::size_t;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size > UINT16_MAX || size <= 1) {
        return 0;
    }

    parser_error_t error = parser_unexpected_error;

    const TypeRef_t type = {.index = data[0], .byId = 0};
    parser_context_t blob = {.buffer = data + 1, .bufferLen = static_cast<uint16_t>(size - 1), .offset = 0};
    parser_context_t metadata = {0};
    RegistryEntry_t tmpEntry = {0};
    PrintItem_t printItem = {0};
    printItem.printing = true;
    printItem.target = 1;

    error = parseTypeRef(&blob, &metadata, &tmpEntry, &type, &printItem);
    if (error != parser_ok) {
        return 0;
    }

    return 0;
}
