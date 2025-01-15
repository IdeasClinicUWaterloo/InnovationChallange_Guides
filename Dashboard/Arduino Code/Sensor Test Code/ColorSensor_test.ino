 //Taken from: https://github.com/Panjkrc/TCS3200_library

#include <tcs3200.h>

int red, green, blue, white;

int scaling = 100; // Can be 0, 2, 20, 100
// If surrounding LEDs are on, lower numbers are better
// Otherwise use higher numbers

// read more at: https://www.mouser.com/catalog/specsheets/TCS3200-E11.pdf

tcs3200 tcs(0, 1, 2, 3, 4); // (S0, S1, S2, S3, output pin)  
// Numbers correspond to the Digital Ports that the sensor is plugged into

void setup() {
  Serial.begin(9600);
}

void loop() {

  red = tcs.colorRead('r', scaling);   //reads color value for red
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("    ");
  
  green = tcs.colorRead('g', scaling);   //reads color value for green
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("    ");

  blue = tcs.colorRead('b', scaling);    //reads color value for blue
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("    ");

  white = tcs.colorRead('c', scaling);    //reads color value for white(clear)
  Serial.print("W(clear)= ");
  Serial.print(white);
  Serial.print("    ");

  Serial.println();

  delay(100);

}
