
// !!! DO NOT ADD #pragma once !!! //
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include "color.h"
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(JSTATIC)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool val_in_list(uint8_t color_set[], uint8_t color_set_size, uint8_t val) {
        for(uint8_t led_idx = 0; led_idx < color_set_size; led_idx++){
            if(color_set[led_idx] == val){
                return true;
            }
        }
        return false;
    }

// e.g: A simple effect, self-contained within a single method
static bool JSTATIC(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  uint8_t color_set1 [] = {
    1, 2, 3, 4, 9, 10, 11, 12,
    19,                        32,33,34,35,36,
    37,                        50,
    54,                                    70,
    71,                        82,
    87, 88, 89,        91, 92, 93,         99

  };
  uint8_t color_set1_size = sizeof(color_set1) / sizeof(uint8_t);

  RGB color1;
  color1.r = 0;
  color1.g = 255;
  color1.b = 255;

  uint8_t color_set2 [] = { 0, 13, 14, 66};
  uint8_t color_set2_size = sizeof(color_set2) / sizeof(uint8_t);

  RGB color2;
  color2.r = 255;
  color2.g = 0;
  color2.b = 0;

//   uint8_t color_set3 [] = { 0, 18 };
//   uint8_t color_set3_size = sizeof(color_set3) / sizeof(uint8_t);

  RGB color3;
  color3.r = 0;
  color3.g = 0;
  color3.b = 25;


  for (uint8_t i = 0; i < 100; i++) {

    if (val_in_list(color_set1, color_set1_size, i)){
        rgb_matrix_set_color(i, color1.r, color1.g, color1.b);
    } else if (val_in_list(color_set2, color_set2_size, i)){
        rgb_matrix_set_color(i, color2.r, color2.g, color2.b);
    } else {
        rgb_matrix_set_color(i, color3.r, color3.g, color3.b);
    }


}

  return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS;
