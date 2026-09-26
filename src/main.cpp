#include <Arduino.h>
#include "Display.h"

const int LED_PIN = 8;
const int BUTTON_PIN = 7;
Display display;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    randomSeed(analogRead(0));
    display.begin();    
}

void loop() {
    while (digitalRead(BUTTON_PIN) == LOW) {
     // Wait for button release
    }
    delay(50);
    
    display.showText("Press to play", 0, 16);


    while (digitalRead(BUTTON_PIN) == HIGH) {
     // Wait for button press
    }

    while (digitalRead(BUTTON_PIN) == LOW) {
     // Wait for button release
    }
    delay(50);

    unsigned long randomNumber = random(1000, 5000);
    unsigned long waitStart = millis();
    display.clear();
    display.showText("Wait for it...", 0, 0);

    while (millis() - waitStart < randomNumber) {
        if (digitalRead(BUTTON_PIN) == LOW){
            display.clear();
            display.showText("Too soon!", 0, 0);
            return;
        }
    }
    unsigned long time = millis();
    digitalWrite(LED_PIN, HIGH);
    display.clear();
    display.showText("GO!", 0, 0);
    
    

    

    while (digitalRead(BUTTON_PIN) == HIGH) {

    }

    unsigned long reactionTime = millis() - time;

    digitalWrite(LED_PIN, LOW);
    display.showResult(reactionTime);
}
