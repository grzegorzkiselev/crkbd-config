#include QMK_KEYBOARD_H

enum crkbd_layers
{
    BASE,
    NAVIGATION,
    NUMBERS,
    FN
};

enum tap_dance_codes {
  DANCE_ESC_GRAVE,
//   DANCE_CTRL_NAV,
//   DANCE_SPACE_NUMBERS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x6_3(
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_TAB,                  KC_Q,            KC_W,      KC_E,      KC_R,      KC_T,                                           KC_Y,           KC_U,        KC_I,      KC_O,      KC_P,           KC_LBRC,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
    MT(MOD_LSFT, KC_F18),           KC_A,            KC_S,      KC_D,      KC_F,      KC_G,                                           KC_H,           KC_J,        KC_K,      KC_L,    KC_SCLN,   MT(MOD_RSFT, KC_QUOT),  
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LCTL,                 KC_Z,            KC_X,      KC_C,      KC_V,      KC_B,                                           KC_N,           KC_M,      KC_COMM,    KC_DOT,   KC_SLSH,          KC_RBRC,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
                                                                         KC_LALT,   KC_LGUI,     TT(NUMBERS),          KC_SPC,   TT(NAVIGATION),     KC_BSLS                                                              
),
[NAVIGATION] = LAYOUT_split_3x6_3(
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_BSPC,                KC_DEL,          KC_ESC,    KC_UP,     KC_NO,     KC_NO,                                           KC_NO,         KC_TRNS,     KC_UP,     KC_ESC,   KC_BSPC,           KC_DEL,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LSFT,                KC_ENT,         KC_RGHT,   KC_DOWN,   KC_LEFT,   KC_TRNS,                                          KC_NO,         KC_LEFT,    KC_DOWN,   KC_RGHT,    KC_ENT,          KC_RSFT,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LCTL,               KC_BRID,         KC_BRIU,   RGB_TOG,   RGB_VAD,   RGB_VAI,                                         KC_MPRV,        KC_MPLY,    KC_MNXT,   KC_MUTE,   KC_VOLD,          KC_VOLU,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
                                                                         KC_LALT,   KC_LGUI,   TG(NAVIGATION),         TT(FN),   TG(NAVIGATION),   TT(NUMBERS)                                                            
),
[NUMBERS] = LAYOUT_split_3x6_3(
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
            KC_1,                   KC_2,            KC_3,      KC_4,      KC_5,      KC_6,                                           KC_7,           KC_8,        KC_9,      KC_0,    KC_MINS,           KC_EQL,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LSFT,         TD(DANCE_ESC_GRAVE),    KC_NO,     KC_NO,     KC_NO,     KC_NO,                                           KC_NO,          KC_NO,      KC_NO,     KC_NO,     KC_NO,            KC_NO,          
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LCTL,            TG(NAVIGATION),      TG(FN),    KC_NO,     KC_NO,     KC_SPC,                                          KC_NO,          KC_NO,      KC_NO,     KC_NO,     KC_NO,            KC_NO,          
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
                                                                         KC_LALT,   KC_LGUI,     TG(NUMBERS),          KC_SPC,       KC_TRNS,      TG(NUMBERS)                                                            
),
[FN] = LAYOUT_split_3x6_3(
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
            KC_F1,                 KC_F2,           KC_F3,     KC_F4,     KC_F5,     KC_F6,                                           KC_F7,          KC_F8,      KC_F9,     KC_F10,    KC_F11,           KC_F12,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LSFT,               KC_BTN1,         KC_BTN2,   KC_MS_U,   KC_LSFT,   KC_WH_U,                                         KC_WH_U,        KC_RSFT,    KC_MS_U,   KC_BTN2,   KC_BTN1,          KC_RSFT,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
           KC_LCTL,               KC_BTN3,         KC_MS_L,   KC_MS_D,   KC_MS_R,   KC_WH_D,                                         KC_WH_D,        KC_MS_L,    KC_MS_D,   KC_MS_R,   KC_BTN3,          KC_RCTL,         
//|:---------------------:|:--------------------:|:--------:|:--------:|:--------:|:--------:|:---------------:|:---:|:-------:|:---------------:|:-----------:|:--------:|:--------:|:--------:|:----------------------:|
                                                                         KC_LALT,   KC_LGUI,       TG(FN),             TG(FN),       KC_RGUI,        KC_RALT                                                              
)
};


#ifdef RGBLIGHT_ENABLE
#define COLOR_BASE 167,	179, 214
#define COLOR_NAV 90, 179, 214
#define COLOR_NUMBERS 255, 130, 224
#define COLOR_SERVICE 30, 235, 252

const rgblight_segment_t PROGMEM nav_layer[] =
    RGBLIGHT_LAYER_SEGMENTS(
        {0, 54, COLOR_NAV});
const rgblight_segment_t PROGMEM numbers_layer[] =
    RGBLIGHT_LAYER_SEGMENTS(
        {0, 54, COLOR_NUMBERS});
const rgblight_segment_t PROGMEM service_layer[] =
    RGBLIGHT_LAYER_SEGMENTS(
        {0, 54, COLOR_SERVICE});

const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(nav_layer, numbers_layer, service_layer);
void keyboard_post_init_user(void)
{
    rgblight_layers = my_rgb_layers;
    rgblight_sethsv(COLOR_BASE);
}

layer_state_t layer_state_set_user(layer_state_t state)
{
    rgblight_set_layer_state(0, layer_state_cmp(state, NAVIGATION));
    rgblight_set_layer_state(1, layer_state_cmp(state, NUMBERS));
    rgblight_set_layer_state(2, layer_state_cmp(state, FN));
    return state;
}
#endif

#ifdef OLED_ENABLE
// oled_rotation_t oled_init_user(oled_rotation_t rotation)
// {
//     if (!is_keyboard_master())
//     {
//         return rotation;
//     }
//     return rotation;
// }

// Print layer names
static void oled_render_layer_state(void)
{
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state))
    {
    case BASE:
        oled_write_ln_P(PSTR("BASE"), false);
        break;
    case NAVIGATION:
        oled_write_ln_P(PSTR("NAVIGATION"), false);
        break;
    case NUMBERS:
        oled_write_ln_P(PSTR("NUMBERS"), false);
        break;
    case FN:
        oled_write_ln_P(PSTR("FN"), false);
        break;
    default:
        oled_write_ln_P(PSTR("UNDEFINED"), false);
        break;
    }
}

bool wpm_keycode_user(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }
    if ((keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_TAB && keycode <= KC_SLSH)) {
        return true;
    }

    return false;
}

static void oled_render_wpm(void) {
  static char wpm_str[4];

  sprintf(wpm_str, "%03d", get_current_wpm());
  oled_set_cursor(0, 1);
  oled_write_P(PSTR("WPM: "), false);
  oled_set_cursor(5, 1);
  oled_write(wpm_str, false);
}

void oled_render_logo(void)
{
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        oled_render_layer_state();
        oled_render_wpm();
    }
    else
    {
        oled_render_logo();
    };
    return false;
}
#endif

extern bool g_suspend_state;

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case TD(DANCE_CTRL_NAV):
        case TD(DANCE_ESC_GRAVE):
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_SINGLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_SINGLE_TAP,
    TRIPLE_HOLD,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

/* CTRL_NAV */
// Escape arrows and other keys in ctrl-navigation mode
// bool process_record_user(uint16_t keycode, keyrecord_t *record)
// {
//     switch (keycode)
//         case KC_UP:
//         case KC_ESC:
//         case KC_BSPC:
//         case KC_LEFT:
//         case KC_DOWN:
//         case KC_RGHT:
//         case KC_ENT:
//         case KC_DEL:
//         {
//             if (record->event.pressed) unregister_code(KC_LCTL);
//         }

//     return true;
// }

// void on_DANCE_CTRL_NAV(tap_dance_state_t *state, void *user_data);
// uint8_t DANCE_CTRL_NAV_dance_step(tap_dance_state_t *state);
// void DANCE_CTRL_NAV_finished(tap_dance_state_t *state, void *user_data);
// void DANCE_CTRL_NAV_reset(tap_dance_state_t *state, void *user_data);

// void on_DANCE_CTRL_NAV(tap_dance_state_t *state, void *user_data) {}

// uint8_t DANCE_CTRL_NAV_dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->pressed) return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->pressed) return DOUBLE_HOLD;
//     } else if (state->count == 3) {
//         if (state->pressed) return TRIPLE_HOLD;
//     }
//     return MORE_TAPS;
// }

// void DANCE_CTRL_NAV_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state.step = DANCE_CTRL_NAV_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_HOLD: register_code16(KC_LCTL); layer_move(1); break;
//         case DOUBLE_HOLD: register_code16(KC_RCTL); layer_move(1); break;
//         case TRIPLE_HOLD: register_code16(KC_LCTL); break;
//     }
// }

// void DANCE_CTRL_NAV_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     layer_move(0);
//     unregister_code16(KC_LCTL);
//     unregister_code16(KC_RCTL);
//     dance_state.step = 0;
// }

/* ESC_GRAVE */
void on_DANCE_ESC_GRAVE(tap_dance_state_t *state, void *user_data);
uint8_t DANCE_ESC_GRAVE_dance_step(tap_dance_state_t *state);
void DANCE_ESC_GRAVE_finished(tap_dance_state_t *state, void *user_data);
void DANCE_ESC_GRAVE_reset(tap_dance_state_t *state, void *user_data);

void on_DANCE_ESC_GRAVE(tap_dance_state_t *state, void *user_data) {}

uint8_t DANCE_ESC_GRAVE_dance_step(tap_dance_state_t *state) {
    if (state->count == 2 && !state->pressed) return DOUBLE_TAP;
    return SINGLE_TAP;
}

void DANCE_ESC_GRAVE_finished(tap_dance_state_t *state, void *user_data) {
    dance_state.step = DANCE_ESC_GRAVE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_ESC); break;
        case DOUBLE_TAP: register_code16(KC_GRV); break;
    }
}

void DANCE_ESC_GRAVE_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_ESC); break;
        case DOUBLE_TAP: unregister_code16(KC_GRV); break;
    }
    dance_state.step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        // [DANCE_CTRL_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_CTRL_NAV, DANCE_CTRL_NAV_finished, DANCE_CTRL_NAV_reset),
        [DANCE_ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(on_DANCE_ESC_GRAVE, DANCE_ESC_GRAVE_finished, DANCE_ESC_GRAVE_reset)
};
