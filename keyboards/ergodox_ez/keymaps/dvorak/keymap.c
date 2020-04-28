#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

/// OSM() -> one-tap modifier
/// OSL() -> one-tap layer
/// MO()  -> temporary layer
/// TO()  -> toggle layer

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE,
    EPRM,
    VRSN,

    SHELL_LSLTR,
    SHELL_CDPRE,
    SHELL_PLESS,
    SHELL_PGREP
};

#define BASE    0
#define SYMB    1 // symbols and numpad
#define SHELL   2
#define TMUX    3
#define MEDIA   4
#define GAMING  5 // qwerty layout for gaming
#define MOUSE   6

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap: Base
*
* ,--------------------------------------------------.           ,--------------------------------------------------.
* | Esc    |   [  |   {  |   }  |   (  |   =  |      |           |      |   *  |   )  |   +  |   ]  |   !  |        |
* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
* | \      |   ;  |   ,  |   .  |   P  |   Y  |      |           |      |   F  |   G  |   C  |   R  |   L  | /      |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* | Ctrl   |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  | Del    |
* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
* | Shift  |   '  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  |        |
* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
*   | Mod  |      |      |      | SYMB |                                       | SYMB |      |      |      | MOUSE|
*   `----------------------------------'                                       `----------------------------------'
*                                        ,-------------.       ,---------------.
*                                        |      |      |       |      |        |
*                                 ,------|------|------|       |------+--------+------.
*                                 |      |      |      |       |      |        |      |
*                                 | BkSp | Tab  |------|       |------| Enter  | Space|
*                                 |      |      |      |       |      |        |      |
*                                 `--------------------'       `----------------------'
*/
[BASE] = LAYOUT_ergodox(
    KC_ESC,  KC_LBRC,   KC_LCBR,  KC_RCBR, KC_LPRN, KC_EQL, KC_TRNS,
    KC_BSLS, KC_SCOLON, KC_COMMA, KC_DOT,  KC_P,    KC_Y,   KC_TRNS,
    KC_LCTL, KC_A,      KC_O,     KC_E,    KC_U,    KC_I,
    KC_LSFT, KC_QUOTE,  KC_Q,     KC_J,    KC_K,    KC_X,   KC_LALT,
    KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, MO(SYMB),
                                                   KC_TRNS, KC_TRNS,
                                                            KC_TRNS,
                                           KC_BSPC, KC_TAB, KC_TRNS,
    KC_TRNS, KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, TO(GAMING),
    KC_TRNS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
             KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_DELT,
    KC_RALT, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RGUI,
                  MO(SYMB), KC_TRNS, KC_TRNS, KC_TRNS, TO(MOUSE),
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_ENTER, KC_SPACE
),

/* Keymap 1: Symbol
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  `   |  ~   |   %  |   ^  |      |      |           |      |      |   7  |   8  |   9  |   |  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  _   |  &   |   #  |   $  |      |------|           |------|      |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |   @  |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   ?  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
       KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
       KC_TRNS,  KC_GRV ,  KC_TILD,  KC_ASTR,  KC_AMPR,  KC_SLSH,  LSFT(KC_COMM),
       KC_TRNS,  KC_UNDS,  KC_CIRC,  KC_PERC,  KC_DLR,   KC_LPRN,
       KC_TRNS,  KC_EQL,   KC_HASH,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_LBRC,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                         KC_TRNS,  KC_TRNS,
                                                   KC_TRNS,
                         LSFT(KC_SLSH),  LSFT(KC_SLSH),  KC_TRNS,
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,  KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_P1,   KC_7,   KC_8,   KC_9,    KC_PIPE, KC_F12,
                KC_P6,   KC_4,   KC_5,   KC_6,    KC_MINS, KC_TRNS,
       KC_RBRC, KC_RCBR, KC_1,   KC_2,   KC_3,    KC_PLUS, KC_TRNS,
                         KC_0,   KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_SCLN, LSFT(KC_SLSH)
),

[MOUSE] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_UP, KC_MS_WH_DOWN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_BTN3, KC_TRNS, KC_TRNS, KC_TRNS, TO(BASE),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN2, KC_BTN1
),
/* Keymap: Gaming
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  | Base   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  | /      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Del    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  Up  | Shift  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      |      | LAlt |Space |                                       |Space |      | Left | Down |Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | VolU |       |      |        |      |
 *                                 | Space| Enter|------|       |------|        | BkSp |
 *                                 |      |      | VolD |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[GAMING] = LAYOUT_ergodox(
    // left hand
    KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TRNS,
    KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
    KC_LCTL, KC_TRNS, KC_TRNS, KC_LALT, KC_SPC,
                                 KC_TRNS,  KC_TRNS,
                                           KC_VOLU,
                           KC_SPC, KC_ENT, KC_VOLD,
    // right hand
    KC_TRNS, KC_6, KC_7, KC_8,    KC_9,   KC_0,	     TO(BASE),
    KC_TRNS, KC_Y, KC_U, KC_I,    KC_O,   KC_P,      KC_SLSH,
             KC_H, KC_J, KC_K,    KC_L,   KC_SCOLON, KC_DELT,
    KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP,     KC_RSFT,
                  KC_SPC, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BSPC
    ),

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
    switch(id){

    }
    return MACRO_NONE;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed) {
    switch (keycode) {
        case EPRM:
            eeconfig_init();
            return false;
            break;
        break;
        case SHELL_LSLTR:
            SEND_STRING("ls -ltr\n");
            return true;
            break;
        case SHELL_CDPRE:
            SEND_STRING("cd ..\n");
            return true;
            break;
        case SHELL_PLESS:
            SEND_STRING(" | less");
            return true;
            break;
        case SHELL_PGREP:
            SEND_STRING(" | grep ");
            return true;
            break;
    }
  }
  return true;
}

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case GAMING:
            ergodox_right_led_1_on();
            break;
        case SYMB:
            ergodox_right_led_2_on();
            break;
        case SHELL:
            ergodox_right_led_3_on();
            break;
        case MOUSE:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();

        default:
            break;
    }
};
