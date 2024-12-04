#include <SoftwareSerial.h>

// Configure the software serial port
// SoftwareSerial ; // RX, TX pins respectively
SoftwareSerial gsm(41, 43);

void setup() {
  // Initialize serial ports
  Serial.begin(9600);   // For debugging
  gsm.begin(9600);  // GSM module communication

  // Initialize GSM module
  Serial.println("AT");   // Check communication
  gsm.println("AT");  // Check communication
  bool sms_mode_flag = 1;
  while (sms_mode_flag) {
    gsm.println("AT");
    Serial.println("AT");
    while (gsm.available() > 0) {
      if (gsm.find("OK")) {
        Serial.println("ok");
        sms_mode_flag = 0;
      }
    }

  }
        delay(1000);
  Serial.println("AT+CMGF=1");   // Set SMS mode to text
  gsm.println("AT+CMGF=1");  // Set SMS mode to text
  delay(1000);
  gsm.println("AT+CNMI=2,2,0,0,0"); 
}
  // delayMicroseconds(unsigned long ms) // New SMS notification


void loop() {
  
  if (gsm.available() > 0) {
    // Read incoming data from GSM module
    String msg = gsm.readString();
    Serial.print(msg);  // Print to Serial Monitor



  }



}
