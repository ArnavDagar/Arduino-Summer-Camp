#define WS A1
int level;
void setup() {
  // put your setup code here, to run once:
  pinMode(WS,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  level = analogRead(WS);
  Serial.println(level);
  delay(100);
}
