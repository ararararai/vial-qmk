/* Copyright 2023 ai03
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

/*
terminalで実行して.uf2ファイルを生成
コマンド
make salicylic_acid3/goforty_ortho:custom
出力先
/vial-qmk/.build/salicylic_acid3_goforty_ortho_custom.uf2
左上のキーを押しながらキーボードを接続するとフォルダーが開かれるので
ドラッグ＆ドロップする
*/

#include QMK_KEYBOARD_H
#define TAPPING_TERM 200



enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    DVORAK,
    LOWER,
    RAISE,
    ADJUST,
    BACKTICKS,
    BACKTICKSCOPY,
};

enum layers {
    _QWERTY,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define QWERTY  MO(_QWERTY)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,--------------------------------------------------------------------------------------------------.
 * |  Up  |   Q  |   W  |   E  |   R  |   T  | Esc  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Right |   A  |   S  |   D  |   F  |   G  |  '   |   H  |   J  |   K  |   L  |   ;  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Left  |   Z  |   X  |   C  |   V  |   B  | Del  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |Down  | Ctrl | Alt  |Shift |Lower |      Space   |Raise | CMD  | Alt  | Ctrl | MEH  |
 * `--------------------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT(
    LCTL(KC_V),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
    LCTL(KC_C), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_MINS,
    LCTL(KC_PLUS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
    LCTL(KC_MINS),  KC_LCTL, KC_F12,  KC_LSFT, LOWER,   KC_TAB,  KC_SPC,  RAISE,   KC_LCMD, LGUI(LSFT(KC_S)), LGUI(LCTL(KC_T)), KC_LALT
),

[_DVORAK] = LAYOUT(
    KC_UP,    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_ESC,  KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_RIGHT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_QUOT, KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LEFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_DEL,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
    KC_DOWN,  KC_LCTL, KC_A,    KC_S,    LOWER,            KC_SPC,  RAISE,   KC_LCMD, KC_A,    KC_TRNS, KC_PGDN, KC_PGUP
),
/* Lower
 * ,---------------------------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   .  |   )  |   (  |  -   |   ~  | Left | Down |  Up  | Right|  :   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   -  |   +  |   }  |   {  |      |   |  |  _   |  +   |   <  |   >  |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT(
    _______,  KC_1,     KC_2,     KC_3,        KC_4,         KC_5,     _______,  KC_6,     KC_7,     KC_8,         KC_9,         KC_0,       KC_BSPC,
    _______,  KC_COMM,  KC_DOT,   KC_RPRN,     KC_LPRN,      KC_MINS,  KC_TILD,  KC_LEFT,  KC_DOWN,  KC_UP,        KC_RGHT,      S(KC_SCLN), KC_EQL,
    _______,  C(KC_B),  KC_PLUS,  KC_RCBR,     KC_LCBR,      KC_EXLM,  KC_PIPE,  KC_UNDS,  KC_PLUS,  S(KC_COMM),   S(KC_DOT),    KC_BSLS,    _______,
    _______,  _______,  _______,  _______,     _______,                _______,  _______,  _______,  _______,      _______,      _______,    _______
),

/* Raise
 * ,---------------------------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   `  |   ^  |   &  |   *  | Home |  End |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |ISO # |   '  |   "  |   |  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  ←  |  ↓  |  ↑  |  →  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT(
    _______,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_GRV,  KC_CIRC,    KC_AMPR,    KC_ASTR,     KC_HOME, KC_END,  _______,
    _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MS_BTN1, KC_QUOT,    S(KC_QUOT),  KC_PIPE, _______, _______,
    _______,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MS_L,    KC_MS_D,    KC_MS_U,     KC_MS_R, _______, _______,
    _______,  _______, _______, _______, _______,          _______, _______,     _______,   _______,     _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,---------------------------------------------------------------------------------------------------.
 * |      |A+Tab |      | RGB  |RGBMOD| MOD  | HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CAG1 | CAG2 |   ]  |   [  | MPLY |      |H+C   |A+D   |A+N   | MsRt |      |PrtScr|
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | CAG3 | CAG4 | Vol- | Vol+ | CAPS |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `---------------------------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
    _______,  A(KC_TAB),   _______,     RGB_TOG,     RGB_RMOD,    RGB_MOD,     RGB_HUI,  RGB_HUD,    RGB_SAI,    RGB_SAD,       RGB_VAI,  RGB_VAD,  KC_DEL,
    _______,  LCAG(KC_1),  LCAG(KC_2),  KC_RBRC,     KC_LBRC,     KC_MPLY,     _______,  MEH(KC_C),  A(KC_D),    A(KC_N),       KC_MS_R,  _______,  LGUI(KC_PSCR),
    _______,  LCAG(KC_3),  LCAG(KC_4),  KC_VOLD,     KC_VOLU,     KC_CAPS,     _______,  _______,    BACKTICKS,  BACKTICKSCOPY, _______,  _______,  _______,
    _______,  _______,     _______,     _______,     _______,                  _______,  _______,    _______,    _______,       _______,  _______, _______
),



};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
static bool lower_pressed = false;
static uint16_t lower_pressed_time = 0;
static bool raise_pressed = false;
static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                lower_pressed = true;
                lower_pressed_time = record->event.time;

                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (lower_pressed && (TIMER_DIFF_16(record->event.time, lower_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_LANGUAGE_2); // for macOS
                    register_code(KC_INT5);
                    unregister_code(KC_INT5);
                    unregister_code(KC_LANGUAGE_2);
                }
                lower_pressed = false;
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                raise_pressed = true;
                raise_pressed_time = record->event.time;

                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
                    register_code(KC_LANGUAGE_1); // for macOS
                    register_code(KC_INT4);
                    unregister_code(KC_INT4);
                    unregister_code(KC_LANGUAGE_1);
                }
                raise_pressed = false;
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
        case BACKTICKS:
            // claudeでコードブロックを挿入するショートカット
            // Shift + Enter(改行)  ↑(カーソルを上に)  ```(コードブロック)  Shift + Enter
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_ENT);
                tap_code(KC_ENT);
                unregister_code(KC_LSFT);
                tap_code(KC_UP);
                SEND_STRING("```");
                register_code(KC_LSFT);
                tap_code(KC_ENT);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
        case BACKTICKSCOPY:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_ENT);
                tap_code(KC_ENT);
                unregister_code(KC_LSFT);
                tap_code(KC_UP);
                SEND_STRING("```");
                register_code(KC_LSFT);
                tap_code(KC_ENT);
                unregister_code(KC_LSFT);
                register_code(KC_LCTL);
                tap_code(KC_V);
                unregister_code(KC_LCTL);
                tap_code(KC_DOWN);
            }
            return false;
            break;
        default:
            if (record->event.pressed) {
                // reset the flags
                lower_pressed = false;
                raise_pressed = false;
            }
            break;
    }
    return true;
}
