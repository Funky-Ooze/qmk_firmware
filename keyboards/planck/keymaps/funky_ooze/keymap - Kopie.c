#include QMK_KEYBOARD_H
#include "keymap_german.h"

extern keymap_config_t keymap_config;

enum layers {
	_QWERTY = 0,
	_RAISE = 1,
	_LOWER = 2,
	_ADJUST = 3,
	_FUNCTION = 4,
	_LALA = 5
	
};

enum planck_keycodes {
	QWERTY = SAFE_RANGE,
	FUNC

};


enum custom_keycodes {
	// These use process_record_user
	CU_SLSH = SAFE_RANGE,
	CU_SCLN,
	CU_COMM,
	CU_DOT,
	CU_QUOT,
	CU_LBRC,
	CU_RBRC,
	CU_BSLS,
	CU_EQL,
	CU_2,
	CU_3,
	CU_6,
	CU_7,
	CU_8,
	CU_9,
	CU_0,
	PASSW,
	OUTLOOK,
	FIREFOX,
	SPOTIFY,
	EVA,
	TOPAS,
	NOTEPAD

};


#define LOWER		MO(_LOWER)
#define RAISE		MO(_RAISE)
#define FUNC		MO(_FUNCTION)
#define M_LALA		LT(5, KC_M)


#define LOGIN		LCTL(LALT(KC_DEL))

#define EMAIL		LCTL(LSFT(KC_M))
#define REPLY		LCTL(LSFT(KC_R))
#define TASK		LCTL(LSFT(KC_K))
#define PROEM		LCTL(LSFT(KC_7))
#define EMTSK		LCTL(LSFT(KC_8))

#define EXIT		LALT(KC_F4)

#define CU_OE		LT(0,DE_O)
#define CU_AE		LT(0,DE_A)
#define CU_UE		LT(0,DE_U)
#define CU_D_SS		LT(0,DE_D)
#define TAB_ESC		LT(0,KC_TAB)
#define ENT_SFT		MT(MOD_LSFT,KC_ENT)
#define TO_START 	LCTL(KC_HOME)
#define TO_END		LCTL(KC_END)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_ortho_4x12(
	KC_ESC,		DE_Q,		DE_W,		DE_E,		DE_R,		DE_T,		DE_Y,		CU_UE,		DE_I,		CU_OE,		DE_P,		KC_BSPC,
	KC_TAB,		CU_AE,		DE_S,		CU_D_SS,	DE_F,		DE_G,		DE_H,		DE_J,		DE_K,		DE_L,		CU_SCLN,	ENT_SFT,
	KC_LSFT,	DE_Z,		DE_X,		DE_C,		DE_V,		DE_B,		DE_N,		M_LALA,		CU_COMM,	CU_DOT,		KC_UP,		CU_QUOT,
	KC_LCTL,	FUNC,		KC_LGUI,	KC_LALT,	LOWER,		KC_SPC,		KC_SPC,		RAISE,		CU_SLSH,	KC_LEFT,	KC_DOWN,	KC_RGHT
),


[_LOWER] = LAYOUT_ortho_4x12(
	KC_DEL,		DE_EXLM,	DE_AT,		DE_HASH,	DE_DLR,		DE_PERC,	DE_CIRC,	DE_AMPR,	DE_ASTR,	DE_LPRN,	DE_RPRN,	KC_BSPC,
	DE_TILD,	KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		DE_UNDS,	DE_PLUS,	DE_LBRC,	DE_RBRC,	_______,
	_______,	KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		_______,	KC_HOME,	KC_END,		XXXXXXX,	DE_PIPE,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MNXT,	KC_VOLU,	KC_VOLD,	KC_MPLY
),


[_RAISE] = LAYOUT_ortho_4x12(
	KC_DEL,		KC_1,		KC_2,		KC_3,		KC_4,		KC_5,		KC_6,		KC_7,		KC_8,		KC_9,		KC_0,		KC_BSPC,
	DE_DOT,		KC_F1,		KC_F2,		KC_F3,		KC_F4,		KC_F5,		KC_F6,		DE_MINS,	CU_EQL,		DE_LCBR,	DE_RCBR,	_______,
	_______,	KC_F7,		KC_F8,		KC_F9,		KC_F10,		KC_F11,		KC_F12,		_______,	KC_PGUP,	KC_PGDN,	XXXXXXX,	DE_BSLS,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	KC_MNXT,	KC_VOLU,	KC_VOLD,	KC_MPLY
),


[_ADJUST] = LAYOUT_ortho_4x12(
	RESET,		_______,	DEBUG,		RGB_TOG,	RGB_MOD,	RGB_HUI,	RGB_HUD,	RGB_SAI,	RGB_SAD,	RGB_VAI,	RGB_VAD,	KC_DEL,
	_______,	_______,	_______,	_______,	_______,	AG_NORM,	AG_SWAP,	QWERTY,		_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______
),


[_FUNCTION] = LAYOUT_ortho_4x12(
	EXIT,		PASSW,		_______,	EVA,		REPLY,		TOPAS,		_______,	PROEM,		EMTSK,		OUTLOOK,	_______,	_______,
	_______,	LOGIN,		SPOTIFY,	_______,	FIREFOX,	_______,	_______,	_______,	TASK,		_______,	_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	EMAIL,		TO_START,	TO_END,		_______,	_______,
	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______,	_______

),

[_LALA] = LAYOUT_ortho_4x12(
	_______,	KC_1,		KC_2,		KC_3,		DE_PLUS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	DE_DEG,		KC_4,		KC_5,		KC_6,		DE_MINS,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_7,		KC_8,		KC_9,		DE_ASTR,	_______,	_______,	_______,	_______,	_______,	_______,	_______,
	_______,	KC_0,		KC_DOT,	 	DE_EQL,		DE_SLSH,	_______,	_______,	_______,	_______,	_______,	_______,	_______

)

};

layer_state_t layer_state_set_user(layer_state_t state) {
	return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
	
}

static bool shift_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch(keycode) {
		case KC_LSFT:
			shift_held = record->event.pressed;
			return true;
			break;
		case KC_RSFT:
			shift_held = record->event.pressed;
			return true;
			break;
					
		case CU_SLSH: {
			if (record->event.pressed) {
					register_code(KC_LSFT); 
				if (shift_held) {
					unregister_code(DE_SS);
					register_code(DE_SS);
				} else {
					unregister_code(DE_7);
					register_code(DE_7);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_SS);
				unregister_code(DE_7);
			}
			return false;
			break;
		}
		case CU_SCLN: {
			if (record->event.pressed) {
					register_code(KC_LSFT); 
				if (shift_held) {
					unregister_code(DE_DOT);
					register_code(DE_DOT);
				} else {
					unregister_code(DE_COMM);
					register_code(DE_COMM);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_DOT);
				unregister_code(DE_COMM);
			}
			return false;
			break;
		}
		case CU_COMM: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_LABK);
					register_code(DE_LABK);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_COMM);
					register_code(DE_COMM);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_LABK);
				unregister_code(DE_COMM);
			}
			return false;
			break;
		}
		case CU_DOT: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT);
					unregister_code(DE_LABK);
					register_code(DE_LABK);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_DOT);
					register_code(DE_DOT);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_LABK);
				unregister_code(DE_DOT);
			}
			return false;
			break;
		}
		case CU_QUOT: {
			if (record->event.pressed) {
					register_code(KC_LSFT); 
				if (shift_held) {
					unregister_code(DE_HASH);
					register_code(DE_2);
				} else {
					unregister_code(DE_2);
					register_code(DE_HASH);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_2);
				unregister_code(DE_HASH);
			}
			return false;
			break;
		}
		case CU_LBRC: {
			if (record->event.pressed) {
					unregister_code(KC_RSFT);
					unregister_code(KC_LSFT);
					register_code(KC_ALGR);
				if (shift_held) {
					unregister_code(DE_7);
					register_code(DE_7);
				} else {
					unregister_code(DE_8);
					register_code(DE_8);
				}
			} else { // Release the key
				unregister_code(KC_ALGR);
				unregister_code(DE_7);
				unregister_code(DE_8);
			}
			return false;
			break;
		}
		case CU_RBRC: {
			if (record->event.pressed) {
					unregister_code(KC_RSFT);
					unregister_code(KC_LSFT);
					register_code(KC_ALGR);
				if (shift_held) {
					unregister_code(DE_0);
					register_code(DE_0);
				} else {
					unregister_code(DE_9);
					register_code(DE_9);
				}
			} else { // Release the key
				unregister_code(KC_ALGR);
				unregister_code(DE_0);
				unregister_code(DE_9);
			}
			return false;
			break;
		}
		case CU_BSLS: {
			if (record->event.pressed) {
					unregister_code(KC_RSFT);
					unregister_code(KC_LSFT);
					register_code(KC_ALGR);
				if (shift_held) {
					unregister_code(DE_LABK);
					register_code(DE_LABK);
				} else {
					unregister_code(DE_SS);
					register_code(DE_SS);
				}
			} else { // Release the key
				unregister_code(KC_ALGR);
				unregister_code(DE_LABK);
				unregister_code(DE_SS);
			}
			return false;
			break;
		}
		case CU_EQL: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_PLUS);
					register_code(DE_PLUS);
				} else {
					register_code(KC_LSFT);
					unregister_code(DE_0);
					register_code(DE_0);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_PLUS);
				unregister_code(DE_0);
			}
			return false;
			break;
		}
		case CU_2: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_RSFT);
					unregister_code(KC_LSFT);
					register_code(KC_ALGR);
					unregister_code(DE_Q);
					register_code(DE_Q);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_2);
					register_code(DE_2);
				}
			} else { // Release the key
				unregister_code(KC_ALGR);
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_Q);
				unregister_code(DE_2);
			}
			return false;
			break;
		}			
		case CU_3: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_HASH);
					register_code(DE_HASH);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_3);
					register_code(DE_3);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_HASH);
				unregister_code(DE_3);
			}
			return false;
			break;
		}
		case CU_4: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_DLR);
					register_code(DE_DLR;
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_3);
					register_code(DE_3);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_HASH);
				unregister_code(DE_3);
			}
			return false;
			break;
		}
		case CU_6: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_CIRC);
					register_code(DE_CIRC);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_6);
					register_code(DE_6);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_CIRC);
				unregister_code(DE_6);
			}
			return false;
			break;
		}
		case CU_7: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT); 
					unregister_code(DE_6);
					register_code(DE_6);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_7);
					register_code(DE_7);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_6);
				unregister_code(DE_7);
			}
			return false;
			break;
		}
		case CU_8: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT); 
					unregister_code(DE_PLUS);
					register_code(DE_PLUS);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_8);
					register_code(DE_8);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_PLUS);
				unregister_code(DE_8);
			}
			return false;
			break;
		}
		case CU_9: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT); 
					unregister_code(DE_8);
					register_code(DE_8);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_9);
					register_code(DE_9);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_8);
				unregister_code(DE_9);
			}
			return false;
			break;
		}
		case CU_0: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT); 
					unregister_code(DE_9);
					register_code(DE_9);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(DE_0);
					register_code(DE_0);
				}
			} else { // Release the key
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_9);
				unregister_code(DE_0);
			}
			return false;
			break;
		}
		
//insert start
				
case LT(0,DE_O): //sends "O" on tap and "Ö" on hold
	if (record->tap.count && record->event.pressed) {
		return true; // Return true for normal processing of tap keycode
		break;
	} else if (record->event.pressed) {
		tap_code16(DE_ODIA); // Intercept hold function to send SEMICOLON    
		return false;
		
		 }
		return true;
		
case LT(0,DE_U): 
	if (record->tap.count && record->event.pressed) {
		return true; 
		break;
	} else if (record->event.pressed) {
		tap_code16(DE_UDIA);   
		return false;
		
		 }
		return true;
		
case LT(0,DE_A): 
	if (record->tap.count && record->event.pressed) {
		return true; 
		break;
	} else if (record->event.pressed) {
		tap_code16(DE_ADIA);   
		return false;
		
		 }
		return true;
		
case LT(0,DE_D):
	if (record->tap.count && record->event.pressed) {
		return true;
		break;
	} else if (record->event.pressed) {
		tap_code16(DE_SS);  
		return false;
		
		 }
		return true;
		
case LT(0,KC_TAB):
	if (record->tap.count && record->event.pressed) {
		return true;
		break;
	} else if (record->event.pressed) {
		tap_code16(KC_ESC);  
		return false;
		
		 }
		return true;
		
case OUTLOOK:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Outlook" SS_DELAY(500) SS_TAP(X_ENT));
		} else {
					// when keycode is released
		}
		break;
		 
case FIREFOX:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Firefox" SS_DELAY(500) SS_TAP(X_ENT));
		} else {
					// when keycode is released
		}
		break;
		 
case SPOTIFY:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Spotify" SS_DELAY(300) SS_TAP(X_ENT));
		} else {
					// when keycode is released
		}
		break;
		 
case EVA:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "DIFFRAC.EVA" SS_DELAY(300) SS_TAP(X_ENT));
		} else {
					// when keycode is released
		}
		break;
		 
case TOPAS:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Topas" SS_DELAY(300) SS_TAP(X_ENT));
		} else {
		// when keycode is released
		}
		break;
		 
case NOTEPAD:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Notepad++" SS_DELAY(300) SS_TAP(X_ENT));
		} else {
					// when keycode is released
		}
		break;
		 
case PASSW:
	if (record->event.pressed) {
		SEND_STRING("Sauerkraut");
		} else {
					// when keycode is released
		}
		break;
		
//insert End
	}
	return true;
};

//switch key codes End

