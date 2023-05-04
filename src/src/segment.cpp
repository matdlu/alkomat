#include "segment.h"
#include "Arduino.h"
#include "pins.h"
#include "error.h"

// for common anode display diodes
#define SEG_ON LOW
#define SEG_OFF HIGH

namespace Segment {
    void showDigit1(bool value) { 
        pinMode(DIGIT1_SEG_PIN, OUTPUT);
        digitalWrite(DIGIT1_SEG_PIN, value ? HIGH : LOW);
    }

    void showDigit2(bool value) {
        digitalWrite(DIGIT2_SEG_PIN, value ? HIGH : LOW);
    }

    void setDot(bool value) {
        digitalWrite(DT_SEG_PIN, value ? SEG_ON : SEG_OFF);
    }

    void setSegment(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
        digitalWrite(A_SEG_PIN, a ? SEG_ON : SEG_OFF);
        digitalWrite(B_SEG_PIN, b ? SEG_ON : SEG_OFF);
        digitalWrite(C_SEG_PIN, c ? SEG_ON : SEG_OFF);
        digitalWrite(D_SEG_PIN, d ? SEG_ON : SEG_OFF);
        digitalWrite(E_SEG_PIN, e ? SEG_ON : SEG_OFF);
        digitalWrite(F_SEG_PIN, f ? SEG_ON : SEG_OFF);
        digitalWrite(G_SEG_PIN, g ? SEG_ON : SEG_OFF);
    }

    /* 0 - 9*/
    void setDigit(unsigned short digit) {
        switch (digit)
        {
        case 0:
            setSegment(true, true, true, true, true, true, false);
            break;
        case 1:
            setSegment(false, true, true, false, false, false, false);
            break;
        case 2:
            setSegment(true, true, false, true, true, false, true);
            break;
        case 3:
            setSegment(true, true, true, true, false, false, true);
            break;
        case 4:
            setSegment(false, true, true, false, false, true, true);
            break;
        case 5:
            setSegment(true, false, true, true, false, true, true);
            break;
        case 6:
            setSegment(true, false, true, true, true, true, true);
            break;
        case 7:
            setSegment(true, true, true, false, false, false, false);
            break;
        case 8:
            setSegment(true, true, true, true, true, true, true);
            break;
        case 9:
            setSegment(true, true, true, true, false, true, true);
            break;
        default:
            error("Segment error, digit larger than 9 or smaller than 0.");
            return;
        }
    }

    void setE() {
        setSegment(true, false, false, true, true, true, true);
        showDigit1(true);
        showDigit2(false);
        setDot(false);
    }

    void clear() {
        digitalWrite(A_SEG_PIN, HIGH);
        digitalWrite(B_SEG_PIN, HIGH);
        digitalWrite(F_SEG_PIN, HIGH);
        digitalWrite(C_SEG_PIN, HIGH);
        digitalWrite(DT_SEG_PIN, HIGH);
        digitalWrite(E_SEG_PIN, HIGH);
        digitalWrite(D_SEG_PIN, HIGH);
        digitalWrite(G_SEG_PIN, HIGH);
    }

    long segment_time = 0;
    long segment_loading_step = 0;

    void loading(unsigned int interval) {
        if ( segment_time == 0 ) {
            segment_time = millis();
            showDigit2(true);
            showDigit1(true);
            setDot(false);
            switch(segment_loading_step) {
            case 0:
                setSegment(false, false, false, false, false, false, true);
                break;
            case 1:
                setSegment(false, false, true, false, false, false, false);
                break;
            case 2:
                setSegment(false, false, false, true, false, false, false);
                break;
            case 3:
                setSegment(false, false, false, false, true, false, false);
                break;
            }
            segment_loading_step++;
            if ( segment_loading_step >= 4 ) {
                segment_loading_step = 0;
            } 
        } else if ((millis() - segment_time) > interval) {
            segment_time = 0;
        } 
    }
    
#ifdef SEGMENT_DEMO
    void demo() {
        Segment::showDigit1(true);
        Segment::showDigit1(true);
        Segment::setDot(true);
        for(int i = 0; i < 10; i++) {
            Segment::setDigit(i);
            delay(1000);
        }
    }
#endif
}