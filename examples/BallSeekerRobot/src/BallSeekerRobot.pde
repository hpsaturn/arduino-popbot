/*******************************************************************************
 * POP-BOT V1.0
 * Filename : BallSeekerRobot.pde
 * Seek ball and move to it.
 ********************************************************************************/
#include <SoftwareSerial.h>
#define rxPin 16
#define txPin 16

SoftwareSerial MySerial = SoftwareSerial(rxPin,txPin);
int PosValue[] = {460,610,760,1050,1340,1500,1660,1940,2220}; // Servo position value
int GP2[9];
int j,Maximum,Position;

void setup(){
    pinMode(3,OUTPUT);                      // Motor  A1
    pinMode(5,OUTPUT);                      // Motor  A2
    pinMode(6,OUTPUT);                      // Motor  B2
    pinMode(9,OUTPUT);                      // Motor  B1
    pinMode(7,OUTPUT);                      // Servo  Motor
    pinMode(14,OUTPUT);                     // PIEZO  Speaker
    pinMode(txPin,OUTPUT);               // SLCD pin
    MySerial.begin(9600);                // Communication With SLCD
    delay(1000);
    LCD_Clear();                         // LCD Clear Screen
    Beep();
    delay(2000);
}

void loop(){
    Motor_Stop();
    Servo_Home();
    for(j=0;j<9;j++){                   // Set the seeking point 9 positions
        Servo_Move(PosValue[j]);              // Move servo motor
        GP2[j]=analogRead(5);                // Read valei from GP2D120
    }
    Position=MAX_Point();                   // Check lost object condition

    LCD_Show_Vars();

    if(Maximum<20){
        Spin_Right(150);delay(100);       // Turn around if value < 20.
    }
    else if(Maximum>420){                   // Check ball position
        Servo_Move(PosValue[MAX_Point()]);
        Beep();                           // Beep to finish
        delay(10);
        Beep();                           // Beep to finish
        LCD_Show_Vars();
        while(1);
    }
    else{
        switch(Position){                 // Seeking routine
            case 0: Spin_Right(200);
                    delay(320);
                    Forward(200);
                    delay(400-Maximum);
                    break;
            case 1: Spin_Right(200);
                    delay(240);
                    Forward(200);
                    delay(400-Maximum);
                    break;
            case 2: Spin_Right(200);
                    delay(160);
                    Forward(200);
                    delay(400-Maximum);
                    break;
            case 3: Spin_Right(200);
                    delay(80);
                    Forward(200);
                    delay(400-Maximum);
                    break;
            case 4:  Forward(200);
                     delay(400-Maximum);
                     break;
            case 5:  Spin_Left(200);
                     delay(80);
                     Forward(200);
                     delay(400-Maximum);
                     break;
            case 6:  Spin_Left(200);
                     delay(160);
                     Forward(200);
                     delay(400-Maximum);
                     break;
            case 7:  Spin_Left(200);
                     delay(240);
                     Forward(200);
                     delay(400-Maximum);
                     break;
            case 8:  Spin_Left(200);
                     delay(320);
                     Forward(200);
                     delay(400-Maximum);
        }
    }
}
/** Calculate the selected position **/
int MAX_Point(){
    int i,Old=0,max_;
    for(i=0;i<9;i++){
        if(GP2[i]>Old){
            Old=GP2[i];
            max_=i;
        }
    }
    Maximum=Old;
    return(max_);
}
/** Servo position control **/
void Servo_Home(){
    Servo_Move(460);
    Servo_Move(460);
    Servo_Move(460);
    Servo_Move(460);
}
void Servo_Move(int val){
    int i;
    for(i=0;i<5;i++){
        digitalWrite(7, HIGH);
        delayMicroseconds(val);
        digitalWrite(7,LOW);
        delay(20);
    }
}
void Forward(int speed){
    analogWrite(3,speed);
    digitalWrite(5,LOW);
    analogWrite(6,speed);
    digitalWrite(9,LOW);
}
void Motor_Stop(){
    digitalWrite(3,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
}
void Spin_Left(int speed){
    analogWrite(5,speed);
    digitalWrite(3,LOW);
    analogWrite(6,speed);
    digitalWrite(9,LOW);
}
void Spin_Right(int speed){
    analogWrite(3,speed);
    digitalWrite(5,LOW);
    analogWrite(9,speed);
    digitalWrite(6,LOW);
}

/** Beep function **/
void Beep(){
    int i;
    for (i=0;i<600;i++){
        digitalWrite(14,HIGH);
        delayMicroseconds(150);
        digitalWrite(14,LOW);
        delayMicroseconds(150);
    }
}

/** SLCD Function **/
void LCD_Show(int Position,int x){
    MySerial.print(0xFE);          // Clear Screen
    MySerial.print(Position);
    MySerial.print(x,DEC);              // Show Data in Decimal
}
void LCD_Show_Text(int Position,char* x){
    MySerial.print(0xFE);          // Clear Screen
    MySerial.print(Position);
    MySerial.print(x);                  // Show text
}
void LCD_Clear(){
    MySerial.print(0xFE);          // Clear Screen
    MySerial.print(0x01);
}
void LCD_Show_Vars(){
    LCD_Clear();
    LCD_Show_Text(0x80,"Position");
    LCD_Show(0x89,Position);
    LCD_Show_Text(0xC0,"Value = ");
    LCD_Show(0xC8,Maximum);
} 

