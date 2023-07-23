#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

//Button Pins
#define BR 8
#define BY 9
#define BG 10
#define BB 12
#define BK 13

#define PB 6 //Buzzer Pin

//Pitches
#define C  262
#define D  294
#define E  330
#define F  349
#define G  392

void setup() {
  // put your setup code here, to run once:
  pinMode(BR, INPUT);
  pinMode(BY, INPUT);
  pinMode(BG, INPUT);
  pinMode(BB, INPUT);
  pinMode(BK, INPUT);
  pinMode(PB, OUTPUT);
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso16_tf);
  u8g2.drawStr(0,16,"Play Piano");
  u8g2.setFont(u8g2_font_unifont_t_76);
  u8g2.drawGlyph(32,48,9833);
  u8g2.sendBuffer();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(BR) == LOW) {
    tone(PB, C, 10);
  }
  else if (digitalRead(BY) == LOW) {
    tone(PB, D, 10);
  }
  else if (digitalRead(BG) == LOW) {
    tone(PB, E, 10);
  }
  else if (digitalRead(BB) == LOW) {
    tone(PB, F, 10);
  }
  else if (digitalRead(BK) == LOW) {
    tone(PB, G, 10);
  }
}
