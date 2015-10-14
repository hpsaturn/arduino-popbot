void setup(){                   // sets the digital pin as output

   pinMode(3,OUTPUT);           // motor A1
   pinMode(5,OUTPUT);           // motor A2
   pinMode(6,OUTPUT);           // motor B2
   pinMode(9,OUTPUT);           // motor B1
   pinMode(7,OUTPUT);           // Servo Motor
   pinMode(14,OUTPUT);          // PIEZO Speaker
   pinMode(15,INPUT);           // Left Switch
   pinMode(17,INPUT);           // Right Switch
   pinMode(txPin,OUTPUT);       // SLCD

   MySerial.begin(9600);
   delay(1000);
   Servo_Home();
   delay(120);
   Beep();
}

