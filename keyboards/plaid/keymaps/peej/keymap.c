#define USE_2U_SPACE 1

#include "peej.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_PEEJ(
    BASE_ROW_2,
    BASE_ROW_3,
    BASE_ROW_4,
    BASE_ROW_5
),

[_SYMBOL] = LAYOUT_PEEJ(
    SYMBOL_ROW_2,
    SYMBOL_ROW_3,
    SYMBOL_ROW_4,
    SYMBOL_ROW_5
),

[_FUNCTION] = LAYOUT_PEEJ(
    FUNCTION_ROW_2,
    FUNCTION_ROW_3,
    FUNCTION_ROW_4,
    FUNCTION_ROW_5
),

[_ADJUST] = LAYOUT_PEEJ(
    ADJUST_ROW_2,
    ADJUST_ROW_3,
    ADJUST_ROW_4,
    ADJUST_ROW_5
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    writePinLow(C4);
    writePinLow(C5);
    
    switch (biton32(state)) {
    case _FUNCTION:
        writePinHigh(C4);
        break;
    case _SYMBOL:
        writePinHigh(C5);
        break;
    case _ADJUST:
        writePinHigh(C4);
        writePinHigh(C5);
        break;
    }
  
    return state;
}
