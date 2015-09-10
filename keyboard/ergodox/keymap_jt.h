static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    KEYMAP(  // layer 0 : default
        // left hand
        ESC,    1,    2,   3,   4,   5,   FN2,
        TAB,    Q,    W,   E,   R,   T,   BTN1,
        LCTL,   A,    S,   D,   F,   G,
        LSFT,   Z,    X,   C,   V,   B,   BTN2,
        LALT, LEFT, DOWN,UP,RGHT,
                                      LCTL,LALT,
                                             NO,
                                 FN5,FN6  ,  NO,
                                 
        // right hand
             FN3,   6,   7,   8,   9,   0,BSPC,
             BTN1,  Y,   U,   I,   O,   P,BSLS,
                    H,   J,   K,   L,SCLN, ENT,
             BTN2,  N,   M,COMM,DOT ,SLSH,RSFT,
                       LEFT,DOWN,UP, RGHT,  NO,
        RALT,RCTL,
        NO,
        FN4, FN6, FN7
    ),
    
    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        GRV,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,   1,   2,   3,   4,   5,TRNS,
        CAPS,MINS,EQL ,LBRC,RBRC,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12 ,  F6,  F7,  F8,  F9, F10,TRNS,
             TRNS,   6,   7,   8,   9,   0,TRNS,
                  LEFT,DOWN,UP  ,RGHT,QUOT,TRNS,
             TRNS,TRNS,PGDN,PGUP,TRNS,BSLS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        FN0, NO  ,NO  ,NO  ,NO  ,NO  ,TRNS,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
        NO  ,NO  ,NO  ,NO  ,NO  ,
                                      NO  ,NO  ,
                                           NO  ,
                                 NO  ,NO  ,NO  ,
        // right hand
         NO , NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
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

    KEYMAP(  // Layer4: mouse and navigation
        // left hand
        TRNS,NO,  NO,  NO,  NO,  NO,  NO,
        TRNS,NO,  NO,  NO,  ACL0,NO,  TRNS,
        TRNS,NO,  NO,  TRNS,ACL1,NO,
        TRNS,NO,  NO,  TRNS,ACL2,NO,  TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,

        // right hand
             BTN3, NO  ,NO  ,NO  ,NO  ,NO  ,NO  ,
             BTN1, MUTE,VOLD,VOLU,NO  ,NO  ,NO  ,
                   MS_L,MS_D,MS_U,MS_R,NO  ,NO  ,
             BTN2, WH_L,WH_D,WH_U,WH_R,NO  ,NO  ,
                        TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
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
    [0] = ACTION_FUNCTION(TEENSY_KEY),
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
    [3] = ACTION_LAYER_TOGGLE(3),
    [4] = ACTION_LAYER_TOGGLE(4),
    [5] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_SPC),
    [6] = ACTION_LAYER_MOMENTARY(4),
    [7] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
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




