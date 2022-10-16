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


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
    _AZERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define CTLTB CTL_T(KC_TAB)
#define GUIEI GUI_T(KC_LANG2) // ?
#define ALTKN ALT_T(KC_LANG1) // ?

#define SPACESFT RSFT_T(KC_SPC) //Right shift when held, Space when tapped
#define ENTCTRL LCTL_T(KC_ENT) //

#define KC_MNXT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AZERTY] = LAYOUT_split_3x6_3(
     KC_ESC,     KC_A,     KC_Z,     KC_E,     KC_R,     KC_T,            KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  KC_BSPC,
     KC_TAB,     KC_Q,     KC_S,     KC_D,     KC_F,     KC_G,            KC_H,     KC_J,     KC_K,     KC_L,     KC_M,  XXXXXXX,
    XXXXXXX,     KC_W,     KC_X,     KC_C,     KC_V,     KC_B,            KC_N,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_EXLM,  XXXXXXX,
                                      XXXXXXX,    LOWER,   ENTCTRL, SPACESFT,  RAISE,  XXXXXXX
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    KC_MPRV,  KC_VOLU,    KC_F2,    KC_F3,    KC_F5,  XXXXXXX,         KC_BSPC,  KC_HOME,    KC_UP,  KC_PGUP,  XXXXXXX,  KC_CALC,
    KC_MPLY,  KC_MUTE,   KC_CUT,  KC_COPY,  KC_PSTE,  XXXXXXX,          KC_DEL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  KC_MAIL,
    KC_MNXT,  KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,   KC_END,  XXXXXXX,  KC_PGDN,  KC_MYCM,  KC_WHOM,
                                      XXXXXXX,  _______,  KC_RSFT,  XXXXXXX,  _______,  XXXXXXX

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,         KC_NLCK,    KC_P7,    KC_P8,    KC_P9,  KC_PMNS,  XXXXXXX,
      KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,         KC_PAST,    KC_P4,    KC_P5,    KC_P6,  KC_PPLS,  XXXXXXX,
    KC_NUBS,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         KC_PSLS,    KC_P1,    KC_P2,    KC_P3,  KC_PENT,  XXXXXXX,
                                      XXXXXXX,  _______,  XXXXXXX,  KC_LCTL,  _______,  KC_P0
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    KC_MPRV,  KC_VOLU,    KC_F2,    KC_F3,    KC_F5,  XXXXXXX,         KC_BSPC,  KC_HOME,    KC_UP,  KC_PGUP,  XXXXXXX,  KC_CALC,
    KC_MPLY,  KC_MUTE,   KC_CUT,  KC_COPY,  KC_PSTE,  XXXXXXX,          KC_DEL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  KC_MAIL,
    KC_MNXT,  KC_VOLD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,          KC_INS,   KC_END,  XXXXXXX,  KC_PGDN,  KC_MYCM,  KC_WHOM,
                                      XXXXXXX,  _______,  KC_RSFT,  XXXXXXX,  _______,  XXXXXXX

  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
    QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,  XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                        GUIEI,  _______,   KC_SPC,   KC_ENT,  _______,    ALTKN
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

#    define KEYLOG_LEN 5
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _AZERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("Lower"), layer_state_is(_LOWER));
    oled_write_P(PSTR("Raise"), layer_state_is(_RAISE));
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    oled_write_P(PSTR("BTMGK"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_keylock_status(host_keyboard_leds());
    render_mod_status(get_mods());
    render_bootmagic_status();

    render_keylogger_status();
}

bool oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_crkbd_logo();
        oled_scroll_left();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    return true;
}
#endif
