#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso16_tf);
  u8g2.drawStr(0,16, "Hello World");
  u8g2.setFont(u8g2_font_unifont_t_77);
  u8g2.drawGlyph(30,52,9924);
  u8g2.sendBuffer();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:

}
