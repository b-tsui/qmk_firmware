/* Copyright 2018
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

#define SFT_P1 LSFT_T(KC_P1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * ,----------------------------------.
   * |  Esc |   ~  |   /  |   *  | Home | R1
   * |------+------+------+------+------|
   * |   7  |   8  |   9  |   -  | PgUp | R2
   * |------+------+------+------+------|
   * |   4  |   5  |   6  |   +  | PgDn | R3
   * |------+------+------+------+------|
   * |   1  |   2  |   3  |  Up  |  End | R4
   * |-Shft-+------+------+------+------|
   * |  Alt |  Cmd | Left | Down | Rght | R4
   * `----------------------------------'
   */
  LAYOUT_ortho_5x5(
    KC_ESC,  KC_TILD, KC_PSLS, KC_PAST, KC_HOME, \
    KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_END, \
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PGUP, \
    SFT_P1,  KC_P2,   KC_P3,   KC_UP,   KC_PGDN,  \
    KC_LALT, KC_LGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
