/**************************************************************************
 
   Blink Random Mod (@hpsaturn)
   ________________________________________________________________________

   Turns on/off an LED for 'led_delay' time randomly. Params and random
   output out via serial.

   This example code is in the public domain.
   ________________________________________________________________________

***************************************************************************/

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:

int led = 13;
int led_delay=30;
long zero_count;
long ones_count;
long count;
long count_limit=1000;
long randNumber;

// the setup routine runs once when you press reset:
//
void setup() {                

    // initialize the digital pin as an output.
    Serial.begin(115200);
    Serial.println("\n\n\r=== Blink ===\n");

    int mode=OUTPUT;
    pinMode(led, mode);     
    long seed=analogRead(0);
    randomSeed(seed);

    Serial.print("LED pin : "); Serial.println(led);
    Serial.print("LED mode: "); Serial.println(mode);
    Serial.print("Delay   : "); Serial.println(led_delay);
    Serial.print("Seed    : "); Serial.println(seed);
    Serial.print("Stats   : "); Serial.println(count_limit);

    Serial.println("\n== EndSetup ==\n\r");

}

// the loop routine runs over and over again forever:
//
void loop() {

    randNumber = random(2);
    Serial.print(randNumber);

    if(count==count_limit){
        Serial.println("\n\n\r== Stats ==\n");
        Serial.print("ZEROS: "); Serial.println(zero_count);
        Serial.print("ONES : "); Serial.println(ones_count);
        zero_count=0;
        ones_count=0;
        count=0;
        Serial.println("\n============\n");
    }

    if(randNumber==1){
        ones_count++;
        digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)

    }else{
        zero_count++;
        digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    }

    count++;
    delay(led_delay);               // wait delay

}
