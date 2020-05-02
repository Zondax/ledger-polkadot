/*******************************************************************************
*   (c) 2018-2020 Zondax GmbH
*   (c) 2016 Ledger
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
#pragma once

#include <stdint.h>
#include "coin.h"

#if defined(LEDGER_SPECIFIC)
#include "bolos_target.h"
#if defined(BOLOS_SDK)
#include "os.h"
#include "cx.h"
#endif
#endif

/// view_init (initializes UI)
void view_init();

/// view_idle_show (idle view - main menu + status)
void view_idle_show(unsigned int ignored);

/// view_error (error view)
void view_error_show();

// shows address in the screen
void view_address_show(address_kind_e addressKind);

// Shows review screen + later sign menu
void view_sign_show();
