#pragma once
#include <Adafruit_SSD1306.h>

class Display {
    public:
        bool begin();
        void showText(const char* text, int x, int y);
        void clear();
        void showResult(unsigned long ms);


    private:
        Adafruit_SSD1306 oled{128, 32, &Wire, -1};
};