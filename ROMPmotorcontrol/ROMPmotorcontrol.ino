#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS;
Adafruit_DCMotor *liftMotor1;
Adafruit_DCMotor *liftMotor2;
Adafruit_DCMotor *internalRotationMotor;
Adafruit_DCMotor *forearmRotationMotor;

void setup() {
  // put your setup code here, to run once:
  AFMS = Adafruit_MotorShield();
  liftMotor1 = AFMS.getMotor(1);
  liftMotor2 = AFMS.getMotor(2);
  internalRotationMotor = AFMS.getMotor(3);
  forearmRotationMotor = AFMS.getMotor(4);
  AFMS.begin();
  liftMotor1->setSpeed(100);
  liftMotor2->setSpeed(100);
  internalRotationMotor->setSpeed(100);
  forearmRotationMotor->setSpeed(100); 
}

void lift(int direction, int speed, int time) {
  if(direction == 1) {
    liftMotor1->run(FORWARD);
    liftMotor2->run(FORWARD);
    delay(time);
    liftMotor1->run(RELEASE);
    liftMotor2->run(RELEASE);
  }
  if(direction == 1) {
    liftMotor1->run(FORWARD);
    liftMotor2->run(FORWARD);
    delay(time);
    liftMotor1->run(RELEASE);
    liftMotor2->run(RELEASE);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  
}
