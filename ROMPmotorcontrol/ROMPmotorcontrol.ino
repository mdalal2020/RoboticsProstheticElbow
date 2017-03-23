#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *liftMotor1 = AFMS.getMotor(1);
Adafruit_DCMotor *liftMotor2 = AFMS.getMotor(2);
Adafruit_DCMotor *internalRotationMotor = AFMS.getMotor(3);
Adafruit_DCMotor *forearmRotationMotor = AFMS.getMotor(4);

void setup() {
  // put your setup code here, to run once
  AFMS.begin();
  liftMotor1->setSpeed(100);
  liftMotor2->setSpeed(100);
  internalRotationMotor->setSpeed(100);
  forearmRotationMotor->setSpeed(100); 
}

void lift(int direction, int speed, int time) {
  liftMotor1->setSpeed(speed);
  liftMotor2->setSpeed(speed);
  if(direction == 1) {
    liftMotor1->run(FORWARD);
    liftMotor2->run(FORWARD);
    delay(time);
    liftMotor1->run(RELEASE);
    liftMotor2->run(RELEASE);
  }
  if(direction == -1) {
    liftMotor1->run(BACKWARD);
    liftMotor2->run(BACKWARD);
    delay(time);
    liftMotor1->run(RELEASE);
    liftMotor2->run(RELEASE);
  }
}
int signal1[] = {1, 100};
int signal2[] = {1, 200};
int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  //We get signal1, signal2, and signal3 from the sensors
  //signals have (direction, speed)
  
  if (signal1!=NULL){
    lift(signal1[0], signal1[1],1);
    }
 if (signal2!=NULL){
    rotate(signal2[0], signal2[1],1);
  }
 counter+=1;
 if (counter==1000){
  signal2[] = NULL;
  }
}
 
 
   
















  
  
}
