#include QMK_KEYBOARD_H
#include "keyboards/fingerpunch/src/fp_rgb_common.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ENGRAMMER,
    _ELOWER,
    _ERAISE,
    _ADJUST,
    _EXTRA
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ELOWER MO(_ELOWER)
#define ERAISE MO(_ERAISE)
#define ADJUST MO(_ADJUST)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_ENGRAMMER] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ELOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_ERAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_EXTRA] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ffkb(
    KC_ESC,             KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,       KC_Y,    KC_U,   KC_I,      KC_O,     KC_P,      KC_BSPC,
    LT(LOWER,KC_TAB),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,       KC_H,    KC_J,   KC_K,      KC_L,     KC_SCLN,   KC_QUOT,
    KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,       KC_N,    KC_M,   KC_COMM,   KC_DOT,   KC_SLSH,   SC_SENT,
               KC_MUTE,     KC_LCTL,     KC_LGUI,     KC_LALT,    KC_SPC,      RAISE,      KC_DEL,     LCTL(KC_BSPC)
),

[_ENGRAMMER] = LAYOUT_ffkb(
    KC_TAB,               KC_B,   KC_Y,   KC_O,   KC_U,   KC_QUOT,      KC_SCLN,   KC_L,   KC_D,   KC_W,   KC_V,   KC_Z,
    MT(MOD_LCTL, KC_ESC),   KC_C,   KC_I,   KC_E,   KC_A,   KC_COMM,      KC_DOT,    KC_H,   KC_T,   KC_S,   KC_N,   KC_Q,
    KC_LGUI,              KC_G,   KC_X,   KC_J,   KC_K,   KC_MINS,      KC_SLSH,   KC_R,   KC_M,   KC_F,   KC_P,   KC_RALT,
    KC_MUTE,   KC_LALT,   MT(MOD_LSFT, KC_SPC),   LT(ERAISE,KC_DEL),      LT(ELOWER,KC_ENT),  MT(MOD_RSFT, KC_BSPC),   KC_RCTL, LCTL(KC_BSPC)
),

/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |             |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps| PgDn | PgUp |      |CpsWrd|             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,     KC_7,       KC_8,    KC_9,    KC_0,    _______,
  ADJUST,  RGB_SAI, RGB_VAI, RGB_HUI, RGB_SPI, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______, RGB_SAD, RGB_VAD, RGB_HUD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, ADJUST,       _______,  _______,    _______, _______
),

[_ERAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,       KC_5,                  KC_6,               KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  _______, KC_MPLY, KC_VOLU, LCTL(KC_Z), LCTL(KC_C), KC_PRINT_SCREEN,       LCTL(KC_LEFT),      KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT, RCTL(KC_RGHT),
  _______, KC_MUTE, KC_VOLD, LCTL(KC_Y), LCTL(KC_V), LCTL(LSFT(KC_T)),      LSFT(LCTL(KC_TAB)), KC_HOME, KC_PGUP, KC_PGDN, KC_END,  RCTL(KC_TAB),
                    _______, _______,    _______,    _______,               ADJUST,             _______, _______, _______
),

/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | TG(1)| TG(2)| TG(3)| TG(4)|      |             |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |CpsWrd|             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_ffkb(
 KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, 
_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS,
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                  _______, _______, _______, _______, _______, ADJUST,  _______, _______
),

[_ELOWER] = LAYOUT_ffkb(
  KC_TILD, KC_EXLM,             KC_AT,               KC_HASH,           KC_DLR,              KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, LSFT(KC_LEFT),       LSFT(KC_DOWN),       LSFT(KC_UP),       LSFT(KC_RGHT),       LALT(KC_LEFT),      KC_BSLS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______,
  _______, LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_DOWN)), LSFT(LCTL(KC_UP)), LSFT(LCTL(KC_RGHT)), LALT(KC_UP),        KC_PIPE, KC_UNDS, KC_PLUS, LSFT(KC_LCBR),  LSFT(KC_RCBR), _______,
                                _______,             _______,           _______,             ADJUST,             _______, _______, _______, _______
),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | RGB_T| RGB_R| RGB_F|      |      |             |   F1 |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_I| HUE_I| SAT_I| VAL_I|      |             |   F6 |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      | Reset|      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_ADJUST] =  LAYOUT_ffkb(
  _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),      KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  _______,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_ENGRAMMER),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, _______,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,      KC_F11,  KC_F12,  _______, _______,  QK_BOOT,  _______,
                     _______, _______, _______, _______,      _______, _______, _______, _______
),

/* Extra
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|             |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |      |      |      |    |      |      |      |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_EXTRA] = LAYOUT_ffkb(
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______,       _______, _______, _______, _______
)
};

//bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
//    switch (get_highest_layer(layer_state)) {
//        case _ENGRAMMER:
//            // Do nothing — same as _QWERTY base layer (let animation play)
//            return true; // returning true prevents the fp library from overriding
//        default:
//            return false; // let fingerpunch handle all other layers
//    }
//}

//layer_state_t layer_state_set_user(layer_state_t state) {
    // Treat ENGRAMMER as the base layer for RGB purposes
//    if (get_highest_layer(state) == _ENGRAMMER) {
//        layer_state_t fake_state = 0;  // pretend we're on layer 0
//        return fake_state | state;     // keep actual state but...
//    }
//    return state;
//}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (get_highest_layer(state) == _ENGRAMMER) {
        // Tell fingerpunch RGB it's the base layer
        fp_layer_state_set_rgb(0);
    }
    return state;
}
