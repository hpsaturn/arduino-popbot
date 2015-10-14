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
void Motor_Stop(){
   digitalWrite(3,LOW);
   digitalWrite(5,LOW);
   digitalWrite(6,LOW);
   digitalWrite(9,LOW);
}

