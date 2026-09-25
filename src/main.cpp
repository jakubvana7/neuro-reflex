#include <Arduino.h>
#include <Adafruit_SSD1306.h>

const int LED_PIN = 8;
const int BUTTON_PIN = 7;
Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    Serial.begin(115200);
    randomSeed(analogRead(0));
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

void loop() {
    while (digitalRead(BUTTON_PIN) == LOW) {
     // Wait for button release
    }
    delay(50);
    
    display.setCursor(0, 16);
    display.println("Press to start");
    display.display();


    while (digitalRead(BUTTON_PIN) == HIGH) {
     // Wait for button press
    }

    while (digitalRead(BUTTON_PIN) == LOW) {
     // Wait for button release
    }
    
    unsigned long randomNumber = random(1000, 5000);
    unsigned long waitStart = millis();
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Get ready...");
    display.display();

    while (millis() - waitStart < randomNumber) {
        if (digitalRead(BUTTON_PIN) == LOW){
            display.clearDisplay();
            display.setCursor(0, 0);
            display.println("Too soon!");
            display.display();
            return;
        }
    }
    
    digitalWrite(LED_PIN, HIGH);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("GO!");
    display.display();

    unsigned long time = millis();

    while (digitalRead(BUTTON_PIN) == HIGH) {

    }

    unsigned long reactionTime = millis() - time;

    digitalWrite(LED_PIN, LOW);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Reaction Time: ");
    display.print(reactionTime);
    display.println(" ms");
    display.display();
}
