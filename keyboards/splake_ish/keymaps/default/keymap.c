// Copyright 2026 theb0b
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY = 0,
    _NUM,
    _UPPER,
    _FN_NAV
};

// Home Row Mod Definitions (Balanced Tap-Hold)
#define HML_S  MT(MOD_LCTL, KC_S)
#define HMR_L  MT(MOD_RCTL, KC_L)

// Layer Tap & Toggle Helpers
#define LT_ENT  LT(_NUM, KC_ENT)

// uint8_t const COMBO_COUNT = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_NO,  KC_Q,   KC_W,   KC_E,    KC_R,   KC_T,      KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_NO,
        KC_NO,  KC_A,   HML_S,  KC_D,    KC_F,   KC_G,      KC_H,   KC_J,   KC_K,    HMR_L,   KC_SCLN, KC_NO,
        KC_NO,  KC_Z,   KC_X,   KC_C,    KC_V,   KC_B,      KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
        EE_CLR,KC_LGUI,LT_ENT,KC_BSPC,             KC_SPC, KC_RSFT,MO(_UPPER), MO(_FN_NAV)
    ),

    /* Layer 2: Numbers & Navigation */
    [_NUM] = LAYOUT(
        KC_NO,  KC_1,   KC_2,   KC_3,    KC_4,   KC_5,      KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_NO,
        KC_NO,  KC_TAB, KC_TRNS,KC_TRNS, KC_LALT,KC_TRNS,   KC_DEL, KC_TRNS,KC_TRNS, KC_UP,   KC_TRNS, KC_NO,
        KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,   KC_TRNS,KC_LEFT,KC_DOWN, KC_RGHT, KC_TRNS, KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),

    /* Layer 3: Upper (Symbols & System) */
    [_UPPER] = LAYOUT(
        KC_NO,  KC_EXLM,KC_AT,  KC_HASH, KC_DLR, KC_PERC,   KC_CIRC,KC_AMPR,KC_ASTR, KC_TRNS, KC_TRNS, KC_NO,
        KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,QK_BOOT,   KC_MINS,KC_EQL, KC_BSLS, KC_GRAVE,KC_TRNS, KC_NO,
        KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,   KC_UNDS,KC_PLUS,KC_PIPE, KC_TILD, KC_TRNS, KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    ),

    /* Layer 4: FN + Nav */
    [_FN_NAV] = LAYOUT(
        KC_NO,  KC_F1,  KC_F2,  KC_F3,   KC_F4,  KC_F5,     KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_NO,
        KC_NO,  KC_F11, KC_F12, KC_TRNS, KC_TRNS,QK_BOOT,   QK_BOOT,KC_TRNS,KC_UP,   KC_TRNS, KC_TRNS, KC_NO,
        KC_NO,  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,   KC_TRNS,KC_LEFT,KC_DOWN, KC_RGHT, KC_TRNS, KC_NO,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,            KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
    )
};


void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}