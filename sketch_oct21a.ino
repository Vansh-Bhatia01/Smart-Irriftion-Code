// Define pins
const int moistureSensorPin = A0;
const int relayPin = 7;

// Define moisture threshold
const int moistureThreshold = 310;  // Adjust based on calibration

void setup() {
  pinMode(moistureSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);  // Turn off water pump initially
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(moistureSensorPin);
  Serial.print("Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < moistureThreshold) {
    digitalWrite(relayPin, LOW);  // Turn on water pump
  } else {
    digitalWrite(relayPin, HIGH);  // Turn off water pump
  }

  delay(2000);  // Check moisture every 2 seconds
}
