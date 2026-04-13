#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // ROW0: ESC, F1, F2, F3, F4, F5
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
        // ROW1: `, 1, 2, 3, 4, 5, 6
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        // ROW2: TAB, Q, W, E, R, T
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        // ROW3: CAPS, A, S, D, F, G
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        // ROW4: LSFT, Z, X, C, V, B
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
        // ROW5: LCTL, Fn, LALT, SPC, M
        KC_LCTL, MO(1),   KC_LALT, KC_SPC,  KC_M
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
