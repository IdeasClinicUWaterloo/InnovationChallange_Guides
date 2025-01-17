const int buttonPin=7; 
// Corresponds to the digital port that the button / touch sensor is plugged into

void setup() {
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

unsigned int pressedCount = 0;
unsigned int notPressedCount = 0;
void loop() {
    int pressed = digitalRead(buttonPin); // 1 if the button is pressed, 0 if it is not
    if(pressed==1)
    {
        pressedCount += 1;
        notPressedCount = 0;
       Serial.print("Button has been pressed for "); Serial.print(pressedCount); Serial.println(" seconds."); 
    }
    else
    {
        pressedCount = 0;
        notPressedCount += 1;
       Serial.print("Button has NOT been pressed for "); Serial.print(notPressedCount); Serial.println(" seconds."); 
    }
    delay(1000);
}

