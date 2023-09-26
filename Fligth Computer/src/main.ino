#include <Wire.h>
#include <Adafruit_MPL3115A2.h>

#include <SD.h>
#include <SPI.h>

#include "config.h"

Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

void setup() {

  pinMode(PIN_CS, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

  pinMode(PIN_OFF, INPUT_PULLUP);

  Serial.begin(SERIAL_PORT_SPEED);

  FILE log_file = SD.open("log/log_file.csv", FILE_WRITE);
  FILE log_errors = SD.open("log/errors.csv", FILE_WRITE);

  // Begin serial starting loop
  for (int i = 0; i < 600; i++) {

    sleep(500);
    digitalWrite(PIN_LED, HIGH);

    if (!log_file) {
      Serial.println("Error opening file");
      continue;
    }

    if (!SD.begin()) {
      Serial.println("Card failed, or not present");
      continue;
    }

    if (!baro.begin()) {
      Serial.println("Couldnt find sensor");
      continue;
    }

    sleep(500);
    digitalWrite(PIN_LED, LOW);

  }

  Serial.println("Everything is OK!");
  digitalWrite(PIN_LED, HIGH);

  log_file.println("Time [ms],Pressure [Pa],Altitude [m],Temperature [*C]");
  log_file.close();
}

void loop() {

  if (digitalRead(PIN_OFF)){
    log_file.close();
    log_errors.close();
    break;
  }

  FILE log_file = SD.open("log/log_file.csv", FILE_WRITE);

  if (!log_file) {
    log_errors.println("["+millis()+"] ERROR: Opening file");
    log_errors.flush();
  }

  digitalWrite(PIN_LED, HIGH);

  log_file.print(millis());

  float pascals = baro.getPressure();
  log_file.print(pascals);
  log_file.print(",");

  float altm = baro.getAltitude();
  log_file.print(altm);
  log_file.print(",");

  float tempC = baro.getTemperature();
  log_file.print(tempC);
  log_file.println(" ");
  digitalWrite(PIN_LED, LOW);
  log_file.flush();

  delay(100);

}
