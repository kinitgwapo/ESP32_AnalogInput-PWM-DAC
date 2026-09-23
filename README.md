# ESP32_AnalogInput-PWM-DAC

### Analog Input Reading Table

| Potentiometer Positions | Raw Value | MilliVolts | Expected |
| :---------------------: | :-------: | :--------: | :------: |
| 0%                      | 0         | 142 mV     | 0 V      |
| 25%                     | 1023      | 940 mV     | 775 mV   |
| 50%                     | 2047      | 1.746 V    | 1.55 V   |
| 75%                     | 3071      | 2.538 V    | 2.325 V  |
| 100%                    | 4095      | 3.108 V    | 3.1 V    |

### PWM Reading Table

| Raw Value | PWM Duty Value | Expected |
| :-------: | :------------: | :------: |
| 0         | 0              | 0        |
| 1023      | 63             | 63.75    |
| 2047      | 126            | 127.5    |
| 3071      | 191            | 191.25   |
| 4095      | 255            | 255      |

### DAC Reading Table

| DAC Value | MultiMeter Value | Expected |
| :-------: | :--------------: | :------: |
| 0         | 109.1 mV         | 0 V      |
| 64        | 890 mV           | 0.825 mV |
| 128       | 1.677 V          | 1.65 V   |
| 192       | 2.458 V          | 2.475 V  |
| 255       | 3.218 V          | 3.3 V    |

PWM output is produced by a the averaging of the duty cycle, while the DAC converts from digital value to actual voltage value (eg. digital 2047 ≈ Half of DAC Maximum GPIO Voltage output)

ADC Saturation means that the input can only represent what its highest digital value could achieve, such as a 12-bit resolution (0-4095 integer values). When your analog signal exceeds above the resolution, the digital value simply caps out and only output 4095 (for 12-bit) and won't follow beyond that.
