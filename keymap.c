#include QMK_KEYBOARD_H

const uint16_t PROGMEM space_left[] = {KC_LGUI, KC_B, COMBO_END};
const uint16_t PROGMEM cmd_right[] = {KC_SPC, KC_N, COMBO_END};
const uint16_t PROGMEM navigation_left[] = {MO(2), KC_LGUI, COMBO_END};
const uint16_t PROGMEM numbers_right[] = {MO(1), KC_SPC, COMBO_END};
const uint16_t PROGMEM fn_left[] = {KC_LALT, KC_V, COMBO_END};
const uint16_t PROGMEM fn_right[] = {MT(MOD_RALT, KC_BSLS), KC_M, COMBO_END};

combo_t key_combos[] = {
    COMBO(space_left, KC_SPC),
    COMBO(cmd_right, KC_RGUI),
    COMBO(numbers_right, MO(2)),
    COMBO(navigation_left, MO(1)),
    COMBO(fn_left, MO(3)),
    COMBO(fn_right, MO(3)),
};

enum crkbd_layers {
    BASE,
    NAVIGATION,
    NUMBERS,
    FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE]       = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, MT(MOD_RSFT, KC_QUOT), MT(MOD_LCTL, KC_F18), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RCTL, KC_RBRC), MT(MOD_LALT, KC_GRV), KC_LGUI, MO(2), MO(1), KC_SPC, MT(MOD_RALT, KC_BSLS)),
[NAVIGATION] = LAYOUT_split_3x6_3(KC_TAB, KC_BSPC, KC_ESC, KC_UP, KC_DEL, KC_NO, KC_NO, KC_BSPC, KC_UP, KC_ESC, KC_DEL, KC_TAB, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT, KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_RSFT, KC_LCTL, KC_BRID, KC_BRIU, UG_HUED, UG_SATD, UG_VALD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, MT(MOD_RCTL, KC_VOLU), KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_RGUI, MT(MOD_RALT, KC_BSLS)),
[NUMBERS]    = LAYOUT_split_3x6_3(LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), RSFT(KC_7), RSFT(KC_8), RSFT(KC_9), RSFT(KC_0), RSFT(KC_MINS), RSFT(KC_EQL), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RCTL, KC_LALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_RGUI, MT(MOD_RALT, KC_BSLS)),
[FN]         = LAYOUT_split_3x6_3(QK_BOOTLOADER, MS_BTN3, MS_BTN2, MS_UP, KC_NO, MS_WHLU, MS_WHLU, KC_NO, MS_UP, MS_BTN2, MS_BTN3, KC_SLEP, KC_LSFT, MS_BTN1, MS_LEFT, MS_DOWN, MS_RGHT, MS_WHLD, MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, MS_BTN1, KC_RSFT, MT(MOD_LCTL, KC_F1), KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, MT(MOD_RCTL, KC_F12), KC_LALT, KC_RGUI, KC_TRNS, KC_TRNS, KC_RGUI, MT(MOD_RALT, KC_BSLS))
};

#ifdef CONSOLE_ENABLE
    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        uprintf("kc=0x%04X %s t=%u\n", keycode, record->event.pressed ? "DN" : "UP", record->event.time);
        return true;
    }
#endif

#ifdef OLED_ENABLE
    void oled_render_layer_state(void) {
        switch (get_highest_layer(layer_state)) {
            case BASE:
                oled_write_ln_P(PSTR(""), false);
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
        }
    }

    void render_mod_status(void) {
        const uint8_t modifiers = get_mods() | get_oneshot_mods();

        if (modifiers & MOD_MASK_SHIFT) { oled_write_P(PSTR("SFT "), false); }
        if (modifiers & MOD_MASK_CTRL) { oled_write_P(PSTR("CTRL "), false); }
        if (modifiers & MOD_MASK_ALT) { oled_write_P(PSTR("OPT "), false); }
        if (modifiers & MOD_MASK_GUI) { oled_write_P(PSTR("CMD "), false); }

        oled_write_ln_P(PSTR(" "), false);
    }

    bool oled_task_user(void) {
        if (is_keyboard_master()) {
            oled_render_layer_state();
            render_mod_status();
        }
        return false;
    }
#endif
