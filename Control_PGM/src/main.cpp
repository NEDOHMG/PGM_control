#include <Arduino.h>
#include "BluetoothSerial.h"

// Create one object of the BluetoothSerialClass
BluetoothSerial SerialBT;

int PGM_ValveA = 25;
int PGM_ValveB = 33;
int PGM_ValveC = 26;

bool ValveState = false;

int dataReceived = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(PGM_ValveA, OUTPUT);
  pinMode(PGM_ValveB, OUTPUT);
  pinMode(PGM_ValveC, OUTPUT);

  digitalWrite(PGM_ValveA, LOW);
  digitalWrite(PGM_ValveB, LOW);
  digitalWrite(PGM_ValveC, LOW);

  // This will stat the Bluetooth
  SerialBT.begin("ESP32NEDO");
}

void loop()
{

  SerialBT.read();
  dataReceived = SerialBT.parseInt();

  if (dataReceived == 5)
  {
    // SerialBT.end(); // Call the reset function
    SerialBT.end();
    ESP.restart();
  }

  if (dataReceived == 1)
  {
    ValveState = true;
  }
  else if (dataReceived == 0)
  {
    ValveState = false;
  }

  if (ValveState == true)
  {
    digitalWrite(PGM_ValveA, HIGH);
    digitalWrite(PGM_ValveB, HIGH);
    digitalWrite(PGM_ValveC, HIGH);
    delayMicroseconds(2000000);
  }
  else if (ValveState == false)
  {
    digitalWrite(PGM_ValveA, LOW);
    digitalWrite(PGM_ValveB, LOW);
    digitalWrite(PGM_ValveC, LOW);
  }
}
