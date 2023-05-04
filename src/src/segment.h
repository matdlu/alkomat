#pragma once

namespace Segment {
    void showDigit1(bool value);
    void showDigit2(bool value);
    void setSegment(bool a, bool b, bool c, bool d, bool e, bool f, bool g);
    void setDot(bool value);
    void setDigit(unsigned short digit);
    void setE();
    void clear();
    void loading(unsigned int interval);
#ifdef SEGMENT_DEMO
    void demo() {
#endif
}