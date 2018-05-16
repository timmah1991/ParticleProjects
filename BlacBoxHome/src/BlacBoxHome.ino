/*
 * Project BlacBoxHome
 * Description: Empty Real Estate Monitoring Script
 * Author: GoldenGadgeteers
 * Date:5/11/2018
 * Sensor List:
        MQ4 Gas Sensor
        PIR Motion Sensor
        RobotDyn Sound Sensor
        DHT22 Temp/Humidity Sensor
 */

//SET UP DHT SENSOR
 #include "Adafruit_DHT_Particle.h"
 #define DHTPIN D5
 #define DHTTYPE DHT22
 DHT dht(DHTPIN, DHTTYPE);

 //SET UP GAS Sensor

 //SET UP SOUND SENSOR
 #define soundSensorPin D3

 //SET UP MOTION SENSOR
 int motionState = LOW;
 #define motionSensorPin D2

 //DEFINE THRESHOLDS
 int SoundThreshold = 60;
 int TempThresholdF = 60;
 int MotionAlert = 1;
 int NumberLoops = 10000;
 int i;
 int s;
 float h;
 float t;
 float f;


void setup() {

  Particle.publish("state", " Starting a BlacBoxHome Device");
	dht.begin();

}








void loop() {

  //Keep checking the sensors for a count and call emergencyNotify if any reading is above alert spec
  for (int i=1; i <= NumberLoops; i++){

    //TODO add a counter/timer for spacing DHT22 queries out by >2 seconds

    //Read from DHT
    float h = dht.getHumidity();
    float t = dht.getTempCelcius();
    float f = dht.getTempFarenheit();

    //Read from sound sensor
    int s = analogRead(soundSensorPin);

    //TODO Read from gas sensor

    //TODO Read from motion sensor

    //TODO IF Motion Detected conditional call emergencyNotify
    //TODO IF Sound > Threshold conditional call emergencyNotify
    //TODO IF Temp > Threshold conditional call emergencyNotify
    //TODO IF Gas > Threshold conditional call emergencyNotify

  }
	Particle.publish("DataFromBBH", String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f}", h, f));

}













void emergencyNotify(int alertlevel){
  switch (alertlevel) {
    case 1:
      // Send motion notify
      Particle.publish("ALERTFromBBH", "BlacBoxHome Device Has Detected Motion");
      break;
    case 2:
      // Send sound notify
      Particle.publish("ALERTFromBBH", "BlacBoxHome Device Has Detected a Loud Noise");
      break;
    case 3:
      // Send temp notify
      Particle.publish("ALERTFromBBH", "BlacBoxHome Device Has Exceeded Temperature Threshold");
      break;
    case 4:
      // Send gas notify
      Particle.publish("ALERTFromBBH", "BlacBoxHome Device Has Detected a Gas Leak");
      break;
      //TODO send power disconnected notify
    default:
      //Send generic warning
      break;
  }
 }
