#include QMK_KEYBOARD_H
#include "eeconfig.h"

#ifdef RGBLIGHT_ENABLE
    #include "rgblight.h"
#endif

extern keymap_config_t keymap_config;

#define PERMISSIVE_HOLD
#define TAPPING_TERM 100

#define _BASE 0
#define _SYMBOL 3
#define _FUNCTION 4
#define _ADJUST 16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
    MC_ARR = SAFE_RANGE,
    MC_DARR,
    MC_DEQL,
    MC_TEQL,
    KC_RESET
};

#define SYMBOL MO(_SYMBOL)
#define FUNCT MO(_FUNCTION)
#define FUNSPC LT(_FUNCTION, KC_SPC)
#define ADJUST MO(_ADJUST)
#define CTLESC LCTL_T(KC_ESC)
#define LOCK LCTL(LGUI(KC_Q))
#define BACK LGUI(KC_LBRC)
#define FORWARD LGUI(KC_RBRC)
#define NXTFUNC LCTL(KC_DOWN)
#define PRVFUNC LCTL(KC_UP)

#ifndef LAYOUT_ortho_4x12
    #define LAYOUT_ortho_4x12 KEYMAP
#endif

#define LAYOUT_PEEJ(...) LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT_PEEJ_7u(...) LAYOUT_ortho_7u(__VA_ARGS__)

/* Base layer
 * ,-----------------------------------------. ,-------------. ,-----------------------------------------.
 * | Esc  |  1   |  2   |  3   |  4   |  5   | |  -   |  =   | |  6   |  7   |  8   |  9   |  0   | Del  |
 * |------+------+------+------+------+------| |------+------| |------+------+------+------+------+------|
 * | Tab  |  Q   |  W   |  E   |  R   |  T   | |  [   |  ]   | |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+------| |------+------| |------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   | |  {   |  }   | |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------| |------+------| |------+------+------+------+------+------|
 * | Shft |  Z   |  X   |  C   |  V   |  B   | |  (   |  )   | |  N   |  M   |  ,   |  .   |  /   | Entr |
 * |------+------+------+------+------+------| |------+------| |------+------+------+------+------+------|
 * | Ctrl |  Fn  | Alt  | Cmd  | Symb | Spce | |      |      | | Spce |  Fn  | Left | Down |  Up  | Rght |
 * `-----------------------------------------' `-------------' `-----------------------------------------'
 */
#define BASE_ROW_1_L          KC_1,  KC_2,    KC_3,    KC_4,   KC_5
#define BASE_ROW_2_L          KC_Q,  KC_W,    KC_E,    KC_R,   KC_T
#define BASE_ROW_3_L          KC_A,  KC_S,    KC_D,    KC_F,   KC_G
#define BASE_ROW_4_L          KC_Z,  KC_X,    KC_C,    KC_V,   KC_B
#define BASE_ROW_5_L KC_LCTL, FUNCT, KC_LALT, KC_LGUI, SYMBOL, KC_SPC

#define ARROW_ROW KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT

#define BASE_ROW_1_R KC_6, KC_7, KC_8, KC_9, KC_0
#define BASE_ROW_2_R KC_Y, KC_U, KC_I, KC_O, KC_P
#define BASE_ROW_3_R KC_H, KC_J, KC_K, KC_L, KC_SCLN
#ifdef ARROW_LAYOUT
    #define BASE_ROW_4_R KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP
    #define BASE_ROW_5_R KC_SPC, FUNCT, KC_SLSH, KC_LEFT, KC_DOWN, KC_RIGHT
#else
    #define BASE_ROW_4_R KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH
    #define BASE_ROW_5_R KC_SPC, FUNCT, ARROW_ROW
#endif

#define BASE_ROW_1_M KC_MINS, KC_EQL
#define BASE_ROW_2_M KC_LPRN, KC_RPRN
#define BASE_ROW_3_M KC_LCBR, KC_RCBR
#define BASE_ROW_4_M KC_LBRC, KC_RBRC

#define BASE_ROW_1 KC_GESC, BASE_ROW_1_L, BASE_ROW_1_R, KC_DEL
#define BASE_ROW_2 KC_TAB,  BASE_ROW_2_L, BASE_ROW_2_R, KC_BSPC
#define BASE_ROW_3 KC_GESC, BASE_ROW_3_L, BASE_ROW_3_R, KC_QUOT
#define BASE_ROW_4 KC_LSFT, BASE_ROW_4_L, BASE_ROW_4_R, KC_ENTER
#define BASE_ROW_5          BASE_ROW_5_L, BASE_ROW_5_R

/* Symbol layer
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   _  |   +  |   (  |   {  |   [  | |   ]  |   }  |   )  |   -  |   =  |   \  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   `  |   ~  |  =>  |  ->  |   -  | |   =  |  ==  |  === |   ~  |   `  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp | | Bksp |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------' `-----------------------------------------'
 */
#define SYMBOL_ROW_1_L          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define SYMBOL_ROW_2_L          KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define SYMBOL_ROW_3_L          KC_UNDS, KC_PLUS, KC_LPRN, KC_LCBR, KC_LBRC
#define SYMBOL_ROW_4_L          KC_GRV,  KC_TILD, MC_DARR, MC_ARR,  KC_MINS
#define SYMBOL_ROW_5_L _______, _______, _______, _______, _______, KC_BSPC

#define SYMBOL_ROW_1_R KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define SYMBOL_ROW_2_R KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define SYMBOL_ROW_3_R KC_RBRC, KC_RCBR, KC_RPRN, KC_MINS, KC_EQL
#ifdef ARROW_LAYOUT
    #define SYMBOL_ROW_4_R KC_EQL, MC_DEQL, MC_TEQL, KC_TILD, KC_PGUP
    #define SYMBOL_ROW_5_R KC_DEL, ADJUST,  KC_GRV,  KC_HOME, KC_PGDN, KC_END
#else
    #define SYMBOL_ROW_4_R KC_EQL,  MC_DEQL, MC_TEQL, KC_TILD, KC_GRV
    #define SYMBOL_ROW_5_R KC_BSPC, _______,  KC_HOME, KC_PGDN, KC_PGUP, KC_END
#endif

#define SYMBOL_ROW_1 _______, SYMBOL_ROW_1_L, SYMBOL_ROW_1_R, _______
#define SYMBOL_ROW_2 _______, SYMBOL_ROW_2_L, SYMBOL_ROW_2_R, _______
#define SYMBOL_ROW_3 _______, SYMBOL_ROW_3_L, SYMBOL_ROW_3_R, KC_BSLS
#define SYMBOL_ROW_4 _______, SYMBOL_ROW_4_L, SYMBOL_ROW_4_R, _______
#define SYMBOL_ROW_5          SYMBOL_ROW_5_L, SYMBOL_ROW_5_R

/* Function layer
 * ,-----------------------------------------. ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | | Left | Down |  Up  | Rght |      |   \  |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  | F10  | | Home | PgDn | PgUp | End  |   `  |      |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      | Ajst |      |      |      | Del  | | Del  |      | Back | Prev | Next | Fwd  |
 * `-----------------------------------------' `-----------------------------------------'
 */
#define FUNCTION_ROW_1_L          KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5
#define FUNCTION_ROW_2_L          KC_1,   KC_2,    KC_3,    KC_4,    KC_5
#define FUNCTION_ROW_3_L          KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5
#define FUNCTION_ROW_4_L          KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10
#define FUNCTION_ROW_5_L _______, ADJUST, _______, _______, _______, KC_DEL

#define FUNCTION_ROW_1_R KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define FUNCTION_ROW_2_R KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define FUNCTION_ROW_3_R KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#ifdef ARROW_LAYOUT
    #define FUNCTION_ROW_4_R KC_HOME, KC_PGDN, KC_PGUP, KC_END, PRVFUNC
    #define FUNCTION_ROW_5_R KC_DEL,  _______, KC_GRV,  BACK,   NXTFUNC, FORWARD
#else
    #define FUNCTION_ROW_4_R KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_GRV
    #define FUNCTION_ROW_5_R KC_DEL,  _______, BACK,    NXTFUNC, PRVFUNC, FORWARD
#endif

#define FUNCTION_ROW_1 _______, FUNCTION_ROW_1_L, FUNCTION_ROW_1_R, _______
#define FUNCTION_ROW_2 _______, FUNCTION_ROW_2_L, FUNCTION_ROW_2_R, _______
#define FUNCTION_ROW_3 _______, FUNCTION_ROW_3_L, FUNCTION_ROW_3_R, KC_BSLS
#define FUNCTION_ROW_4 _______, FUNCTION_ROW_4_L, FUNCTION_ROW_4_R, _______
#define FUNCTION_ROW_5          FUNCTION_ROW_5_L, FUNCTION_ROW_5_R


/* Adjust layer */
#define ADJUST_ROW_2_L          KC_RESET, XXXXXXX, XXXXXXX, BL_STEP, BL_TOGG
#define ADJUST_ROW_3_L          XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_ROW_4_L          AG_NORM,  AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX
#define ADJUST_ROW_5_L XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______, XXXXXXX

#define ADJUST_ROW_2_R RGB_TOG, RGB_VAI, RGB_SAI, RGB_HUI, XXXXXXX
#define ADJUST_ROW_3_R RGB_MOD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX
#ifndef ARROW_LAYOUT
    #define ADJUST_ROW_4_R RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_G, KC_VOLU
    #define ADJUST_ROW_5_R XXXXXXX, _______, XXXXXXX, KC_MPLY, KC_VOLD, KC_MUTE
#else
    #define ADJUST_ROW_4_R RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_G, RGB_M_T
    #define ADJUST_ROW_5_R XXXXXXX, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE
#endif

#define ADJUST_ROW_2 XXXXXXX, ADJUST_ROW_2_L, ADJUST_ROW_2_R, LOCK
#define ADJUST_ROW_3 XXXXXXX, ADJUST_ROW_3_L, ADJUST_ROW_3_R, XXXXXXX
#define ADJUST_ROW_4 XXXXXXX, ADJUST_ROW_4_L, ADJUST_ROW_4_R, XXXXXXX
#define ADJUST_ROW_5          ADJUST_ROW_5_L, ADJUST_ROW_5_R

#define EMPTY_ROW    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool is_shifted = keyboard_report->mods & MOD_LSFT;

    if (record->event.pressed) {
        switch(keycode) {
            case MC_ARR:
                if (is_shifted) {
                    unregister_mods(MOD_LSFT);
                    SEND_STRING("=>");
                    register_mods(MOD_LSFT);
                } else {
                    SEND_STRING("->");
                }
                return false;
            case MC_DARR:
                unregister_mods(MOD_LSFT);
                SEND_STRING("=>");
                if (is_shifted) register_mods(MOD_LSFT);
                return false;
            case MC_DEQL:
                if (is_shifted) {
                    unregister_mods(MOD_LSFT);
                    SEND_STRING("!=");
                    register_mods(MOD_LSFT);
                } else {
                    SEND_STRING("==");
                }
                return false;
            case MC_TEQL:
                if (is_shifted) {
                    unregister_mods(MOD_LSFT);
                    SEND_STRING("!==");
                    register_mods(MOD_LSFT);
                } else {
                    SEND_STRING("===");
                }
                return false;
            case KC_RESET:
                #ifdef RGBLIGHT_ENABLE
                    rgblight_enable_noeeprom();
                    rgblight_mode_noeeprom(1);
                    rgblight_setrgb_red();
                #endif
                reset_keyboard();
                return false;
        }
    }

    return true;
};
