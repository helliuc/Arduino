#include <Button.h>

Button btn1;

void setup() {
    Serial.begin(115200);
    Button_init(&btn1, 9); // Button an GPIO4
}

void loop() {
    uint8_t action = Button_check(&btn1);

    if (action == 1) {
        Serial.println("Kurzer Klick!");
    } 
    else if (action == 2) {
        Serial.println("Langer Klick!");
    }

    delay(10); // Kleine Verzögerung
}
