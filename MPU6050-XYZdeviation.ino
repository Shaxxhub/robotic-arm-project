#include <Arduino.h>
#include <MPU6050_light.h>
#include "Wire.h"

MPU6050 mpu(Wire);

long angle = 0;
unsigned long timer = 0;

void gyroSetUp()
{
  byte status = mpu.begin();
  Serial.print("MPU6050 status: ");
  Serial.println(status);
  while (status != 0)
  {
  } // stop everything if could not connect to MPU6050

  Serial.println("Calculating offsets, do not move MPU6050");
  delay(1000);
  mpu.calcOffsets(true, true); // gyro and accelero
  Serial.println("Done!\n");
}

void PrintAngles()
{
  Serial.print("X: ");
  Serial.print(mpu.getAngleX());
  Serial.print("\tY: ");
  Serial.print(mpu.getAngleY());
  Serial.print("\tZ: ");
  Serial.print(mpu.getAngleZ());
  Serial.print("\n");
}

void setup()
{
  Serial.begin(115200);

  Serial.println("Starting");
  Wire.begin();

  gyroSetUp();
}

void loop()
{
  mpu.update();

  if ((millis() - timer) > 1000)
  {
    PrintAngles();
    timer = millis();
  }
}