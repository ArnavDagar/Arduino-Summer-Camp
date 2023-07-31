#include "DHT.h"

#define HT 4
#define DHTTYPE DHT11

DHT dht(HT, DHTTYPE);

float temp, humidity;

void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
} 

void loop() {
  // put your main code here, to run repeatedly:
  temp = dht.readTemperature() * 1.8 + 32;
  humidity = dht.readHumidity();
  Serial.print(temp);
  Serial.print(" F");
  Serial.print(", ");
  Serial.print(humidity);
  Serial.println(" %");
  delay(200);
}
