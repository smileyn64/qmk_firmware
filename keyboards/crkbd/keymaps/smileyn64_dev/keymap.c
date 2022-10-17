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

#include QMK_KEYBOARD_H
#include "Animations/ocean_dream.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, FN_MO13,  KC_SPC,     KC_ENT, FN_MO23, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, RGB_M_P, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

static const char PROGMEM alt[][80] = {
  {
    0x1f, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0xe0, 0x90, 0x88, 0x90, 0xe0, 0x00, 0x00, 0xf8, 0x00,
  	0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xf8, 0x08, 0x08, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x1f,
  	0x1f, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x03, 0x02,
  	0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x1f
  },
  {
    0x1f, 0x01, 0xfd, 0xfd, 0xfd, 0xfc, 0xfc, 0x1c, 0x6c, 0x74, 0x6c, 0x1c, 0xfc, 0xfc, 0x04, 0xfc,
	  0xfc, 0xfc, 0xfc, 0xfc, 0xf4, 0xf4, 0x04, 0xf4, 0xf4, 0xfc, 0xfc, 0xfd, 0xfd, 0xfd, 0x01, 0x1f,
	  0x1f, 0x10, 0x17, 0x17, 0x17, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x04, 0x05,
	  0x05, 0x05, 0x07, 0x07, 0x07, 0x07, 0x04, 0x07, 0x07, 0x07, 0x07, 0x17, 0x17, 0x17, 0x10, 0x1f,
  }
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
    //return rotation;
  } else {
    return OLED_ROTATION_270;
    //return rotation;
  }
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            //oled_write_raw_P(alt[0], sizeof(alt[0]));
            oled_write("0", false);
            break;
        case L_LOWER:
            oled_write("2", false);
            break;
        case L_RAISE:
            //oled_write_raw_P(alt[1], sizeof(alt[1]));
            oled_write("4", false);
            break;
        case L_ADJUST:
            break;
        case L_ADJUST|L_LOWER:
            break;
        case L_ADJUST|L_RAISE:
            break;
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write("8", false);
            break;
      }
}

char keylog_str[24] = {};
uint16_t thechar= 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

/*void render_bootmagic_status(bool status) {
    // Show Ctrl-Gui Swap options
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}*/

void oled_render_logo(void) {
    static const char PROGMEM logo[][2][3] = {
        {{0x80, 0x81, 0}, {0xA0, 0xA1, 0}}, // 0 grand
        {{0x82, 0x83, 0}, {0xA2, 0xA3, 0}}, // 1 grand
        {{0x84, 0x85, 0}, {0xA4, 0xA5, 0}}, // 2 grand
        {{0x86, 0x87, 0}, {0xA6, 0xA7, 0}}, // 3 grand
        {{0x88, 0x89, 0}, {0xA8, 0xA9, 0}}, // 4 grand
        {{0x8A, 0x8B, 0}, {0xAA, 0xAB, 0}}, // 5 grand
        {{0x8C, 0x8D, 0}, {0xAC, 0xAD, 0}}, // 6 grand
        {{0x8E, 0x8F, 0}, {0xAE, 0xAF, 0}}, // 7 grand
        {{0x90, 0x91, 0}, {0xB0, 0xB1, 0}}, // 8 grand
        {{0x92, 0x93, 0}, {0xB2, 0xB3, 0}}, // 9 grand
    };

    oled_clear();
    oled_set_cursor(0,3);
    oled_set_cursor(0,0);
    switch (layer_state) {
        case L_BASE:
            //oled_write_raw_P(alt[0], sizeof(alt[0]));
            oled_write_P(logo[0][0], false);
            oled_set_cursor(0,1);
            oled_write_P(logo[0][1], false);
            break;
        case L_LOWER:
            //oled_write_raw_P(alt[0], sizeof(alt[0]));
            oled_write_P(logo[1][0], false);
            oled_set_cursor(0,1);
            oled_write_P(logo[1][1], false);
            break;
        case L_RAISE:
            //oled_write_raw_P(alt[1], sizeof(alt[1]));
            //oled_write_char(thechar,false);
            //thechar++;
            oled_write_P(logo[2][0], false);
            oled_set_cursor(0,1);
            oled_write_P(logo[2][1], false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            break;
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
      oled_render_logo();
        //oled_render_keylog();
    } else {
      #    ifdef OCEAN_DREAM_ENABLE
              //render_stars();
              //oled_scroll_right();
      #    endif
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  switch (keycode) {
      case KC_LCTL:
      case KC_RCTL:
          #ifdef OCEAN_DREAM_ENABLE
                      is_calm = (record->event.pressed) ? true : false;
          #endif
          break;
  }
  return true;
}
#endif // OLED_ENABLE
