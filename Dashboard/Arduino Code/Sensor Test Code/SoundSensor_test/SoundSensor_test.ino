// Connect the sensor to the A0 (Analog 0) pin on the Arduino board
const int pinSound = A0; 

void setup(){ 
  Serial.begin(9600); 
  delay(100); 
} 

int SoundVal = 0;


void loop()
{ 
SoundVal = analogRead(pinSound); 
Serial.println(SoundVal); 
delay(100); 
} 
