/*
 * Project BlacBoxHomeDev
 * Description:
 * Author:
 * Date:
 */

 /*
  * PIR sensor tester
  */


  //Uncommnent the following line to work in offline mode
  //SYSTEM_MODE(MANUAL);

  int led = D7; // we will use D7 LED to monitor sensor activity
  int pir = D0; //connect the PIR output to pin D0 of the Electron

  void setup() {
      pinMode(D0, INPUT_PULLDOWN);
      pinMode(D7,OUTPUT);
      Particle.publish("state", "DHTxx test start");
      blinkitbitch(25, 50);
  }

  void loop() {
      if (digitalRead(D0) == HIGH) {
        Particle.publish("Motion","Detected",60); //publish an event
        blinkitbitch(25, 50);
        delay(1000);
          while (digitalRead(D0) == HIGH); // wait for the sensor to return back to normal
      }
      digitalWrite(D7,LOW);
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
