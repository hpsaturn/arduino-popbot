//  Demo function:The application method to drive the DC motor.
//  Author:Frankie.Chu
//  Date:20 November, 2012

#include "MotorDriver.h"

MotorDriver motor;

void setup()
{
	/*Configure the motor A to control the wheel at the left side.*/
	/*Configure the motor B to control the wheel at the right side.*/
    Serial.begin(115200);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately
    Serial.print("Starting setup..");
	motor.init();
	motor.setSpeed(255,MOTORB);
	motor.setSpeed(255,MOTORA);
    Serial.println("..end setup.");
}
 
void loop()
{
	motor.goForward();
	delay(3000);
    motor.goBackward();
	delay(3000);
    motor.goLeft();
    delay(1000);
    motor.goRight();
    delay(1000);

    /*
	delay(3000);
	motor.stop();
	delay(1000);
	motor.goBackward();
	delay(2000);
	motor.stop();
	delay(1000);
	motor.goLeft();
	delay(2000);
	motor.stop();
	delay(1000);
	motor.goRight();
	delay(2000);
	motor.stop();
	delay(1000);
    */
	
}
