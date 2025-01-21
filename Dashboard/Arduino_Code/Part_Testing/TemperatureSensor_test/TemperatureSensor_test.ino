#include <math.h>
// Connect the sensor to the A0 (Analog 0) pin on the Arduino board

int B = 3975;  // B-value of the sensor, a constant

void setup()
{
    Serial.begin(15000);
}

void loop()
{
    int a = analogRead(1);

    // Calculate the resistance of the sensor:
    // W1023 is the maximum ADC value (for a 10-bit ADC), and 10000 is the known fixed resistor value.
    float resistance = (float)(1023 - a) * 10000 / a; 

    // Steinhart-Hart equation to calculate the temperature in Celsius:
    float temperature = 1 / (log(resistance / 10000) / B + 1 / 298.15) - 273.15;
    delay(1000);
    Serial.print("Current temperature is ");
    Serial.print(temperature);
    Serial.print(" °C");
    Serial.println();
}
