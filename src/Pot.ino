#define LED 5
#define POT A0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(POT, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pVal = analogRead(POT);
  Serial.println(pVal);
  analogWrite(LED, pVal/4);
}
