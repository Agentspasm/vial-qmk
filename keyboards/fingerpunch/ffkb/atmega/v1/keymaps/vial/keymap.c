#include QMK_KEYBOARD_H

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
#if (defined(FP_EC11_UNDER_PALMS) || defined(FP_EVQ_UNDER_PALMS)) && defined(FP_EC11_CENTER) && !defined(OLED_ENABLE) && !defined(PIMORONI_TRACKBALL_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),    ENCODER_CCW_CW(RGB_SAD, RGB_SAI),   ENCODER_CCW_CW(RGB_HUD, RGB_HUI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),    ENCODER_CCW_CW(RGB_SPD, RGB_SPI),   ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),   ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [_EXTRA] =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),   ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),  ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif
// under palms enabled, and not the center... or the center is also enabled, but so is oled or pimoroni (not valid, so we disable the center anyway)
#if (defined(FP_EC11_UNDER_PALMS) || defined(FP_EVQ_UNDER_PALMS)) && (!defined(FP_EC11_CENTER) || defined(OLED_ENABLE) || defined(PIMORONI_TRACKBALL_ENABLE))
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),    ENCODER_CCW_CW(RGB_SAD, RGB_SAI) },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),    ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),   ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_EXTRA] =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),   ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
#if !defined(FP_EC11_UNDER_PALMS) && !defined(FP_EVQ_UNDER_PALMS) && defined(FP_EC11_CENTER)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
    [_EXTRA] =  { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
#endif
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |   |ALTTAB|  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
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
               KC_MUTE,     KC_LCTL,     KC_LGUI,     KC_LALT,    KC_SPC,      RAISE,      KC_DEL,     LCTL(KC_BSPC),
                                                           LALT(KC_TAB)
),

[_ENGRAMMER] = LAYOUT_ffkb(
    KC_TAB,               KC_B,   KC_Y,   KC_O,   KC_U,   KC_QUOT,      KC_SCLN,   KC_L,   KC_D,   KC_W,   KC_V,   KC_Z,
    LT(KC_LCTL,KC_ESC),   KC_C,   KC_I,   KC_E,   KC_A,   KC_COMM,      KC_DOT,    KC_H,   KC_T,   KC_S,   KC_N,   KC_Q,
    KC_LGUI,              KC_G,   KC_X,   KC_J,   KC_K,   KC_UNDS,      KC_SLSH,   KC_R,   KC_M,   KC_F,   KC_P,   KC_RALT,
    KC_MUTE,   KC_LALT,   LT(KC_LSFT,KC_SPC),   LT(ERAISE,KC_DEL),      LT(ELOWER,KC_ENT)  LT(KC_LSFT,KC_SPC),   KC_RCTL, LCTL(KC_BSPC),
                                                               LALT(KC_TAB)
),

/* Raise
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * | Home | Left | Down |  Up  | Right| End  |   |ALTTAB|  |      |   -  |   =  |   [  |   ]  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      | PgDn | PgUp |      |CpsWrd|             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_RAISE] = LAYOUT_ffkb(
 _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
 ADJUST,  RGB_SAI, RGB_VAI, RGB_HUI, RGB_SPI, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
 _______, RGB_SAD, RGB_VAD, RGB_HUD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,
                   _______, _______, _______, _______, _______, _______, _______, _______
                                                  _______
),

[_ERAISE] = LAYOUT_ffkb(
  KC_GRV,  KC_1,    KC_2,    KC_3,       KC_4,       KC_5,                  KC_6,               KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  _______, KC_MPLY, KC_VOLU, LCTL(KC_Z), LCTL(KC_C), KC_PRINT_SCREEN,       LCTL(KC_LEFT),      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RCTL(KC_RGHT),
  _______, KC_MUTE, KC_VOLD, LCTL(KC_Y), LCTL(KC_V), LCTL(LSFT(KC_T)),      LSFT(LCTL(KC_TAB)), KC_HOME, KC_PGUP, KC_PGDN, KC_END,  RCTL(KC_TAB),
                    _______, _______,    _______,    _______,               ADJUST,             _______, _______, _______,
                                                                     _______
),

/* Lower
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      | TG(1)| TG(2)| TG(3)| TG(4)|      |   |ALTTAB|  |      |   _  |   +  |   {  |   }  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |  Caps|      |      |      |      |             |      |      |      |   |  |   "  |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_LOWER] = LAYOUT_ffkb(
KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, 
_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PLUS,
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                  _______, _______, _______, _______, _______, ADJUST,  _______, _______,
                                                  _______
),

[_ELOWER] = LAYOUT_ffkb(
  KC_TILD, KC_EXLM,             KC_AT,               KC_HASH,           KC_DLR,              KC_PERC,            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, LSFT(KC_LEFT),       LSFT(KC_DOWN),       LSFT(KC_UP),       LSFT(KC_RGHT),       LALT(KC_LEFT),      KC_BSLS, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, _______,
  _______, LSFT(LCTL(KC_LEFT)), LSFT(LCTL(KC_DOWN)), LSFT(LCTL(KC_UP)), LSFT(LCTL(KC_RGHT)), LALT(KC_UP),        KC_PIPE, KC_UNDS, KC_PLUS, LSFT(KC_LCBR),  LSFT(KC_RCBR), _______,
                                _______,             _______,           _______,             ADJUST,             _______, _______, _______, _______,
                                                                                                          _______
),

/* Adjust (Lower + Raise)

 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      | RGB_T| RGB_R| RGB_F|      |      |             |   F1 |  F2  |  F3  |  F4  |  F5  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      | SPD_I| HUE_I| SAT_I| VAL_I|      |   |ALTTAB|  |   F6 |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      | SPD_D| HUE_D| SAT_D| VAL_D|      |             |  F11 |  F12 |      |      | Reset|      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_ADJUST] =  LAYOUT_ffkb(
  _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______, _______,      KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,  _______,
  _______, RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_ENGRAMMER),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10, _______,
  _______, RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,      KC_F11,  KC_F12,  _______, _______,  QK_BOOT,  _______,
                     _______, _______, _______, _______,      _______, _______, _______, _______,
                                                       _______
),

/* Extra
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |ALTTAB|  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
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
                    _______, _______, _______, _______,       _______, _______, _______, _______,
                                                       _______
)
};


#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
      return OLED_ROTATION_180;
}


// Commenting out logo as it takes up a lot of space :(
static void render_logo(void) {
    // ffkb logo, 128x64px
    static const char PROGMEM ffkb_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
    0xf0, 0x10, 0x10, 0x10, 0x90, 0x30, 0x30, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xfc, 0x3c, 0x3c, 0x38, 0x70,
    0x70, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0x70,
    0x70, 0x38, 0x3c, 0x3c, 0xfc, 0xf8, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x10, 0x00,
    0x80, 0x90, 0xd0, 0xf0, 0x30, 0x30, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0x3f, 0x21, 0x01, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe7, 0xff, 0x7f, 0x7f, 0xbc, 0x9e, 0x8e, 0x8f,
    0x87, 0x87, 0x83, 0x83, 0x81, 0x81, 0x81, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x81, 0x81, 0x81, 0x83, 0x83, 0x87, 0x87,
    0x8f, 0x8e, 0x9e, 0xbc, 0x7f, 0x7f, 0xff, 0xe7, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x23, 0x07,
    0x0f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3e, 0x3c, 0x38, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
    0xfc, 0x44, 0x44, 0x44, 0xe4, 0x0c, 0x0c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x06, 0x06, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1b, 0x3b, 0x3b, 0x73, 0x73, 0x73, 0xe3,
    0xe3, 0xdf, 0xdf, 0xdf, 0x8b, 0x83, 0x03, 0x03, 0x07, 0x1f, 0xfe, 0xfc, 0xf8, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0xf8, 0xfc, 0xfe, 0x1f, 0x07, 0x03, 0x03, 0x83, 0x8b, 0xdf, 0xdf, 0xdf, 0xe3,
    0xe3, 0x73, 0x73, 0x73, 0x3b, 0x3b, 0x1b, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x07, 0x06, 0x06, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0x44, 0x44,
    0x44, 0xfc, 0xfc, 0xfc, 0xfc, 0xf8, 0xb8, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,
    0x0f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x0e, 0x1f, 0x3f, 0x3f, 0x3f, 0x36, 0x36,
    0x36, 0x36, 0x3f, 0x3f, 0x3f, 0x1f, 0x0e, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x08, 0x08,
    0x08, 0x0f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
    oled_write_raw_P(ffkb_logo, sizeof(ffkb_logo));

}

bool oled_task_user(void) {
    // If you don't want to display the logo, switch
    if (false) {
        //render_status();
    } else if (true) {
        render_logo();
    } else {
        //render_logo_text();
    }
    return true;
}

#endif
