// Capacitor Timer Reader on ESP32
const int capPin = 32; // Analog pin

void setup() {
  Serial.begin(115200);
  pinMode(capPin, INPUT); // optional, but good practice
}

void loop() {
  int capValue = analogRead(capPin); // read capacitor voltage
  Serial.print("Capacitor Voltage Reading: ");
  Serial.println(capValue);
  delay(200); // wait 200 ms
}
