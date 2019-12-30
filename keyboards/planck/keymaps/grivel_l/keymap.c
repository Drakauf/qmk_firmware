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


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _OPTS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

enum custom_keycodes {
  TMUX_PREFIX
};

#define OPTS MO(_OPTS)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | OPTS | Alt  |Lower |  GUI | Spc  | Entr |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,         KC_W,    KC_E,  KC_R,         KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,         KC_S,    KC_D,  KC_F,         KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, LCTL_T(KC_Z), KC_X,    KC_C,  LALT_T(KC_V), KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, OPTS,         KC_LALT, LOWER, KC_LGUI,      KC_SPC, KC_ENT, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | DEL  | HOME | END  | PGUP |PGDOWN|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BRI_U |BRI_D |      |      |      |SCREEN| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MUTE |V_DOWN| V_UP |      | GUI  | Spc  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,
    _______, _______, _______, _______, _______, _______,    KC_DEL,  KC_HOME, KC_END,  KC_PGUP,  KC_PGDOWN, _______,
    KC_BRID,  KC_BRIU,  _______, _______, _______, KC_PSCREEN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,   _______,
    KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_LGUI, KC_SPC,     _______, _______, _______, _______,  _______,   _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  | BTN3 |  7   |  8   |  9   |   A  |   B  |   !  |   @  |   (  |   )  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CTL_A |  4   |  5   |  6   |  C   |  D   |   #  |   $  |   [  |   ]  |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  X   |  1   |  2   |  3   |  E   |  F   |   -  |  *   |  &   |  %   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Alt  |  0   | GUI  | Spc  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_BTN3,     KC_7,    KC_8, KC_9,    KC_A,   KC_B,    KC_EXCLAIM, KC_AT,   KC_LPRN, KC_RPRN, KC_EQUAL,
    _______, TMUX_PREFIX, KC_4,    KC_5, KC_6,    KC_C,   KC_D,    KC_HASH,    KC_DLR,  KC_LBRC, KC_RBRC, KC_CIRC,
    KC_LSFT, KC_X,        KC_1,    KC_2, KC_3,    KC_E,   KC_F,    KC_MINUS,   KC_ASTR, KC_AMPR, KC_PERC, KC_BSLS,
    KC_LCTL, _______,     KC_LALT, KC_0, KC_LGUI, KC_SPC, _______, _______,    _______, _______, _______, _______
),

/* Options
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |TGLAUD|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |TGLMUS|MUSMOD|      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_OPTS] = LAYOUT_planck_grid(
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    AU_TOG,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MU_TOG,  MU_MOD,  _______, _______, _______, _______, _______, _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, 0);
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
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
    case TMUX_PREFIX:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("a"));
      }
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
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_OPTS);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_OPTS);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case OPTS:
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
