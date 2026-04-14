//  Demo function:The application method to drive the DC motor.
//  Author:Frankie.Chu
//  Date:20 November, 2012

#include "MotorDriver.h"

MotorDriver motor;

int max_cicles=20;
int cicles=0;
int maxspd=100;
int speedup=0;
int speeddown=maxspd;

void setup()
{
	/*Configure the motor A to control the wheel at the left side.*/
	/*Configure the motor B to control the wheel at the right side.*/
    Serial.begin(115200);
    while (!Serial); // wait for Leonardo enumeration, others continue immediately
    Serial.print("Starting setup..");
	motor.init();
    motor.stop();
    Serial.println("..end setup.");
}
 
void loop()
{
    if(cicles<max_cicles){
        if(speedup<maxspd){
            moveForward(speedup++);
            delay(50);
        }else if(speeddown>0){
            moveForward(speeddown--);
            delay(50);
        }else{
            speedup=0;
            speeddown=maxspd;
            cicles++;
            motor.stop();
            delay(15000);
        }
    }else{
        motor.stop();
    }
}

void moveForward(int8_t spd){
    motor.goForward();
    motor.setSpeed(spd,MOTORA);
    motor.setSpeed(spd,MOTORB);
}


