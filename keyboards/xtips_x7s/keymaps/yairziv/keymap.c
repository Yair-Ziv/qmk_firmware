// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



/*
 * Layers
 */
enum layers {
    _QWERTY,
    _SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /*
  * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
  * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
  * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
  * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
  * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
  * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
  * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
  *           ┌───┐                   ┌───┐
  *           │GUI├───┐           ┌───┤Alt│
  *           └───┤Bsp├───┐   ┌───┤Ent├───┘
  *               └───┤   │   │   ├───┘
  *                   └───┘   └───┘
  */
[_QWERTY] = LAYOUT_split_3x5_3(
KC_Q,         KC_W,       KC_E,       KC_R,       KC_T,        /*||*/           KC_Y,    KC_U,       KC_I,       KC_O,             KC_P,
LGUI_T(KC_A), LOPT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,     /*||*/              KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), ROPT_T(KC_L),       RGUI_T(KC_SCLN),
KC_Z,       LOPT_T(KC_X), KC_C,       KC_V,       KC_B,       /*||*/            KC_N,    KC_M,       KC_COMM,    ROPT_T(KC_DOT),     KC_SLSH,
                       KC_LGUI, KC_BSPC, LT(_SYM, KC_SPC),     /*||*/      LT(_NUM, KC_ENT),  KC_ENT,  KC_RALT
),
[_SYM] = LAYOUT_split_3x5_3(
RSFT(KC_GRV),       RSFT(KC_COMM),       RSFT(KC_DOT),       LSFT(KC_6),       RSFT(KC_BSLS),         /*||*/          LSFT(KC_7),    KC_BSLS,       KC_LBRC,       KC_RBRC,  KC_NO,
KC_ESC, KC_MINS, LSFT(KC_EQL), KC_EQL, KC_QUOT,        /*||*/           RSFT(KC_QUOT),    KC_NO, RSFT(KC_9), RSFT(KC_0),       LSFT(KC_SCLN),
KC_NO,       KC_SLSH, RSFT(KC_8),       LSFT(KC_4),       KC_NO,       /*||*/            KC_NO,    KC_NO,       RSFT(KC_LBRC),    LSFT(KC_RBRC),     KC_NO,
                       KC_LGUI, KC_BSPC, LT(_SYM, KC_SPC),      /*||*/     KC_SPC,  KC_ENT,  KC_RALT
),
};
