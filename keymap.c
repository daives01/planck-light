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
