#include <SD.h>
#include <SPI.h>

File myFile;

const int SERIAL_PORT_SPEED = 9600;

int pinCS = 10; // Pin 10 on Arduino Uno

void setup() {

  Serial.begin(SERIAL_PORT_SPEED);
  pinMode(pinCS, OUTPUT);

  // SD Card Initialization
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    return;
  }

  // Create/Open file
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file didn't open, print an error:
  if (!myFile){
    Serial.println("File open failed!");
    return;
  }

  // If the file opened okay, write to it:
  Serial.println("Writing to file...");

  // Write to file
  myFile.println("Testing text 1, 2 ,3...");
  myFile.close(); // close the file
  Serial.println("Done.");

  /*
  // Reading the file
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("Read:");
    // Reading the whole file
    while (myFile.available()) {
      Serial.write(myFile.read());
   }
    myFile.close();
  }
  else {
    Serial.println("error opening test.txt");
  }
  */
}
void loop() {
  // empty
}
