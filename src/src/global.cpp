#include "global.h"
#include "Segment.h"
#include "Button.h"
#include "pins.h"

namespace Global {
    Segment seg;
    Button btn;
    void setup() {
        seg.setup(Pins::segPins);
        btn.setup(BUTTON_PIN);
    }
}