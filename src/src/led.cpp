#include <Arduino.h>
#include "led.h"
#include "pins.h"

void led_on(long pin) {
	digitalWrite(pin, HIGH);  
}

void led_off(long pin) {
	digitalWrite(pin, LOW);
}

long led_on_time = 0;
long led_off_time = 0;

void led_blink(long pin, int interval) {
	if ( led_on_time == 0 ) {
		led_on(pin);
		led_on_time = millis();
	} else if (led_off_time == 0 && (millis() - led_on_time) > interval) {
		led_off(pin);
		led_off_time = millis();
	} else if (led_off_time != 0 && (millis() - led_off_time) > interval ) {
		led_on_time = 0;
		led_off_time = 0;
	}
}

void led_flash_block(long pin, int interval) {
	led_on(pin);
	delay(interval);
	led_off(pin);
	delay(interval);
}

void led_flash_err_block(long pin) {
	for(int i=0; i<6; i++) {
		led_flash_block(pin, 100);
	}
	delay(1000);
}

void led_all_off() {
	led_off(GREEN_LED_PIN);
	led_off(YELLOW_LED_PIN);
	led_off(RED_LED_PIN);
}
