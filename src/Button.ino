#define LED 6
#define BUT 8

void setup() {
  // put your setup code here, to run once:
    pinMode(LED, OUTPUT);
    pinMode(BUT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bVal = digitalRead(BUT);
  if (bVal == 0) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
}
