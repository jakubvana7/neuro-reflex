#include <Arduino.h>
#include "Display.h"
#include "Button.h"

const int LED_PIN = 8;
const int BUTTON_PIN = 7;
Display display;
Button button(BUTTON_PIN);

void setup() {
    if (!display.begin()){
        Serial.println("OLED not found!");
        while (true) {}
    }

    pinMode(LED_PIN, OUTPUT);
    Serial.begin(115200);
    randomSeed(analogRead(0));
    display.begin();    
    button.begin();
}

 void loop() {
    button.waitForRelease();

    display.showText("Press to play", 0, 16);

    button.waitForPress();

    button.waitForRelease();

    unsigned long randomNumber = random(1000, 5000);
    unsigned long waitStart = millis();
    display.clear();
    display.showText("Wait for it...", 0, 0);

    while (millis() - waitStart < randomNumber) {
        if (button.isPressed()) {
            display.clear();
            display.showText("Too soon!", 0, 0);
            return;
        }
    }

    unsigned long time = millis();
    digitalWrite(LED_PIN, HIGH);
    display.clear();
    display.showText("GO!", 0, 0);

    button.waitForPress();

    unsigned long reactionTime = millis() - time;

    digitalWrite(LED_PIN, LOW);
    display.showResult(reactionTime);
}