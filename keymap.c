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
#include "quantum/color.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

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
#define MAC DF(_MAC)
#define GAMING DF(_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Windows 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Del  |Lower |    Space    |Raise | Back | GUI  | Ctrl | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_WINDOWS] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_ESC,  KC_A, MT(MOD_LALT, KC_S), MT(MOD_LGUI, KC_D), MT(MOD_LCTL, KC_F), KC_G, KC_H,  MT(MOD_RCTL, KC_J), MT(MOD_RGUI, KC_K), MT(MOD_RALT, KC_L),    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_RGUI, KC_RCTL, KC_ENT  
),

/* Mac 
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Del  |Lower |    Space    |Raise | Back | GUI  | Alt  | Enter|
 * `-----------------------------------------------------------------------------------'
 */
[_MAC] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_ESC,  KC_A, MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G, KC_H,  MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L),    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LALT, KC_LGUI, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_BSPC, KC_RGUI, KC_RALT, KC_ENT  
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

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//   }
//   return true;
// }

// A small helper to get LED index from row/col:


#define IDX(r,c) g_led_config.matrix_co[(r)][(c)]

#define RGB(r, g, b)   (rgb_t){ (r), (g), (b) }

// clamp x to [0..255]
#define CLAMP255(x)  ( ((x) > 255) ? 255 : ( (x) < 0 ? 0 : (x) ) )

// OFFSET(col, d) → take base rgb_t 'col', add 'd' to each channel, clamp to [0,255]
#define OFFSET(col, d)                                                         \
  (rgb_t){                                                                      \
    CLAMP255((col).r + (d)),                                                    \
    CLAMP255((col).g + (d)),                                                    \
    CLAMP255((col).b + (d))                                                     \
  }

#define BCK RGB(0x00, 0x00, 0x00)
#define BLU RGB(0x00, 0x00, 0xFF)
#define GRN RGB(0x00, 0xFF, 0x00)
#define RED RGB(0xFF, 0x00, 0x00)
#define CYN RGB(0x00, 0xFF, 0xFF)
#define YLW RGB(0xFF, 0xFF, 0x00)
#define MAG RGB(0xFF, 0x00, 0xFF)
#define ORNG RGB(0xFF, 0xA5, 0x00)
#define PURP RGB(0x80, 0x00, 0x80)
#define WHT RGB(0xFF, 0xFF, 0xFF)

// A fully QMK-native rgb_t grid:
static const rgb_t layer_colors[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _WINDOWS, _MAC, _GAMING: all off */
  [_WINDOWS] = {
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BLU, BCK, BCK, BLU, BCK, BCK, BCK, BCK }
  },
  [_MAC] = {
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BLU, BCK, BCK, BLU, BCK, BCK, BCK, BCK }
  },
  [_GAMING] = {
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, WHT, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, WHT, WHT, WHK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BLK, BCK, BCK, BLU, BCK, BCK, BCK, BCK }
  },

[_LOWER] = {
    { BLU, OFFSET(BLU, -25), OFFSET(BLU, -20), OFFSET(BLU, -15), OFFSET(BLU, -10), OFFSET(BLU, -5), OFFSET(BLU, 0), OFFSET(BLU, 5), OFFSET(BLU, 10), OFFSET(BLU, 15), OFFSET(BLU, 20),  BLU },
    { BCK, OFFSET(GRN, -20), OFFSET(GRN, -10), OFFSET(GRN, 0), OFFSET(GRN, 10), OFFSET(GRN, 20), BCK, YEL, YEL, BCK, BCK, BCK, BCK },
    { BCK, OFFSET(ORG, -20), OFFSET(ORG, -10), OFFSET(ORG, 0), OFFSET(ORG, 10), OFFSET(ORG, 20), YEL, YEL, YEL, YEL, PURP, BCK, BCK },
    { BCK, OFFSET(RED, -10), OFFSET(RED,  10), BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK }
},

[_RAISE] = {
    { BLU, OFFSET(BLU,-25), OFFSET(BLU,-20), OFFSET(BLU,-15), OFFSET(BLU,-10), OFFSET(BLU,-5), OFFSET(BLU,0), OFFSET(BLU,5), OFFSET(BLU,10), OFFSET(BLU,15), OFFSET(BLU,20), BLU },
    { BCK, OFFSET(GRN,-20), OFFSET(GRN,-10), OFFSET(GRN,0), OFFSET(GRN,10), OFFSET(GRN,20), CYA, CYA, CYA, CYA, BCK, YEL },
    { BCK, OFFSET(ORG,-20), OFFSET(ORG,-10), OFFSET(ORG,0), OFFSET(ORG,10), OFFSET(ORG,20), CYA, CYA, CYA, CYA, PUP, BCK },
    { BCK, OFFSET(RED,-10), OFFSET(RED,10), BCK, YEL, BCK, BCK, PUP, BCK, BCK, BCK, BCK }
},

[_ADJUST] = {
    { RED, OFFSET(RED,10), BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK },
    { CYA, OFFSET(CYA,10), RED, YEL, GRN, BLU, BCK, MAG, MAG, MAG, BCK, BCK },
    { BCK, OFFSET(RED,-10), YEL, GRN, BLU, PUP, BCK, BCK, BCK, BCK, BCK, BCK },
    { BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK, BCK }
},
};

// Advanced indicator callback: only iterates within [led_min..led_max)
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t layer = biton32(layer_state);

  // paint our per-layer grid
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

  // return false to stop any keyboard-level indicators
  return false;
}