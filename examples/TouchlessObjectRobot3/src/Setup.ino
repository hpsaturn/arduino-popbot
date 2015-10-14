void setup(){
   pinMode(3,OUTPUT);                    // sets the digital pin as output
   pinMode(5,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(7,OUTPUT);                   // Servo Motor
   pinMode(14,OUTPUT);                  // PIEZO Speaker
   pinMode(txPin,OUTPUT);
   pinMode(15,INPUT);           // Left Switch
   pinMode(17,INPUT);           // Right Switch
   MySerial.begin(9600);
   delay(1000);
   Servo_Home();
   delay(120);
   Beep();
}

