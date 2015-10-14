/*******************************************************************************
* POP-BOT V1.0
* Filename : TouchlessObjectRobot.pde
********************************************************************************/
#include <SoftwareSerial.h>
//#include <TimedAction.h>
#define rxPin 16                         // SLCD pin
#define txPin 16                         // Same pin

SoftwareSerial MySerial = SoftwareSerial(rxPin,txPin);
//TimedAction LCD_Action  = TimedAction(1000,LCD_Show_Vars);
int PosValue[] = {460,610,760,1050,1340,1500,1660,1940,2220};
//int PosValue[] = {460,760,1340,1660,2220,1660,1340,760,460};

//int PosValue[] = {1000,1500};
float distance;
int gp2,j;
int Count=0;
int Flag_=0;

void loop(){
  int i;
  for (i=0;i<5;i++){                    // Loop 5 times for noise filter
    gp2=(gp2+analogRead(5));
  }
  
  gp2=gp2/5;
  distance=(2914/(gp2+5))-1;            // Convert to Centimetre unit
  
  for(j=0;j<2;j++){                   // Check 9 positions
    Servo_Move(PosValue[j]);
   }

  Forward(150);
  if (Count>5){            // Trapped in a croner more than 5 times ?
    Count=0;
    Backward(150);         // Escape from corner
    delay(2000);
    Spin_Right(200);
    delay(800);
  }
  if (digitalRead(15)==0){ // Test left switch
    if(Flag_==1){          // Check previous state
    Count++;
    }
    else{
      Count=0;
    }
    Flag_=0;
    Backward(150);         // Normal operate
    delay(500);
    Spin_Right(200);
    delay(400);
  }
  if (digitalRead(17)==0){ // Test right switch
    if(Flag_==0){          // Check previous state
      Count++;
    }
    else{
      Count=0;
    }
    Flag_=1;
    Backward(150);         // Normal operate
    delay(400);
    Spin_Left(200);
    delay(400);
  } 
  if (gp2>400){                         // Found object
    Backward(200);                      // Move backward to change direction
    delay(300);
    Spin_Left(200); delay(350);         // Change direction
    Count++;
    Beep();
  }
  else{
    Forward(200);                       // Moving forward
  }
  
  //LCD_Action.check();                   // Refresh Display
  
}

