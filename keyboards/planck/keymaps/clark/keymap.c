/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _GAME,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

// tapdance definitions
enum {
  CESC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define QWERTY DF(_QWERTY)
#define GAME DF(_GAME)

#define CMDTB LGUI(KC_TAB)
#define CMDTD LGUI(KC_GRAVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | CEsc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Sft ( |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft ) |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Caps | Alt  | GUI  | Raise|Space | Space|Lower | GUI  | Alt  | Lead |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    TD(CESC), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    KC_GRAVE, KC_CAPS, KC_LALT, KC_LGUI, RAISE,  KC_SPC,  KC_SPC,  LOWER,   KC_RGUI, KC_RALT, KC_LEAD, KC_BSLS
),

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSFT |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | RSFT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  | Caps | Alt  | GUI  | Raise|Space | Space|Lower | GUI  | Alt  | Lead |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    KC_TAB  , KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ESC,
    KC_LCTL , KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT , KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_GRAVE, KC_CAPS, KC_LALT, KC_LGUI, RAISE,  KC_SPC,  KC_SPC,  LOWER,   KC_RGUI, KC_RALT, KC_LEAD, KC_BSLS
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |CMDTAB|CMDTLD|   [  |   ]  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  |Right |      | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Minus| Undsc|  Eq  | Plus |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______,    CMDTB,     CMDTD,   KC_LBRC, KC_RBRC, KC_DEL ,
    _______, _______, _______, _______, _______, _______, KC_LEFT,  KC_DOWN,     KC_UP,   KC_RGHT, _______,  KC_ENT,
    _______, _______, _______, _______, _______, _______, KC_MINS, KC_UNDS ,    KC_EQL,   KC_PLUS, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______,  _______,   _______,   _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
   KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9 ,    KC_0,  KC_BSLS,
    _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,  _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,  _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      | Reset|Reset |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET  ,        QWERTY,     GAME, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,        AU_TOG,   MU_TOG,  MU_MOD, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MFFD, _______, _______,
    _______, CLICKY_TOGGLE,    CK_UP, CK_DOWN, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,       _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
