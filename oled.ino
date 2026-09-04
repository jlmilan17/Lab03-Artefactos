#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define ANCHO 128
#define ALTO  64
#define RESET -1
#define LM35  A0

Adafruit_SH1106G oled(ANCHO, ALTO, &Wire, RESET);


void setup() { 
  oled.clearDisplay();
  oled.display();
  oled.setTextColor(SH110X_WHITE);
}

void loop() {
  int lectura = analogRead(LM35);
  float temp = lectura * (5.0 / 1023.0) * 100.0;  

  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setCursor(0, 0);
  oled.print("Temperatura");

  oled.setTextSize(3);
  oled.setCursor(0, 25);
  oled.print(temp, 1);
  oled.print((char)247);
  oled.print("C");

  oled.display();
  delay(1000);
}