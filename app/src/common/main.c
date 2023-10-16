/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018, 2019 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include "app_main.h"
#include "view.h"
#include "swap.h"
#include "lib_standard_app/swap_lib_calls.h"

#include <os_io_seproxyhal.h>

#ifdef HAVE_NBGL
#include "nbgl_use_case.h"
#endif

// Helper to quit the application in a limited THROW context
static void app_exit(void) {
    BEGIN_TRY_L(exit) {
        TRY_L(exit) {
            os_sched_exit(-1);
        }
        FINALLY_L(exit) {
        }
    }
    END_TRY_L(exit);
}

// Helper to handle the different library commands
static void library_main(libargs_t *args) {
    BEGIN_TRY {
        TRY {
            switch (args->command) {
                case SIGN_TRANSACTION: {
                    // Backup up transaction parameters and wipe BSS to avoid collusion with
                    // app-exchange BSS data.
                    bool success = copy_transaction_parameters(args->create_transaction);
                    if (success) {
                        // BSS was wiped, we can now init these globals
                        G_swap_state.called_from_swap = true;
                        G_swap_state.should_exit = false;

#ifdef HAVE_NBGL
                        // On Stax, display a modal
                        nbgl_useCaseSpinner("Signing");
#endif  // HAVE_NBGL

                        view_init();
                        app_init();
                        app_main();
                    }
                    break;
                }
                case CHECK_ADDRESS:
                    handle_check_address(args->check_address);
                    break;
                case GET_PRINTABLE_AMOUNT:
                    handle_get_printable_amount(args->get_printable_amount);
                    break;
                default:
                    break;
            }
        }
        CATCH_OTHER(e)
        {
        }
        FINALLY
        {
            os_lib_end();
        }
    }
    END_TRY;
}

__attribute__((section(".boot"))) int
main(int arg0) {
    // exit critical section
    __asm volatile("cpsie i");

    os_boot();

    if (arg0 != 0) {
        // The app has been started in library mode
        libargs_t *args = (libargs_t *) arg0;
        if (args->id != 0x100) {
            // Invalid mode ID
            app_exit();
        } else {
            library_main(args);
        }
    } else {
        // The app has been launched from the dashboard
        G_swap_state.called_from_swap = false;
        BEGIN_TRY
        {
            TRY
            {
                view_init();
                app_init();
                app_main();
            }
            CATCH_OTHER(e)
            {}
            FINALLY
            {}
        }
        END_TRY;
    }
}
