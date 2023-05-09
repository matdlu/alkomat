#include "mq3.h"
#include "Arduino.h"
#include "pins.h"

// based on Polish BBR ratio
#define BBR 2.1

namespace Mq3 {
    void turnOn() {
        digitalWrite(HEATER_MQ3_PIN, HIGH);
    }

    void turnOff() {
        digitalWrite(HEATER_MQ3_PIN, LOW);
    }

    long offset = 0;

    void calibrate() {
        long read_n = 20;
        long read_sum = 0;
        for(int i = 0; i < read_n; i++) {
            read_sum += analogRead(SIGNAL_MQ3_PIN);
            delay(100);
        }
        offset = read_sum / read_n;
    }

    int read() {
		int read = analogRead(SIGNAL_MQ3_PIN) - offset;
        return read > 0 ? read : 0;
    }

    // convert mgl measurement to permille
    int permille(int mgl) {
        return mgl * BBR;
    }
}