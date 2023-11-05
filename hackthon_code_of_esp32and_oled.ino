
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


const int trigPin = D3;  
const int echoPin = D4; 


const int ledPin = D5;   

void setup() {
  
  Serial.begin(115200);


  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  pinMode(ledPin, OUTPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0); 
  display.println("MEDICO.IN");
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,25);
  display.println("READY TO FETCH");
  display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,45);
    display.println(":):):):)"); 
  

  
  
  display.display();     
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  
  long duration = pulseIn(echoPin, HIGH);

 
  float distance_cm = (duration * 0.0343) / 2;


  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm > 25) {  
    digitalWrite(ledPin, LOW); 
  } else {
    digitalWrite(ledPin, HIGH);  
  }

  delay(10); s
}
