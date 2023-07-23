#include "Ultrasonic.h"
#define US 7
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

Ultrasonic ultrasonic(US);

long Range;

void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("Range: ");
  Range = ultrasonic.MeasureInCentimeters();
  //Serial.print(Range);
  //Serial.println(" cm");
  u8g2.clearBuffer();                   // clear the internal memory
  u8g2.setFont(u8g2_font_logisoso16_tf);   // choose a suitable font
  u8g2.drawStr(0,16,"Range Finder");    // write something to the internal memory
  u8g2.drawStr(0,48,"Range: ");    // write something to the internal memory
  u8g2.setCursor(60, 48);
  if(Range==520)
  {
    u8g2.drawStr(60,48,"___");    // write something to the internal memory
  }
  else{
    u8g2.print(Range);
  }
  
  u8g2.drawStr(96, 48, "cm");
  u8g2.sendBuffer(); // transfer internal memory to the display
}
