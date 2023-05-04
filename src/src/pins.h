#pragma once

#define BUILTIN_LED_PIN PC13
#define GREEN_LED_PIN PA1
#define YELLOW_LED_PIN PA2
#define RED_LED_PIN PA3
#define BUTTON_PIN PB1

// B5621BH segment display
// Wired from the top, left to right (except DIGIT pins)
#define DIGIT1_SEG_PIN PA11
#define DIGIT2_SEG_PIN PA12
#define A_SEG_PIN PA15 // A
#define B_SEG_PIN PB3 // B
#define F_SEG_PIN PB4 // F
#define C_SEG_PIN PB5 // C
#define DT_SEG_PIN PB6 // DT 
#define E_SEG_PIN PB7 // E
#define D_SEG_PIN PB8 // D
#define G_SEG_PIN PB9 // G

namespace Pins {
    void setup();
}
