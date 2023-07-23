#include "DHT.h" // Adafriut Temperature and
#define HT 4
#define DHTTYPE DHT11

DHT dht(HT, DHTTYPE);

#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

float temp, humidity;

void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    temp = dht.readTemperature();  
    humidity = dht.readHumidity();
    u8g2.clearBuffer();                   // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso16_tf);   // choose a suitable font
    u8g2.drawStr(0,16,"WeatherStation");    // write something to the internal memory
    u8g2.setCursor(48, 40);
    //u8g2.print(int(temp));
    u8g2.print(temp);
    u8g2.setCursor(48, 64);
    //u8g2.print(int(humidity));
    u8g2.print(humidity);

    u8g2.setFont(u8g2_font_unifont_t_symbols);
    u8g2.drawGlyph(100,40,8451); 
    u8g2.drawGlyph(100, 64, 37);

    u8g2.setFont(u8g2_font_unifont_t_weather);
    u8g2.drawGlyph(16,40, 49); 
    u8g2.drawGlyph(16, 64, 50);

    u8g2.sendBuffer(); // transfer internal memory to the display
  
    delay(250);
}
