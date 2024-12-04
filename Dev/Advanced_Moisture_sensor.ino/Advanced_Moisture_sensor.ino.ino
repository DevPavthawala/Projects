#include <Servo.h>



const int relay1 = 3;  //relay
const int relay2 = 2;
const int servo1Pin = 4;     // Pin connected to first servo motor
const int servo2Pin = 5;     // Pin connected to second servo motor
const int Moisture1 = A0;    //read
const int Moisture2 = A1;    //read
const int sensorPower1 = 7;  //sensorpower

const int sensorPower2 = 6;  //sensorpower


Servo servoMotor1;
Servo servoMotor2;

void setup() {
  Serial.begin(9600);

  pinMode(sensorPower1, OUTPUT);
  pinMode(sensorPower2, OUTPUT);
  digitalWrite(sensorPower1, LOW);
  digitalWrite(sensorPower2, LOW);
  pinMode(Moisture1, INPUT);
  pinMode(Moisture2, INPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  servoMotor1.attach(servo1Pin);
  servoMotor2.attach(servo2Pin);
  servoMotor1.write(0);
  servoMotor2.write(0);
}

void loop() {
  // Serial.println("Analog output: ");
  int data1 = readSensor1();
  int data2 = readSensor2();
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  toOneEighty();
  toZero();

  // Serial.println(data);
  if (data1 <= 600) {
    Serial.println("if");
    digitalWrite(relay1, HIGH);

    delay(1000);
  }


  if (data2 <= 600) {
    Serial.println("if");
    digitalWrite(relay2, HIGH);

    delay(1000);
  }


  // delay(1000);
}

int readSensor1() {
  digitalWrite(sensorPower1, HIGH);  // Turn the sensor ON
  delay(10);                         // Allow power to settle
  int val1 = analogRead(Moisture1);  // Read the analog value form sensor
  digitalWrite(sensorPower1, LOW);   // Turn the sensor OFF
  return val1;                       // Return analog moisture value
}

int readSensor2() {
  digitalWrite(sensorPower2, HIGH);  // Turn the sensor ON
  delay(10);                         // Allow power to settle
  int val2 = analogRead(Moisture2);  // Read the analog value form sensor
  digitalWrite(sensorPower2, LOW);   // Turn the sensor OFF
  return val2;                       // Return analog moisture value
}

void toOneEighty() {
  // Open the bridge gate by rotating both servos to 120 degrees
  servoMotor1.write(180);
  servoMotor2.write(180);
}

void toZero() {
  // Close the bridge gate by rotating both servos to 0 degrees
  servoMotor1.write(0);
  servoMotor2.write(0);
}
