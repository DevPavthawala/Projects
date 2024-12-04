#include <SoftwareSerial.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DISPLAY1_ADDRESS 0x27

#define DISPLAY_COLUMNS 16
#define DISPLAY_ROWS 2

LiquidCrystal_I2C lcd1(DISPLAY1_ADDRESS, DISPLAY_COLUMNS, DISPLAY_ROWS);

const String phone = "+919879894854";
const int RX = 3;
const int TX = 2;
// const int IR = 4;
const int button = 7;
const int ledPin = 13;  // the number of the LED pin

bool buttonState = false;


SoftwareSerial sim800(RX, TX);
String smsStatus, senderNumber, receivedDate, msg;
boolean isReply = false;

// int state = 0;


void setup() {
  Serial.println("MESSage ");

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

  lcd1.init();
  lcd1.backlight();
}

void loop() {

  // doAction();


  int buttonState = digitalRead(button);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    // Serial.println("high");
    lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
    lcd1.print("I Am In Trouble");
    lcd1.setCursor(0, 1);
    lcd1.print("Please Help ME");  // Move cursor to the second row of display 2
    ("Please Help ME!!");
    digitalWrite(ledPin, HIGH);
    Reply("I Am In Trouble Please Help ME, Location: https://www.google.com/maps/place/21%C2%B013'21.8%22N+72%C2%B052'44.2%22E");
    Serial.println("I Am In Trouble Please Help ME, Location: https://www.google.com/maps/place/21%C2%B013'21.8%22N+72%C2%B052'44.2%22E");

  } else {
    // turn LED off:
    // Serial.println("low");
    digitalWrite(ledPin, LOW);
    lcd1.setCursor(0, 0);  // Move cursor to the second row of display 2
    lcd1.print("NO Woories      ");
    lcd1.setCursor(0, 1);  // Move cursor to the second row of display 2
    lcd1.print("I AM SAFE       ");
    
  }


  // Handle incoming messages
  // if (sim800.available()) {
  //   while (sim800.available()) {
  //     parseData(sim800.readString());
  //   }
  // }
}


// void parseData(String buff) {
//   Serial.println(buff);

//   unsigned int len, index;
//   //////////////////////////////////////////////////
//   //Remove sent "AT Command" from the response string.
//   index = buff.indexOf("\r");
//   buff.remove(0, index + 2);
//   buff.trim();
//   //////////////////////////////////////////////////

//   //////////////////////////////////////////////////
//   if (buff != "OK") {
//     index = buff.indexOf(":");
//     String cmd = buff.substring(0, index);
//     cmd.trim();

//     buff.remove(0, index + 2);

//     if (cmd == "+CMTI") {
//       //get newly arrived memory location and store it in temp
//       index = buff.indexOf(",");
//       String temp = buff.substring(index + 1, buff.length());
//       temp = "AT+CMGR=" + temp + "\r";
//       //get the message stored at memory location "temp"
//       sim800.println(temp);
//     } else if (cmd == "+CMGR") {
//       extractSms(buff);

//       if (senderNumber == phone) {
//         doAction();
//         gsm_init();
//       }
//     }
//     //////////////////////////////////////////////////
//   } else {
//     //The result of AT Command is "OK"
//   }
// }


// void extractSms(String buff) {
//   unsigned int index;

//   index = buff.indexOf(",");
//   smsStatus = buff.substring(1, index - 1);
//   buff.remove(0, index + 2);

//   senderNumber = buff.substring(0, 13);
//   buff.remove(0, 19);

//   receivedDate = buff.substring(0, 20);
//   buff.remove(0, buff.indexOf("\r"));
//   buff.trim();

//   index = buff.indexOf("\n\r");
//   buff = buff.substring(0, index);
//   buff.trim();
//   buttonState = buff;
//   buff = "";
//   // buttonState.toLowerCase();
// }


// void doAction() {
//   if (buttonState == false) {
//     buttonState = false;
//     digitalWrite(button, buttonState);
//     Serial.println("Sending sms");
//     // lcd.clear();
//     // lcd.setCursor(0, 1);
//     // lcd.print("Sending sms");
//     // lcd.clear();
//     // lcd.setCursor(0, 1);
//     // lcd.print("Light OFF");
//     // Reply("Light OFF");
//   } else if (buttonState == true) {
//     buttonState = true;
//     digitalWrite(button, buttonState);
//     Serial.println("Sending sms");
//     // lcd.clear();
//     // lcd.setCursor(0, 1);
//     // lcd.print("Sending sms");
//     // lcd.clear();
//     // lcd.setCursor(0, 1);
//     // lcd.print("Light ON");
//     Reply("Alert!");
//     buttonState = false;
//   }



//   smsStatus = "";
//   senderNumber = "";
//   receivedDate = "";
//   buttonState = "";
// }


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

// void gsm_init() {
//   Serial.println();
//   Serial.println();
//   Serial.println("Finding Module..");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Finding Module..");
//   boolean at_flag = 1;
//   while (at_flag) {
//     sim800.println("AT");
//     while (sim800.available() > 0) {
//       if (sim800.find("OK"))
//         at_flag = 0;
//     }
//     delay(2000);
//   }
//   Serial.println("Module Connected..");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Module Connected..");
//   delay(1000);
//   Serial.println();
//   Serial.println();
//   Serial.println("Disabling ECHO");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Disabling ECHO");
//   boolean echo_flag = 1;
//   while (echo_flag) {
//     sim800.println("ATE0");
//     while (sim800.available() > 0) {
//       if (sim800.find("OK"))
//         echo_flag = 0;
//     }
//     delay(1000);
//   }

//   Serial.println("Echo OFF");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Echo OFF");
//   delay(1000);
//   Serial.println();
//   Serial.println();
//   Serial.println("Finding Network..");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Finding Network..");
//   boolean net_flag = 1;
//   while (net_flag) {
//     sim800.println("AT+CPIN?");
//     while (sim800.available() > 0) {
//       if (sim800.find("+CPIN: READY")) {
//         net_flag = 0;
//         Reply("SYSTEM READY");
//       }
//     }
//     delay(2000);
//   }
//   Serial.println("Network Found..");
//   // lcd.clear();
//   // lcd.setCursor(0, 1);
//   // lcd.print("Network Found..");
//   // delay(2000);
//   // Serial.println();
//   Serial.println();
// }
