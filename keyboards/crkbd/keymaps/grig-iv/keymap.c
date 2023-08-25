#include QMK_KEYBOARD_H
#include <stdio.h>

enum layers {
  _COLEMAK_DH,
  _QWERTY,
  _SYM,
  _NUM,
  _NAV,
  _WEB,
  _QMK,
  _MOUSE,
  _MEDIA,
  _TMUX,
};

// Thumb row mods
#define TMB_LL LT(0, KC_DEL)
#define TMB_LM LT(_SYM, KC_BSPC)
#define TMB_LR LCTL_T(KC_ESC)
#define TMB_RL LT(_NUM, KC_ENT)
#define TMB_RM LT(_NAV, KC_SPC)
#define TMB_RR ALGR_T(KC_TAB)

#define MOD_USR TMB_LL

#define DF_QWRT DF(_QWERTY)
#define DF_CLMK DF(_COLEMAK_DH)

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
#define B_PREV C(S(KC_TAB))
#define B_NEXT C(KC_TAB)
#define B_FWRD KC_WFWD
#define B_BACK KC_WBAK
#define B_SRCH KC_WSCH

// Mouse
#define L_MOUSE MO(_MOUSE)

// Tmux
#define L_TMUX MO(_TMUX)
#define TMUX_PREFIX C(KC_B)
#define N_WIND KC_N
#define P_WIND KC_P

// Web
#define L_WEB MO(_WEB)

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

// Language Change
#define CH_LN LALT(KC_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   CH_LN, KC_RWIN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TMB_LL, TMB_LM,  TMB_LR,     TMB_RL,  TMB_RM,  TMB_RR
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_LWIN,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_RWIN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RALT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            TMB_LL, TMB_LM,  TMB_LR,     TMB_RL,  TMB_RM,  TMB_RR
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_QUOT,  LCBRC,    RCBRC,   TILDE,     XOR,                      S(KC_3), S(KC_4), S(KC_5), S(KC_2), KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, DB_QUOT,  LPRNTH,  RPRNTH, KC_SCLN,     AND,                        LABRC, KC_MINS,    PLUS,  KC_EQL,   RABRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_GRV, KC_LBRC, KC_RBRC,     CLN,      OR,                         ASTR,   UNDRL,   EXCLM,    QSTN, KC_SLSH, _______,
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
      _______,   L_QMK,   L_WEB, _______, _______, _______,                       KC_F13,  KC_F14,  B_PREV,  B_NEXT,  KC_F17, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______,  L_TMUX, _______,                       KC_F18, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, L_MEDIA, _______,                       KC_INS, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, L_MOUSE, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_WEB] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX,                       B_SRCH,  B_BACK,  B_PREV,  B_NEXT,  B_FWRD, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
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

  [_TMUX] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_L, XXXXXXX,  P_WIND,  N_WIND, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,                      KC_SCLN, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,  LPRNTH,  RPRNTH, XXXXXXX, _______,
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

void activate_user_mod(void){
    if (is_linux_sysetm) {
        register_code(KC_LGUI);
    } else {
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
    if (keycode == MOD_USR) {
        if (!is_usr_mod_on && !record->tap.count && record->event.pressed) {
            activate_user_mod();
            return false;
        } else if (is_usr_mod_on && !record->event.pressed) {
            deactivate_user_mod();
            return false;
        }
    }

    if (is_usr_mod_on && layer_state_is(_NAV)) {
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
            case L_WEB:
                return handle_as(WS_WEB, record);
            case KC_S:
                return handle_as(WS_SYS, record);
            case KC_C:
                return handle_as(WS_CHT, record);
            case KC_B:
                return handle_as(WS_MND, record);
        }
    }

    if (layer_state_is(_TMUX) && record->event.pressed) {
        tap_code16(TMUX_PREFIX);
    }

    return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true;
    }
}


const uint16_t PROGMEM leader_key_combo[] = {TMB_LR, TMB_RL, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(leader_key_combo, QK_LEAD),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // [L]ayout [Q]werty
        SEQ_TWO_KEYS(KC_L, KC_Q) {
            default_layer_set(1U << _QWERTY);
        }

        // [L]ayout [C]olemak
        SEQ_TWO_KEYS(KC_L, KC_C) {
            default_layer_set(1U << _COLEMAK_DH);
        }

        // [S]ystem [L]inux
        SEQ_TWO_KEYS(KC_S, KC_L) {
            is_linux_sysetm = true;
        }

        // [S]ystem [W]indows
        SEQ_TWO_KEYS(KC_S, KC_W) {
            is_linux_sysetm = false;
        }
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case _NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case _NUM:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x80, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE
