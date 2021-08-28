#include <LiquidCrystal.h>

#define BUTTON_PIN 0
#define LED_PIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int buttonValue = 0;
const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  lcd.begin(16, 2);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600); 
}

void loop() {
  buttonValue = digitalRead(BUTTON_PIN);
  Serial.println(buttonValue);
  if(!buttonValue) {
    digitalWrite(LED_PIN, HIGH);
    lcd.setCursor(0, 0);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);   

    duration = pulseIn(echoPin, HIGH); 

    distance= duration*0.034/2;

    lcd.write("Height: ");
    lcd.print(distance);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}