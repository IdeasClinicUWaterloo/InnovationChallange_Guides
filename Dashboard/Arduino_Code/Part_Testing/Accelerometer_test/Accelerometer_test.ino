#include <DFRobot_BMX160.h>
DFRobot_BMX160 bmx160;

void setup(){
  Serial.begin(115200);
  delay(100);
  
  //init the hardware bmx160  
  while (bmx160.begin() != true){
    Serial.println("Initialization failed! Check your wiring.");
    delay(1000);
  }
  delay(100);
}

void loop(){
  //Gets all the sensor data
  sBmx160SensorData_t Omagn, Ogyro, Oaccel;
  bmx160.getAllData(&Omagn, &Ogyro, &Oaccel);

  //Print out the accelerometer raw x, y, and z values to Serial Monitor
  Serial.print("RAW: ");
  Serial.print(Oaccel.x); Serial.print(" "); Serial.print(Oaccel.y    ); Serial.print(" "); Serial.print(Oaccel.z    ); Serial.println(" m/s^2"); 
  delay(100);
}
