#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

/* #define LEADER_TIMEOUT 200 */

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define CMND 2 // media keys
#define MDIA 3 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),
  [2] = ACTION_MODS_ONESHOT(MOD_LSFT)
};

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*  // action to do when TD(1) is tap-danced */
/*   [1] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_LEAD), */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | caps |           |  L1  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |OSM(S)|           | OS(1)|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|  L2  |           | LEAD |------+------+------+------+------+--------|
 * |(/LShift|Z/Ctrl| X/Alt| C/Gui|   V  |   B  |      |           |      |   N  |   M  | ,/Gui| ./Alt|//Ctrl|)/RShift|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  {   |   }  | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  |OSM(G)|       |OSM(A)|OSM(C)  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
	KC_EQL,         KC_1,          KC_2,          KC_3,        KC_4,   KC_5,   KC_CAPSLOCK,
        KC_DELT,        KC_Q,          KC_W,          KC_E,        KC_R,   KC_T,   OSM(MOD_LSFT),
        KC_BSPC,        KC_A,          KC_S,          KC_D,        KC_F,   KC_G,
        KC_LSPO,        KC_Z,          KC_X,          KC_C,        KC_V,   KC_B,   OSL(MDIA),
        LCTL_T(KC_GRV),  LALT_T(KC_LCBR),LGUI_T(KC_RCBR),KC_LEFT,     KC_RGHT,
	ALT_T(KC_APP), OSM(MOD_LGUI),
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
	TG(SYMB),    KC_6,   KC_7,  KC_8,           KC_9,         KC_0,             KC_MINS,
	OSL(1),      KC_Y,   KC_U,  KC_I,           KC_O,         KC_P,             KC_BSLS,
	KC_H,        KC_J,   KC_K,  KC_L,           LT(MDIA, KC_SCLN),KC_QUOT,
	TG(MDIA),     KC_N,   KC_M,  GUI_T(KC_COMM), KC_DOT,KC_SLSH,   KC_RSPC,
	                     KC_UP, KC_DOWN,        RGUI_T(KC_LBRC),RALT_T(KC_RBRC),  RCTL_T(KC_FN1),
	OSM(MOD_LALT),        KC_ESC,
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    :    |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------| ^C   |           |      |------+------+------+------+------+--------|
 * |    _    |   #  |   $  |   +  |   *  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------| ^D   |           |      |------+------+------+------+------+--------|
 * |    "    |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Hue-  |Hue+  |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,            KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_COLON,        KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,LCTL(KC_C),
       KC_UNDERSCORE,   KC_HASH,KC_DLR, KC_PLUS,KC_ASTR,KC_GRV,
       KC_DQT,          KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,LALT(KC_TAB),
          EPRM, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
                               /* RGB_VAD,RGB_VAI,KC_TRNS, */
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
       KC_DOWN, KC_4,    KC_5,   KC_6,    KC_PLUS, LCTL(KC_F5),
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      | ^T   |      |           |      | ^Z   | ^Y   | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|  ^D  |Alt+F4|      |------|           |------| ^D   |MsLeft|MsDown|MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | ^C   | ^V   | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, LCTL(KC_T), KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  LCTL(KC_Z), LCTL(KC_Y), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 LCTL(KC_D), LALT(KC_F4), KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  LCTL(KC_C), LCTL(KC_V), KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};


/* LEADER_EXTERNS(); */

/* void matrix_scan_user(void) { */
/* LEADER_DICTIONARY() { */
/*     leading = false; */
/*     leader_end(); */

/*     SEQ_ONE_KEY(KC_J) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_J); */
/*       unregister_code(KC_J); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_K) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_K); */
/*       unregister_code(KC_K); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_A) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_A); */
/*       unregister_code(KC_A); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_S) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_S); */
/*       unregister_code(KC_S); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_D) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_D); */
/*       unregister_code(KC_D); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_F) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_F); */
/*       unregister_code(KC_F); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_1) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_1); */
/*       unregister_code(KC_1); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_2) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_2); */
/*       unregister_code(KC_2); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_3) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_3); */
/*       unregister_code(KC_3); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_4) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_4); */
/*       unregister_code(KC_4); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_5) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_5); */
/*       unregister_code(KC_5); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_6) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_6); */
/*       unregister_code(KC_6); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_7) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_7); */
/*       unregister_code(KC_7); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_8) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_8); */
/*       unregister_code(KC_8); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_P) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_P); */
/*       unregister_code(KC_P); */
/*       unregister_code(KC_LGUI); */
/*    } */
/*     SEQ_ONE_KEY(KC_E) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_E); */
/*       unregister_code(KC_E); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_R) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_R); */
/*       unregister_code(KC_R); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_P) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_P); */
/*       unregister_code(KC_P); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_U) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_U); */
/*       unregister_code(KC_U); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_I) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_I); */
/*       unregister_code(KC_I); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_A) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_A); */
/*       unregister_code(KC_A); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_X) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_X); */
/*       unregister_code(KC_X); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_C) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_C); */
/*       unregister_code(KC_C); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_V) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_V); */
/*       unregister_code(KC_V); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_K) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_K); */
/*       unregister_code(KC_K); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_B) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_B); */
/*       unregister_code(KC_B); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_U) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_U); */
/*       unregister_code(KC_U); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_T) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_T); */
/*       unregister_code(KC_T); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_BSLS) { */
/*       register_code(KC_LCTL); */
/*       register_code(KC_BSLS); */
/*       unregister_code(KC_BSLS); */
/*       unregister_code(KC_LCTL); */
/*     } */
/*     SEQ_ONE_KEY(KC_SPC) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_SPC); */
/*       unregister_code(KC_SPC); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_LBRC) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_LBRC); */
/*       unregister_code(KC_LBRC); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_LCBR) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_LBRC); */
/*       unregister_code(KC_LBRC); */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_LGUI); */
/*     }     */
/*     SEQ_ONE_KEY(KC_RCBR) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_RBRC); */
/*       unregister_code(KC_RBRC); */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_LGUI); */
/*     } */
/*     SEQ_ONE_KEY(KC_GRV) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_GRV); */
/*       unregister_code(KC_GRV); */
/*       unregister_code(KC_LGUI); */
/*     }     */
/*     SEQ_ONE_KEY(KC_LEAD) { */
/*       register_code(KC_LGUI); */
/*       register_code(KC_TAB); */
/*       unregister_code(KC_TAB); */
/*       unregister_code(KC_LGUI); */
/*     } */

/*     /\* SEQ_ONE_KEY(KC_9) { *\/ */
/*     /\*   register_code(KC_LGUI); *\/ */
/*     /\*   register_code(KC_9); *\/ */
/*     /\*   unregister_code(KC_9); *\/ */
/*     /\*   unregister_code(KC_LGUI); *\/ */
/*     /\* } *\/ */
/*     /\* SEQ_TWO_KEYS(KC_A, KC_S) { *\/ */
/*     /\*   register_code(KC_H); *\/ */
/*     /\*   unregister_code(KC_H); *\/ */
/*     /\* } *\/ */
/*     /\* SEQ_THREE_KEYS(KC_A, KC_S, KC_D) { *\/ */
/*     /\*   register_code(KC_LGUI); *\/ */
/*     /\*   register_code(KC_S); *\/ */
/*     /\*   unregister_code(KC_S); *\/ */
/*     /\*   unregister_code(KC_LGUI); *\/ */
/*     /\* } *\/ */
/*   } */
