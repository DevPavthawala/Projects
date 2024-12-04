#include <SoftwareSerial.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DISPLAY1_ADDRESS 0x27

#define DISPLAY_COLUMNS 16
#define DISPLAY_ROWS 2

LiquidCrystal_I2C lcd1(DISPLAY1_ADDRESS, DISPLAY_COLUMNS, DISPLAY_ROWS);

SoftwareSerial gsm(3, 2);

String password;  // Variable to store the extracted password
String message;
String inputString;
const int relay = 4;


void setup() {

                       
    if (message == "on") {
      digitalWrite(relay, HIGH);
      Serial.println("on ");

      lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
      lcd1.print("Password Correct");
      delay(1000);
        lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
      lcd1.print("Motor Start     ");
    } else if (message == "off") {
      Serial.println("off ");
      digitalWrite(relay, LOW);
      lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
      lcd1.print("Password Correct");
      delay(1000);
        lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
      lcd1.print("Motor Stop      ");
    }
  }

