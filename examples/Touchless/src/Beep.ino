
void Beep(){
    int i;
    for (i=0;i<1100;i++){  
        digitalWrite(14,HIGH);
        delayMicroseconds(150);
        digitalWrite(14,LOW);
        delayMicroseconds(150);
    }
}

