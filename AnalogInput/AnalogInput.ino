#define POTENTIOMETER_PIN 34

void setup() {
  // Set Pin 34 Analog to Digital resolution to 12 bits (0-4095 values)
  analogReadResolution(12);

  // Attenuate (Reduce) Pin 34 Max Analog Reading resolution to 150-3100mV (ESP32 Standard) 
  analogSetPinAttenuation(POTENTIOMETER_PIN, ADC_11db);

  Serial.begin(115200);
}

void loop() {
  // Simply Reads and store the raw Analog Value. This value is uncalibrated and represents the ADC reading.
  uint32_t rawAnalogValue = analogRead(POTENTIOMETER_PIN);

  // Automatically calibrates a raw analog value to mV
  uint32_t analogTomV = analogReadMilliVolts(POTENTIOMETER_PIN);

  Serial.println("Raw Value: " + String(rawAnalogValue) + "\t Millivolts: " + String(analogTomV));
  delay(100);
}
