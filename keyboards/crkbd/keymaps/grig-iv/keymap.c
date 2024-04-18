#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
  BASE,
  SYM,
  FUN,
  NUM,
  NAV,
};

enum custom_keycodes {
    CH_LANG = SAFE_RANGE
};


// Thumb row mods
#define TMB_LL LT(FUN, KC_DEL)
#define TMB_LM KC_SPC
#define TMB_LR LT(NUM, KC_BSPC)
#define TMB_RL LT(SYM, KC_ENT)
#define TMB_RM LT(NAV, KC_ESC)
#define TMB_RR ALGR_T(KC_TAB)

// Base
#define GUI_W LGUI_T(KC_W)
#define ALT_Z LALT_T(KC_Z)
#define SFT_F LSFT_T(KC_F)
#define CTRL_D LCTL_T(KC_D)
#define CTRL_H RCTL_T(KC_H)
#define SFT_U RSFT_T(KC_U)
#define ALT_SLSH LALT_T(KC_SLSH)
#define GUI_Y RGUI_T(KC_Y)

// Nav
#define B_PREV C(KC_PGUP)
#define B_NEXT C(KC_PGDN)
#define B_BACK KC_F19
#define B_FWRD KC_F22

#define NAV_1 LGUI_T(G(KC_1))
#define NAV_2 LALT_T(G(KC_2))
#define NAV_3 LSFT_T(G(KC_3))
#define NAV_4 LCTL_T(G(KC_4))
#define NAV_5 G(KC_5)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,    KC_Q,   GUI_W,   SFT_F,    KC_P,    KC_B,             KC_J,    KC_L,   SFT_U,   GUI_Y, _______, _______,
      _______,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O, _______,
      _______,   ALT_Z,    KC_X,    KC_C,  CTRL_D,    KC_V,             KC_K,  CTRL_H, KC_COMM,  KC_DOT,ALT_SLSH, _______,
                                  TMB_LL,  TMB_LM,  TMB_LR,           TMB_RL,  TMB_RM,  TMB_RR
   ),                        //`--------------------------'        `--------------------------'

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,  KC_GRV, KC_LCBR, KC_RCBR, KC_TILD, KC_CIRC,          KC_HASH, KC_DLR,  KC_PERC,   KC_AT, _______, _______,
      _______, KC_DQUO, KC_LPRN, KC_RPRN, KC_SCLN, KC_AMPR,            KC_LT, KC_MINS, KC_PLUS,  KC_EQL,   KC_GT, _______,
      _______, KC_QUOT, KC_LBRC, KC_RBRC, KC_COLN, KC_PIPE,          KC_ASTR, KC_UNDS, KC_EXLM, KC_QUES, KC_BSLS, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, _______,    KC_7,    KC_8,    KC_9,  KC_ESC,          XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______,
      _______,    KC_0,    KC_4,    KC_5,    KC_6,  KC_ENT,            KC_LT, KC_MINS, KC_PLUS,   KC_EQL,   KC_GT, _______,
      _______, _______,    KC_1,    KC_2,    KC_3, C(KC_V),          KC_ASTR, KC_UNDS, KC_COMM,   KC_DOT, KC_BSLS, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______, XXXXXXX, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX,          KC_MUTE, KC_PSCR, XXXXXXX,  KC_INS, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, CW_TOGG, XXXXXXX,  KC_F11,           KC_F12, XXXXXXX, KC_VOLU, KC_VOLD, XXXXXXX, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,          XXXXXXX, KC_BTN4,  B_PREV,  B_NEXT, KC_BTN5, _______,
      _______, _______, _______, _______, _______, _______,          XXXXXXX, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,          XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'
};


// OS DETECTION
static bool is_linux_system = false;
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_LINUX:
            is_linux_system = true;
            break;
        default:
            is_linux_system = false;
            break;
    }

    return true;
}


// CUSTOM LOGIC
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // language change
    switch (keycode) {
        case CH_LANG:
            if (record->event.pressed) {
                register_code(KC_LALT);
                wait_ms(25);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                wait_ms(25);
                unregister_code(KC_LALT);
            }
            return false;
    }

    return true;
}


// COMBOS
const uint16_t PROGMEM ch_lang_combo[] = {TMB_LM, TMB_RM, COMBO_END};
combo_t key_combos[] = {
    COMBO(ch_lang_combo, CH_LANG),
};


// PER KEY SETTINGS
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMB_LL:
        // case TMB_LM:
        case TMB_LR:
        case TMB_RL:
        case TMB_RM:
        case TMB_RR:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case TMB_LL:
        case TMB_LM:
        // case TMB_LR:
        // case TMB_RL:
        // case TMB_RM:
        // case TMB_RR:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_W:
        case GUI_Y:
            return TAPPING_TERM + 50;
        case SFT_F:
        case SFT_U:
            return TAPPING_TERM + 30;
        default:
            return TAPPING_TERM;
    }
}


// INIT
void keyboard_post_init_user(void) {
    // Set Num Lock on at startup
    register_code(KC_NUM);
    unregister_code(KC_NUM);
}
