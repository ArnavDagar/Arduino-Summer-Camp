#include <U8g2lib.h>
#include "Ultrasonic.h"
#include "DHT.h"

//Button Pins
#define BR 8
#define BY 9
#define BG 10
#define BB 12
#define BK 13

#define PB 6 //Buzzer Pin
#define POT A0
#define LED 5  //set the LED pin
#define HT 4
#define US 7
#define WS A1 //Water sensor pin
#define POTNOISE 5
#define DHTTYPE DHT11

//Pitches
#define C  262
#define D  294
#define E  330
#define F  349
#define G  392
#define A  440
#define pitch 220 //for metronome
#define onTime 50 //50msec 

#define Q 1 // Quarter Note gets a beat
#define H 2 // Half Note gets two beats

//Objects and Variables
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C
DHT dht(HT, DHTTYPE);
Ultrasonic ultrasonic(US);

const char string_0[] PROGMEM = "Play Piano"; // Stored strings
const char string_1[] PROGMEM = "Metronome";
const char string_2[] PROGMEM = "Auto Piano";
const char string_3[] PROGMEM = "WeatherStation";
const char string_4[] PROGMEM = "Range Finder";
const char string_5[] PROGMEM = "Collision Alert";
const char string_6[] PROGMEM = "WaterOverflow";
const char string_7[] PROGMEM = "BPM: ";
const char string_8[] PROGMEM = "Clear";
const char string_9[] PROGMEM = "Caution";
const char string_10[] PROGMEM = "Danger";
const char string_11[] PROGMEM = "Critical";

const char *const string_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5,
string_6, string_7, string_8, string_9, string_10, string_11};

char buffer[15];  // make sure this is large enough for the largest string it must hold

uint8_t p = 0; //project number

float timeOff;  //time for which buzzer is off between notes
int preval = -1 * POTNOISE; //Previous value of the POT
int val; //Current POT Value
int beatsPerMinute;
float period; //milliseconds
uint8_t i = 0; //ith note in the melody
long Range;
int level;
int alert;
int prevAlert = -1;

float temp, humidity;

// notes in the melody:
uint8_t numNotes = 42;

int melody[] = {

 C, C, G, G, A, A, G, F, F, E, E, 
 D, D, C, G, G, F, F, E, E, D, 
 G, G, F, F, E, E, D, C, C, G, G,
 A, A, G, F, F, E, E, D, D, C
};

// note values - quarter (Q), half (H)
/*
uint8_t noteValues[] = {

  Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q,
  Q, Q, H, Q, Q, Q, Q, Q, Q, H,
  Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q,
  Q, Q, H, Q, Q, Q, Q, Q, Q, H
};
*/
uint8_t noteValues[] = {
  Q, Q, Q, Q, Q, Q, H
};


void setup_display(uint8_t i){ // Get the display ready for the ith project
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_logisoso16_tf);
  strcpy_P(buffer, (char *)pgm_read_word(&(string_table[i]))); 
  u8g2.drawStr(0,16,buffer);
}


void setup() {
  // put your setup code here, to run once:
  pinMode(BR, INPUT);
  pinMode(BY, INPUT);
  pinMode(BG, INPUT);
  pinMode(BB, INPUT);
  pinMode(BK, INPUT);
  pinMode(PB, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(POT, INPUT);
  pinMode(WS, INPUT);
  Serial.begin(9600);
  u8g2.begin();

  dht.begin();
  //temp = dht.readTemperature();
  //humidity = dht.readHumidity();
  
  setup_display(p);
  u8g2.setFont(u8g2_font_unifont_t_76);
  u8g2.drawGlyph(32,48,9833);
  u8g2.sendBuffer();
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ((digitalRead(BR) == LOW) && (digitalRead(BK) == LOW)){
    //set loopOnce for projects needing to run sections only 1 time
    p += 1;
    p = p % 7;
    Serial.print("Project ");
    Serial.println(p);

    if (p == 0) {
      setup_display(p);
      u8g2.setFont(u8g2_font_unifont_t_76);
      u8g2.drawGlyph(32,48,9833);
      u8g2.sendBuffer();
      delay(100);
    }
    preval = -1 * POTNOISE;
    prevAlert = -1;
  }
// Manual Piano, Metronome, Automatic Piano, Range Finder, CollisionAlert, Weather Station, Water Overflow

  switch(p) {
    case 1: //Metronome
      val = analogRead(POT); //values are between 0 and 1023
      if (abs(val - preval) > POTNOISE -1) { //update the period and the display
        beatsPerMinute = map(val,0,1023,40,208); //metronome range 40-208
        period = 1000/(beatsPerMinute/60.0); //milliseconds 
        preval = val;
        setup_display(p);
        strcpy_P(buffer, (char *)pgm_read_word(&(string_table[7]))); 
        u8g2.drawStr(0,48,buffer);    // write something to the internal memory
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
      break;

    case 2: //Auto Piano
      val = analogRead(POT);   //values range from 0 to 1023
      if (abs(val - preval) > POTNOISE -1){ //update period and display
        beatsPerMinute = map(val, 0, 1023, 40, 208);
        period = 1000/(beatsPerMinute/60.0);
        timeOff = period * 0.3;
        preval = val;
        setup_display(p);
        u8g2.setCursor(60,48);
        u8g2.print(beatsPerMinute);
        u8g2.setFont(u8g2_font_unifont_t_76);
        u8g2.drawGlyph(32,48,9833);
        u8g2.sendBuffer();
        delay(100);
        i=0;
      }

      float durNote;  //how long to play the note
      durNote = period * noteValues[i%7];
      tone(PB, melody[i], durNote - timeOff);
      delay(durNote);

      i += 1;
      i = i%numNotes;
      if (i == 0) {
        delay(2000);
      }
      break;

    case 3:
      // Reading temperature or humidity takes about 250 milliseconds!
      // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)        
      setup_display(p);
      /*
      temp = dht.readTemperature();
      humidity = dht.readHumidity();
      u8g2.setCursor(48, 40);
      u8g2.print(temp);
      u8g2.setCursor(48, 64);
      u8g2.print(humidity);
      */
      u8g2.setFont(u8g2_font_unifont_t_symbols);
      u8g2.drawGlyph(100,40,8451); 
      u8g2.drawGlyph(100, 64, 37);

      u8g2.setFont(u8g2_font_unifont_t_weather);
      u8g2.drawGlyph(16,40, 49); 
      u8g2.drawGlyph(16, 64, 50);

      u8g2.sendBuffer(); // transfer internal memory to the display
    
      delay(250);

      break;

    case 4:
      Range = ultrasonic.MeasureInCentimeters();
      //Serial.print(Range);
      //Serial.println(" cm");
      setup_display(p);
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

      break;

    case 5:
      Range = ultrasonic.MeasureInCentimeters();
      Serial.println(Range);
      if(Range>200){
        alert = 0;
      }
      else if (Range > 100){
        alert = 1;
        beatsPerMinute = 60;
      }
      else if (Range > 50){
        alert = 2;
        beatsPerMinute = map(Range, 51, 100, 240, 60);
      }
      else{
        alert = 3;
        beatsPerMinute = map(Range,0,50,1200,240); //faster as we get closer
      }

      if(alert != prevAlert)
      {
        setup_display(p);
        switch(alert){
          case 0:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[8]))); 
            u8g2.drawStr(0,48,buffer);    // Clear
            break;
          case 1:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[9]))); 
            u8g2.drawStr(0,48,buffer);    // Caution
            break;
          case 2:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[10]))); 
            u8g2.drawStr(0,48,buffer);    // Danger
            break;
          case 3:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[11]))); 
            u8g2.drawStr(0,48,buffer);    //Critical
            break;
          default:
            u8g2.drawStr(0,48,"Error");    // write something to the internal memory
        }
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

      break; 

    case 6:
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
        setup_display(p);
        
        switch(alert){
          case 0:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[8]))); 
            u8g2.drawStr(32,48,buffer);    // Clear
            break;
          case 1:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[9]))); 
            u8g2.drawStr(32,48,buffer);    // Caution
            break;
          case 2:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[10]))); 
            u8g2.drawStr(32,48,buffer);    // Danger
            break;
          case 3:
            strcpy_P(buffer, (char *)pgm_read_word(&(string_table[11]))); 
            u8g2.drawStr(32,48,buffer);    // Critical
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
      break;

    default:
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
}
