/*******************************************************************************
* Robo-Spinner V1.0
* Filename : Rectangle_Running.pde
* Running 90 Degree Turnleft And Turnright
********************************************************************************/

int MAX_CICLES=2;   
int ADVANCED=1500;
int cicles=10;

void setup(){
  pinMode(3,OUTPUT);              // Motor A1
  pinMode(5,OUTPUT);              // Motor A2
  pinMode(6,OUTPUT);              // Motor B2
  pinMode(9,OUTPUT);              // Motor B1
  pinMode(2,INPUT);               // LeftSwitch
  pinMode(4,INPUT);               // RightSwitch
  pinMode(14,OUTPUT);             // PIEZO Speaker
}
void Forward(int speed){
  analogWrite(3,speed);
  digitalWrite(5,LOW);
  analogWrite(6,speed);
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
void Motor_Stop(){
   digitalWrite(3,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(9,LOW);
}

void Beep(){
   int i;
   for (i=0;i<1400;i++){  
     digitalWrite(14,HIGH);
     delayMicroseconds(150);
     digitalWrite(14,LOW);
     delayMicroseconds(150);
  }
}
void loop(){

  if (digitalRead(2)==0){         // Switch Di2 Press
     cicles=0;
     Beep();
     delay(1200);
     while(cicles<MAX_CICLES){
//       Forward(2);
//       delay(ADVANCED);
       Spin_Left(230);            // Turnleft 180 degree (adjust)
       delay(400);
       cicles++;
     }
     Motor_Stop();
  }
  if (digitalRead(4)==0){         // Switch Di4 Press
     cicles=0;
     Beep();
     delay(1200);
     while(cicles<MAX_CICLES){
       Forward(255);
       delay(ADVANCED);
       Spin_Right(200);           // Turnleft 180 degree (adjust)
       delay(400);
       cicles++;
     }
     Motor_Stop();
  }

}



