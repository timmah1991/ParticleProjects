#include "Adafruit_DHT_Particle.h"
#define DHTPIN D2
#define DHT2PIN D4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);


void setup() {
  pinMode(D7, OUTPUT);
	Particle.publish("state", "DHT22 test start");
	dht.begin();
  dht2.begin();
	delay(5000);
  blinkitbitch(25, 50);
}

void loop() {
	float h = dht.getHumidity();
	float t = dht.getTempCelcius();
	float f = dht.getTempFarenheit();
  float h2 = dht2.getHumidity();
	float t2 = dht2.getTempCelcius();
	float f2 = dht2.getTempFarenheit();
	if (isnan(h) || isnan(t) || isnan(f)) {
		Particle.publish("SensorErrorStatus", "FAILED TO READ DATA FROM SENSOR 1", PRIVATE);
    blinkitbitch(25, 500);
		return;
	}
  if (isnan(h2) || isnan(t2) || isnan(f2)) {
		Particle.publish("SensorErrorStatus", "FAILED TO READ DATA FROM SENSOR 2", PRIVATE);
    blinkitbitch(25, 500);
		return;
	}
	float hi = dht.getHeatIndex();
	float dp = dht.getDewPoint();
	float k = dht.getTempKelvin();
  float hi2 = dht2.getHeatIndex();
	float dp2 = dht2.getDewPoint();
	float k2 = dht2.getTempKelvin();
	Particle.publish("DataFromDHT22_PhotonS1", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h, f, dp, hi));
  Particle.publish("DataFromDHT22_PhotonS2", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h2, f2, dp2, hi2));

  blinkitbitch(500, 4);
 	delay(10000);
 }

void blinkitbitch(int times, int counts){
   int i;
   for (int i=1; i <= counts; i++){
     digitalWrite(D7, HIGH);
     delay(times);
     digitalWrite(D7, LOW);
     delay(times);
  }
 }
