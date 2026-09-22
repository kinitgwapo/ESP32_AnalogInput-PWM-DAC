#define POTENTIOMETER_PIN 34
#define PWM_LED_GREEN_PIN 19

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(POTENTIOMETER_PIN, ADC_11db);

  pinMode(PWM_LED_GREEN_PIN, OUTPUT);
  digitalWrite(PWM_LED_GREEN_PIN, LOW);

  // If PWM Configuration fails, it loops for another reconfiguration until it works
  while(true) {
    bool tempvalue = ledcAttach(PWM_LED_GREEN_PIN, 5000, 8);
    delay(100);

    if(tempvalue) {
      Serial.println("PWM Configuration Successful!");
      break;
    }
  }
}

void loop() {
  uint32_t rawAnalogValue = analogRead(POTENTIOMETER_PIN);
  uint32_t dutyValue = constrain(map(rawAnalogValue, 0, 4095, 0, 255), 0L, 255L);
  ledcWrite(PWM_LED_GREEN_PIN, dutyValue);

  Serial.println("Raw Value: " + String(rawAnalogValue) + "\t PWM Duty Value: " + String(dutyValue));
  delay(20);
}
