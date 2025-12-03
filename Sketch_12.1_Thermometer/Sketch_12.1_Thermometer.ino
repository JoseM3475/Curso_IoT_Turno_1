/**********************************************************************
  Filename    : Thermometer
  Description : Making a thermometer by thermistor.
  Auther      : www.freenove.com
  Modification: 2024/06/19
**********************************************************************/

#define PIN_ANALOG_IN   4

void setup() {
  Serial.begin(115200);
}

void loop() {
  int adcValue = analogRead(PIN_ANALOG_IN);                       // read ADC pin
  double voltage = (float)adcValue / 4095.0 * 3.3;                // calculate voltage
  double Rt = 10 * voltage / (3.3 - voltage);                     // calculate resistance value of thermistor
  double tempK = 1 / (1 / (273.15 + 25) + log(Rt / 10) / 3950.0);  // calculate temperature (Kelvin)
  double tempC = tempK - 273.15;                                  // calculate temperature (Celsius)

  // Mostrar datos normales
  Serial.printf("ADC value : %d,\tVoltage : %.2fV, \tTemperature : %.2fC", adcValue, voltage, tempC);

  // Alerta si pasa de 24 ºC
  if (tempC > 24) {
    Serial.print("  >>> ALERTA: Temperatura ALTA!!!");
  }

  Serial.println(); // salto de línea
  delay(1000);
}

