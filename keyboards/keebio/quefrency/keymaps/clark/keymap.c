#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE_STD 0
#define _BASE_CLARK 1
#define _BASE_GAME 2
#define _LOWER 3

#define BASE_STD DF(_BASE_STD)
#define BASE_CLARK DF(_BASE_CLARK)
#define BASE_GAME DF(_BASE_GAME)
#define LOWER MO(_LOWER)

#define CMDTB LGUI(KC_TAB)
#define CMDTD LGUI(KC_GRAVE)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_STD] = LAYOUT(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, \
    KC_GRAVE, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,    KC_SPC,  LOWER,   KC_RGUI,   KC_RALT, KC_RCTL, _______, KC_DEL
  ),

  [_BASE_CLARK] = LAYOUT(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, \
    KC_GRAVE, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,    KC_SPC,  LOWER,   KC_RGUI,   KC_RALT, KC_RCTL, _______, KC_BSLS
  ),

  [_LOWER] = LAYOUT(
      _______, BASE_STD, BASE_CLARK, BASE_GAME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
      _______,  _______,    _______,   _______, _______, _______, _______,   CMDTB,   CMDTD, KC_LBRC, KC_RBRC, _______, _______, KC_DEL,
      _______,  _______,    _______,   _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
      _______,  _______,    _______,   _______, _______, _______, KC_MINS, KC_UNDS,  KC_EQL, KC_PLUS, KC_BSLS, _______, _______,
      _______,  _______,    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};
