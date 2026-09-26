#include "Display.h"

bool Display::begin() {
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        return false;
    }
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 0);
    return true;
}

void Display::showText(const char* text, int x, int y){
    oled.setCursor(x, y);
    oled.println(text);
    oled.display();
}

void Display::clear() {
    oled.clearDisplay();
    oled.display();
}

void Display::showResult
