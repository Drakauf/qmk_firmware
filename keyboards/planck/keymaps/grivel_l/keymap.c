/* Copyright 2017-2017 Jack Humbert
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
  _COLEMAK,
  _LOWER,
  _RAISE,
  _OPTS,
  _MOUSE
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
#define MOUSE MO(_MOUSE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |V_DOWN|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  | V_UP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY| OPTS | Alt  |Lower |  GUI | Spc  | Entr |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,         KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
  KC_ESC,   LSFT_T(KC_A),   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   RSFT_T(KC_O),    KC_QUOT,
  KC_VOLD,    LCTL_T(KC_Z),   KC_X,   KC_C,   LALT_T(KC_V),   KC_B,   KC_K,   KC_M,   KC_COMM,    KC_DOT,   RCTL_T(KC_SLSH),    KC_VOLU,
  DF(_QWERTY), OPTS, KC_LALT, LOWER,    KC_LGUI,    KC_SPC,   KC_ENT,   RAISE,    KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |V_DOWN|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | V_UP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |COLEMA| OPTS | Alt  |Lower |  GUI | Spc  | Entr |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,          KC_W,    KC_E,  KC_R,         KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,             KC_BSPC,
    KC_ESC,  LSFT_T(KC_A), KC_S,    KC_D,  KC_F,         KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    RSFT_T(KC_SCLN), KC_QUOT,
    _______, LCTL_T(KC_Z),  KC_X,    KC_C,  LALT_T(KC_V), KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), _______,
    KC_MUTE, OPTS,          KC_LALT, LOWER, KC_LGUI,      KC_SPC, KC_ENT, RAISE, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Shift | Left |  Up  | Down |Right | DEL  | HOME | END  | PGUP |PGDOWN|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BRI_U |BRI_D |      |      | Alt  |SCREEN| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MUTE |V_DOWN| V_UP |      | GUI  | Spc  |      |Mouse |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,
    _______, KC_LSFT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,    KC_DEL,  KC_HOME, KC_END,  KC_PGUP,  RSFT_T(KC_PGDOWN), _______,
    KC_BRID, LCTL_T(KC_BRIU), _______, _______, KC_LALT, KC_PSCREEN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,   _______,
    KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_LGUI, KC_SPC,     _______, MOUSE,   _______, _______,  _______,   _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  | BTN3 |  7   |  8   |  9   |   A  |   B  |   !  |   @  |   (  |   )  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |CTL_A |  4   |  5   |  6   |  C   |  D   |   #  |   $  |   [  |   ]  |  ^   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  X   |  1   |  2   |  3   |  E   |  F   |   -  |  *   |  &   |  %   |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Alt  |  0   | GUI  | Spc  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_BTN3,     KC_7,    KC_8, KC_9,    KC_A,   KC_B,    KC_EXCLAIM, KC_AT,   KC_LPRN, KC_RPRN, KC_EQUAL,
    _______, TMUX_PREFIX, KC_4,    KC_5, KC_6,    KC_C,   KC_D,    KC_HASH,    KC_DLR,  KC_LBRC, KC_RBRC, KC_CIRC,
    KC_LSFT, LCTL_T(KC_X),        KC_1,    KC_2, KC_3,    KC_E,   KC_F,    KC_MINUS,   KC_ASTR, KC_AMPR, KC_PERC, KC_BSLS,
    _______, _______,     KC_LALT, KC_0, KC_LGUI, KC_SPC, _______, _______,    _______, _______, _______, _______
),

/* Options
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |TGLRGB|RGBHUE|RGBSAT|RGBVAL|RGM_M |RGB_M |RGB_M |RGB_M |RGB_M |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |TGLAUD|TGLMUS|MUSMOD|      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_OPTS] = LAYOUT_planck_grid(
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_KNIGHT, RGB_MODE_GRADIENT, _______,
    _______, _______, AU_TOG, MU_TOG,  MU_MOD,  _______, _______, _______, _______, _______, _______, _______
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |WHL_L | BTN1 | BTN3 | BTN2 |WHL_R |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |WHL_D | SPD1 | SPD2 | SPD3 |WHL_U |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_WH_L, KC_BTN1, KC_BTN3, KC_BTN2, KC_WH_R, _______,
    _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_D, KC_ACL0, KC_ACL1, KC_ACL2, KC_WH_U, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
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
  static uint16_t keyTimer;

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
        keyTimer = timer_read();
        SEND_STRING(SS_DOWN(X_LSFT));
      } else {
        SEND_STRING(SS_UP(X_LSFT));
        if (timer_elapsed(keyTimer) < TAPPING_TERM + 100) {
          SEND_STRING(SS_LCTL("a"));
        }
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
    if (clockwise)
      tap_code(KC_VOLU);
    else
      tap_code(KC_VOLD);
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

uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LCTL_T(KC_X):
    case LCTL_T(KC_Z):
    case LCTL_T(KC_BRIU):
      return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
}
