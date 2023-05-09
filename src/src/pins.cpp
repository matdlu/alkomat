#include "pins.h"
#include "Arduino.h"

namespace Pins {
    SegmentPins segPins;

    void pinModeSink(int pin) {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }

    void setup() {
        // setup LED
        pinMode(BUILTIN_LED_PIN, OUTPUT);
        digitalWrite(BUILTIN_LED_PIN, HIGH);
        pinMode(GREEN_LED_PIN, OUTPUT);
        pinMode(YELLOW_LED_PIN, OUTPUT);
        pinMode(RED_LED_PIN, OUTPUT);
        pinMode(BUTTON_PIN, INPUT_PULLUP);

        // setup segment
        segPins.a = A_SEG_PIN;
        segPins.b = B_SEG_PIN;
        segPins.c = C_SEG_PIN;
        segPins.d = D_SEG_PIN;
        segPins.e = E_SEG_PIN;
        segPins.f = F_SEG_PIN;
        segPins.g = G_SEG_PIN;
        segPins.dt = DT_SEG_PIN;
        segPins.digits_n = 2;
        segPins.digits[0] = DIGIT1_SEG_PIN;
        segPins.digits[1] = DIGIT2_SEG_PIN;
    }
}