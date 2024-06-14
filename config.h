#pragma once

#define EE_HANDS

#define QUICK_TAP_TERM 125 
#define TAPPING_TERM 130
#define TAPPING_TOGGLE 3
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define PERMISSIVE_HOLD

#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LAYERS_RETAIN_VAL
// #define RGB_DISABLE_TIMEOUT 10000
#endif

#ifdef OLED_ENABLE
#define OLED_FONT_H "keyboards/crkbd/keymaps/grzegorzkiselev/glcdfont.c"
#define OLED_TIMEOUT 60000
#endif

// /* animation */
// #define OLED_UP DATE_PROCESS_LIMIT 2
// #define SPLIT_WPM_ENABLE
// /* noitamina */
// /* optimization */
// #define NO_ACTION_MACRO
// #define NO_ACTION_FUNCTION
// /* noitazimitpo */