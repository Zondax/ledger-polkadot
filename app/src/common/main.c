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

#include <os_io_seproxyhal.h>

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

__attribute__((section(".boot"))) int
main(int arg0) {
    // exit critical section
    __asm volatile("cpsie i");

    view_init();
    os_boot();

    if (arg0) {
        libargs_s *args = (libargs_s *) arg0;
        if (args->id != 0x100) {
            app_exit();
            return 0;
        }

        swap_handle_command(args);
        if (!G_swap_state.called_from_swap) {
            os_lib_end();
        }
    }

    BEGIN_TRY
    {
        TRY
        {
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
