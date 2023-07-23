#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

#define PB 6 //set the buzzer Pin
#define LED 5  //set the LED pin
#define WS A1 //Water sensor pin

int onTime = 50; //milliseconds
int pitch = 220; //Hz
int beatsPerMinute;
float period; //milliseconds
int level;
int alert; //0: Clear, 1: Caution, 2: Danger, 3: Critical
int prevAlert = -1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  u8g2.begin();
  pinMode(PB, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(WS, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(WS);
  Serial.println(level);
  if(level>512){
    alert = 0;
  }
  else if (level > 256){
    alert = 1;
    beatsPerMinute = 60;
  }
  else if (level > 128){
    alert = 2;
    beatsPerMinute = map(level, 128, 255, 240, 60);
  }
  else{
    alert = 3;
    beatsPerMinute = map(level,0,128,1200,240); //faster as we get closer
  }

  //Serial.print(Range);
  //Serial.println(" cm");
  if(alert != prevAlert)
  {
    u8g2.clearBuffer();                   // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso16_tf);   // choose a suitable font
    u8g2.drawStr(0,16,"WaterOverflow");    // write something to the internal memory
    
    switch(alert){
      case 0:
        u8g2.drawStr(32,48,"Clear");    // write something to the internal memory
        break;
      case 1:
        u8g2.drawStr(32,48,"Caution");    // write something to the internal memory
        break;
      case 2:
        u8g2.drawStr(32,48,"Danger");    // write something to the internal memory
        break;
      case 3:
        u8g2.drawStr(32,48,"Critical");    // write something to the internal memory
        break;
      default:
        u8g2.drawStr(32,48,"Error");    // write something to the internal memory
    }
    u8g2.setFont(u8g2_font_unifont_t_weather); 
    u8g2.drawGlyph(0, 48, 50);
    u8g2.sendBuffer(); // transfer internal memory to the display
    prevAlert = alert;
  }

  if(alert != 0)
  {
    period = 1000/(beatsPerMinute/60.0); //milliseconds 
    tone(PB, pitch, onTime);
    digitalWrite(LED, HIGH);
    delay(onTime);
    digitalWrite(LED, LOW);
    delay(period-onTime);
  }  
  

}
