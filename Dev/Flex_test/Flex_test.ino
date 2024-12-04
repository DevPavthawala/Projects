

#define RELAY_1_PIN 11 // Digital pin for Relay 1
#define RELAY_2_PIN 10 // Digital pin for Relay 2
#define RELAY_3_PIN 9 // Digital pin for Relay 3
#define RELAY_4_PIN 8 // Digital pin for Relay 4

#define BUTTON_1_PIN A1 // Digital pin for Push Button 1
#define BUTTON_2_PIN A2 // Digital pin for Push Button 2
#define BUTTON_3_PIN A3 // Digital pin for Push Button 3
#define BUTTON_4_PIN A4 // Digital pin for Push Button 4



bool buttonState = false;

void setup() {

  // Set relay pins as output
  pinMode(RELAY_1_PIN, OUTPUT);
  pinMode(RELAY_2_PIN, OUTPUT);
  pinMode(RELAY_3_PIN, OUTPUT);
  pinMode(RELAY_4_PIN, OUTPUT);

  // Set button pins as input
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  pinMode(BUTTON_3_PIN, INPUT_PULLUP);
  pinMode(BUTTON_4_PIN, INPUT_PULLUP);

digitalWrite(RELAY_1_PIN, HIGH);
digitalWrite(RELAY_2_PIN, HIGH);
digitalWrite(RELAY_3_PIN, HIGH);
digitalWrite(RELAY_4_PIN, HIGH);
}


void loop() {
 buttonState = digitalRead(BUTTON_1_PIN);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(RELAY_1_PIN, LOW);


  } else {
    // turn LED off:
    digitalWrite(RELAY_1_PIN, HIGH);
  }

  // Check each button and toggle corresponding relay
}


