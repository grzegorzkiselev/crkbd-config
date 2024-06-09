#include QMK_KEYBOARD_H

enum crkbd_layers
{
    BASE,
    NUMBERS,
    FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, MT(MOD_LSFT,KC_F19), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RSFT, KC_QUOT), KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_RGUI, MO(2)),
	[NUMBERS] = LAYOUT_split_3x6_3(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, MT(MOD_RSFT, KC_BSLS), KC_LCTL, KC_GRV, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_NO, KC_NO),
	[FN] = LAYOUT_split_3x6_3(KC_BRID, KC_BRIU, KC_NO, KC_NO, BL_DOWN, BL_UP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO)
};

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
        oled_write_ln_P(PSTR("NUMBERS"), false);
        break;
    case 2:
        oled_write_ln_P(PSTR("FN"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undef"), false);
        break;
    }
}

bool oled_task_user(void)
{
    if (is_keyboard_master())
    {
        oled_render_layer_state();
    }
    return false;
}

#endif
