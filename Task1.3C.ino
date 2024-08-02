// Define sensor and LED pins
const int motionSensorPin = 2;
const int irSensorPin = A0;
const int ledPin = 13;
volatile bool motionDetected = false;
const int irThreshold = 500; // IR sensor threshold for triggering the LED

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up sensor and LED pins
  pinMode(motionSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach interrupt to the motion sensor pin
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionInterrupt, RISING);
}

void loop() {
  // Check IR sensor
  int irValue = analogRead(irSensorPin);

  // Simulate IR sensor manipulation (for testing purposes)
  // Replace this with your own logic to manipulate IR values in TinkerCad
  irValue = simulateIRSensorValue();

  if (motionDetected && irValue < irThreshold) {
    // Print sensor values to Serial Monitor
    Serial.print("Motion detected! IR sensor value: ");
    Serial.println(irValue);
    
    // Update LED based on sensor inputs
    digitalWrite(ledPin, HIGH);
    
    // Reset the flag
    motionDetected = false;
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(100); // Small delay for stability
}

void motionInterrupt() {
  motionDetected = true;
}

// Function to simulate IR sensor value manipulation
int simulateIRSensorValue() {
  // Replace this with actual IR value manipulation logic
  // For example, you can cycle through different values to test the threshold logic
  static int simulatedValue = 600;
  simulatedValue = (simulatedValue > 300) ? simulatedValue - 100 : 600;
  return simulatedValue;
}
