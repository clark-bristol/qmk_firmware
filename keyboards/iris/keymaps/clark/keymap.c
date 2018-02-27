#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// tapdance definitions
// enum {
//   W_LPRN = 0,
//   E_LBRC = 0,
//   R_LCBR = 0,
//   // TD_LALT,
//   // TD_LSFT,
//   // TD_RSFT,
// };

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP
// #define LPRN LSFT(KC_9)
// #define RPRN LSFT(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
     KC_GESC , KC_1   ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                         KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_TAB  , KC_Q   ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                         KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     KC_LCTL , KC_A   ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                         KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------.    ,--------|--------+--------+--------+--------+--------+--------|
      KC_LSPO, KC_Z   ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,TG(_RAISE),    KC_ASTG,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSPC,
  //`--------+--------+--------+--------+--------+--------+--------/    \--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, KC_LGUI, KC_SPC ,         KC_ENT , KC_LOWR, KC_LEAD
  //                                  `--------+--------+--------'        `--------+--------+--------'
  ),

// hotkey categories:
  // cmd... : switch focus between apps (tab), windows (grave), tabs (numbers)
  // opt... : switch focus between panes (add: opt+tab)
  // cmd+shft : move and resize windows
  // ?

// MEH = Left Control, Shift and Alt
// CAPS = Left Control, Shift, Alt and GUI

[_LOWER] = KC_KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
    GRAVE    ,        ,        ,        ,        ,        ,                               ,        ,        ,MINS    , EQL    , DEL    ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,        ,LPRN    ,LBRC    ,LCBR    ,        ,                               ,RCBR    ,RBRC    ,RPRN    ,        ,        ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,MINS    ,UNDS    ,EQL     ,PLUS    ,        ,                       LEFT    ,DOWN    , UP     ,RGHT    ,        ,        ,
  //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
             ,        ,        ,        ,        ,        ,         ,        CAPS,        ,MINS    ,UNDS    ,EQL     ,PLUS    ,        ,
  //`--------+--------+--------+--------+--------+--------+--------/    \--------+--------+--------+--------+--------+--------+--------'
                                                ,        ,    LEAD,               ,        ,
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
             ,        ,        ,        ,        ,        ,        ,    ,        ,PDOT    , P0     , P1     , P2     , P3     ,
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


//Tap Dance Declarations
//**************** Definitions needed for quad function to work *********************//
//Enums used to clearly convey the state of the tap dance

// enum {
//   SINGLE_TAP = 1,
//   SINGLE_HOLD = 2,
//   DOUBLE_TAP = 3,
//   DOUBLE_HOLD = 4,
//   DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
//   // Add more enums here if you want for triple, quadruple, etc.
// };

// typedef struct {
//   bool is_press_action;
//   int state;
// } tap;

// int cur_dance (qk_tap_dance_state_t *state) {
//   if (state->count == 1) {
//     //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
//     if (state->interrupted || state->pressed==0) return SINGLE_TAP;
//     else return SINGLE_HOLD;
//   }
//   //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
//   //with single tap. In example below, that means to send `xx` instead of `Escape`.
//   else if (state->count == 2) {
//     if (state->interrupted) return DOUBLE_SINGLE_TAP;
//     else if (state->pressed) return DOUBLE_HOLD;
//     else return DOUBLE_TAP;
//   }
//   else return 6; //magic number. At some point this method will expand to work for more presses
// }



//**************** Definitions needed for quad function to work *********************//



// //LALT
// static tap lalt_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void lalt_finished (qk_tap_dance_state_t *state, void *user_data) {
//   lalt_tap_state.state = cur_dance(state);
//   switch (lalt_tap_state.state) {
//     case SINGLE_TAP: register_code(KC_LBRC); break;
//     case SINGLE_HOLD: register_code(KC_LALT); break;
//   }
// }

// void lalt_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (lalt_tap_state.state) {
//     case SINGLE_TAP: unregister_code(KC_LBRC); break;
//     case SINGLE_HOLD: unregister_code(KC_LALT); break;
//   }
//   lalt_tap_state.state = 0;
// }



// //LSFT
// static tap lsft_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void lsft_finished (qk_tap_dance_state_t *state, void *user_data) {
//   lsft_tap_state.state = cur_dance(state);
//   switch (lsft_tap_state.state) {
//     case SINGLE_TAP:
//       register_code(KC_LSFT);
//       register_code(KC_9);
//       break;
//     case SINGLE_HOLD: register_code(KC_LSFT); break;
//   }
// }

// void lsft_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (lsft_tap_state.state) {
//     case SINGLE_TAP:
//       unregister_code(KC_9);
//       unregister_code(KC_LSFT);
//       break;
//     case SINGLE_HOLD: unregister_code(KC_LSFT); break;
//   }
//   lsft_tap_state.state = 0;
// }



// // W
// static tap w_tap_state = {
//   .is_press_action = true,
//   .state = 0
// };

// void w_finished (qk_tap_dance_state_t *state, void *user_data) {
//   w_tap_state.state = cur_dance(state);
//   switch (w_tap_state.state) {
//     case SINGLE_TAP:
//       register_code(KC_W);
//       break;
//     case DOUBLE_TAP:
//       register_code(KC_LSFT);
//       register_code(KC_9);
//       break;
//   }
// }

// void w_reset (qk_tap_dance_state_t *state, void *user_data) {
//   switch (w_tap_state.state) {
//     case SINGLE_TAP:
//       unregister_code(KC_W);
//       break;
//     case DOUBLE_TAP:
//       unregister_code(KC_9);
//       unregister_code(KC_LSFT);
//       break;
//   }
//   w_tap_state.state = 0;
// }



// //Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   // [W_LPRN]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, w_finished, w_reset),
//   // [E_LBRC]  = ACTION_TAP_DANCE_DOUBLE (KC_E, KC_LBRC),
//   // [R_LCBR]  = ACTION_TAP_DANCE_DOUBLE (KC_R, KC_LCBR),
//   // [TD_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
//   // [TD_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_finished, rsft_reset),
// };



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
    SEQ_TWO_KEYS(KC_Q, KC_L) {
      SEND_STRING("LIMIT 10;");
    }
    SEQ_TWO_KEYS(KC_Q, KC_J) {
      SEND_STRING("LEFT JOIN table t ON t.col = a.col");
    }
    SEQ_TWO_KEYS(KC_Q, KC_U) {
      SEND_STRING("SELECT col, COUNT(*) FROM table GROUP BY 1 ORDER BY 2 DESC;");
    }
  }
}
