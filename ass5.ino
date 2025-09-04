// ESP32 Back EMF Detector
// Reads voltage spikes from an inductor using ADC pin
// Displays readings on Serial Monitor

const int emfPin = 35;   // Analog pin connected to voltage divider
const int threshold = 100; // Noise threshold (adjust as needed)

void setup() {
  Serial.begin(115200);
  delay(1000); // Allow time for Serial Monitor to open
  Serial.println("=== ESP32 Back EMF Detector ===");
  Serial.println("Monitoring voltage spikes on pin 35...");
}

void loop() {
  // Read raw ADC value (0 - 4095 on ESP32, 12-bit resolution)
  int emfValue = analogRead(emfPin);

  // Convert ADC value to approximate voltage (assuming 3.3V reference)
  float voltage = (emfValue / 4095.0) * 3.3;

  // Display live readings
  Serial.print("ADC: ");
  Serial.print(emfValue);
  Serial.print("  |  Voltage: ");
  Serial.print(voltage, 3);
  Serial.print(" V");

  // Check if back EMF spike detected
  if (emfValue > threshold) {
    Serial.print("  --> Back EMF detected!");
  }

  Serial.println(); // New line for readability

  delay(200); // Adjust delay for smoother/faster monitoring
}
