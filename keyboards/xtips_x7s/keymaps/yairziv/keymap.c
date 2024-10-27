// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



/*
 * Layers
 */
enum layers {
    _QWERTY,
    _SYM,
    _NUM,
    _NAV
};

// EMPTY LAYER
// [_SYM] = LAYOUT_split_3x5_3(
// XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,         /*||*/          XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,  XXXXXXX,
// XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        /*||*/           XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,
// XXXXXXX,       XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,       /*||*/            XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,     XXXXXXX,
//                        XXXXXXX, XXXXXXX, XXXXXXX,      /*||*/     XXXXXXX,  XXXXXXX,  XXXXXXX
// ),

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
                       LT(_SYS, KC_LGUI), LT(_NAV, KC_BSPC), LT(_SYM, KC_ENT),     /*||*/      LT(_NUM, KC_SPC),  KC_DEL,  KC_RALT
),
[_SYM] = LAYOUT_split_3x5_3(
RSFT(KC_GRV),       RSFT(KC_COMM),       RSFT(KC_DOT),       LSFT(KC_6),       RSFT(KC_BSLS),         /*||*/          LSFT(KC_7),    KC_BSLS,       KC_LBRC,       KC_RBRC,  XXXXXXX,
KC_ESC, KC_MINS, LSFT(KC_EQL), KC_EQL, KC_QUOT,        /*||*/           RSFT(KC_QUOT),    XXXXXXX, RSFT(KC_9), RSFT(KC_0),       LSFT(KC_SCLN),
XXXXXXX,       KC_SLSH, RSFT(KC_8),       LSFT(KC_4),       XXXXXXX,       /*||*/            XXXXXXX,    XXXXXXX,       RSFT(KC_LBRC),    LSFT(KC_RBRC),     XXXXXXX,
                       KC_LGUI, KC_BSPC, LT(_SYM, KC_SPC),      /*||*/     KC_SPC,  KC_ENT,  KC_RALT
),
[_NUM] = LAYOUT_split_3x5_3(
LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),        /*||*/               LSFT(KC_6), LSFT(KC_7), LSFT(KC_8),       LSFT(KC_9), LSFT(KC_0),
KC_1, KC_2, KC_3, KC_4, KC_5,        /*||*/               KC_6, KC_7, KC_8,       KC_9, KC_0,
KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,        /*||*/               KC_F6, KC_F7, KC_F8,       KC_F9, KC_F10,
                       XXXXXXX, XXXXXXX, XXXXXXX,      /*||*/     XXXXXXX,  XXXXXXX,  XXXXXXX
),
[_NAV] = LAYOUT_split_3x5_3(
LGUI(KC_TAB),       XXXXXXX,       XXXXXXX,       KC_PGUP,       XXXXXXX,         /*||*/          XXXXXXX,    XXXXXXX,       XXXXXXX,       XXXXXXX,  KC_PRINT_SCREEN,
LCTL(KC_TAB), XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX,        /*||*/           KC_LEFT, KC_DOWN, KC_UP,       KC_RIGHT, XXXXXXX,
XXXXXXX,       XXXXXXX, XXXXXXX,       KC_PGDN,       XXXXXXX,       /*||*/            XXXXXXX,    KC_PRINT_SCREEN,       XXXXXXX,    XXXXXXX,     XXXXXXX, // TODO: MOVE PRINT SCREEN FROM HERE
                       XXXXXXX, XXXXXXX, XXXXXXX,      /*||*/     XXXXXXX,  XXXXXXX,  XXXXXXX
),
};


/*
* Combos
*/
enum combos{
    FJ_ESC,
    GH_DASH,
    BN_UNDERSCORE,
    F4F5_F11,
    F6F7_F12,
    SD_EQUALS,
    SX_EQUAL_LESS,
    SW_EQUAL_GREATER
};
const uint16_t PROGMEM fj_esc[] =        {KC_T, KC_Y, COMBO_END};
// TODO: Make work later
// const uint16_t PROGMEM yt_caps_word[] =  {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM gh_dash[] =       {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM bn_underscore[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM f4f5_f11[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM f6f7_f12[] = {KC_F6, KC_F7, COMBO_END};

const uint16_t PROGMEM sd_equals[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM sx_equal_less[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM sw_equal_greater[] = {KC_S, KC_W, COMBO_END};

combo_t key_combos[] = {
    [FJ_ESC]        = COMBO(fj_esc, KC_ESC),
    [GH_DASH]       = COMBO(gh_dash, KC_MINS),
    [BN_UNDERSCORE] = COMBO(bn_underscore, LSFT(KC_MINS)),
    [F4F5_F11]      = COMBO(f4f5_f11, KC_F11),
    [F6F7_F12]      = COMBO(f6f7_f12, KC_F12),
    [SD_EQUALS]     = COMBO_ACTION(sd_equals),
    [SX_EQUAL_LESS]     = COMBO_ACTION(sx_equal_less),
    [SW_EQUAL_GREATER]     = COMBO_ACTION(sw_equal_greater),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case SD_EQUALS:
      if (pressed) {
        SEND_STRING("=");
      }
      break;
    case SX_EQUAL_LESS:
      if (pressed) {
        SEND_STRING("<=");
      }
      break;
    case SW_EQUAL_GREATER:
      if (pressed) {
        SEND_STRING(">=");
      }
      break;
  }
}
