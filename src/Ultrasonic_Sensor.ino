#include "Ultrasonic.h"
#define US 7

Ultrasonic ultrasonic(US);

long Range;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Range: ");
  Range = ultrasonic.MeasureInCentimeters();
  Serial.print(Range);
  Serial.println(" cm");
  delay(250);
}
