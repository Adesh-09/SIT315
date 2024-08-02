// Define sensor and LED pins
const int motionSensorPin = 2;
const int ledPin = 13;
volatile bool motionDetected = false;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up sensor and LED pins
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach interrupt to the motion sensor pin
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionInterrupt, CHANGE);
}

void loop() {
  if (motionDetected) {
    // Print sensor value to Serial Monitor
    Serial.println("Motion detected!");
    
    // Update LED based on sensor input
    digitalWrite(ledPin, HIGH);
    
    // Reset the flag
    motionDetected = false;
  } else {
    digitalWrite(ledPin, LOW);
  }
}

void motionInterrupt() {
  motionDetected = true;
}
