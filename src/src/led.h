#pragma once

void led_on(long pin);
void led_off(long pin);
void led_blink(long pin, int interval);
void led_flash_block(long pin, int interval);
void led_flash_err_block(long pin);
void led_all_off();
