// This #include statement was automatically added by the Particle IDE.
#include <TM1637Display.h>

#define CLK D2
#define DIO D3

TM1637Display displayTime(CLK,DIO);

void setup() {
   displayTime.setBrightness(0xff); //set the diplay to maximum brightness
//    displayTime.setBrightness(0x0a); //not so bright
    Time.zone(-7.00);  // setup a time zone, which is part of the ISO6801 format
}



void loop() {
    int h = Time.hour();
    int m = Time.minute();

    // Set center colon on without array - Start
    uint8_t segto;
    int value = 1244;
    segto = 0x80 | displayTime.encodeDigit((value / 100)%10); // And off will be without this 0x80 bit set
    displayTime.setSegments(&segto, 1, 1);
    //delay(1000) ; // constant colon
    // End

    // Print Data array - Start
    uint8_t data[] = {0xff, 0xff, 0xff, 0xff};

      data[0] = displayTime.encodeDigit(h / 10);
      data[1] = displayTime.encodeDigit(h % 10) | (Time.second() % 2 ? 0x80 : 0x00);
      data[2] = displayTime.encodeDigit(m / 10);
      data[3] = displayTime.encodeDigit(m % 10);
      displayTime.setSegments(data);

}
