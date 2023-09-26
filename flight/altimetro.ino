#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

const int SERIAL_PORT_SPEED = 9600;

void setup() {
  Serial.begin(SERIAL_PORT_SPEED);
  Serial.println("Adafruit_MPL3115A2 test!");
}

void loop() {
  if (!baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }

  float pascals = baro.getPressure(); // Our weather page presents pressure in Inches (Hg)

  Serial.print(pascals / 3377);
  Serial.print(" Inches (Hg)\t");

  float altm = baro.getAltitude();
  Serial.print(altm);
  Serial.print("   meters\t");

  float tempC = baro.getTemperature();
  Serial.print(tempC);
  Serial.println("*C");
}
