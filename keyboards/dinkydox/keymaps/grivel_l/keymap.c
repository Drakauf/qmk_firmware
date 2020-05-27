#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _COLEMAK 3
#define _ADJUST 16

enum custom_keycodes {
  COLEMAK,
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  TMUX_PREFIX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Tab |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  |   "  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |V_DOWN|   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  | V_UP |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |Lower | GUI  |      |           |      |RAISE | Alt  |
 *                      `-------------|Space |           | Entr |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_COLEMAK] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,         KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC,
  KC_ESC,   LSFT_T(KC_A),   KC_R,   KC_S,   KC_T,   KC_D,   KC_H,   KC_N,   KC_E,   KC_I,   RSFT_T(KC_O),    KC_QUOT,
  KC_VOLD,    LCTL_T(KC_Z),   KC_X,   KC_C,   LALT_T(KC_V),   KC_B,   KC_K,   KC_M,   KC_COMM,    KC_DOT,   RCTL_T(KC_SLSH),    KC_VOLU,
                    LOWER,    KC_LGUI,    KC_SPC,   KC_ENT,   RAISE,    KC_LALT
),

/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |V_DOWN|   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | V_UP |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |Lower | GUI  |      |           |      |RAISE | Alt  |
 *                      `-------------|Space |           | Entr |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,   LSFT_T(KC_A),   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   RSFT_T(KC_SCLN),    KC_QUOT,
  KC_VOLD,    LCTL_T(KC_Z),   KC_X,   KC_C,   LALT_T(KC_V),   KC_B,   KC_N,   KC_M,   KC_COMM,    KC_DOT,   RCTL_T(KC_SLSH),    KC_VOLU,
                    LOWER,    KC_LGUI,    KC_SPC,   KC_ENT,   RAISE,    KC_LALT
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |Shift | Left |  Up  | Down |Right |           | DEL  | HOME | END  | PGUP |PGDOWN|      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |BRI_U |BRI_D |      |      | Alt  |PRTSCR|           | Left | Down |  Up  |Right |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |      |      |      |           |      |Adjust|      |
 *                      `-------------|      |           | MUTE |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_LOWER] = LAYOUT( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,    KC_F12,
    _______, KC_LSFT, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,    KC_DEL,  KC_HOME, KC_END,  KC_PGUP,  RSFT_T(KC_PGDOWN), _______,
    KC_BRID, LCTL_T(KC_BRIU), _______, _______, KC_LALT, KC_PSCREEN, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,   _______,
                              _______, _______, _______,     KC_MUTE, ADJUST, _______
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |   `  | BTN3 |  7   |  8   |  9   |  A   |           |  B   |  !   |  @   |  (   |  )   |  =   |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |CTL_A |  4   |  5   |  6   |  C   |           |  D   |  #   |  $   |  [   |  ]   |  ^   |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |Shift |  X   |  1   |  2   |  3   |  E   |           |  F   |  -   |  *   |  &   |  %   |  \   |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |  0   | GUI  | Spc  |           |      |      |      |
 *                      `-------------|      |           |      |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_RAISE] = LAYOUT( \
    KC_GRV,  KC_BTN3,     KC_7,    KC_8, KC_9,    KC_A,   KC_B,    KC_EXCLAIM, KC_AT,   KC_LPRN, KC_RPRN, KC_EQUAL,
    _______, TMUX_PREFIX, KC_4,    KC_5, KC_6,    KC_C,   KC_D,    KC_HASH,    KC_DLR,  KC_LBRC, KC_RBRC, KC_CIRC,
    KC_LSFT, KC_X,        KC_1,    KC_2, KC_3,    KC_E,   KC_F,    KC_MINUS,   KC_ASTR, KC_AMPR, KC_PERC, KC_BSLS,
                              KC_0, KC_LGUI, KC_SPC, _______, _______,    _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |      |Reset |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |      |      |      |      |      |      |           |      |      |      |      |      |      |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |      |      |      |           |      |      |      |
 *                      `-------------|      |           |      |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_ADJUST] = LAYOUT( \
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                               _______, _______, DF(_COLEMAK), DF(_QWERTY), _______, _______
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t keyTimer;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
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
    case TMUX_PREFIX:
      if (record->event.pressed) {
        keyTimer = timer_read();
        SEND_STRING(SS_DOWN(X_LSFT));
      } else {
        SEND_STRING(SS_UP(X_LSFT));
        if (keyTimer != 0 && timer_elapsed(keyTimer) < TAPPING_TERM) {
          SEND_STRING(SS_LCTL("a"));
        }
      }
      break;
    default:
      if (keyTimer != 0)
        keyTimer = 0;
  }
  return true;
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
