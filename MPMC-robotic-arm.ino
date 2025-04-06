#include <Wire.h>
#include <ESP32Servo.h> 

Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;

const int MPU_addr = 0x68;
int16_t axis_X, axis_Y, axis_Z;
int minVal = 265;
int maxVal = 402;
double x;
double y;
double z;

const int IR_SENSOR_PIN = 12; // Changed to GPIO 12 to avoid conflict with servo_2

void setup() {
  Serial.begin(115200);
  Wire.begin(27, 25); // Initialize I2C with SDA=GPIO27, SCL=GPIO25
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  // Attach servos to GPIO pins
  servo_1.attach(2);
  servo_2.attach(13);
  servo_3.attach(4);
  servo_4.attach(5);

  pinMode(IR_SENSOR_PIN, INPUT); // Set IR sensor pin as input
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);

  axis_X = Wire.read() << 8 | Wire.read();
  axis_Y = Wire.read() << 8 | Wire.read();
  axis_Z = Wire.read() << 8 | Wire.read();

  int xAng = map(axis_X, minVal, maxVal, -90, 90);
  int yAng = map(axis_Y, minVal, maxVal, -90, 90);
  int zAng = map(axis_Z, minVal, maxVal, -90, 90);

  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI);
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  int gripper;
  int irSensorState = digitalRead(IR_SENSOR_PIN); // Read IR sensor

  // Adjust logic based on your sensor's behavior
  if (irSensorState == HIGH) { // Obstacle detected
    gripper = 0; // Close gripper
  } else {
    gripper = 120; // Open gripper
  }

  servo_3.write(gripper);

  // Servo control logic
  if (x >= 0 && x <= 60) {
    int mov1 = map(x, 0, 60, 0, 90);
    servo_1.write(mov1);
  } else if (x >= 300 && x <= 360) {
    int mov2 = map(x, 360, 300, 0, 180);
    servo_2.write(mov2);
  }

  if (y >= 0 && y <= 60) {
    int mov3 = map(y, 0, 60, 90, 180);
    servo_4.write(mov3);
  } else if (y >= 300 && y <= 360) {
    int mov3 = map(y, 360, 300, 90, 0);
    servo_4.write(mov3);
  }
}