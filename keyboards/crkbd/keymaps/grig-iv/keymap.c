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
#define TMB_LL ALGR_T(KC_DEL)
#define TMB_LM LT(SYM, KC_BSPC)
#define TMB_LR LT(FUN, KC_ESC)
#define TMB_RL LT(NUM, KC_ENT)
#define TMB_RM LT(NAV, KC_SPC)
#define TMB_RR ALGR_T(KC_TAB)

// Homerow mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)
#define GUI_1 LGUI_T(KC_1)
#define ALT_2 LALT_T(KC_2)
#define SFT_3 LSFT_T(KC_3)
#define CTL_4 LCTL_T(KC_4)

// Symbols
#define LCBRC S(KC_LBRC)
#define RCBRC S(KC_RBRC)
#define LPRNTH S(KC_9)
#define RPRNTH S(KC_0)
#define LABRC S(KC_COMM)
#define RABRC S(KC_DOT)
#define DB_QUOT S(KC_QUOT)
#define CLN S(KC_SCLN)
#define TILDE S(KC_GRV)
#define XOR S(KC_6)
#define AND S(KC_7)
#define OR S(KC_BSLS)
#define EXCLM S(KC_1)
#define QSTN S(KC_SLSH)
#define UNDRL S(KC_MINS)
#define PLUS S(KC_EQL)
#define ASTR S(KC_8)

// Nav
#define B_PREV C(KC_PGUP)
#define B_NEXT C(KC_PGDN)
#define B_BACK KC_F19
#define B_FWRD KC_F22

// User mod space
#define PRV_WS  KC_LBRC
#define NXT_WS  KC_RBRC
#define FCS_MST KC_M
#define PRV_WND KC_COMM
#define NXT_WND KC_DOT
#define PRV_SCR KC_LEFT
#define NXT_SCR KC_RGHT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,   KC_U,    KC_Y,  CH_LANG, _______,
      _______,   GUI_A,   ALT_R,   SFT_S,  CTRL_T,    KC_G,             KC_M,   CTL_N,   SFT_E,   ALT_I,   GUI_O, _______,
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,             KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______,  TMB_LM,  TMB_LR,           TMB_RL,  TMB_RM,  _______
   ),                        //`--------------------------'        `--------------------------'

  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, KC_GRV,  LCBRC,    RCBRC,    TILDE,     XOR,          S(KC_3), S(KC_4), S(KC_5), S(KC_2), XXXXXXX, _______,
      _______, DB_QUOT,  LPRNTH,  RPRNTH, KC_SCLN,     AND,            LABRC, KC_MINS,    PLUS,  KC_EQL,   RABRC, _______,
      _______, KC_QUOT, KC_LBRC, KC_RBRC,     CLN,      OR,             ASTR,   UNDRL,   EXCLM,    QSTN, KC_BSLS, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, KC_MNXT, KC_MNXT, XXXXXXX, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX,  KC_TAB, XXXXXXX,          KC_MUTE, KC_MFFD, KC_VOLU, KC_VOLD, KC_MRWD, _______,
      _______, XXXXXXX, C(KC_X), C(KC_C),  KC_DEL, C(KC_V),          RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F11,           KC_F12, XXXXXXX, KC_COMM,  KC_DOT, XXXXXXX, _______,
                                 _______, _______, _______,          _______, _______, _______
   ),                        //`--------------------------'        `--------------------------'

  [NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.        ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,           KC_F18,  B_BACK,  B_PREV,  B_NEXT,  B_FWRD, _______,
      _______,   GUI_1,   ALT_2,   SFT_3,   CTL_4,    KC_5,           KC_F24, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
      _______, _______, _______, _______, _______, _______,           KC_INS, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
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
        case OS_WINDOWS:
            is_linux_system = false;
            break;
        case OS_LINUX:
            is_linux_system = true;
            break;
        default:
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
                wait_ms(30);
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                wait_ms(30);
                unregister_code(KC_LALT);
            }
            return false;
    }

    return true;
}


// COMBOS
const uint16_t PROGMEM paste_combo[] = {TMB_LM, KC_V, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {TMB_LM, KC_D, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {TMB_LM, CTRL_T, COMBO_END};
const uint16_t PROGMEM caps_words_combo[] = {SFT_S, SFT_E, COMBO_END};
const uint16_t PROGMEM altgr_combo[] = {TMB_LM, TMB_RM, COMBO_END};
const uint16_t PROGMEM ch_lang_combo[] = {TMB_LR, TMB_RL, COMBO_END};
combo_t key_combos[] = {
    COMBO(paste_combo, LCTL(KC_V)),
    COMBO(delete_combo, KC_DEL),
    COMBO(tab_combo, KC_TAB),
    COMBO(caps_words_combo, CW_TOGG),
    COMBO(altgr_combo, OSM(MOD_RALT)),
    COMBO(ch_lang_combo, CH_LANG),
};


// PER KEY SETTINGS
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMB_LL:
        case TMB_LM:
        case TMB_RL:
        case TMB_RR:
            return true;
        default:
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TMB_RM:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_O:
        case GUI_A:
            return TAPPING_TERM + 50;
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
