#include "Button.h"

void Button_init(Button *btn, uint8_t pin) {
    btn->btnPin = pin;
    btn->state = HIGH; // Standardmäßig HIGH (Pull-Up)
    btn->buttonClickedMs = 0;
//    pinMode(pin, INPUT_PULLUP);
    pinMode(pin, INPUT);
}

uint8_t Button_check(Button *btn) {
    uint8_t result = 0;
    uint8_t prevState = btn->state;
    btn->state = digitalRead(btn->btnPin);

    if (prevState == HIGH && btn->state == LOW) { // Gedrückt (fallende Flanke)
        btn->buttonClickedMs = millis();
    } 
    else if (prevState == LOW && btn->state == HIGH) { // Losgelassen (steigende Flanke)
        uint32_t elapsed = millis() - btn->buttonClickedMs;

        if (elapsed < 50) {
            result = 0; // Entprellen
        } 
        else if (elapsed >= 50 && elapsed < 1000) {
            result = 1; // Kurzer Klick
        } 
        else if (elapsed >= 1000) {
            result = 2; // Langer Klick
        }
    }

    return result;
}
