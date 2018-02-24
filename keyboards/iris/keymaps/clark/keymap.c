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

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RST RESET
#define KC_BL_S BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GESC, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,BSLS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  , MEH,     LEAD, N  , M  ,COMM,DOT ,SLSH,RSFT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                        LALT,LGUI,SPC ,       ENT ,LOWR,RASE
  //                  `----+----+----'        `----+----+----'
  ),

// hotkey categories:
  // cmd... : switch focus between apps (tab), windows (grave), tabs (numbers)
  // opt... : switch focus between panes (add: opt+tab)
  // cmd+shft : move and resize windows
  // ?

// MEH = Left Control, Shift and Alt
// CAPS = Left Control, Shift, Alt and GUI

[_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
    GRAVE,    ,    ,    ,    ,    ,                   ,    ,    ,MINS, EQL, DEL,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LPRN,LBRC,LCBR,    ,                   ,RCBR,RBRC,RPRN,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MINS,UNDS,EQL ,PLUS,    ,               LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,     CAPS,    ,MINS,UNDS,EQL ,PLUS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    , LEAD,            ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

[_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MRWD,MFFD,VOLU,PGUP,    ,                   ,PSLS,PMNS, P7 , P8 , P9 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MSTP,MPLY,VOLD,PGDN,    ,                   ,PAST,PPLS, P4 , P5 , P6 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,PDOT, P0 , P1 , P2 , P3 ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
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
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

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
