
#include QMK_KEYBOARD_H
#include "funky_ooze.h"


enum layers {
	_QWERTY = 0,
	_LOWER	= 1,	
	_RAISE	= 2,
	_ADJUST = 3,
	_ALPHA	= 4,
	_BETA	= 5
	
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all(
                                                                                                       KC_MPLY,
    KC_GESC, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Y,    CU_UE,   DE_I,    CU_OE,   DE_P,    KC_BSPC,
    KC_TAB,  CU_AE,   DE_S,    CU_D_SS, DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,             KC_ENT,
    KC_LSFT,          DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    CU_COMM, CU_DOT,  KC_LSFT,
    KC_LCTL, KC_LGUI, KC_LALT, ALPHA,           ENT_LO,                     SPC_RA,  BETA,    CU_SLSH, CU_QUOT
),
[1] = LAYOUT_all(
                                                                                                       _______,
    EXIT,    DE_EXLM, DE_AT,   DE_HASH,	DE_DLR,  DE_PERC, DE_CIRC, DE_AMPR,	DE_ASTR, DE_LPRN, DE_RPRN, CU_SCLN,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   DE_UNDS, DE_PLUS, DE_LBRC,          DE_RBRC,
    _______,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, KC_MPRV, KC_MNXT, _______
),
[2] = LAYOUT_all(
                                                                                                       _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    CU_DOT,  KC_F1,	  KC_F2,   KC_F3,   KC_F4,	 KC_F5,   KC_F6,   DE_MINS, CU_EQL,  DE_LCBR,          DE_RCBR,
    _______,          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PGUP, KC_PGDN,
    _______, _______, _______, _______,          _______,                   _______, DE_DEG, DE_BSLS, _______
),
[3] = LAYOUT_all(                                                             
																									    _______,
    RESET,   _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,  RESET,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,         _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______, _______, EEP_RST
),

 [4] = LAYOUT_all(                                                                                     _______,
    KC_DEL,   KC_UP,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______,          CU_SCLN,
    _______,          _______, _______, _______, _______, _______, _______, KC_HOME, KC_END,  KC_UP, _______,
    _______, _______, ALT_SFT, _______,          _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT
),

 [5] = LAYOUT_all(                                                                                     _______,
    KC_NLCK, PASSW,   PWHOME,  _______, _______, _______, _______, PROEM,   EMTSK,   _______, _______, _______,
    _______, LOGIN,   _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
)

};
// clang-format on

/*layer switcher */
layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	
}

/* rotary encoder (MX12) - add different functions for layers here */
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_ADJUST)) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    } else if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
           tap_code(KC_WH_D);
       } else {
           tap_code(KC_WH_U);
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif

/* oled stuff :) */
#ifdef OLED_ENABLE
uint16_t startup_timer = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    startup_timer = timer_read();
    return rotation;
}
static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  8,  0,192,194,192,192, 60, 60, 44, 60,188, 60, 60, 60, 60, 44, 61, 60,192,192,192,208,  1,  0,252,252,180,252, 60, 60, 44, 60,252,253,252,252, 60, 60, 44, 60,244,220,252,252,  0,  0, 16,  0,  0,  0,192,192, 65,192, 60, 60, 52, 60,192,193,192,192, 16,  0,  0,144,  4,  0,252,125,244, 60, 60, 60, 60, 61,252,252,244,252, 60, 60, 60, 61,248,108,252,  0,  0, 61, 60,188, 60, 52,252,252,220,252, 61, 60, 60, 52,  0,  0,192,210, 64,192, 60, 60, 44, 61, 60, 60, 60, 61, 52, 60, 60, 60,192,192, 64,196,  0,  4,  0,
        0, 16,  0, 61, 63, 55, 63,192, 64,192,196,192,192,192,200,192,196,192,192,  3,  3,  2, 11,  0,  0, 35,  3,  3,  3,  0, 64,  2,  0,255,255,253,247,  0,  0,  0, 32,  1,  0,  1, 65,  8,  0,189,244,252,236,  3,130,  3,  1,  0, 68,  0,  0,  3, 34,131,  3,252,252,236,252,  0, 32, 17,  1,  1,  0,  0, 32,  0,  2,255,255,127,247,  0,  1,  0,  8,  1,  1,  1,  0,  0,  0, 16,  0, 64,  0,255,191,255,251,  0,129,  0,  2, 32,  0,255,255,239,255,  0,  0,  2,  0,  0,  0,  8, 64,  0,  1,  0,  0,  3, 35,  3,  3,  0,  8,  0,
        1, 16,  0,192, 64,194,192,  3, 67,  3,  3,  9,  3,  3,  3,  3,  2, 83,  3,252,252,188,244,  0,  2, 32,  0,  0,  2,  0,144,  0,  0,255,255,237,255,  0, 16,  0,  0,  0, 64,  2,  0,128,  0,255,123,255,255, 60, 52, 60, 60, 60, 60, 60, 60, 44, 60, 56, 60,239,255,126,255,  0,  2, 32,  0,  0, 34,  0,  0, 16,  0,255,255,255,223,  0,  0,  4,  0,  0,  0, 33,  0,  0, 17,  0,  0,  0,  0,255,255,239,255,  0,128,  0,  0, 72,  0,255,253,247,255,  0,  0,  1,  0,144,  0,  4,  0, 32,  0,  0,  2,192,192,192,200,  0, 16,  0,
        64,  4,  0,  3,  7,  3,  3, 60, 60, 52,188, 60, 61, 60, 60, 60, 60, 44, 60, 67,  3,  3,  3,  0,  0, 64,  0,  0,  4,  0,  0, 16,  0, 47, 63, 62, 63,  0,  0,132,  0,  0,  0,  0,128,  8,  0,255,255,111,127,  0,  0,  0,  2,128,  0,  0,  0, 64,  4,  0,128,127,127,107,127,  0, 32,  0,  0,  0, 66,  0,  0,  0,136, 55, 63, 61, 63,  0,  0,  0,  2,  0, 64,  0,136,  0,  0, 60, 44,189, 60, 63, 63, 63, 59, 60, 60,172, 60,  0, 64,  3,  2,  3,131, 60, 44, 60, 60, 60, 60,188, 60, 56, 44, 60, 60,  3,  3,131,  2,  0, 32,  2,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
/* Shows the name of the current layer and locks for the host (CAPS etc.) */
static void render_layer(void) {
    led_t led_state = host_keyboard_led_state();
    // clang-format off
    static const char PROGMEM logo[][3][7] = {
        {{0x97, 0x98, 0x99, 0x9A, 0}, {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0}, {0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0}}, /* l      num      CB */
        {{0xB7, 0xB8, 0xB9, 0xBA, 0}, {0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0}, {0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0}}, /* 1      num      CB */
        {{0xD7, 0xD8, 0xD9, 0xDA, 0}, {0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0}, {0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0}}, /* 1      cap      CB */
        {{0xF7, 0xF8, 0xF9, 0xFA, 0}, {0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0}, {0xFB, 0xFC, 0xFD, 0xFE, 0xFF, 0}}, /* l      cap      CB */
        {{0xB7, 0xC0, 0xC1, 0xBA, 0}, {0xB7, 0xC2, 0xC3, 0xBA, 0},             {0xB7, 0xC4, 0xC5, 0xBA, 0}},       /* 2       3       4  */
        {{0xD7, 0xE0, 0xE1, 0xDA, 0}, {0xD7, 0xE2, 0xE3, 0xDA, 0},             {0xD7, 0xE4, 0xE5, 0xDA, 0}},       /* 2       3       4  */
    };
    // clang-format on
    oled_set_cursor(0, 0);
    oled_write_P(logo[0][0], false);
    oled_set_cursor(0, 3);
    oled_write_P(logo[3][0], false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_set_cursor(0, 1);
            oled_write_P(logo[1][0], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[2][0], false);
            break;
        case _LOWER:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][0], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][0], false);
            break;
        case _RAISE:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][1], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][1], false);
            break;
        case _ADJUST:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][2], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][2], false);
            break;
        case _ALPHA:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][2], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][2], false);
            break;
        case _BETA:
            oled_set_cursor(0, 1);
            oled_write_P(logo[4][2], false);
            oled_set_cursor(0, 2);
            oled_write_P(logo[5][2], false);
            break;
        default:
            oled_set_cursor(0, 1);
            oled_write_P(PSTR("    "), false);
            oled_set_cursor(0, 2);
            oled_write_P(PSTR("    "), false);
    }
    oled_set_cursor(8, 0);
    oled_write_P(led_state.num_lock ? logo[0][1] : PSTR("      "), false);
    oled_set_cursor(8, 1);
    oled_write_P(led_state.num_lock ? logo[1][1] : PSTR("      "), false);
    oled_set_cursor(8, 2);
    oled_write_P(led_state.caps_lock ? logo[2][1] : PSTR("      "), false);
    oled_set_cursor(8, 3);
    oled_write_P(led_state.caps_lock ? logo[3][1] : PSTR("      "), false);

    oled_set_cursor(16, 0);
    oled_write_P(logo[0][2], false);
    oled_set_cursor(16, 1);
    oled_write_P(logo[1][2], false);
    oled_set_cursor(16, 2);
    oled_write_P(logo[2][2], false);
    oled_set_cursor(16, 3);
    oled_write_P(logo[3][2], false);
}

bool oled_task_user(void) {
    static bool finished_timer = false;
    if (!finished_timer && (timer_elapsed(startup_timer) < 3000)) {
        render_logo();
    } else {
        if (!finished_timer) {
            oled_clear();
            finished_timer = true;
        }
        render_layer();
    }
    return false;
}
#endif
