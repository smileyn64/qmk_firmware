/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

/* Enable sharing of parameters between sides */
#define SPLIT_LAYER_STATE_ENABLE   //Shares the layer status between sides
#define SPLIT_OLED_ENABLE          //Shares the OLED on/off status 

//#define OLED_BRIGHTNESS 128

#ifdef RGBLIGHT_ENABLE
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

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
#define OLED_FONT_H "keyboards/crkbd/keymaps/smileyn64_bépo/Fonts/glcdfont.c"
//#define OLED_FONT_WIDTH 7
//#define OLED_FONT_HEIGHT 9
//#define OLED_FONT_START 0
//#define OLED_FONT_END 120

//#define OLED_FADE_OUT
// #define OLED_FADE_OUT_INTERVAL 10
//#define OLED_TIMEOUT 5000
//#define OLED_FONT_HEIGHT 16
