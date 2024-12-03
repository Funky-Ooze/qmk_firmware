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


[0] = LAYOUT_ortho_4x12(
	KC_ESC,		DE_Q,		DE_W,		DE_E,		DE_R,		DE_T,		DE_Y,		CU_UE,		DE_I,		CU_OE,		DE_P,		KC_BSPC,
	KC_TAB,		CU_AE,		DE_S,		CU_D_SS,	DE_F,		DE_G,		DE_H,		DE_J,		DE_K,		DE_L,		CU_SCLN,	ENT_SFT,
	KC_LSFT,	DE_Z,		DE_X,		DE_C,		DE_V,		DE_B,		DE_N,		M_BETA,		CU_COMM,	CU_DOT,		KC_UP,		CU_QUOT,
	KC_LCTL,	ALPHA,		KC_LGUI,	KC_LALT,	LOWER,		KC_SPC,		KC_SPC,		RAISE,		CU_SLSH,	KC_LEFT,	KC_DOWN,	KC_RGHT
),


[1] = LAYOUT_ortho_4x12(
	KC_DEL,		DE_EXLM,	DE_AT,		DE_HASH,	DE_DLR,		DE_PERC,	DE_CIRC,	DE_AMPR,	DE_ASTR,	DE_LPRN,	DE_RPRN,	KC_BSPC,
	DE_TILD,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		DE_UNDS,	DE_PLUS,	DE_LBRC,	DE_RBRC,	_______,
	_______,	KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		_______,	KC_HOME,	KC_END,		XXXXXXX,	DE_PIPE,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MNXT,	KC_VOLU,	KC_VOLD,	KC_MPLY
),


[2] = LAYOUT_ortho_4x12(
	KC_DEL,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,
	DE_DOT,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		DE_MINS,	CU_EQL,		DE_LCBR,	DE_RCBR,	_______,
	_______,	KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		_______,	KC_PGUP,	KC_PGDN,	XXXXXXX,	DE_BSLS,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MNXT,	KC_VOLU,	KC_VOLD,	KC_MPLY
),


[3] = LAYOUT_ortho_4x12(
	RESET,		_______,	DEBUG,		RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_HUD,	RGB_SAI,	RGB_SAD,	RGB_VAI,	RGB_VAD,	KC_DEL,
	_______,	_______,	_______,	_______,	_______,	AG_NORM,	AG_SWAP,	QWERTY,		_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
),


[4] = LAYOUT_ortho_4x12(
	EXIT,		PASSW,		PWHOME,		EVA,		REPLY,		TOPAS,		_______,	PROEM,		EMTSK,		OUTLOOK,	_______,	_______,
	_______,	LOGIN,		_______,	_______,	FIREFOX,	_______,	_______,	_______,	TASK,		_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	EMAIL,		TO_START,	TO_END,		_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______

),

[5] = LAYOUT_ortho_4x12(
	_______,	KC_1,		KC_2,		KC_3,		DE_PLUS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	DE_DEG,		KC_4,		KC_5,		KC_6,		DE_MINS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_7,		KC_8,		KC_9,		DE_ASTR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_0,		KC_DOT,	 	DE_EQL,		DE_SLSH,	_______,	_______,	_______,	_______,	_______,	_______,	_______

)

};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	
}

