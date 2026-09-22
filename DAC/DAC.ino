#define DAC_PIN 25

void setup() {
}

void loop() {
  dacWrite(DAC_PIN, 0);
  delay(2000);

  dacWrite(DAC_PIN, 64);
  delay(2000);

  dacWrite(DAC_PIN, 128);
  delay(2000);

  dacWrite(DAC_PIN, 192);
  delay(2000);

  dacWrite(DAC_PIN, 255);
  delay(2000);
}
