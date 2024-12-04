#include <SoftwareSerial.h>
// #include <LiquidCrystal.h>

// const int rs = A5, en = A4, d4 = A3, d5 = A2, d6 = A1, d7 = A0;
// LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const String phone = "+917574035609";
const int RX = 2;
const int TX = 3;
const int IR = 4;
const int button = 11;
bool buttonState = false;
const int ledPin = 13;  // the number of the LED pin


SoftwareSerial sim800(2, 3);
String smsStatus, senderNumber, receivedDate, msg;
boolean isReply = false;

// int state = 0;


void setup() {
  Serial.begin(9600);
  sim800.begin(9600);

  // lcd.begin(16, 2);

  pinMode(button, INPUT);
  pinMode(ledPin, OUTPUT);

  // pinMode(IR, INPUT);

  // digitalWrite(button, LOW);

  // lcd.setCursor(0, 1);
  // lcd.print("Automation Project");
  // delay(3000);

  smsStatus = "";
  senderNumber = "";
  receivedDate = "";
  buttonState = "";

  sim800.print("AT+CMGF=1\r");  //SMS text mode
  delay(1000);
  Serial.println("MESSage ");

  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("GSM Initializing");
}

void loop() {




  buttonState = digitalRead(button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Reply("Alert!\n Accident Happen!! \n Locaton : 21,11'03.8\"N 72,48'36.6\"E ");

  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }


  // Handle incoming messages
  if (sim800.available()) {
    while (sim800.available()) {
      parseData(sim800.readString());
    }
  }
}


void parseData(String buff) {
  Serial.println(buff);

  unsigned int len, index;
  //////////////////////////////////////////////////
  //Remove sent "AT Command" from the response string.
  index = buff.indexOf("\r");
  buff.remove(0, index + 2);
  buff.trim();
  //////////////////////////////////////////////////

  //////////////////////////////////////////////////
  if (buff != "OK") {
    index = buff.indexOf(":");
    String cmd = buff.substring(0, index);
    cmd.trim();

    buff.remove(0, index + 2);

    if (cmd == "+CMTI") {
      //get newly arrived memory location and store it in temp
      index = buff.indexOf(",");
      String temp = buff.substring(index + 1, buff.length());
      temp = "AT+CMGR=" + temp + "\r";
      //get the message stored at memory location "temp"
      sim800.println(temp);
    } else if (cmd == "+CMGR") {
      extractSms(buff);

      if (senderNumber == phone) {
        doAction();
        gsm_init();
      }
    }
    //////////////////////////////////////////////////
  } else {
    //The result of AT Command is "OK"
  }
}


void extractSms(String buff) {
  unsigned int index;

  index = buff.indexOf(",");
  smsStatus = buff.substring(1, index - 1);
  buff.remove(0, index + 2);

  senderNumber = buff.substring(0, 13);
  buff.remove(0, 19);

  receivedDate = buff.substring(0, 20);
  buff.remove(0, buff.indexOf("\r"));
  buff.trim();

  index = buff.indexOf("\n\r");
  buff = buff.substring(0, index);
  buff.trim();
  buttonState = buff;
  buff = "";
  // buttonState.toLowerCase();
}


void doAction() {
  if (buttonState == false) {
    buttonState = false;
    digitalWrite(button, buttonState);
    Serial.println("Sending sms");
    // lcd.clear();
    // lcd.setCursor(0, 1);
    // lcd.print("Sending sms");
    // lcd.clear();
    // lcd.setCursor(0, 1);
    // lcd.print("Light OFF");
    // Reply("Light OFF");
  } else if (buttonState == true) {
    buttonState = true;
    digitalWrite(button, buttonState);
    Serial.println("Sending sms");
    // lcd.clear();
    // lcd.setCursor(0, 1);
    // lcd.print("Sending sms");
    // lcd.clear();
    // lcd.setCursor(0, 1);
    // lcd.print("Light ON");
    Reply("Alert!");
    buttonState = false;
  }



  smsStatus = "";
  senderNumber = "";
  receivedDate = "";
  buttonState = "";
}


void Reply(String text) {
  sim800.print("AT+CMGF=1\r");
  delay(1000);
  sim800.print("AT+CMGS=\"" + phone + "\"\r");
  delay(1000);
  sim800.print(text);
  delay(100);
  sim800.write(0x1A);  //ascii code for ctrl-26 //sim800.println((char)26); //ascii code for ctrl-26
  delay(1000);
  Serial.println("SMS Sent Successfully.");
  Serial.println("SMS Sent Successfully.");
}

void gsm_init() {
  Serial.println();
  Serial.println();
  Serial.println("Finding Module..");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Finding Module..");
  boolean at_flag = 1;
  while (at_flag) {
    sim800.println("AT");
    while (sim800.available() > 0) {
      if (sim800.find("OK"))
        at_flag = 0;
    }
    delay(2000);
  }
  Serial.println("Module Connected..");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Module Connected..");
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("Disabling ECHO");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Disabling ECHO");
  boolean echo_flag = 1;
  while (echo_flag) {
    sim800.println("ATE0");
    while (sim800.available() > 0) {
      if (sim800.find("OK"))
        echo_flag = 0;
    }
    delay(1000);
  }

  Serial.println("Echo OFF");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Echo OFF");
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("Finding Network..");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Finding Network..");
  boolean net_flag = 1;
  while (net_flag) {
    sim800.println("AT+CPIN?");
    while (sim800.available() > 0) {
      if (sim800.find("+CPIN: READY")) {
        net_flag = 0;
        Reply("SYSTEM READY");
      }
    }
    delay(2000);
  }
  Serial.println("Network Found..");
  // lcd.clear();
  // lcd.setCursor(0, 1);
  // lcd.print("Network Found..");
  // delay(2000);
  // Serial.println();
  Serial.println();
}
