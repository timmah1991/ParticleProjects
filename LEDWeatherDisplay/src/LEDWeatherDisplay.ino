
 // Example usage for Custom_SSD1306 library by Tomais Williamson.

 #include "Custom_SSD1306.h"
 #include "Adafruit_DHT_Particle.h"
 #define DHTPIN D5
 #define DHTTYPE DHT11
 DHT dht(DHTPIN, DHTTYPE);

 // Initialize objects from the lib
 Custom_SSD1306 oled;

 void setup() {
   oled.begin();
   for (int i=0; i <= 64; i++){
     oled.clearString(i);
   }
   oled.drawCenteredString(0, "Lovebot 1.0");
   oled.display();
   pinMode(D7, OUTPUT);
   Particle.publish("state", "DHTxx test start");
   dht.begin();
   delay(5000);
 }

 void loop() {
   float h = dht.getHumidity();
   float t = dht.getTempCelcius();
   float f = dht.getTempFarenheit();
   float hi = dht.getHeatIndex();
   float dp = dht.getDewPoint();
   float k = dht.getTempKelvin();
   oled.drawCenteredString(9, String::format("{Hum: %4.2f,}", h));
   oled.drawCenteredString(18, String::format("{Temp: %4.2f,}", f));
   oled.drawCenteredString(27, String::format("{DP: %4.2f,}", dp));
   oled.drawCenteredString(36, String::format("{HI: %4.2f}", hi));
   oled.drawCenteredString(45, "Refreshing in 10");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 9");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 8");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 7");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 6");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 5");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 4");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 3");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 2");
   oled.display();
   delay(1000);
   oled.clearString(45);
   oled.drawCenteredString(45, "Refreshing in 1");
   oled.display();
   delay(1000);
 }


//String::format("{\"Hum(\%)\": %4.2f, \"Temp(°F)\": %4.2f, \"DP(°C)\": %4.2f, \"HI(°C)\": %4.2f}", h, f, dp, hi)
