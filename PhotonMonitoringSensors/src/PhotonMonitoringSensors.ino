#include "Adafruit_DHT_Particle.h"
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  pinMode(D7, OUTPUT);
	Particle.publish("state", "DHTxx test start");
	dht.begin();
	delay(5000);
  blinkitbitch(25, 50);
}

void loop() {
	float h = dht.getHumidity();
	float t = dht.getTempCelcius();
	float f = dht.getTempFarenheit();
	if (isnan(h) || isnan(t) || isnan(f)) {
		Particle.publish("SensorErrorStatus", "FAILED TO READ DATA FROM SENSOR", PRIVATE);
    blinkitbitch(25, 500);
		return;
	}
	float hi = dht.getHeatIndex();
	float dp = dht.getDewPoint();
	float k = dht.getTempKelvin();
	Particle.publish("DataFromDHT11_Photon", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h, f, dp, hi));

  blinkitbitch(500, 4);
 	delay(5000);
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
