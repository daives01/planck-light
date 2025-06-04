/* Copyright 2015-2021 Jack Humbert
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
#include "rgb_matrix.h"       // for rgb_matrix_indicators_advanced_user
#include "colors.h"

enum planck_layers {
  _WINDOWS,
  _MAC,
  _GAMING,
  _LOWER,
  _RAISE,
  _ADJUST
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define WINDOWS PDF(_WINDOWS)
#define MAC PDF(_MAC)
#define GAMING PDF(_GAMING)

static bool caps_active = false;

void caps_word_set_user(bool active) {
    caps_active = active;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Windows 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Back | GUI  | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_WINDOWS] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_CAPS,  KC_A, MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LCTL, KC_F), KC_G, KC_H,  MT(MOD_RCTL, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L),    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC, KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_RGUI, KC_RCTL, KC_ENT  
),

/* Mac 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Back | GUI  | Alt  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_CAPS,  KC_A, MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G, KC_H,  MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L),    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_ESC, KC_LALT, KC_LGUI, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_RGUI, KC_RALT, KC_ENT  
),

/* Gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Z   |  X   |  C   |  V   |Space |Space |Raise |  ,   |  .   |  /   | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT_planck_grid(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_SPC,  KC_SPC,  RAISE,   KC_COMM, KC_DOT,  KC_SLSH, KC_ENT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |  (   |  )   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |   (  |  )   |      |      |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |  {   |   [  |  ]   |  }   |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 | F12  |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_EQL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_LPRN,    KC_RPRN,    _______, _______, KC_MINS,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_LCBR, KC_LBRC,    KC_RBRC,    KC_RCBR, KC_BSLS, _______,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | Left | Down |  Up  | Right|      |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 | Prev | Vol- | Vol+ | Next |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 | F12  |      |Lower |             |      | Play |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_MINS,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_BSLS, _______,
    _______, KC_F11,  KC_F12,  _______, LOWER,   _______, _______, _______, KC_MPLY, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset|Debug |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB  | Next | HUE+ | SAT+ |BRGT+ | SPED+|      | Win  |  Mac | Game |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | HUE- | SAT- |BRGT- | SPED-|      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
  QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, WINDOWS, MAC,     GAMING,  _______, _______,
  _______, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define IDX(r,c) g_led_config.matrix_co[(r)][(c)]

static const rgb_t layer_colors[][MATRIX_ROWS][MATRIX_COLS] = {
[_WINDOWS] = {
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BLK, BLK, BCK, BCK, BCK, BCK, BCK, BCK }
},

[_MAC] = {
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK }
},

[_GAMING] = {
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, RED, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, RED, RED, RED, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
  { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK }
},

[_LOWER] = {
    { BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU },
    { BCK, RED, RED, RED, RED, RED, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, RED, RED, RED, RED, RED, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, RED, RED, BCK, WHT, BCK, BCK, BCK, BCK, BCK, BCK, BCK }
},

[_RAISE] = {
    { BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU },
    { BCK, RED, RED, RED, RED, RED, CYA, CYA, CYA, CYA, BCK, BCK },
    { BCK, RED, RED, RED, RED, RED, PUP, PUP, PUP, PUP, BCK, BCK },
    { BCK, RED, RED, BCK, BLU, BCK, BCK, WHT, BCK, BCK, BCK, BCK }
},

[_ADJUST] = {
    { RED, RED, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { WHT, WHT, WHT, WHT, WHT, WHT, BCK, CYA, PUP, RED, BCK, BCK },
    { BCK, WHT, WHT, WHT, WHT, WHT, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, WHT, BCK, BCK, WHT, BCK, BCK, BCK, BCK }
},
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // combine default + momentary layers
    uint8_t layer = get_highest_layer(default_layer_state | layer_state);

    // paint our per-layer grid...
    for (uint8_t r = 0; r < MATRIX_ROWS; r++) {
        for (uint8_t c = 0; c < MATRIX_COLS; c++) {
            uint8_t idx = IDX(r,c);
            if (idx < led_min || idx >= led_max) continue;
            rgb_t col = layer_colors[layer][r][c];
            if (col.r || col.g || col.b) {
                rgb_matrix_set_color(idx, col.r, col.g, col.b);
            }
        }
    }

    // highlight the current active base layer
    if (layer == _ADJUST) {
        uint8_t base_layer = get_highest_layer(default_layer_state);
        uint8_t key_col = 7;  // default to Windows
        if (base_layer == _MAC) {
            key_col = 8;
        } else if (base_layer == _GAMING) {
            key_col = 9;
        }
        uint8_t idx = IDX(0, key_col);
        // set to white
        if (idx >= led_min && idx < led_max) {
            rgb_matrix_set_color(idx, WHT_R, WHT_G, WHT_B);
        }
    }

    if (host_keyboard_led_state().caps_lock || caps_active) {
        uint8_t idx = IDX(1, 0); // Caps Lock key position
        if (idx >= led_min && idx < led_max) {
            rgb_matrix_set_color(idx, RED_R, RED_G, RED_B); // Set to red when Caps Lock is active
        }
    }
    return false;
}