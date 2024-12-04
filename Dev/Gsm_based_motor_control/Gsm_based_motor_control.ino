#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// #include <SoftwareSerial.h>

// SoftwareSerial Serial1(41, 43);  // RX, TX

const int en = 3;

const int in1 = 5;
const int in2 = 6;

String smsStatus, receivedDate, msg, senderNumber;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(en, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  lcd.setCursor(0, 0);
  Serial.println("     Smart      ");
  lcd.setCursor(0, 1);
  Serial.println("  Motor Driver  ");
  delay(2000);

  lcd.setCursor(0, 0);
  Serial.println("Connecting      ");
  lcd.setCursor(0, 1);
  Serial.println("to Network...   ");
  delay(2000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial1.print("AT+CMGF=1\r");  //SMS text mode
  delay(1000);



  Serial1_init();
  Reply("SYSTEM READY");




  analogWrite(en, 0);

  lcd.clear();
  lcd.setCursor(0, 0);
  Serial.println("Motor Off");
}

void loop() {

  // digitalWrite(in1, HIGH);
  // digitalWrite(in2, LOW);


  // for (int i = 60; i <= 255; i++) {
  //   analogWrite(en, i);
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   Serial.println(i);
  //   delay(50);
  // }

  // for (int i = 255; i >= 60; i--) {
  //   analogWrite(en, i);
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   Serial.println(i);
  //   delay(50);
  // }

  // delay(1000);


  // digitalWrite(in2, HIGH);
  // digitalWrite(in1, LOW);


  // for (int i = 60; i <= 255; i++) {
  //   analogWrite(en, i);
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   Serial.println(i);
  //   delay(50);
  // }

  // for (int i = 255; i >= 60; i--) {
  //   analogWrite(en, i);
  //   lcd.clear();
  //   lcd.setCursor(0, 0);
  //   Serial.println(i);
  //   delay(50);
  // }


  if (Serial1.available()) {
    while (Serial1.available()) {
      Serial.println(Serial1.readString());
      parseData(Serial1.readString());
    }
  }
}


void Serial1_init() {
  // Serial.println("Finding Module..");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Finding Module..");
  delay(1500);
  boolean at_flag = 1;
  while (at_flag) {
    Serial1.println("AT");
    while (Serial1.available() > 0) {
      Serial.println(Serial1.readString());
      if (Serial1.find("OK"))
        at_flag = 0;
    }
    // delay(2000);
  }
  // Serial.println("Module Connected..");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Module Connected..");
  delay(2000);
  // Serial.println();
  // Serial.println();
  // Serial.println("Disabling ECHO");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Disabling ECHO");
  delay(1500);
  boolean echo_flag = 1;
  while (echo_flag) {
    Serial1.println("ATE0");
    while (Serial1.available() > 0) {
      if (Serial1.find("OK"))
        echo_flag = 0;
    }
    // delay(2000);
  }

  // Serial.println("Echo OFF");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Echo OFF");
  delay(2000);
  // Serial.println();
  // Serial.println();
  // Serial.println("Finding Network..");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Finding Network..");
  delay(1500);
  boolean net_flag = 1;
  while (net_flag) {
    Serial1.println("AT+CPIN?");
    while (Serial1.available() > 0) {
      if (Serial1.find("+CPIN: READY")) {
        net_flag = 0;
        // Reply("SYSTEM READY");
        // Reply("SYSTEM READY");
        // Reply("SYSTEM READY");
        // Reply("SYSTEM READY");
        // Reply("SYSTEM READY");
        // delay(5000);
      }
    }
    // delay(2000);
  }
  // Serial.println("Network Found..");
  lcd.clear();
  lcd.setCursor(0, 1);
  Serial.println("Network Found..");
  delay(2000);
  // Serial.println();
  // Serial.println();



  // Serial.println("Setting Mode 1..");
  boolean mode1_flag = 1;
  while (mode1_flag) {
    Serial1.println("AT+CNMI=2,2,0,0,0");
    while (Serial1.available() > 0) {
      if (Serial1.find("OK"))
        mode1_flag = 0;
    }
  }
  // Serial.println("Mode 1 Set..");
  delay(10);

  // Serial.println("Setting Mode 2..");
  boolean mode2_flag = 1;
  while (mode2_flag) {
    Serial1.println("AT+CMGR=1");
    while (Serial1.available() > 0) {
      if (Serial1.find("OK"))
        mode2_flag = 0;
    }
  }
  // Serial.println("Mode 2 Set..");
  delay(10);


  // Serial.println("Sending sms");
  delay(10);

  // Serial.println("Setting SMS Mode..");
  boolean sms_mode_flag = 1;
  while (sms_mode_flag) {
    Serial1.println("AT+CMGF=1\r");
    while (Serial1.available() > 0) {
      if (Serial1.find("OK"))
        sms_mode_flag = 0;
    }
  }



  // Serial1.println("AT");  //Handshaking with SIM900
  // updateSerial();
  // Serial1.println("AT+CSQ");  //Signal quality test, value range is 0-31 , 31 is the best
  // updateSerial();
  // Serial1.println("AT+CCID");  //Read SIM information to confirm whether the SIM is plugged
  // updateSerial();
  // Serial1.println("AT+CREG?");  //Check whether it has registered in the network
  // updateSerial();

  // Serial1.println("ATI");  //Returns the module name and revision.
  // updateSerial();
  // Serial1.println("AT+COPS?");  //Checks which network you are connected to.
  // updateSerial();
  // Serial1.println("AT+COPS=?");  //Returns the list of operators present in the network.
  // updateSerial();
  // Serial1.println("AT+CBC");  //Returns Li-Po battery status. The second number is the battery level (in our case it is 93%) and the third number is the actual voltage in mV (in our case 3.877 V)
  // updateSerial();


  digitalWrite(13, HIGH);
}

void Reply(String text) {
  // Serial.println("sending sms");
  Serial1.println("AT+CMGF=1");  // Configuring TEXT mode
  delay(1000);
  Serial1.println("AT+CMGS=\"+919409462433\"");
  delay(1000);
  // Serial1.print(text);
  Serial1.print(text);
  delay(100);
  Serial.print("msg  ");
  Serial.println(text);
  delay(100);
  // Serial1.write(0x1A);  //ascii code for ctrl-26 //Serial1.println((char)26); //ascii code for ctrl-26
  Serial1.write(26);
  delay(1000);
  // Serial.println("SMS Sent Successfully.");
  // Serial.println("SMS Sent Successfully.");
}

void parseData(String buff) {
  // Serial.println("msg recived");
  unsigned int len, index;
  index = buff.indexOf("\r");
  buff.remove(0, index + 2);
  buff.trim();
  if (buff != "OK") {
    index = buff.indexOf(":");
    String cmd = buff.substring(0, index);
    cmd.trim();

    buff.remove(0, index + 2);

    // Serial.println("buff");
    // Serial.println(buff);

    if (cmd == "+CMT") {

      extractSms(buff);

      // if (senderNumber == PHONE_0) {
      change_attrib();
      // }
      // if (senderNumber == PHONE_1) {
      //   change_attrib_2();
      // }
    }
  } else {
  }
}


void change_attrib() {

  // Serial.println(msg.indexOf("*"));
  // Serial.println(msg.indexOf("#"));
  Serial.println(msg.length());

  if ((msg.indexOf("*") == 0) && (msg.indexOf("#") == msg.length() - 1)) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(en, 0);

    delay(500);
    // Serial.println("ok");

    if (msg.length() == 5) {
      String status = msg.substring(msg.indexOf("*") + 1, msg.indexOf("#"));
      // Serial.println(" status  ");
      // Serial.println(status);

      if (status == "off") {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(en, 0);

        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println("Motor Off");
      }
    } else if (msg.length() > 5) {
      // Serial.println("\n\n\n msg  ");
      // Serial.println(msg);
      String status = msg.substring(msg.indexOf("*") + 1, msg.indexOf(","));
      // Serial.println(" status  ");
      // Serial.println(status);
      msg.remove(0, msg.indexOf(",") + 1);
      // Serial.println(" msg  ");
      // Serial.println(msg);
      String direction = msg.substring(0, msg.indexOf(","));
      // Serial.println(" direction  ");
      // Serial.println(direction);
      msg.remove(0, msg.indexOf(",") + 1);
      // Serial.println(" msg  ");
      // Serial.println(msg);

      String speed = msg.substring(msg.indexOf("=") + 1, msg.indexOf("#"));
      // Serial.println(" speed  ");
      // Serial.println(speed);

      int speed_int = speed.toInt();
      // Serial.println(" speed int  ");
      // Serial.println(speed_int);

      if ((status == "on") && (speed_int <= 10) && (speed_int >= 0) && ((direction == "forward") || (direction == "reverse"))) {
        Serial.println("in");

        lcd.clear();
        lcd.setCursor(0, 0);
        Serial.println("Motor On");
        lcd.setCursor(0, 1);
        Serial.println("Speed ");
        lcd.setCursor(6, 1);
        Serial.println(speed_int);
        lcd.setCursor(9, 1);
        Serial.println(direction);




        analogWrite(en, map(speed_int, 1, 10, 60, 255));
        if (direction == "forward") {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
        }
        if (direction == "reverse") {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
      }
    }
  }




  // // Serial.println("\n\n\n msg  ");
  // // Serial.println(msg);
  // String status = msg.substring(msg.indexOf("*") + 1, msg.indexOf(","));
  // Serial.println(" status  ");
  // Serial.println(status);
  // msg.remove(0, msg.indexOf(",") + 1);
  // // Serial.println(" msg  ");
  // // Serial.println(msg);
  // String direction = msg.substring(0, msg.indexOf(","));
  // Serial.println(" direction  ");
  // Serial.println(direction);
  // msg.remove(0, msg.indexOf(",") + 1);
  // // Serial.println(" msg  ");
  // // Serial.println(msg);

  // String speed = msg.substring(msg.indexOf("=") + 1, msg.indexOf("#"));
  // Serial.println(" speed  ");
  // Serial.println(speed);

  // int speed_int = speed.toInt();
  // Serial.println(" speed int  ");
  // Serial.println(speed_int);

  // if (msg == "on") {
  //   digitalWrite(in1, HIGH);
  //   digitalWrite(in2, LOW);
  // }
  // if ((!Full_status) && (msg == "on")) {
  //   on_status = HIGH;
  //   digitalWrite(RelayPin, LOW);
  //   Reply("Motor Start");
  //   delay(500);
  //   msg = "";
  // }

  // if ((!Full_status) && (msg == "off")) {
  //   on_status = LOW;
  //   digitalWrite(RelayPin, HIGH);
  //   Reply("Motor Stop");
  //   delay(500);
  //   msg = "";
  // }

  // if ((Full_status) && (msg == "on")) {
  //   // on_status = HIGH;
  //   digitalWrite(RelayPin, HIGH);
  //   Reply("Tank already Full");
  //   delay(500);
  //   msg = "";
  // }

  // if ((Full_status) && (msg == "off")) {
  //   // on_status = LOW;
  //   digitalWrite(RelayPin, HIGH);
  //   Reply("Tank already Full && Motor OFF");
  //   delay(500);
  //   msg = "";
  // }
}

void extractSms(String buff) {
  unsigned int index;

  senderNumber = buff.substring(1, 14);

  buff.remove(0, 19);

  buff.remove(0, buff.indexOf("\r"));
  buff.trim();

  index = buff.indexOf("\n\r");
  buff = buff.substring(0, index);
  buff.trim();

  msg = buff;

  msg.toLowerCase();
  Serial.println("\n\n\n msg  ");
  Serial.println(msg);

  buff = "";
}