#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _COLEMAK 3
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |      |CTRL()|      |      |      |      |           |      |      |      |GUI() |CTRL()|      |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |GUI   |Lower |      |           |      |RAISE | Alt  |
 *                      `-------------|Space |           | Entr |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_QWERTY] = LAYOUT( \
    KC_TAB,   KC_Q,           KC_W,   KC_E,   KC_R,   KC_T,             KC_Y,   KC_U,   KC_I,       KC_O,           KC_P,               KC_BSPC,
    KC_ESC,   KC_A,           KC_S,   KC_D,   KC_F,   KC_G,             KC_H,   KC_J,   KC_K,       KC_L,           KC_SCLN,            KC_QUOT,
    KC_LSFT,  LCTL_T(KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,             KC_N,   KC_M,   KC_COMM,    RGUI_T(KC_DOT), RCTL_T(KC_SLSH),    KC_RSFT,
                              KC_LGUI,   LOWER,     KC_SPC,             KC_ENT, RAISE,  KC_ROPT
),

/* Lower
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |PRTSCR| Left | Down |  Up  | Right|      |           | DEL  | HOME | END  | PGUP |PGDOWN|      |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |Shft()|CTRL()|BRI_U |BRI_D |      |      |           | Mute |Vol D |Vol U |GUI() |CTRL()|Shft()|
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |      |      |      |           |      |      |  Alt |
 *                      `-------------|      |           |      |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_LOWER] = LAYOUT( \
    KC_F1,              KC_F2,      KC_F3,      KC_F4,  KC_F5,      KC_F6,                  KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
    KC_PSCREEN,         KC_LEFT,   KC_DOWN,    KC_UP,  KC_RIGHT,    _______,                KC_DEL,     KC_HOME,    KC_END,     KC_PGUP,    KC_PGDOWN,  _______,
    KC_LSFT,    KC_LCTL, KC_BRID, KC_BRIU, _______, _______,               KC_MUTE, KC_VOLD, KC_VOLU,   KC_RGUI, KC_RCTL,   KC_RSFT,
                                                    _______, _______, _______,              _______, _______, KC_ROPT
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |   `  | BTN3 |      |  7   |  8   |  9   |           |   !  |  @   |  (   |  )   |  =   | Bksp |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Esc |CTL_B |      |  4   |  5   |  6   |           |   #  |  $   |  [   |  ]   |  ^   |  Alt |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |Shift | CTRL | Alt  |  1   |  2   |  3   |           |   -  |  *   |  &   |  %   |  \   | Shift|
 * |      |      |      |      |      |      |           |      |      |      |      |CTRL()|      |
 * `-----------------------------------------'           `-----------------------------------------'
 *                      ,--------------------.           ,------,-------------.
 *                      |  GUI |  0   | Spc  |           |      |      |      |
 *                      `-------------|      |           |      |------+------.
 *                                    |      |           |      |
 *                                    `------'           `------'
 */
[_RAISE] = LAYOUT( \
    KC_GRV,     KC_BTN3,        _______,    KC_7,    KC_8,  KC_9,       KC_EXCLAIM, KC_AT,      KC_LPRN,    KC_RPRN,            KC_EQUAL,           KC_BSPC,
    KC_ESC,     LCTL(KC_B),     _______,    KC_4,    KC_5,  KC_6,       KC_HASH,    KC_DLR,     KC_LBRC,    KC_RBRC,            KC_CIRC,            KC_ROPT,
    KC_LSFT,    KC_LCTL,        KC_LOPT,    KC_1,    KC_2,  KC_3,       KC_MINUS,   KC_ASTR,    KC_AMPR,    KC_PERC,    RCTL_T(KC_BSLS),    KC_RSFT,
                                KC_LGUI,    KC_0,   KC_SPC,             _______, _______,    _______
)
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void  matrix_init_user(void) {
  set_unicode_input_mode(UC_LNX);
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
    default:
      if (keyTimer != 0)
        keyTimer = 0;
  }
  return true;
}

/* uint16_t get_tapping_term(uint16_t keycode) {
  switch (keycode) {
    case LCTL_T(KC_X):
    case LCTL_T(KC_Z):
    case LCTL_T(KC_BRIU):
      return TAPPING_TERM - 30;
    default:
      return TAPPING_TERM;
  }
} */
