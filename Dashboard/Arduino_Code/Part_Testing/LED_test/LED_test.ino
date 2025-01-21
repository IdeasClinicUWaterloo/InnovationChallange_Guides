#include <Adafruit_NeoPixel.h> 
#define LED_PIN 13 //change to match board setup 
#define LED_COUNT 3 //change to # of lights on LED strip you want to display the color 
#define BRIGHTNESS 10 //set in range 0-255 

#include <Adafruit_NeoPixel.h> 
#ifdef __AVR__ 
#include <avr/power.h> 
#endif 

//Declare our NeoPixel strip object: 
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); 


void setup() { 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000) 
  clock_prescale_set(clock_div_1); 
#endif
 
  strip.begin(); 
  strip.show(); 
  strip.setBrightness(BRIGHTNESS); 
} 

 
//color is light purple 
//Change color values to test other colors! 
uint8_t red = 91; 
uint8_t green = 32; 
uint8_t blue = 125; 
 
void loop() { 
  strip.setPixelColor(0, 0, 0, 255);
  strip.setPixelColor(1,0,255,0);
  strip.setPixelColor(2,255,0,0);
  strip.show();
  delay(2000);
  strip.setPixelColor(1, 0, 0, 255);
  strip.setPixelColor(2,0,255,0);
  strip.setPixelColor(0,255,0,0);
  strip.show();
  delay(2000);
  strip.setPixelColor(2, 0, 0, 255);
  strip.setPixelColor(0,0,255,0);
  strip.setPixelColor(1,255,0,0);
  strip.show();
  delay(2000);
  for(int i = 0; i < 3; ++i){
    strip.setPixelColor(i, red, blue, green);
    strip.show();
  }
  delay(2000);
} 