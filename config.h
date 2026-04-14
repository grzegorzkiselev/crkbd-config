#pragma once

#define EE_HANDS

#define TAPPING_TERM 140
#define HOLD_ON_OTHER_KEY_PRESS
# Нужно для правильной обработки смены языка по тапу на F18 на macOS
#define TAP_CODE_DELAY 5

#ifdef OLED_ENABLE
#define OLED_FONT_H "keyboards/crkbd/keymaps/grzegorzkiselev/glcdfont.c"
#define OLED_TIMEOUT 60000
#endif