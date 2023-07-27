#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);    //Software I2C

#define PB 6    //Buzzer Pin
#define POT A0  //POT Pin
#define POTNOISE 5

//Pitches
#define C  262
#define D  294
#define E  330
#define F  349
#define G  392
#define A  440

#define Q 1 // Quarter Note gets a beat
#define H 2 // Half Note gets two beats


// notes in the melody:
int numNotes = 42;

int melody[] = {

 C, C, G, G, A, A, G, F, F, E, E, 
 D, D, C, G, G, F, F, E, E, D, 
 G, G, F, F, E, E, D, C, C, G, G,
 A, A, G, F, F, E, E, D, D, C
};

// note values - quarter (Q), half (H)
int noteValues[] = {

  Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q,
  Q, Q, H, Q, Q, Q, Q, Q, Q, H,
  Q, Q, Q, Q, Q, Q, H, Q, Q, Q, Q,
  Q, Q, H, Q, Q, Q, Q, Q, Q, H
};

float timeOff;  //time for which buzzer is off between notes
int val;        //value read from pot
int preVal = -1 * POTNOISE;    //earlier value of pot, initially set to non-existant value
int beatsPerMinute; //tempo
float period;       //period for the tempo

int i = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(PB, OUTPUT);
  pinMode(POT, INPUT);
  u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(POT);   //values range from 0 to 1023

  if (abs(val - preVal) > 5){ //update period and display
    beatsPerMinute = map(val, 0, 1023, 40, 208);
    period = 1000/(beatsPerMinute/60.0);
    timeOff = period * 0.3;
    preVal = val;
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_logisoso16_tf);
    u8g2.drawStr(0,16,"Auto Piano");
    u8g2.setCursor(60,48);
    u8g2.print(beatsPerMinute);
    u8g2.setFont(u8g2_font_unifont_t_76);
    u8g2.drawGlyph(32,48,9833);
    u8g2.sendBuffer();
    delay(100);
    i=0;
  }

  float durNote;  //how long to play the note
  durNote = period * noteValues[i];
  tone(PB, melody[i], durNote - timeOff);
  delay(durNote);

  i += 1;
  i = i%numNotes;
  if (i == 0) {
    delay(2000);
  }
}
