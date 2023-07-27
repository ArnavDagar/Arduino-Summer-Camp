#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

#define POT A0
#define PB 6 //set the buzzer Pin
#define LED 5  //set the LED pin
#define POTNOISE 5

int onTime = 50; //milliseconds
int pitch = 220; //Hz
int preval = -1*POTNOISE; 
int val;
int beatsPerMinute;
float period; //milliseconds

void setup()
{
  pinMode(PB, OUTPUT); // set the buzzer as output mode
  pinMode(LED,OUTPUT);
  pinMode(POT, INPUT);
  //preval = analogRead(POT);
  u8g2.begin();
  Serial.begin(9600);           //  setup serial
}

void loop()
{
  val = analogRead(POT); //values are between 0 and 1023
  if (abs(val - preval) > POTNOISE -1) { //update the period and the display
    beatsPerMinute = map(val,0,1023,40,208); //metronome range 40-208
    period = 1000/(beatsPerMinute/60.0); //milliseconds 
    preval = val;
    u8g2.clearBuffer();                   // clear the internal memory
    u8g2.setFont(u8g2_font_logisoso16_tf);   // choose a suitable font
    u8g2.drawStr(0,16,"Metronome");    // write something to the internal memory
    u8g2.drawStr(0,48,"BPM: ");    // write something to the internal memory
    u8g2.setCursor(60, 48);
    u8g2.print(beatsPerMinute);
    u8g2.sendBuffer(); // transfer internal memory to the display
    delay(100);
  }
  else {
    tone(PB, pitch, onTime);
    digitalWrite(LED, HIGH);
    delay(onTime);
    digitalWrite(LED, LOW);
    delay(period-onTime);
  }
  Serial.print(val);
  Serial.print("    ");
  Serial.println(preval);
}
