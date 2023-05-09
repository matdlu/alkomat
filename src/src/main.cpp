#include "Arduino.h"
#include "pins.h"
#include "led.h"
#include "global.h"
#include "Timer.h"

using namespace Global;

void setup()
{
	Serial.begin(9600);
	Pins::setup();
	Global::setup();
	analogReadResolution(12);
	delay(1000);
}

enum State {
	SLEEP,
	READY,
	HEATING,
	BLOW_READY,
	RESULT
};

#define HEATING_TIME 10000 //120000
Timer heatingTimer;

const int read_n = 100;
long read_sum = 0; 
long read_avg = 0;

int lastState = SLEEP;
int state = SLEEP;
void changeState(State newState) {
	lastState = state;
	state = newState;
}

void cleanState() { // clean only once
	if ( lastState != state ) {
		led_all_off();
		seg.clear();
		lastState = state;
		// stop timers
		heatingTimer.stop();
	}
}

short firstDigit(int number) {
	while(number >= 10)
	{
		number = number / 10;
	}
	return number;
}

void loop()
{
	switch ( state ) 
	{
	case SLEEP:
		cleanState();
		if ( btn.shortReleased() ) {
			changeState(READY);
		}
		mq3.turnOff();
		break;
	case READY:
		cleanState();
		if ( btn.shortReleased() ) {
			changeState(HEATING);
		}
		led_on(GREEN_LED_PIN);
		mq3.turnOn();
		break;
	case HEATING:
		cleanState();
		mq3.turnOn();
		seg.loading(250);
		led_blink(YELLOW_LED_PIN, 500);
		if ( heatingTimer.available(HEATING_TIME) ) {
			mq3.calibrate();
			changeState(BLOW_READY);
		}
		break;
	case BLOW_READY:
		cleanState();
		led_on(RED_LED_PIN);
		if ( btn.shortReleased() ) {
			for(int i = 0; i < read_n; i++) {
				read_sum += mq3.read();
				led_off(RED_LED_PIN);
				delay(25);
				led_on(RED_LED_PIN);
				delay(25);
			}
			read_avg = read_sum / read_n;
			read_sum = 0;
			changeState(RESULT);
		}
		break;
	case RESULT:
		cleanState();
		int permille = mq3.permille(read_avg);
		if ( permille < 200 ) {
			led_on(GREEN_LED_PIN);
		} else if ( permille < 250 ) {
			led_on(YELLOW_LED_PIN);
		} else {
			led_on(RED_LED_PIN);
		}
		seg.displayNumber(permille, 500, 1500);
		if ( btn.shortReleased() ) {
			changeState(SLEEP);
		}
		break;
	}
}
