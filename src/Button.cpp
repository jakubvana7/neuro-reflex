#include "Button.h"

Button::Button(int pin) : pin(pin) {}

void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return digitalRead(pin) == LOW;
}

void Button::waitForRelease() {
    while (isPressed()) {
        delay(10);
    }
    delay(50);
}

void Button::waitForPress() {
    while (!isPressed()) {
    }
}
