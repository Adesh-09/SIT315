// Define sensor and LED pins
const int motionSensorPin = 2;
const int ledPin = 13;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up sensor and LED pins
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read motion sensor input
  int sensorValue = digitalRead(motionSensorPin);
  
  // Print sensor value to Serial Monitor
  Serial.println(sensorValue);
  
  // Update LED based on sensor input
  if (sensorValue == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Small delay for stability
  delay(100);
}
