/*******************************************************************************
 * POP-BOT V1.0
 * Filename : TouchlessObjectRobot.pde
 ********************************************************************************/

float distance;
int gp2,j;
int Count=0;
int Flag_=0;

void setup(){                   // sets the digital pin as output

   pinMode(3,OUTPUT);           // motor A1
   pinMode(5,OUTPUT);           // motor A2
   pinMode(6,OUTPUT);           // motor B2
   pinMode(9,OUTPUT);           // motor B1
   pinMode(14,OUTPUT);          // PIEZO Speaker
   pinMode(15,INPUT);           // Left Switch
   pinMode(17,INPUT);           // Right Switch
   Beep();Beep();
}

void readGp2(){
    for (int i=0;i<5;i++){                      // Loop 5 times for noise filter
        gp2=(gp2+analogRead(5));
    }
    gp2=gp2/5;
    //distance=(2914/(gp2+5))-1;                  // Convert to Centimetre unit
}

void loop(){

    readGp2();
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

}

