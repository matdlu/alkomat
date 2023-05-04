#include "btn.h"
#include "Arduino.h"
#include "pins.h"

static int lastState = LOW;
static int currentState = LOW;
static long pressedTime = 0;
static long releasedTime = 0;

namespace Btn {
    bool shortPress() {
        bool value = false;
        currentState = digitalRead(BUTTON_PIN);
        if(lastState == HIGH && currentState == LOW) {
            pressedTime = millis();
        } else if(lastState == LOW && currentState == HIGH) { 
            releasedTime = millis();
            long pressDuration = releasedTime - pressedTime;
            if( pressDuration < 500 ) {
                value = true;
            }
        }	
        lastState = currentState;
        return value;
    }
}