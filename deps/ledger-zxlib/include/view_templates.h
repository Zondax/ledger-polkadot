/*******************************************************************************
*   (c) 2016 Ledger
*   (c) 2018 Zondax GmbH
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

#include <bagl.h>

#define UI_CENTER11PX       BAGL_FONT_OPEN_SANS_REGULAR_11px | BAGL_FONT_ALIGNMENT_CENTER
#define UI_CENTER11PX_BOLD  BAGL_FONT_OPEN_SANS_EXTRABOLD_11px | BAGL_FONT_ALIGNMENT_CENTER
#define UI_11PX 11

#define DEFAULT_FONT        BAGL_FONT_OPEN_SANS_LIGHT_16px | BAGL_FONT_ALIGNMENT_LEFT
#define UI_WHITE 0xFFFFFF
#define UI_BLACK 0x000000

#define UIID_ICONLEFT       0x10
#define UIID_ICONRIGHT      0x11
#define UIID_LABEL          0x20
#define UIID_LABELSCROLL    0x71

#define UI_FillRectangle(id, x, y, w, h, fgcolor, bgcolor)  \
{                                                           \
    {                                                       \
        BAGL_RECTANGLE, /* type     */                      \
        id,           /* usedid   */                        \
        x,              /* x        */                      \
        y,              /* y        */                      \
        w,              /* width    */                      \
        h,              /* height   */                      \
        0,              /* stroke   */                      \
        0,              /* radius   */                      \
        BAGL_FILL,      /* fill     */                      \
        fgcolor,        /* fgcolor  */                      \
        bgcolor,        /* bgcolor  */                      \
        0,              /* font_id  */                      \
        0               /* icon_id  */                      \
    },                                                      \
        NULL,   /* text             */                      \
}

#define UI_LabelLine(id, x, y, w, h, fgcolor, bgcolor, text)    \
{                                                               \
    {                                                           \
        BAGL_LABELINE, /* type     */                           \
        id,           /* usedid   */                            \
        x,              /* x        */                          \
        y,              /* y        */                          \
        w,              /* width    */                          \
        h,              /* height   */                          \
        0,              /* stroke   */                          \
        0,              /* radius   */                          \
        0,              /* fill     */                          \
        fgcolor,        /* fgcolor  */                          \
        bgcolor,        /* bgcolor  */                          \
        UI_CENTER11PX,  /* font_id  */                          \
        0               /* icon_id  */                          \
    },                                                          \
        text,   /* text             */                          \
}

#define UI_LabelLineScrolling(id, x, y, w, h, fgcolor, bgcolor, text)    \
{                                                               \
    {                                                           \
        BAGL_LABELINE, /* type     */                           \
        id,           /* usedid   */                            \
        x,              /* x        */                          \
        y,              /* y        */                          \
        w,              /* width    */                          \
        h,              /* height   */                          \
        5 | BAGL_STROKE_FLAG_ONESHOT, /* stroke | scr pause */ \
        0,              /* radius   */                          \
        0,              /* fill     */                          \
        fgcolor,        /* fgcolor  */                          \
        bgcolor,        /* bgcolor  */                          \
        UI_CENTER11PX,  /* font_id  */                          \
        50 /* icon_id / scroll speed  */ \
    },                                                          \
        text,   /* text             */                          \
}

#if defined(TARGET_NANOX)
#define UI_SCREEN_WIDTH  128
#define UI_SCREEN_HEIGHT 64

#define BAGL_GLYPH_ICON_LEFT ((const char*)&C_icon_left)
#define BAGL_GLYPH_ICON_RIGHT ((const char*)&C_icon_right)
#define BAGL_GLYPH_ICON_CROSS ((const char*)&C_icon_crossmark)
#define BAGL_GLYPH_ICON_CHECK ((const char*)&C_icon_validate)

#define UI_Icon(id, x, y, w, h, icon)                       \
{                                                           \
    {                                                       \
        BAGL_ICON,      /* type     */                      \
        id,           /* usedid   */                        \
        x,              /* x        */                      \
        y,              /* y        */                      \
        w,              /* width    */                      \
        h,              /* height   */                      \
        0,              /* stroke   */                      \
        0,              /* radius   */                      \
        0,              /* fill     */                      \
        UI_WHITE,       /* fgcolor  */                      \
        UI_BLACK,       /* bgcolor  */                      \
        0,              /* font_id  */                      \
        0               /* icon_id  */                      \
    },                                                      \
        icon,   /* text             */                      \
        0,      /* touch_area_brim  */                      \
        0,      /* overfgcolor      */                      \
        0,      /* overbgcolor      */                      \
        NULL,   /* tap              */                      \
        NULL,   /* out              */                      \
        NULL,   /* over             */                      \
}

#define UI_BACKGROUND \
        UI_FillRectangle(0, 0, 0, UI_SCREEN_WIDTH, UI_SCREEN_HEIGHT, 0x000000, 0xFFFFFF)

#define UI_BACKGROUND_LEFT_RIGHT_ICONS \
        UI_BACKGROUND, \
        UI_Icon(UIID_ICONLEFT, 2, 28, 4, 7, BAGL_GLYPH_ICON_LEFT), \
        UI_Icon(UIID_ICONRIGHT, 122, 28, 4, 7, BAGL_GLYPH_ICON_RIGHT)

#else
#define UI_SCREEN_WIDTH  128
#define UI_SCREEN_HEIGHT 32

#define UI_Icon(id, x, y, w, h, icon)                       \
{                                                           \
    {                                                       \
        BAGL_ICON,      /* type     */                      \
        id,           /* usedid   */                        \
        x,              /* x        */                      \
        y,              /* y        */                      \
        w,              /* width    */                      \
        h,              /* height   */                      \
        0,              /* stroke   */                      \
        0,              /* radius   */                      \
        0,              /* fill     */                      \
        UI_WHITE,       /* fgcolor  */                      \
        UI_BLACK,       /* bgcolor  */                      \
        0,              /* font_id  */                      \
        icon            /* icon_id  */                      \
    },                                                      \
        NULL,   /* text             */                      \
}

#define UI_BACKGROUND \
        UI_FillRectangle(0, 0, 0, UI_SCREEN_WIDTH, UI_SCREEN_HEIGHT, 0x000000, 0xFFFFFF)

#define UI_BACKGROUND_LEFT_RIGHT_ICONS \
        UI_BACKGROUND, \
        UI_Icon(UIID_ICONLEFT, 0, 0, 7, 7, BAGL_GLYPH_ICON_LEFT), \
        UI_Icon(UIID_ICONRIGHT, 128 - 7, 0, 7, 7, BAGL_GLYPH_ICON_RIGHT)
#endif
