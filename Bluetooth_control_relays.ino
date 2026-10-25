#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// პორტების განსაზღვრა
#define LED 23   //Onboard LED
#define RELAY1 32
#define RELAY2 33
#define RELAY3 25
#define RELAY4 26

void setup() {
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
  digitalWrite(RELAY3, LOW);
  digitalWrite(RELAY4, LOW);

  SerialBT.begin("ESP32_4_Relay");

}

void loop() {

  if (SerialBT.available()) {

    char cmd = SerialBT.read();
    switch(cmd) {
      case '1':
        digitalWrite(RELAY1, HIGH);
        break;

      case '2':
        digitalWrite(RELAY1, LOW);
        break;

      case '3':
        digitalWrite(RELAY2, HIGH);
        break;

      case '4':
        digitalWrite(RELAY2, LOW);
        break;

      case '5':
        digitalWrite(RELAY3, HIGH);
        break;

      case '6':
        digitalWrite(RELAY3, LOW);
        break;

      case '7':
        digitalWrite(RELAY4, HIGH);
        break;

      case '8':
        digitalWrite(RELAY4, LOW);
        break;
      
      case '9':
        digitalWrite(LED, HIGH);
        break;

      case '0':
        digitalWrite(LED, LOW);
        break;
      
      case 's':
        String str =
          String(digitalRead(RELAY1)) +
          String(digitalRead(RELAY2)) +
          String(digitalRead(RELAY3)) +
          String(digitalRead(RELAY4)) +
          String(digitalRead(LED));
        SerialBT.print(str);
        Serial.print(str);
        break;
        
    }
  }
}
