
void setup() {
  pinMode(D7, OUTPUT);
}

void loop() {
  //newfunction(1000000, 10000);
  blinkitbitch(1000,50000);
}

void blinkitbitch(int times, int counts){
  for (int i=1; i <= counts; i++){
    digitalWrite(D7, HIGH);
    delay(times);
    digitalWrite(D7, LOW);
    delay(times);
    times = times * .9;
  }
}

void newfunction(int counts, float stop){
  float times = 1000 ;
  for (int i=1; i <= counts; i++){
    times= -(1/stop)*(i-1)+times;
    digitalWrite(D7, HIGH);
    delay(times);
    digitalWrite(D7, LOW);
    delay(times);
  }
}
