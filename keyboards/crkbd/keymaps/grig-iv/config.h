/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// Mouse setup
#define MK_COMBINED

// 60hz 1600px
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 3
// 144hz 2k
// #define MOUSEKEY_INTERVAL 7
// #define MOUSEKEY_MAX_SPEED 7
// #define MOUSEKEY_TIME_TO_MAX 100



#define TAPPING_TERM 180
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY

#define MASTER_RIGHT
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define LEADER_TIMEOUT 250
#define LEADER_PER_KEY_TIMING

#define COMBO_COUNT 1
#define EXTRA_LONG_COMBOS

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
