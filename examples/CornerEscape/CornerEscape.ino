/*******************************************************************************
 * POP-BOT V1.0
 * Filename : CornerEscape.pde
 * Robot escapes from corner
 ********************************************************************************/
int Count=0;
int Flag_=0;

void setup(){
    pinMode(3,OUTPUT); // Motor A1
    pinMode(5,OUTPUT); // Motor A2
    pinMode(6,OUTPUT); // Motor B2
    pinMode(9,OUTPUT); // Motor B1
    pinMode(15,INPUT); // Left Switch
    pinMode(17,INPUT); // Right Switch
}

void loop(){
    Forward(150);
    if (Count>5){ // Trapped in a croner more than 5 times ?
        Count=0;
        Backward(150); // Escape from corner
        delay(2000);
        Spin_Right(200);
        delay(800);
    }
    if (digitalRead(15)==0){ // Test left switch
        if(Flag_==1){ // Check previous state
            Count++;
        }
        else{
            Count=0;
        }
        Flag_=0;
        Backward(150); // Normal operate
        delay(500);
        Spin_Right(200);
        delay(400);
    }
    if (digitalRead(17)==0){ // Test right switch
        if(Flag_==0){ // Check previous state
            Count++;
        }
        else{
            Count=0;
        }
        Flag_=1;
        Backward(150); // Normal operate
        delay(400);
        Spin_Left(200);
        delay(400);
    }
}

/******************************************************************************/
void Forward(int speed){
    analogWrite(3,speed);
    digitalWrite(5,LOW);
    analogWrite(6,speed);
    digitalWrite(9,LOW);
}
void Backward(int speed){
    analogWrite(5,speed);
    digitalWrite(3,LOW);
    analogWrite(9,speed);
    digitalWrite(6,LOW);
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
/******************************************************************************/
