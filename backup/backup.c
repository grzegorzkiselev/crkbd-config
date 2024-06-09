#include QMK_KEYBOARD_H

// bool process_record_user(uint16_t keycode, keyrecord_t *record)
// {
//     switch (keycode)
//     case KC_BSPC:
//     case KC_DEL:
//     case KC_UP:
//     case KC_LEFT:
//     case KC_DOWN:
//     case KC_RGHT:
//     case KC_ENT:
//     case KC_BSLS:
//     case KC_LCTL:
//     case KC_ESC:
//     case KC_BRID:
//     case KC_BRIU:
//     case KC_MUTE:
//     case KC_VOLD:
//     case KC_VOLU:
//     {
//         if (record->event.pressed)
//         {
//             unregister_code(KC_LCTL);
//         }
//         else
//         {
//             if (get_mods() == MOD_BIT(KC_LCTL))
//             {
//                 register_code(KC_LCTL);
//             }
//         }
//         break;
//     }
//         return true;
// }

enum crkbd_layers
{
    BASE,
    NAVIGATION,
    NUMBERS,
    SERVICE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC, MT(MOD_LSFT, KC_F19), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RSFT, KC_QUOT), KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_LBRC, MT(MOD_RCTL, KC_SLSH), KC_LALT, KC_LGUI, MO(2), KC_SPC, KC_RGUI, MO(1)),
    [NAVIGATION] = LAYOUT_split_3x6_3(
        KC_TAB, KC_ESC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_BSPC, KC_DEL, KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, KC_BSLS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_MUTE, KC_VOLD, KC_VOLU, KC_LALT, KC_LGUI, MO(2), KC_SPC, KC_TRNS, KC_TRNS),
    [NUMBERS] = LAYOUT_split_3x6_3(
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_TRNS, MO(3), KC_TRNS, KC_NO),
    [SERVICE] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_TRNS, KC_SPC, KC_TRNS, KC_TRNS, KC_RALT)};

#define COLOR_BASE 25, 239, 128
#define COLOR_NAV 25, 226, 128
#define COLOR_NUMBERS 25, 213, 128
#define COLOR_SERVICE 25, 200, 128

#ifdef RGBLIGHT_ENABLE
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
    rgblight_set_layer_state(2, layer_state_cmp(state, SERVICE));
    return state;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation)
{
    if (!is_keyboard_master())
    {
        return OLED_ROTATION_180;
    }
    return rotation;
}

static void oled_render_layer_state(void)
{
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state))
    {
    case 0:
        oled_write_ln_P(PSTR("BASE"), false);
        break;
    case 1:
        oled_write_ln_P(PSTR("NAVIGATION"), false);
        break;
    case 2:
        oled_write_ln_P(PSTR("NUMBERS"), false);
        break;
    case 3:
        oled_write_ln_P(PSTR("SERVICE"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undef"), false);
        break;
    }
}

// char key_name = ' ';
// static const char PROGMEM code_to_name[60] = {' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};
// static void set_keylog(uint16_t keycode, keyrecord_t *record)
// {
//     key_name = ' ';
//     if (IS_QK_MOD_TAP(keycode))
//     {
//         if (record->tap.count)
//         {
//             keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
//         }
//         else
//         {
//             keycode = 0xE0 + biton(QK_MOD_TAP_GET_MODS(keycode) & 0xF) + biton(QK_MOD_TAP_GET_MODS(keycode) & 0x10);
//         }
//     }
//     else if (IS_QK_LAYER_TAP(keycode) && record->tap.count)
//     {
//         keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
//     }
//     else if (IS_QK_MODS(keycode))
//     {
//         keycode = QK_MODS_GET_BASIC_KEYCODE(keycode);
//     }
//     else if (IS_QK_ONE_SHOT_MOD(keycode))
//     {
//         keycode = 0xE0 + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0xF) + biton(QK_ONE_SHOT_MOD_GET_MODS(keycode) & 0x10);
//     }
//     if (keycode > ARRAY_SIZE(code_to_name))
//     {
//         return;
//     }

//     // update keylog
//     key_name = pgm_read_byte(&code_to_name[keycode]);
// }

// static void oled_render_keylog(void)
// {
//     oled_write_char(key_name, false);
// }

// bool process_record_kb(uint16_t keycode, keyrecord_t *record)
// {
//     if (record->event.pressed)
//     {
//         set_keylog(keycode, record);
//     }
//     return process_record_user(keycode, record);
// }

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        oled_render_layer_state();
        // oled_render_keylog();
        // oled_render_wpm();
        // oled_render_anim();
    }
    else
    {
        // oled_render_logo();
    }
    return false;
}

#endif

// void oled_render_logo(void)
// {
//     static const char PROGMEM crkbd_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//         0};
//     oled_write_P(crkbd_logo, false);
// }

// #include "./animation/crab.c"

// static void oled_render_wpm(void) {
//   static char wpm_str[4];

//   sprintf(wpm_str, "%03d", get_current_wpm());
//   oled_set_cursor(0, 1);
//   oled_write_P(PSTR("WPM: "), false);
//   oled_set_cursor(5, 1);
//   oled_write(wpm_str, false);
// }
