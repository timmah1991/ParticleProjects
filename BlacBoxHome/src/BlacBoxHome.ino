/*
 * Project BlacBoxHome
 * Description: Empty Real Estate Monitoring Script
 * Author: GoldenGadgeteers
 * Date:5/11/2018
 */

//SET UP DHT SENSOR
 #include "Adafruit_DHT_Particle.h"
 #define DHTPIN D5
 #define DHTTYPE DHT22
 DHT dht(DHTPIN, DHTTYPE);

 //SET UP GAS Sensor

 //SET UP SOUND SENSOR

 //SET UP MOTION SENSOR

 //DEFINE THRESHOLDS
 int SoundThreshold = 60;
 int TempThresholdF = 60;
 int MotionAlert = 1;
 int NumberLoops = 10000;
 int i;



// setup() runs once, when the device is first turned on.
void setup() {

  Particle.publish("state", " Starting a BlacBoxHome Device");
	dht.begin();

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  for (int i=1; i <= NumberLoops; i++){  //Keep checking the sensors for a count and call emergencyNotify if any reading is above alert spec

    //Read from DHT
    float h = dht.getHumidity();
    float t = dht.getTempCelcius();
    float f = dht.getTempFarenheit();

    //Read from sound sensor
    sensorval = analogRead(sensorPin);

    //TODO Read from gas sensor

    //TODO Read from motion sensor

    //TODO IF Motion Detected conditional call emergencyNotify
    //TODO IF Sound > Threshold conditional call emergencyNotify
    //TODO IF Temp > Threshold conditional call emergencyNotify
    //TODO IF Gas > Threshold conditional call emergencyNotify

  }
	Particle.publish("DataFromBBH", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h, f, dp, hi));

}








void emergencyNotify(int times, int counts){
   int i;
   for (int i=1; i <= counts; i++){
     digitalWrite(D7, HIGH);
     delay(times);
     digitalWrite(D7, LOW);
     delay(times);
  }
 }
