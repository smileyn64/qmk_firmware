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

enum crkbd_layers {
    _AZERTY,
    _QWERTY,
    _BEPO,
    _L1,
    _L2,
    _L3,
    _ADJUST,
};

#define L0 TO(_AZERTY)
#define L1 TO(_L1)
#define L2 TO(_L2)
#define L3 TO(_L3)
#define ADJUST TO(_ADJUST)

#define CTLTB CTL_T(KC_TAB)

#define SPACESFT RSFT_T(KC_SPC) //Right shift when held, Space when tapped
#define ENTCTRL LCTL_T(KC_ENT) //

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT_split_3x6_3(
     KC_ESC,     KC_A,     KC_Z,     KC_E,     KC_R,     KC_T,            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
     KC_TAB,     KC_Q,     KC_S,     KC_D,     KC_F,     KC_G,            KC_H,     KC_J,     KC_K,     KC_L,     KC_M,  XXXXXXX,
    XXXXXXX,     KC_W,     KC_X,     KC_C,     KC_V,     KC_B,            KC_N,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_EXLM,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,   ENTCTRL, SPACESFT,       L1,  XXXXXXX
  ),
  /*
  [_QWERTY] = LAYOUT_split_3x6_3(
    XXXXXXX,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,   ENTCTRL, SPACESFT,       L1,  XXXXXXX
  ),
  [_BEPO] = LAYOUT_split_3x6_3(
     XXXXXXX,     KC_B,     KC_E,     KC_P,     KC_O,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX,  XXXXXXX,   ENTCTRL, SPACESFT,       L1,  XXXXXXX
  ),
  */
  [_L1] = LAYOUT_split_3x6_3(
    KC_MPRV,  KC_VOLU,    KC_F2,    KC_F3,    KC_F5,  XXXXXXX,         KC_BSPC,  KC_HOME,    KC_UP,  KC_PGUP,  XXXXXXX,  KC_CALC,
    KC_MPLY,  KC_MUTE,   KC_CUT,  KC_COPY,  KC_PSTE,  XXXXXXX,          KC_DEL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  KC_MAIL,
    KC_MNXT,  KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,   KC_END,  XXXXXXX,  KC_PGDN,  KC_MYCM,  KC_WHOM,
                                      XXXXXXX,       L0,  KC_RSFT,  XXXXXXX,       L2,  XXXXXXX
  ),
  [_L2] = LAYOUT_split_3x6_3(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,         KC_NLCK,    KC_P7,    KC_P8,    KC_P9,  KC_PMNS,  XXXXXXX,
      KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,         KC_PAST,    KC_P4,    KC_P5,    KC_P6,  KC_PPLS,  XXXXXXX,
    KC_NUBS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         KC_PSLS,    KC_P1,    KC_P2,    KC_P3,  KC_PENT,  XXXXXXX,
                                      XXXXXXX,       L1,  XXXXXXX,  KC_LCTL,       L3,  KC_P0
  ),
  [_L3] = LAYOUT_split_3x6_3(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX,       L2,  XXXXXXX,  KC_LCTL,   TO(_ADJUST),  KC_P0
  ),
  [_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                      XXXXXXX,       L0,   KC_SPC,   KC_ENT,  XXXXXXX,  XXXXXXX
  )
};

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _L1, _L2, _ADJUST);
    return state;
}
*/

#ifdef OLED_ENABLE
#include <stdio.h> //standard C library for macros, constants, definition of functions in I/O relations

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
    //return rotation;
  } else {
    return OLED_ROTATION_270;
    //return rotation;
  }
}

void oled_render_os(void) {
  static const char PROGMEM os[][2][3] = {
      {{0x01, 0x02, 0}, {0x21, 0x22, 0}}, //mac
      {{0x03, 0x04, 0}, {0x23, 0x24, 0}}, //windows
  };
  oled_set_cursor(0,0);
  oled_write_P(os[0][0], false);
  oled_write_P(PSTR(" "),false);
  oled_write_P(os[1][0], true);
  oled_write_P(os[0][1], false);
  oled_write_P(PSTR(" "),false);
  oled_write_P(os[1][1], true);
}

void oled_render_layout_state(void) {
  oled_set_cursor(0,2);
  switch (get_highest_layer(default_layer_state)) {
      case _AZERTY:
          oled_write_P(PSTR("Azrty"), false);
          break;
      case _QWERTY:
          oled_write_P(PSTR("Qwrty"), false);
          break;
      case _BEPO:
          oled_write_P(PSTR(" Bépo"), false);
          break;
  }
}

void oled_render_modifier_state(void) {
  static const char PROGMEM command[][2][3] = {
      {{133, 134, 0}, {165, 166, 0}}, //white
      {{141, 142, 0}, {173, 174, 0}}, //black
  };
  static const char PROGMEM option[][2][3] = {
      {{135, 136, 0}, {167, 168, 0}}, //white
      {{143, 144, 0}, {175, 176, 0}}, //black
  };
  static const char PROGMEM ctrl[][2][3] = {
      {{137, 138, 0}, {169, 170, 0}}, //white
      {{145, 146, 0}, {177, 178, 0}}, //black
  };
  static const char PROGMEM shift[][2][3] = {
      {{139, 140, 0}, {171, 172, 0}}, //white
      {{147, 148, 0}, {179, 180, 0}}, //black
  };
  static const char PROGMEM separators[][2][2] = {
      {{197, 0}, {198, 0}}, //off_off
      {{199, 0}, {200, 0}}, //on_off
      {{201, 0}, {202, 0}}, //off_on
      {{203, 0}, {204, 0}}, //on_on
  };
  /*
    static const char PROGMEM alt[][2][3] = {
        {{28, 29, 0}, {60, 61, 0}}, //white
        {{30, 31, 0}, {62, 63, 0}}, //black
    };
    static const char PROGMEM windows[][2][3] = {
        {{91, 92, 0}, {123, 124, 0}}, //white
        {{93, 94, 0}, {125, 126, 0}}, //black
    };
  */
  oled_set_cursor(0,3);
  oled_write_P(command[0][0], false);
  oled_write_P(separators[0][0], false);
  oled_write_P(option[0][0], false);
  oled_write_P(command[0][1], false);
  oled_write_P(separators[0][1], false);
  oled_write_P(option[0][1], false);

  oled_write_P(ctrl[0][0], false);
  oled_write_P(separators[0][0], false);
  oled_write_P(shift[0][0], false);
  oled_write_P(ctrl[0][1], false);
  oled_write_P(separators[0][1], false);
  oled_write_P(shift[0][1], false);
  /*
    oled_write_P(alt[0][0], false);
    oled_write_P(separators[0][0], false);
    oled_write_P(windows[0][0], false);
    oled_write_P(alt[0][1], false);
    oled_write_P(separators[0][1], false);
    oled_write_P(windows[0][1], false);
  */
}

void oled_render_keylock_state (void) {
  static const char PROGMEM inser[][2][6] = {
      {{5, 6, 7, 8, 9, 0}, {37, 38, 39, 40, 41, 0}}, //white
      {{11, 12, 13, 14, 15, 0}, {43, 44, 45, 46, 0}}, //black
  };
  oled_write_P(inser[0][0], false);
  oled_write_P(inser[0][1], false);
}

void oled_render_layer_state(void) {
  static const char PROGMEM layer[][3][4] = {
      {{145, 146, 147, 0}, {177, 178, 179, 0}, {209, 210, 211, 0}}, //0 _AZERTY | _QWERTY | _BEPO
      {{148, 149, 150, 0}, {180, 181, 182, 0}, {212, 213, 214, 0}}, //1
      {{151, 152, 153, 0}, {183, 184, 185, 0}, {215, 216, 217, 0}}, //2
      {{154, 155, 156, 0}, {186, 187, 188, 0}, {218, 219, 220, 0}}, //3
      {{157, 158, 159, 0}, {189, 190, 191, 0}, {221, 222, 223, 0}}, //_ADJUST
  };

  if(layer_state_is(_AZERTY)) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][2], false);
  } else if(layer_state_is(_L1)) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[1][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[1][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[1][2], false);
  } else if(layer_state_is(_L2)) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[2][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[2][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[2][2], false);
  } else if(layer_state_is(_L3)) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[3][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[3][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[3][2], false);
  } else if(layer_state_is(_ADJUST)) {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[4][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[4][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[4][2], false);
  } else {
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][0], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][1], false);
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(layer[0][2], false);
  }

}

/*
void oled_render_logo(void) {
  static const char PROGMEM logo[][6] = {
      {128, 129, 130, 131, 132, 0},
      {160, 161, 162, 163, 164, 0},
      {192, 193, 194, 195, 196, 0},
  };
  oled_write_P(PSTR("\n"), false);
  oled_write_P(logo[0], false);
  oled_write_P(logo[1], false);
  oled_write_P(logo[2], false);
}
*/

bool oled_task_user(void) {
  /*
      if (is_keyboard_master()) {
        oled_render_os();
        oled_render_layout_state();
        oled_render_modifier_state();
        oled_render_keylock_state();
        oled_render_layer_state();
        oled_render_logo();
      } else {

      }
  */
    oled_render_os();
    oled_render_layout_state();
    oled_render_modifier_state();
    oled_render_keylock_state();
    oled_render_layer_state();
    //oled_render_logo();
    return false;
}

#endif // OLED_ENABLE
