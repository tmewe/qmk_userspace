#include QMK_KEYBOARD_H

// GENERAL
// Thumb keys
// Both
#define L1_SPC LT(1, KC_SPC)
// Right
#define RCTL_ENT RCTL_T(KC_ENT)
// Right
#define L2_BSPC LT(2, KC_BSPC)
#define LCTL_TAB LCTL_T(KC_TAB)

// Combos
const uint16_t PROGMEM F_J_ESC[] = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};
combo_t key_combos[] = {
    COMBO(F_J_ESC, KC_ESC),
};


// LAYER 0
// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define CTL_SC LCTL_T(KC_SCLN)

// Used for Aerospace
#define LCA_V LCA_T(KC_V)

// Key overrides
const key_override_t ae_key_override = ko_make_basic(MOD_MASK_ALT, CTL_A, RALT(KC_Q));
const key_override_t oe_key_override = ko_make_basic(MOD_MASK_ALT, KC_O, RALT(KC_P));
const key_override_t ue_key_override = ko_make_basic(MOD_MASK_ALT, KC_U, RALT(KC_Y));

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&ae_key_override,
	&oe_key_override,
	&ue_key_override
};

// MS Teams
#define SG_H SGUI(KC_H)
#define SG_M SGUI(KC_M)


// LAYER 1
// Left-hand brackets with home row mods
#define CTL_CIR LCTL_T(KC_CIRC)
#define ALT_LBR LALT_T(KC_LBRC)
#define GUI_LCB LGUI_T(KC_LCBR)
#define SFT_LPR LSFT_T(KC_LPRN)


// LAYER 2
// Left hand math symbols with home row mods
#define CTL_MIN LCTL_T(KC_MINS)
#define ALT_AST LALT_T(KC_PAST)
#define GUI_SLS LGUI_T(KC_SLSH)
#define SFT_PLS LSFT_T(KC_PPLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    SG_H,    KC_VOLU,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      CW_TOGG,   CTL_A,   ALT_S,   GUI_D,   SFT_F,    KC_G,    SG_M,    KC_VOLD,    KC_H,   SFT_J,   GUI_K,   ALT_L,  CTL_SC, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,   LCA_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          L2_BSPC,  L1_SPC,LCTL_TAB,   RCTL_ENT,  L1_SPC,  MO(2)
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      _______, KC_QUES, KC_AMPR,  KC_DLR, KC_PERC, KC_TILD, _______,    KC_BRIU, _______, KC_UNDS, KC_EXLM, KC_HASH,  KC_GRV, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      _______, CTL_CIR, ALT_LBR, GUI_LCB, SFT_LPR,  KC_EQL, _______,    KC_BRID, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS, _______,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE, KC_RBRC, KC_RCBR, KC_RPRN,   KC_AT,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      RM_NEXT, _______, _______, _______, _______, _______, _______,    KC_MNXT, _______,    KC_4,    KC_5,    KC_6, _______, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      RM_TOGG, CTL_MIN, ALT_AST, GUI_SLS, SFT_PLS,  KC_EQL, _______,    KC_MPRV,    KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT, DB_TOGG,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      RM_HUEU, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, KC_COMM, EE_CLR,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_BSPC, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};

// The basic keycode limitation with Mod-Tap can be worked around by intercepting it in process_record_user.
// (https://docs.qmk.fm/mod_tap#changing-tap-function)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_CIR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            break;
        case GUI_LCB:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;
        case SFT_LPR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
    }
    return true;
}

// Not using magic keycodes to swap keycodes or modifiers
// -> reduce firmware size (https://docs.qmk.fm/squeezing_avr#magic-functions)
#ifndef MAGIC_ENABLE
uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}
#endif

#ifndef MAGIC_ENABLE
uint8_t mod_config(uint8_t mod) {
    return mod;
}
#endif
