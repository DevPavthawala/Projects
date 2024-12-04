#include <SoftwareSerial.h>
#include <SparkFun_ADXL345.h>

ADXL345 adxl = ADXL345();
SoftwareSerial bluetooth(2, 3); // RX, TX pins for Bluetooth module

int range = 2; // Range: 2g, 4g, 8g, 16g

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600); // Initialize Bluetooth serial communication

  adxl.powerOn();
  adxl.setRangeSetting(range);
}

void loop() {
  int x, y, z;
  adxl.readAccel(&x, &y, &z);

  if (y >= 150) {
    Serial.print(y);
    bluetooth.println(" Right");
  }
  if (y <= -150) {
    Serial.print(y);
    bluetooth.println(" Left");
  }
  if (x >= 150) {
    Serial.print(x);
    bluetooth.println(" Forward");
  }
  if (x <= -150) {
    Serial.print(x);
    bluetooth.println(" Backward++");
  }
 
  delay(1000);
}