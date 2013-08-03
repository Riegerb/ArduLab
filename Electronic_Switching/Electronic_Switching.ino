/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ADG = 17;
int TS = 16;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ADG, OUTPUT);
  pinMode(TS, OUTPUT);  

  
  //digitalWrite(TS, HIGH); 
  //digitalWrite(ADG, HIGH);
  
  
}

// the loop routine runs over and over again forever:
void loop() {

  delay(50000);
  //delay(100000);
  digitalWrite(TS, HIGH); 
  delay(10000);
  digitalWrite(ADG, HIGH);
  
  
  //  delay(50000);
  digitalWrite(TS, LOW); 
  delay(1000);
  digitalWrite(ADG, LOW);
  delay(60000);


    
 

  //digitalWrite(ADG, LOW);
  //digitalWrite(TS, HIGH);   // turn the LED on (HIGH is the voltage level)
 // delay(1000);               // wait for a second
 // digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
// delay(1000);               // wait for a second
}
