#include <Arduino.h>
#include <pins.h>
#include <led.h>
#include <btn.h>
#include <segment.h>

void setup()
{
	Pins::setup();
	Serial.begin(9600);
	delay(1000);
}

enum State {
	SLEEP,
	READY,
	HEATING,
	BLOW,
	RESULT
};

bool sensorReady = false;

int lastState = SLEEP;
int state = SLEEP;
void changeState(State newState) {
	lastState = state;
	state = newState;
}

void cleanState() { // clean only once
	if ( lastState != state ) {
		led_all_off();
		Segment::clear();
		lastState = state;
	}
}

void loop()
{
	switch ( state ) 
	{
	case SLEEP:
		cleanState();
		if ( Btn::shortPress() ) {
			changeState(READY);
		}
		break;
	case READY:
		cleanState();
		if ( Btn::shortPress() ) {
			changeState(HEATING);
		}
		led_on(GREEN_LED_PIN);
		break;
	case HEATING:
		cleanState();
		Segment::loading(250);
		led_blink(YELLOW_LED_PIN, 500);
		break;
	case BLOW:
		cleanState();
		led_blink(RED_LED_PIN, 100);
		break;
	case RESULT:
		cleanState();
		led_on(RED_LED_PIN);
		break;
	}
}
