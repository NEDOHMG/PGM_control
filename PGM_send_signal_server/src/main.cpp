#include <Arduino.h>
int SwitchA = 25;
int SwitchB = 33;
int SwitchC = 32;
int SwitchD = 27;
int A_past;
int A_now;
int B_past;
int B_now;
int C_past;
int C_now;
int D_past;
int D_now;

int LED = 26;

/*BLE---------------------------------------------------*/
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID "91bad492-b950-4226-aa2b-4ede9fa42f59"
#define CHARACTERISTIC_UUID "0d563a58-196a-48ce-ace2-dfec78acc814"

BLECharacteristic *pCharacteristic;
uint8_t value = 0;
/*------------------------------------------------------*/

void setup()
{
  /*BLE-------------------------------------------------*/
  Serial.println("Starting BLE work!");

  BLEDevice::init("ESP32");
  BLEServer *pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
      CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE |
          BLECharacteristic::PROPERTY_NOTIFY |
          BLECharacteristic::PROPERTY_INDICATE);

  pCharacteristic->setValue("Hello World says Neil");
  pService->start();
  pServer->getAdvertising()->addServiceUUID(BLEUUID(SERVICE_UUID));
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
  /*---------------------------------------------------*/

  Serial.begin(115200);
  pinMode(SwitchA, INPUT);
  pinMode(SwitchB, INPUT);
  pinMode(SwitchC, INPUT);
  pinMode(SwitchD, INPUT);
  pinMode(LED, OUTPUT);
  Serial.println("Serial connection start!!");
  pCharacteristic->setValue("3");
}

void loop()
{
  digitalWrite(LED, HIGH);
  // put your main code here, to run repeatedly:
  A_now = digitalRead(SwitchA);
  B_now = digitalRead(SwitchB);
  C_now = digitalRead(SwitchC);
  D_now = digitalRead(SwitchD);
  if (A_now != A_past)
  {
    if (A_now == HIGH)
    {
      Serial.println("SwitchA");
      pCharacteristic->setValue("0");
    }
    A_past = A_now;
  }
  if (B_now != B_past)
  {
    if (B_now == HIGH)
    {
      Serial.println("SwitchB");
      pCharacteristic->setValue("1");
    }
    B_past = B_now;
  }
  if (C_now != C_past)
  {
    if (C_now == HIGH)
    {
      Serial.println("SwitchC");
      pCharacteristic->setValue("2");
    }
    C_past = C_now;
  }
  if (D_now != D_past)
  {
    if (D_now == HIGH)
    {
      Serial.println("SwitchD");
      pCharacteristic->setValue("3");
    }
    D_past = D_now;
  }
}