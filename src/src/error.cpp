#include <Arduino.h>
#include "global.h"
#include "pins.h"

void error(const char* msg) {
	Serial.println(msg);
	Global::seg.setE();
}

void error(const char* msg, const char *arg) {
	Serial.print(msg);
	Serial.println(arg);
	Global::seg.setE();
}

void debug(const char* msg) {
#ifdef MY_DEBUG
	Serial.println(msg);
#endif
}

void debug(const char* msg, const char *arg) {
#ifdef MY_DEBUG
	Serial.print(msg);
	Serial.println(arg);
#endif 
}