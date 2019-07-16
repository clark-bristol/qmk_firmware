#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  ADJUST,
};

// tapdance definitions
enum {
  CESC
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_GAME GAME
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
    KC_TAB   ,   KC_Q ,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
    TD(CESC) ,   KC_A ,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
    KC_LSPO  ,   KC_Z ,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSPC,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
    KC_GRAVE , KC_CAPS, KC_LALT, KC_LGUI,  RAISE ,  KC_SPC,         ,            ,   KC_SPC,  LOWER, KC_RGUI, KC_RALT, KC_LEAD, KC_BSLS,
  //`--------+--------+--------+--------+--------+--------+--------/    \--------+--------+--------+--------+--------+--------+--------'
                                                ,        ,        ,               ,        ,
  //                                  `--------+--------+--------'        `--------+--------+--------'
  ),

[_GAME] = KC_KEYMAP(
//,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
            ,  ESC  ,    1   ,     2  ,      3 ,     4  ,                               ,        ,        ,        ,        ,        ,
//|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
            ,  TAB  ,    Q   ,    W   ,     E  ,    R   ,                               ,        ,        ,        ,        ,        ,
//|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
           ,  LCTL  ,    A   ,     S  ,      D  ,    F  ,                               ,        ,        ,        ,        ,        ,
//|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
           ,  LSFT  ,    Z   ,     X  ,    C   ,   V    ,         ,            ,        ,        ,        ,        ,        ,        ,
//`--------+--------+--------+--------+--------+--------+--------/    \--------+--------+--------+--------+--------+--------+--------'
                                             ,        ,        ,               ,        ,
//                                  `--------+--------+--------'        `--------+--------+--------'
),

// hotkey categories:
  // cmd... : switch focus between apps (tab), windows (grave), tabs (numbers)
  // opt... : switch focus between panes (add: opt+tab)
  // cmd+shft : move and resize windows
  // ?

// MEH = Left Control, Shift and Alt
// CAPS = Left Control, Shift, Alt and GUI

[_LOWER] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LBRC, KC_RBRC, KC_DEL ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        KC_MINS, KC_UNDS,  KC_EQL, KC_PLUS, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+--------+--------+--------+--------/    \--------+--------+--------+--------+--------+--------+--------'
                                        _______, _______,_______ ,        _______,  _______,_______
  //                                  `--------+--------+--------'        `--------+--------+--------'
  ),

[_RAISE] = KC_KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     F12     , F1     , F2     , F3     , F4     , F5     ,                        F6     , F7     , F8     , F9     ,F10     ,F11     ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,MRWD    ,MFFD    ,VOLU    ,PGUP    ,        ,                               ,PSLS    ,PMNS    , P7     , P8     , P9     ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,MSTP    ,MPLY    ,VOLD    ,PGDN    ,        ,                               ,PAST    ,PPLS    , P4     , P5     , P6     ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,        ,        ,        ,        ,        ,        ,             ,        ,PDOT    , P0     , P1     , P2     , P3     ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
                                                ,        ,        ,                ,        ,
  //                                  `--------+--------+--------'        `--------+--------+--------'
  ),

[_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, RESET  , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+--------+---+--------+--------+--------/        \--------+--------+--------+---+--------+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

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



#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}


// Leader Key
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // SEQ_ONE_KEY(KC_T) {
    //   SEND_STRING("SELECT COUNT");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_H);
    //   unregister_code(KC_H);
    // }
    SEQ_TWO_KEYS(KC_Q, KC_C) {
      SEND_STRING("SELECT COUNT(*) FROM ");
    }
    SEQ_TWO_KEYS(KC_Q, KC_S) {
      SEND_STRING("SELECT * FROM ");
    }
    SEQ_TWO_KEYS(KC_Q, KC_L) {
      SEND_STRING("LIMIT 10;");
    }
    SEQ_TWO_KEYS(KC_Q, KC_J) {
      SEND_STRING("LEFT JOIN table t ON t.col = a.col");
    }
    SEQ_TWO_KEYS(KC_Q, KC_U) {
      SEND_STRING("SELECT col, COUNT(*) FROM table GROUP BY 1 ORDER BY 2 DESC;");
    }
    SEQ_TWO_KEYS(KC_Q, KC_D) {
      SEND_STRING("SELECT ddl\nFROM admin.v_generate_tbl_ddl\nWHERE schemaname = 'warehouse' AND tablename = 'table_name';\n\nSELECT get_ddl('table', 'warehouse.table_name');");
    }
  }
}
