#include "global.h"
#include "pins.h"

namespace Global {
    Segment seg;
    Button btn;
    Mq3 mq3;
    void setup() {
        seg.setup(Pins::segPins);
        btn.setup(BUTTON_PIN);
        mq3.setup(SIGNAL_MQ3_PIN, HEATER_MQ3_PIN);
    }
}