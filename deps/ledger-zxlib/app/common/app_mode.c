/*******************************************************************************
*   (c) 2020 Zondax GmbH
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

#include "app_mode.h"

typedef struct {
    uint32_t expert;
} app_mode_t;

#if defined(TARGET_NANOS) || defined(TARGET_NANOX)
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//NV_CONST app_mode_t N_appmode NV_ALIGN;
//#define N_APPMODE_PTR  ((NV_VOL app_mode_t *)PIC(&N_appmode))
app_mode_t app_mode;

void app_mode_reset(){
    app_mode.expert = 0;
}

bool app_mode_expert() {
//    TODO: read from NVRAM
//    app_mode_t *p = N_APPMODE_PTR;
//    uint8_t expert = p->expert;
//    return expert;
//    app_mode_t* p =(NV_VOL app_mode_t *)PIC(&N_appmode_impl);
//    return p->expert;
    return app_mode.expert;
}

void app_mode_set_expert(uint8_t val) {
//    TODO: write to NVRAM
    app_mode.expert = val;
}

#else
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

app_mode_t app_mode;

void app_mode_reset() {
    app_mode.expert = 0;
}

bool app_mode_expert() {
    return app_mode.expert;
}

void app_mode_set_expert(uint8_t val) {
    app_mode.expert = val;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

#endif
