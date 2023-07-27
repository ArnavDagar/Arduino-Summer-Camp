#define PB 6
#define C 262

void setup() {
  // put your setup code here, to run once:
  pinMode(PB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(PB, C, 500);
  delay(1000);
}
