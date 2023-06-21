/*   
modified on Sep 21, 2020
Modified by MohammedDamirchi from https://github.com/adafruit/Adafruit_MPL3115A2_Library
Home 
*/ 


#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

// Power by connecting Vin to 3-5V, GND to GND
// Uses I2C - connect SCL to the SCL pin, SDA to SDA pin
// See the Wire tutorial for pinouts for each Arduino
// http://arduino.cc/en/reference/wire
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit_MPL3115A2 test!");
}

void loop() {
  if (! baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }
  
  float pascals = baro.getPressure();
  // Our weather page presents pressure in Inches (Hg)
  // Use http://www.onlineconversion.com/pressure.htm for other units
  Serial.print(pascals/3377); Serial.print(" Inches (Hg)\t");

  float altm = baro.getAltitude();
  Serial.print(altm); Serial.print("   meters\t");

  float tempC = baro.getTemperature();
  Serial.print(tempC); Serial.println("*C");

 }
