#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0
#define SYMB 1

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
// Some basic macros
/* #define TASK    LCTL(LSFT(KC_ESC)) */
/* #define TAB_R   LCTL(KC_TAB) */
/* #define TAB_L   LCTL(LSFT(KC_TAB)) */
/* #define TAB_RO  LCTL(LSFT(KC_T)) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,------------------------------------------------.           ,------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  | caps |           | caps |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |OSM(S)|           |OSM(S)|   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------+------|           |------|------+------+------+------+------+------|
 * | BkSp |   A  |   S  |   D  |   F  |   G  | OS(1)|           | OS(1)|   H  |   J  |   K  |   L  |   ;  |'/Cmd |
 * |------+------+------+------+------+------+------|           |------|------+------+------+------+------+------|
 * |(/LSft|Z/Ctrl| X/Alt| C/Gui|   V  |   B  |  L1  |           |  L1  |   N  |   M  | ,/Gui| ./Alt|//Ctrl|)/RSft|
 * `------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
 *               | Left | Right|                                                     |  Up  | Down |
 *               `-------------'                                                     `-------------'
 *                                      ,-------------.       ,-------------.
 *                                      | Tab  | space|       |enter | Esc  |
 *                                      |------|------|       |------+------|
 *                                      | App  | Home |       | PgUp |OSM(G)|
 *                                      |------+------|       |------|------|
 *                                      |OSM(C)| End  |       | PgDn |OSM(A)|
 *                                      `-------------'       `-------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_5x7_alt(
		    // left hand
		    KC_EQL,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_CAPS,
		    KC_DELT,        KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           OSM(MOD_LSFT),
		    KC_BSPC,        KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           OSL(SYMB),
		    KC_LSPO,	    LCTL_T(KC_Z),   LALT_T(KC_X),   LGUI_T(KC_C),   KC_V,           KC_B,	    TG(SYMB),
					 	    KC_LEFT,        KC_RGHT,
                         		            KC_TAB,         KC_SPC,
		                                    KC_APP,         KC_HOME, 
		                                    OSM(MOD_LCTL),  KC_END,
		    // right hand
		    KC_CAPS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
                    OSM(MOD_LSFT),  KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                    OSL(SYMB),      KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT, 
                    TG(SYMB),       KC_N,           KC_M,           RGUI_T(KC_COMM),RALT_T(KC_DOT), RCTL_T(KC_SLSH),KC_RSPC,
                                                                    KC_UP,          KC_DOWN,
                                                                    KC_ENT,         KC_ESC, 
		                                                    KC_PGUP,        OSM(MOD_RGUI),
		                                                    KC_PGDN,        OSM(MOD_LALT)
		    ),
/* Keymap 1: Symbol layer
 *
 * ,------------------------------------------------.           ,------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------|           |------+------+------+------+------+------+------|
 * |  :   |   !  |   @  |   {  |   }  |   |  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   /  |
 * |------+------+------+------+------+------+------|           |------|------+------+------+------+------+------|
 * |  _   |   #  |   $  |   +  |   *  |   `  |  ^C  |           |  ^D  | Down |   4  |   5  |   6  |   +  |   ?  |
 * |------+------+------+------+------+------+------|           |------|------+------+------+------+------+------|
 * |  "   |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |   '  |
 * `------+------+------+------+------+-------------'           `-------------+------+------+------+------+------'
 *               | Left | Right|                                                     |   .  |   0  |
 *               `-------------'                                                     `-------------'
 *                                      ,-------------.       ,-------------.
 *                                      |      |      |       |      |      |
 *                                      |------|------|       |------+------|
 *                                      |      |      |       |      |      |
 *                                      |------+------|       |------|------|
 *                                      |      |      |       |      |      |
 *                                      `-------------'       `-------------'
 */
[SYMB] = LAYOUT_5x7_alt(
		    // left hand
		    KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,          _______,
		    KC_COLN,        KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        _______,
		    KC_UNDS,        KC_HASH,        KC_DLR,         KC_PLUS,        KC_ASTR,        KC_GRV,         LCTL(KC_C),
		    KC_DQUO,	    KC_PERC,        KC_CIRC,        KC_LBRC,        KC_RBRC,        KC_TILD,	    _______,
					 	    _______,        _______,
                         		            _______,        _______,
		                                    _______,        _______, 
		                                    _______,        _______,
		    // right hand
		    _______,        KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,
                    _______,        KC_UP,          KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
                    LCTL(KC_D),     KC_DOWN,        KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOT, 
                    _______,        KC_AMPR,        KC_M,           RGUI_T(KC_COMM),RALT_T(KC_DOT), RCTL_T(KC_SLSH),KC_RSPC,
                                                                    _______,        _______,
                                                                    _______,        _______, 
		                                                    _______,        _______,
		                                                    _______,        _______
		    ),
};
