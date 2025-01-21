// Code to provide update to button press when prompted by user
// If the user types '<button>', then the arduino will respond with the current button status
// If the user types anything else, the arudino will repeat back what it was sent

// ALL MESSAGES MUST BE SENT IN THE FOLLOWING FORMAT:
// <message>

const int buttonPin = 7;
// Corresponds to the digital port that the button / touch sensor is plugged into

const byte numChars = 64; // Longest possible input from Python
char receivedChars[numChars];
boolean newData = false;
boolean prompt = false;

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  static byte ndx = 0;
  char rc;

  char startMarker = '<';
  char endMarker = '>';

  static unsigned long startTime = 0;          // Track the start time for the timeout
  const unsigned long timeoutDuration = 1000;  // Timeout in milliseconds

  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();

    if (recvInProgress == true) {

      if (millis() - startTime >= timeoutDuration) {
        recvInProgress = false;  // Timeout occurred, stop receiving
        ndx = 0;                 // Reset index
        Serial.println("ERROR: RECEIVING TIMED OUT");
        return;  // Exit function
      }

      if (rc != endMarker) {
        receivedChars[ndx] = rc;
        ndx++;
        if (ndx >= numChars) {
          ndx = numChars - 1;
        }
      } else {
        receivedChars[ndx] = '\0';  // terminate the string
        recvInProgress = false;
        ndx = 0;
        newData = true;
      }
    }

    else if (rc == startMarker) {
      recvInProgress = true;
      startTime = millis();  // Record the time when receiving starts
    }
  }
}

void replyToMessage() {
  if (strcmp(receivedChars, "button") == 0){
    int pressed = digitalRead(buttonPin);
    if (pressed == 1) {
      Serial.println("Button is currently pressed!");
    } else {
      Serial.println("Button is currently NOT pressed!");
    }
  } else {
    Serial.print("Recieved the message: "); Serial.println(receivedChars);
  }
}


void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

unsigned int pressedCount = 0;
unsigned int notPressedCount = 0;
void loop() {
  while(newData == false) {
    recvWithStartEndMarkers();
  }
  replyToMessage();
  newData = false;
  delay(100);
}
