#include "rgb_lcd.h"
rgb_lcd lcd;

// lcd display variables
const int colorR = 240;
const int colorG = 117;
const int colorB = 128;


void setup()
{
    Serial.begin(115200);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);

    // Print a message to the LCD.
    lcd.print("hola, world!");
    delay(1000);

}

void loop()
{
    // Clear the text that was there before
    lcd.clear();
    // Start writing text in the top left
    lcd.setCursor(0, 0); // Column 0, row 0
    lcd.setRGB(0, 0, 255);
    lcd.print("I am Blue!");
    delay(2000);
    lcd.clear();

    lcd.setRGB(255, 0, 0);
    lcd.print("I am Red!");
    delay(2000);
    lcd.clear();

    lcd.setRGB(0, 255, 0);
    lcd.print("I am Green!");
    delay(2000);
    lcd.clear();

    //Change red, green, and blue variable values to change lcd backlight
    //Change text in lcd.print to output different text
    lcd.setRGB(colorR, colorG, colorB);
    lcd.print("You can change");
    // Continue the text on the second row 
    lcd.setCursor(0, 1); // column 0, row 1
    lcd.print("the background!");
    delay(2000);
}
