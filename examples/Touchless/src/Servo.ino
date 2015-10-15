/** Servo position control **/
void Servo_Home(){
   Servo_Move(1250);
   Servo_Move(1250);
}

void Servo_Move(int val){
   int i;
   for(i=0;i<60;i++){
     digitalWrite(7, HIGH);
     delayMicroseconds(val);
     digitalWrite(7,LOW);
     delay(10);
   }
}

