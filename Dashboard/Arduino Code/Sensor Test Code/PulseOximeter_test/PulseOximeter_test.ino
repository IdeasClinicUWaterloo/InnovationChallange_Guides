#include <DFRobot_MAX30102.h>
DFRobot_MAX30102 particleSensor;


    // heart rate variables
    int32_t SPO2;           //SPO2
    int8_t SPO2Valid;       //Flag to display if SPO2 calculation is valid
    int32_t heartRate;      //Heart-rate
    int8_t heartRateValid;  //Flag to display if heart-rate calculation is valid


void setup() {
    Serial.begin(115200);

  while (!particleSensor.begin()) {
    Serial.println("MAX30102 was not found, check your wiring!");
    delay(100);
  }

  particleSensor.sensorConfiguration(/*ledBrightness=*/50, /*sampleAverage=*/SAMPLEAVG_16,
                                     /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_800,
                                     /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

void loop()
{
  particleSensor.heartrateAndOxygenSaturation(/**SPO2=*/&SPO2, /**SPO2Valid=*/&SPO2Valid, /**heartRate=*/&heartRate, /**heartRateValid=*/&heartRateValid);
  
  if (heartRateValid == 1){
    Serial.print("Detected Heart Rate: "); Serial.println(heartRate);
  }else{
    Serial.println("No heart rate detected.");
  }
  if (SPO2Valid == 1){
    Serial.print("Detected Blood Oxygenation %: "); Serial.println(SPO2);
  }else{
    Serial.println("No blood oxygenation levels detected.");
  }
  delay(100);
}