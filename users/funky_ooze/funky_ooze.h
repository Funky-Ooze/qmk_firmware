#pragma once
 
#include "quantum.h"
#include "keymap_german.h"

enum custom_keycodes {	// These use process_record_user
	CU_SLSH = SAFE_RANGE,
	CU_SCLN,
	CU_COMM,
	CU_DOT,
	CU_QUOT,
	CU_LBRC,
	CU_RBRC,
	CU_BSLS,
	CU_EQL,
	
	CU_1,
	CU_2,
	CU_3,
	CU_4,
	CU_5,
	CU_6,
	CU_7,
	CU_8,
	CU_9,
	CU_0,
	KC_LT46,
	
	PWHOME,	
	PASSW,
	OUTLOOK,
	FIREFOX,
	NOTEPAD,
	SMILE,
	WINK,
	LAUGH,
	DEF,
	IFDEF,
	ENDIF

};


// Layer Toggles
#define QWERTY		MO(_QWERTY)
#define LOWER		MO(_LOWER)
#define RAISE		MO(_RAISE)
#define ALPHA		MO(_ALPHA)
#define BETA		MO(_BETA)
#define SPC_LO		LT(1,KC_SPC)
#define SPC_RA		LT(2,KC_SPC)
#define ENT_LO		LT(1,KC_ENT)
#define M_BETA		LT(5, KC_M)
#define Z_ALPHA		LT(4,KC_Y)


// Short Cuts
#define LOGIN		LCTL(LALT(KC_DEL))
#define EMAIL		LCTL(LSFT(KC_M))
#define REPLY		LCTL(LSFT(KC_R))
#define TASK		LCTL(LSFT(KC_K))
#define PROEM		LCTL(LSFT(KC_7))
#define EMTSK		LCTL(LSFT(KC_8))
#define EXIT		LALT(KC_F4)
#define TO_START 	LCTL(KC_HOME)
#define TO_END		LCTL(KC_END)
#define COPY	  	LCTL(KC_C)
#define CUT    	  	LCTL(KC_X)
#define PASTE	  	LCTL(KC_V)
#define SAVE		LCTL(KC_S)
#define ALT_SFT		LALT(KC_LSFT)
#define SWTABF		LCTL(KC_PGUP)
#define SWTABB		LCTL(KC_PGDN)


// Special Characters on hold
#define CU_OE		LT(0,DE_O)
#define CU_AE		LT(0,DE_A)
#define CU_UE		LT(0,DE_U)
#define CU_D_SS		LT(0,DE_D)

// Double ALPHA Keys
#define ENT_SFT		MT(MOD_LSFT,KC_ENT)
#define SPC_SFT  	LSFT_T(KC_SPC)


//QAZpad specific
#define Q_ESC  		LT(0,KC_Q)
#define ON_SFT    	LSFT_T(KC_1)
#define TW_SFT    	LSFT_T(KC_2)
#define TH_SFT    	LSFT_T(KC_3)
#define DOT_CTL    	LCTL_T(KC_DOT)
#define Z_SFT  		LSFT_T(KC_Y)


