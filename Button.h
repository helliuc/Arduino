#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

typedef struct {
    uint8_t btnPin;
    uint8_t state;
    uint32_t buttonClickedMs;
} Button;

void Button_init(Button *btn, uint8_t pin);
uint8_t Button_check(Button *btn);

#endif
