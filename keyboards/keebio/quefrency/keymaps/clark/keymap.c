#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE_STD 0
#define _BASE_CLARK 1
#define _LOWER 3

#define BASE_STD DF(_BASE_STD)
#define BASE_CLARK DF(_BASE_CLARK)
#define LOWER MO(_LOWER)

#define CMDTB LGUI(KC_TAB)
#define CMDTD LGUI(KC_GRAVE)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

// tapdance definitions
enum {
  CESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_STD] = LAYOUT(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  KC_BSPC, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, \
    KC_GRAVE, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,    LOWER,  KC_SPC,   KC_RGUI,   KC_RALT, KC_RCTL, _______, KC_DEL
  ),

  [_BASE_CLARK] = LAYOUT(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______,  _______, \
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    TD(CESC),  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______, \
    KC_GRAVE, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,    KC_SPC,  LOWER,   KC_RGUI,   KC_RALT, KC_RCTL, _______, KC_BSLS
  ),

  [_LOWER] = LAYOUT(
      _______,    KC_F1,      KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, KC_DEL,
      _______,  _______,    _______,   _______, _______, _______, _______,   CMDTB,   CMDTD, KC_LBRC, KC_RBRC, _______, _______,  KC_DEL,
      _______,  _______,    _______,   _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
      _______,  _______,    _______,   _______, _______, _______, KC_MINS, KC_UNDS,  KC_EQL, KC_PLUS, KC_BSLS, _______, _______,
      BASE_STD,  BASE_CLARK,    _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),
};


// Tap Dance Declarations
// **************** Definitions needed for quad function to work *********************//
// Enums used to clearly convey the state of the tap dance

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}


// CESC
static tap cesc_tap_state = {
  .is_press_action = true,
  .state = 0
};

void cl_finished (qk_tap_dance_state_t *state, void *user_data) {
  cesc_tap_state.state = cur_dance(state);
  switch (cesc_tap_state.state) {
    case SINGLE_TAP: register_code(KC_ESC); break;
    case SINGLE_HOLD: register_code(KC_LCTL); break;
  }
}

void cl_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (cesc_tap_state.state) {
    case SINGLE_TAP: unregister_code(KC_ESC); break;
    case SINGLE_HOLD: unregister_code(KC_LCTL); break;
  }
  cesc_tap_state.state = 0;
}



// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [CESC]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, cl_finished, cl_reset),
};
