#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

#include <SD.h>
#include <SPI.h>

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

File test;

int pinCS = 10;
int pinLED = 9;

const int SERIAL_PORT_SPEED = 9600;

void setup() {

  // Serial inilization
  Serial.begin(SERIAL_PORT_SPEED);
  Serial.println("Adafruit_MPL3115A2 test!");

  pinMode(pinCS, OUTPUT);
  pinMode(pinLED, OUTPUT);

  // SD card initialization
  if (!SD.begin()) {
    Serial.println("Card failed, or not present");
    return;
  }

  Serial.println("Card initialized.");

  // Create file and write
  test = SD.open("test.txt", FILE_WRITE);
  test.println("Pressure [Pa] , Altitude [m] , Temperature [*C]");
  test.close();
}

void loop() {

  if (!baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }

  test = SD.open("test.txt", FILE_WRITE);

  if (!test) {
    Serial.println("Error opening file");
    return;
  }

  digitalWrite(pinLED, HIGH);
  Serial.println("File opened, writing");

  float pascals = baro.getPressure();
  test.print(pascals);
  test.print(" , ");

  float altm = baro.getAltitude();
  test.print(altm);
  test.print(" , ");

  float tempC = baro.getTemperature();
  test.print(tempC);
  test.println(" ");
  digitalWrite(pinLED, LOW);
  test.close();

  delay(500);
}
