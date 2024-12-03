#include "funky_ooze.h"

uint16_t lt46_timer;

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
			
//QAZpad specific


		case LSFT_T(KC_1):
			shift_held = record->event.pressed;
			return true;
			break;
		case LSFT_T(KC_2):
			shift_held = record->event.pressed;
			return true;
			break;
		case LSFT_T(KC_3):
			shift_held = record->event.pressed;
			return true;
			break;	
		case LSFT_T(KC_Y):
			shift_held = record->event.pressed;
			return true;
			break;				
			
//QAZpad specific end
					
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_PLUS);
				unregister_code(DE_0);
			}
			return false;
			break;
		}
		case CU_1: {
			if (record->event.pressed) {
				if (shift_held) {
					unregister_code(KC_1);
					register_code(KC_1);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(KC_1);
					register_code(KC_1);
				}
			} else { 
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(KC_1);
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
			} else { 
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
			} else { 
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
					register_code(KC_LSFT);
					unregister_code(KC_4);
					register_code(KC_4);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(KC_4);
					register_code(KC_4);
				}
			} else { 
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(KC_4);
			}
			return false;
			break;
		}
		case CU_5: {
			if (record->event.pressed) {
				if (shift_held) {
					register_code(KC_LSFT);
					unregister_code(KC_5);
					register_code(KC_5);
				} else {
					unregister_code(KC_LSFT);
					unregister_code(KC_RSFT);
					unregister_code(KC_5);
					register_code(KC_5);
				}
			} else { 
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(KC_5);
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
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
			} else { 
				unregister_code(KC_LSFT);
				unregister_code(KC_RSFT);
				unregister_code(DE_9);
				unregister_code(DE_0);
			}
			return false;
			break;
		}
		

				
case LT(0,DE_O): //sends "O" on tap and "Ö" on hold
	if (record->tap.count && record->event.pressed) {
		return true; // Return true for normal processing of tap keycode
		break;
	} else if (record->event.pressed) {
		tap_code16(DE_ODIA); // Intercept hold function to send "Ö"  
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
		
case LT(0,KC_P):
	if (record->tap.count && record->event.pressed) {
		return true;
		break;
	} else if (record->event.pressed) {
		tap_code16(KC_ENT);  
		return false;
		
		 }
		return true;
		
case LT(0,DE_Q):
	if (record->tap.count && record->event.pressed) {
		return true;
		break;
	} else if (record->event.pressed) {
		tap_code16(KC_ESC);  
		return false;
		
		 }
		return true;
// Test with layer tap and toggle - START

  case KC_LT46:                                  
    if(record->event.pressed){
      lt46_timer = timer_read();
      layer_on(4);
    } else {
      layer_off(4);
      if (timer_elapsed(lt46_timer) < TAPPING_TERM) {  
        layer_invert(6);
      }
    }
    return true; 
	
// Test with layer tap and toggle - END
		
case OUTLOOK:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Outlook" SS_DELAY(500) SS_TAP(X_ENT));
		} else {
					 
		}
		break;
		 
case FIREFOX:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Firefox" SS_DELAY(500) SS_TAP(X_ENT));
		} else {
					 
		}
		break;
		 
case NOTEPAD:
	if (record->event.pressed) {
		SEND_STRING(SS_TAP(X_LGUI) "Notepad++" SS_DELAY(300) SS_TAP(X_ENT));
		} else {
					 
		}
		break;
		 
case PASSW:
	if (record->event.pressed) {
		SEND_STRING("youWish1234");
		} else {
					 
		}
		break;
		
case PWHOME:
	if (record->event.pressed) {
		SEND_STRING("myAss666");
		} else {
					
		}
		break;
		
case SMILE:		
	if (record->event.pressed) {
		SEND_STRING(">/(");
		} else {
					
		}
		break;
		
case WINK:		
	if (record->event.pressed) {
		SEND_STRING("</(");
		} else {
					
		}
		break;
		
case LAUGH:		
	if (record->event.pressed) {
		SEND_STRING(">/D");
		} else {
					
		}
		break;
		
	}
	return true;
};

//switch key codes End

