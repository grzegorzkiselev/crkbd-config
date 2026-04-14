#pragma once

#define EE_HANDS

#define QUICK_TAP_TERM 0
#define TAPPING_TERM 125
#define PERMISSIVE_HOLD

#ifdef RGBLIGHT_ENABLE
#undef RGBLED_NUM
#define RGBLED_NUM 27
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17
#define RGBLIGHT_LIMIT_VAL 120
#define RGBLIGHT_SLEEP
#define RGBLIGHT_SPLIT
#define RGBLIGHT_LAYERS
#endif

// #define OLED_FONT_H "./custom-logo/glcdfont.c"
