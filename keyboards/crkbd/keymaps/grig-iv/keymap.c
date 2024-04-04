#include QMK_KEYBOARD_H
#include <stdio.h>

enum custom_keycodes {
    CH_LANG = SAFE_RANGE
};

enum layers {
  _COLEMAK_DH,
  _SYM,
  _NUM,
  _NAV,
  _QMK,
  _MOUSE,
  _MEDIA,
};

// Thumb row mods
#define TMB_LL ALGR_T(KC_DEL)
#define TMB_LM LT(_SYM, KC_BSPC)
#define TMB_LR LT(0, KC_ESC)
#define TMB_RL LT(_NUM, KC_ENT)
#define TMB_RM LT(_NAV, KC_SPC)
#define TMB_RR ALGR_T(KC_TAB)

// User mod
#define MOD_USR TMB_LR

// Homerow mods
#define GUI_A LGUI_T(KC_A)
#define ALT_R LALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTRL_T LCTL_T(KC_T)
#define CTL_N RCTL_T(KC_N)
#define SFT_E RSFT_T(KC_E)
#define ALT_I LALT_T(KC_I)
#define GUI_O RGUI_T(KC_O)

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

// Mouse
#define L_MOUSE MO(_MOUSE)

// Qmk
#define L_QMK MO(_QMK)

// Media
#define L_MEDIA MO(_MEDIA)

// User mod space
#define RT_LT   XXXXXXX
#define PRV_LT  XXXXXXX
#define NXT_LT  XXXXXXX
#define PRV_WS  KC_LBRC
#define NXT_WS  KC_RBRC
#define FCS_MST KC_M
#define PRV_WND KC_COMM
#define NXT_WND KC_DOT
#define PRV_SCR KC_LEFT
#define NXT_SCR KC_RGHT
#define RST_LT  XXXXXXX
#define SRNK    XXXXXXX
#define EXPND   XXXXXXX

#define WS_WEB KC_1
#define WS_DEV KC_2
#define WS_SYS KC_3
#define WS_CHT KC_4
#define WS_MND KC_5


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,   KC_U,    KC_Y,  CH_LANG, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   GUI_A,   ALT_R,   SFT_S,  CTRL_T,    KC_G,                         KC_M,   CTL_N,   SFT_E,   ALT_I,   GUI_O, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TMB_LL, TMB_LM,  TMB_LR,     TMB_RL,  TMB_RM,  TMB_RR
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_GRV,  LCBRC,    RCBRC,   TILDE,     XOR,                      S(KC_3), S(KC_4), S(KC_5), S(KC_2),  XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DB_QUOT,  LPRNTH,  RPRNTH, KC_SCLN,     AND,                        LABRC, KC_MINS,    PLUS,  KC_EQL,   RABRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_QUOT, KC_LBRC, KC_RBRC,     CLN,      OR,                         ASTR,   UNDRL,   EXCLM,    QSTN, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX,   KC_UP, KC_DOWN, XXXXXXX,  KC_F11,                       KC_F12, XXXXXXX, KC_COMM,  KC_DOT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   L_QMK, _______, _______, _______, _______,                       KC_F18,  B_BACK,  B_PREV,  B_NEXT,  B_FWRD, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                       KC_F24, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, L_MEDIA, _______,                       KC_INS, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, L_MOUSE, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_QMK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, RGB_HUI, RGB_HUD, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,RGB_RMOD, RGB_SAI, RGB_SAD, RGB_MOD, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, XXXXXXX, RGB_VAI, RGB_VAD, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, KC_MNXT, KC_MNXT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MUTE, KC_MFFD, KC_VOLU, KC_VOLD, KC_MRWD, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                      KC_ACL2, KC_BTN4, KC_BTN3, XXXXXXX, KC_BTN5, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                      KC_ACL1, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ACL0, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};


void keyboard_post_init_user(void) {
    // Set Num Lock on at startup
    register_code(KC_NUM);
    unregister_code(KC_NUM);
}

static bool is_usr_mod_on = false;
static bool is_linux_sysetm = false;

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_WINDOWS:
            is_linux_sysetm = false;
            break;
        case OS_LINUX:
            is_linux_sysetm = true;
            break;
        default:
            break;
    }
    
    return true;
}

void activate_user_mod(void){
    if (is_linux_sysetm) {
        register_code(KC_LGUI);
    } else {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_LGUI);
    }
    is_usr_mod_on = true;
}

void deactivate_user_mod(void){
    if (is_linux_sysetm) {
        unregister_code(KC_LGUI);
    } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
    }
    is_usr_mod_on = false;
}

bool handle_as(uint16_t new_key, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code(new_key);
    } else {
        unregister_code(new_key);
    }

    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // user mode activation
    if (keycode == MOD_USR) {
        if (!is_usr_mod_on && !record->tap.count && record->event.pressed) {
            activate_user_mod();
            return false;
        } else if (is_usr_mod_on && !record->event.pressed) {
            deactivate_user_mod();
            return false;
        }
    }

    // user mode navigation
    if (is_usr_mod_on && layer_state_is(_NAV) && !is_linux_sysetm) {
        switch (keycode) {
            case B_PREV:
                return handle_as(PRV_WS, record);
            case B_NEXT:
                return handle_as(NXT_WS, record);
            case KC_UP:
                return handle_as(PRV_WND, record);
            case KC_DOWN:
                return handle_as(NXT_WND, record);
            case L_MEDIA:
                return handle_as(WS_DEV, record);
            case KC_S:
                return handle_as(WS_SYS, record);
            case KC_C:
                return handle_as(WS_CHT, record);
            case KC_B:
                return handle_as(WS_MND, record);
        }
    }

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

const uint16_t PROGMEM leader_key_combo[] = {TMB_LR, TMB_RL, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {TMB_LM, KC_V, COMBO_END};
const uint16_t PROGMEM delete_combo[] = {TMB_LM, KC_D, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {TMB_LM, CTRL_T, COMBO_END};
const uint16_t PROGMEM caps_words_combo[] = {SFT_S, SFT_E, COMBO_END};
const uint16_t PROGMEM altgr_combo[] = {TMB_LM, TMB_RM, COMBO_END};
combo_t key_combos[] = {
    COMBO(leader_key_combo, QK_LEAD),
    COMBO(paste_combo, LCTL(KC_V)),
    COMBO(delete_combo, KC_DEL),
    COMBO(tab_combo, KC_TAB),
    COMBO(caps_words_combo, CW_TOGG),
    COMBO(altgr_combo, OSM(MOD_RALT)),
};

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_S, KC_L)) { // [S]ystem [L]inux
        is_linux_sysetm = true;
    } else if (leader_sequence_two_keys(KC_S, KC_W)) { // [S]ystem [W]indows
        is_linux_sysetm = false;
    }
}
