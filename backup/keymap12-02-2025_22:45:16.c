#include QMK_KEYBOARD_H

enum crkbd_layers {
    BASE,
    NAVIGATION,
    NUMBERS,
    FN,
};

const uint16_t PROGMEM right_shift[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM left_space[] = {KC_B, KC_LGUI, COMBO_END};
const uint16_t PROGMEM fn_left[] = {MO(2), KC_B, COMBO_END};

combo_t key_combos[] = {
    COMBO(right_shift, KC_RSFT),
    COMBO(left_space, KC_SPC),
    COMBO(fn_left, MO(3)),
};

// enum tap_dance_codes {
//     NUM_NAV_FN,
//     NAV_NUM_FN,
//     SPC_GUI,
//     GUI_SPC
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_split_3x6_3(
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_TAB,             KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,                                                    KC_Y,               KC_U,                KC_I,            KC_O,            KC_P,              KC_LBRC,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_LSFT,            KC_A,         KC_S,         KC_D,         KC_F,          KC_G,                                                    KC_H,               KC_J,                KC_K,            KC_L,          KC_SCLN,             KC_QUOT,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
    MT(MOD_LCTL, KC_F18),      KC_Z,         KC_X,         KC_C,         KC_V,          KC_B,                                                    KC_N,               KC_M,              KC_COMM,          KC_DOT,         KC_SLSH,             KC_RBRC,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
                                                                        KC_LALT,      KC_LGUI,          MO(2),                  MO(1),          KC_SPC,             KC_BSLS                                                                                     
),
[NAVIGATION] = LAYOUT_split_3x6_3(
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
            KC_NO,            KC_BSPC,      KC_ESC,        KC_UP,       KC_DEL,        KC_NO,                                                    KC_NO,             KC_BSPC,             KC_UP,           KC_ESC,          KC_DEL,              KC_NO,          
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_LSFT,           KC_ENT,       KC_LEFT,      KC_DOWN,      KC_RGHT,       KC_NO,                                                    KC_NO,             KC_LEFT,            KC_DOWN,         KC_RGHT,          KC_ENT,             KC_RSFT,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_LCTL,           KC_BRID,      KC_BRIU,      RGB_HUD,      RGB_SAD,      RGB_VAD,                                                  KC_MPRV,            KC_MPLY,            KC_MNXT,         KC_MUTE,         KC_VOLD,             KC_VOLU,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
                                                                        KC_LALT,       KC_LGUI,         MO(3),                 KC_TRNS,         KC_RGUI,            KC_RALT                                                                                    
),
[NUMBERS] = LAYOUT_split_3x6_3(
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
         LSFT(KC_1),        LSFT(KC_2),   LSFT(KC_3),   LSFT(KC_4),   LSFT(KC_5),    LSFT(KC_6),                                              RSFT(KC_7),         RSFT(KC_8),          RSFT(KC_9),      RSFT(KC_0),    RSFT(KC_MINS),        RSFT(KC_EQL),      
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
            KC_1,              KC_2,         KC_3,         KC_4,         KC_5,          KC_6,                                                    KC_7,               KC_8,                KC_9,            KC_0,          KC_MINS,              KC_EQL,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_LCTL,           KC_LSFT,      KC_GRV,        KC_NO,        KC_NO,        KC_NO,                                                LSA(KC_LBRC),       LSA(KC_RBRC),       LALT(KC_LBRC),   LALT(KC_RBRC),       KC_NO,              KC_RCTL,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
                                                                        KC_LALT,       KC_RGUI,        KC_TRNS,                  MO(3),         KC_RGUI,      MT(MOD_RALT, KC_BSLS)                                                                             
),
[FN] = LAYOUT_split_3x6_3(
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
        QK_BOOTLOADER,        KC_BTN3,      KC_BTN2,      KC_MS_U,       KC_NO,       KC_WH_U,                                                  KC_WH_U,            TG(FN),             KC_MS_U,         KC_BTN2,         KC_BTN3,         KC_SYSTEM_SLEEP,     
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
           KC_LSFT,           KC_BTN1,      KC_MS_L,      KC_MS_D,      KC_MS_R,      KC_WH_D,                                                  KC_WH_D,            KC_MS_L,            KC_MS_D,         KC_MS_R,         KC_BTN1,             KC_RSFT,         
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
     MT(MOD_LCTL, KC_F1),      KC_F2,        KC_F3,        KC_F4,        KC_F5,        KC_F6,                                                    KC_F7,              KC_F8,              KC_F9,           KC_F10,          KC_F11,       MT(MOD_RCTL, KC_F12),  
//|:---------------------:|:-----------:|:-----------:|:-----------:|:-----------:|:------------:|:---------------:|:---:|:---------------:|:-------------:|:---------------------:|:--------------:|:--------------:|:--------------:|:----------------------:|
                                                                        KC_LALT,      KC_RGUI,         KC_TRNS,                KC_TRNS,          KC_RGUI,    MT(MOD_RALT, KC_BSLS)                                                                              
)
};

// extern bool g_suspend_state;

// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;

// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MT(MOD_RGUI, KC_BSLS):
//         case MT(MOD_RCTL, KC_VOLU): 
//         case MT(MOD_RCTL, KC_RBRC):
//         case MT(MOD_LSFT, KC_F18):
//             return false;
//         default:
//             return true;
//     }
// }

// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_TAP,
//     DOUBLE_HOLD,
//     TRIPPLE_TAP,
//     TRIPPLE_HOLD,
//     MOD_HOLD,
// };

// static tap dance_state = {
//     .is_press_action = true,
//     .step = 0
// };

// /* NUM_NAV_FN */
// void on_NUM_NAV_FN(tap_dance_state_t *state, void *user_data);
// uint8_t NUM_NAV_FN_dance_step(tap_dance_state_t *state);
// void NUM_NAV_FN_finished(tap_dance_state_t *state, void *user_data);
// void NUM_NAV_FN_reset(tap_dance_state_t *state, void *user_data);

// void on_NUM_NAV_FN(tap_dance_state_t *state, void *user_data) {};

// uint8_t NUM_NAV_FN_dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->pressed || !state->interrupted) return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->pressed || !state->interrupted) return DOUBLE_HOLD;
//     } else if (state->count == 3) {
//         if (state->pressed || !state->interrupted) return TRIPPLE_HOLD;
//     }
//     return SINGLE_HOLD;
// }

// void NUM_NAV_FN_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state.step = NUM_NAV_FN_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_HOLD: layer_move(NUMBERS); break;
//         case DOUBLE_HOLD: layer_move(NAVIGATION); break;
//         case TRIPPLE_HOLD: layer_move(FN); break;
//     }
// }

// void NUM_NAV_FN_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     layer_move(0);
//     dance_state.step = 0;
// }

// /* NAV_NUM_FN */
// void on_NAV_NUM_FN(tap_dance_state_t *state, void *user_data);
// uint8_t NAV_NUM_FN_dance_step(tap_dance_state_t *state);
// void NAV_NUM_FN_finished(tap_dance_state_t *state, void *user_data);
// void NAV_NUM_FN_reset(tap_dance_state_t *state, void *user_data);

// void on_NAV_NUM_FN(tap_dance_state_t *state, void *user_data) {};

// uint8_t NAV_NUM_FN_dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->pressed || !state->interrupted) return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->pressed || !state->interrupted) return DOUBLE_HOLD;
//     } else if (state->count == 3) {
//         if (state->pressed || !state->interrupted) return TRIPPLE_HOLD;
//     }
//     return SINGLE_HOLD;
// }

// void NAV_NUM_FN_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state.step = NAV_NUM_FN_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_HOLD: layer_move(NAVIGATION); break;
//         case DOUBLE_HOLD: layer_move(NUMBERS); break;
//         case TRIPPLE_HOLD: layer_move(FN); break;
//     }
// }

// void NAV_NUM_FN_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     layer_move(0);
//     dance_state.step = 0;
// }

// /* CMD_SPC */
// void on_GUI_SPC(tap_dance_state_t *state, void *user_data);
// uint8_t GUI_SPC_dance_step(tap_dance_state_t *state);
// void GUI_SPC_finished(tap_dance_state_t *state, void *user_data);
// void GUI_SPC_reset(tap_dance_state_t *state, void *user_data);

// void on_GUI_SPC(tap_dance_state_t *state, void *user_data) {};

// uint8_t GUI_SPC_dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (!state->pressed || state->interrupted) return SINGLE_TAP;
//     } else if (state->count == 2) {
//         return DOUBLE_TAP;
//     }
//     return SINGLE_TAP;
// }

// void GUI_SPC_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state.step = GUI_SPC_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_TAP: register_code16(KC_LGUI); break;
//         case DOUBLE_TAP: register_code16(KC_SPC); break;
//     }
// }

// void GUI_SPC_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     unregister_code16(KC_LGUI);
//     unregister_code16(KC_SPC); 
//     dance_state.step = 0;
// }

// /* SPC_GUI */
// void on_SPC_GUI(tap_dance_state_t *state, void *user_data);
// uint8_t SPC_GUI_dance_step(tap_dance_state_t *state);
// void SPC_GUI_finished(tap_dance_state_t *state, void *user_data);
// void SPC_GUI_reset(tap_dance_state_t *state, void *user_data);

// void on_SPC_GUI(tap_dance_state_t *state, void *user_data) {};

// uint8_t SPC_GUI_dance_step(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->pressed) return SINGLE_HOLD;
//         return SINGLE_TAP;
//     } else if (
//         state->count == 2
//         && state->pressed
//     ) {
//         return DOUBLE_HOLD;
//     }
//     return SINGLE_TAP;
// }

// void SPC_GUI_finished(tap_dance_state_t *state, void *user_data) {
//     dance_state.step = SPC_GUI_dance_step(state);
//     switch (dance_state.step) {
//         case SINGLE_TAP:
//         case SINGLE_HOLD: register_code16(KC_SPC); break;
//         case DOUBLE_HOLD: register_code16(KC_RGUI); break;
//     }
// }

// void SPC_GUI_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     unregister_code16(KC_SPC);
//     unregister_code16(KC_RGUI);
//     dance_state.step = 0;
// }

// tap_dance_action_t tap_dance_actions[] = {
//     [NAV_NUM_FN] = ACTION_TAP_DANCE_FN_ADVANCED(on_NAV_NUM_FN, NAV_NUM_FN_finished, NAV_NUM_FN_reset),
//     [NUM_NAV_FN] = ACTION_TAP_DANCE_FN_ADVANCED(on_NUM_NAV_FN, NUM_NAV_FN_finished, NUM_NAV_FN_reset),
//     [GUI_SPC] = ACTION_TAP_DANCE_FN_ADVANCED(on_GUI_SPC, GUI_SPC_finished, GUI_SPC_reset),
//     [SPC_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(on_SPC_GUI, SPC_GUI_finished, SPC_GUI_reset),
// };

#ifdef OLED_ENABLE

/* LAYER */
void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
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
    }
}
/* REYAL */

/* MODIFIERS */
void render_mod_status(void) {
    const uint8_t modifiers = get_mods() | get_oneshot_mods();

    if (modifiers & MOD_MASK_SHIFT) { oled_write_P(PSTR("SFT "), false); }
    if (modifiers & MOD_MASK_CTRL) { oled_write_P(PSTR("CTRL "), false); }
    if (modifiers & MOD_MASK_ALT) { oled_write_P(PSTR("OPT "), false); }
    if (modifiers & MOD_MASK_GUI) { oled_write_P(PSTR("CMD "), false); }

    oled_write_ln_P(PSTR(" "), false);
}
/* SREIFIDOM */

/* LOGO */
void oled_render_logo(void) {
   static const char PROGMEM crkbd_logo[] = {
       0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
       0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
       0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
       0};
   oled_write_P(crkbd_logo, false);
}
/* OGOL */

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        render_mod_status();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif