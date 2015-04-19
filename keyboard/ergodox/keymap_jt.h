static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(  // layer 0 : default
        // left hand
        //
        // BSLS
        // QUOT
        // MINS
        //
        // LBRC RBRC
        ESC,    1,    2,   3,   4,   5,   EQL,
        TAB,    Q,    W,   E,   R,   T,   FN2,
        LCTL,   A,    S,   D,   F,   G,
        LSFT,   Z,    X,   C,   V,   B,   FN1,
        LGUI, GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 FN5,DEL, END,
                                 
                                 
        // right hand
             FN3, 6,   7,   8,   9,   0,   BSPC,
             NO,  Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,   SCLN, ENT,
             FN1, N,   M,   COMM,DOT, SLSH,RSFT,
                       LEFT,DOWN,UP,  RGHT,RGUI,
        RALT,RCTL,
        PGUP,
        PGDN,ENT, FN6
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  LEFT,DOWN,UP  ,RGHT,QUOT,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        FN0, NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,
                                      NO  ,NO  ,
                                           NO  ,
                                 NO  ,NO  ,NO  ,
        // right hand
             FN4, NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                  NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
                       NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,
        NO  ,
        NO  ,NO  ,NO  
    ),

    KEYMAP(  // layer 3: numpad
        // left hand
        NO  ,NO  ,  PSLS,PAST,PAST,PMNS,BSPC,
        NO  ,NO  ,  P7,  P8,  P9,NO  ,NO  ,
        NO  ,NO  ,  P4,  P5,  P6,NO  ,
        NO  ,NO  ,  P1,  P2,  P3,PENT,NO  ,
        NO  ,NO  ,  P0,PDOT,SLSH,
                                      NO  ,NO  ,
                                           NO  ,
                                 PENT,NO  ,NO  ,
        // right hand
            FN3 ,NO,PSLS,PAST,PAST,PMNS,BSPC,
             NO  ,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             NO  ,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        NO  ,NO  ,
        NO  ,
        NO  ,NO  ,NO  
    ),

};

/* id for user defined functions */
enum function_id {
    TEENSY_KEY,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(TEENSY_KEY),                    // Teensy key
    [1] = ACTION_LAYER_MOMENTARY(1),                      // switch to Layer1
    [2] = ACTION_LAYER_SET(2, ON_PRESS),                  // set Layer2
    [3] = ACTION_LAYER_TOGGLE(3),                         // toggle Layer3 aka Numpad layer
    [4] = ACTION_LAYER_SET(0, ON_PRESS),                  // set Layer0
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_SPC),          // Space and LGUI
    [6] = ACTION_LAYER_TAP_KEY(1, KC_SPC),                // momentary Layer4 on A key, to use with unconvenient keys
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == TEENSY_KEY) {
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}




