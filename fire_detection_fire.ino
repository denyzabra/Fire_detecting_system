// Flame sensor pin
const int flamePin = 2;

// Buzzer pin
const int buzzerPin = 3;

// Temperature sensor pin
const int tempPin = A0;

// Threshold values
const int flameThreshold = 500; // Adjust this value based on your sensor
const int tempThreshold = 30; // Adjust this value based on your desired temperature threshold

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read flame sensor value
  int flameValue = analogRead(flamePin);

  if (flameValue > flameThreshold) {
    digitalWrite(buzzerPin, HIGH); // Activate the buzzer
    Serial.println("Fire detected!");
  } else {
    digitalWrite(buzzerPin, LOW); // Deactivate the buzzer
  }

  // Read temperature sensor value
  float tempValue = analogRead(tempPin) * 0.48828125; // Convert analog reading to voltage
  tempValue = tempValue / 10.0; // Convert voltage to temperature in Celsius

  Serial.print("Temperature: ");
  Serial.print(tempValue);
  Serial.println("°C");

  if (tempValue > tempThreshold) {
    Serial.println("High temperature detected!");
  }

  delay(1000); // Delay for stability
}
