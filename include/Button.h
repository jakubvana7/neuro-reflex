#pragma once
#include <Arduino.h>

class Button {
    public:
        Button(int pin);
        void begin();
        bool isPressed();
        void waitForRelease();
        void waitForPress();

    private:
        int pin;
};