#include "Arduino.h"
#include "pins.h"

namespace Pins {
    void pinModeSink(int pin) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void setupSegment() {
        pinMode(DIGIT1_SEG_PIN, OUTPUT);
        digitalWrite(DIGIT1_SEG_PIN, LOW);
        pinMode(DIGIT2_SEG_PIN, OUTPUT);
        digitalWrite(DIGIT2_SEG_PIN, LOW);
        pinModeSink(A_SEG_PIN);
        pinModeSink(B_SEG_PIN);
        pinModeSink(F_SEG_PIN);
        pinModeSink(C_SEG_PIN);
        pinModeSink(DT_SEG_PIN);
        pinModeSink(E_SEG_PIN);
        pinModeSink(D_SEG_PIN);
        pinModeSink(G_SEG_PIN);
    }

    void setup() {
        pinMode(BUILTIN_LED_PIN, OUTPUT);
        digitalWrite(BUILTIN_LED_PIN, HIGH);
        pinMode(GREEN_LED_PIN, OUTPUT);
        pinMode(YELLOW_LED_PIN, OUTPUT);
        pinMode(RED_LED_PIN, OUTPUT);
        pinMode(BUTTON_PIN, INPUT_PULLUP);
        setupSegment();
    }
}