#include <Arduino.h>

const int LED_PIN = 8;
const int BUTTON_PIN = 7;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    randomSeed(analogRead(0));
}

void loop() {
    while (digitalRead(BUTTON_PIN) == LOW) {
     // Wait for button release
    }
    delay(50);
    
    unsigned long randomNumber = random(1000, 5000);
    unsigned long waitStart = millis();

    while (millis() - waitStart < randomNumber) {
        if (digitalRead(BUTTON_PIN) == LOW){
            Serial.println("Too soon! Wait for the LED to turn on.");
            return;
        }
    }
    
    digitalWrite(LED_PIN, HIGH);

    unsigned long time = millis();

    while (digitalRead(BUTTON_PIN) == HIGH) {

    }

    unsigned long reactionTime = millis() - time;

    digitalWrite(LED_PIN, LOW);

    Serial.print("Reaction Time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");

}
