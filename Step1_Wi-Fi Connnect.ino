#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;
const char *SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
const char *CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";

void setup() {
  Serial.begin(115200);
  BLEDevice::init("ESP32_S3_BLE");

  pServer = BLEDevice::createServer();
  pCharacteristic = pServer->createService(SERVICE_UUID)
                        ->createCharacteristic(
                            CHARACTERISTIC_UUID,
                            BLECharacteristic::PROPERTY_READ |
                                BLECharacteristic::PROPERTY_WRITE);

  pCharacteristic->setValue("Hello BLE");
  pServer->startAdvertising();
  Serial.println("Waiting for a client connection...");
}

void loop() {
  if (deviceConnected) {
    Serial.println("Device connected");
  } else {
    Serial.println("Waiting for a connection...");
  }
  delay(1000);
}
