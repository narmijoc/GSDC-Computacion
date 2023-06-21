#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

#include <SD.h>
#include <SPI.h>

File test;
int pinCS = 10;
int pinLED = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Adafruit_MPL3115A2 test!");
  pinMode(pinCS, OUTPUT);
  pinMode(pinLED, OUTPUT);
  
  if(SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
  test = SD.open("test.txt", FILE_WRITE);
  test.println("Pressure [Pa] , Altitude [m] , Temperature [*C]");
  test.close();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!baro.begin())
  {
    Serial.println("Couldnt find sensor");
    return;
  }
  
  test = SD.open("test.txt", FILE_WRITE);
  
  if(test)
  {
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
    
  } else
  {
    Serial.println("Error opening file");
  }
  delay(500);
}
