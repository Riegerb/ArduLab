/*

Welcome to the ArdLab Family! This program,
when uploaded to the ArduLab will light up the
four underside LEDs sequentially. This serves
as a great first program to make sure your
ArduLab is properly connected and operating.

Don't worry about understanding this code. These
LEDs have a special syntax because we have saved
all of the easy-to-use pins for your use! =)

Confirm that the 4 LEDs are flashing on the
underside of your ArduLab and continue to the
next step of 'Getting Started'

*/


//The Setup block initializes the LED pins for use
void setup() {        

  DDRJ |= B01111000;

}

// the loop routine flashes the LEDS over and over forever
void loop() {

  //LEDS
  delay(200);
  DDRJ |= B01000000;
  PORTJ |= B01000000;
  
  delay(200);
  DDRJ |= B01100000;
  PORTJ |= B01100000;  

  delay(200);
  DDRJ |= B01110000;
  PORTJ |= B01110000;
  
  delay(200);
  DDRJ |= B01111000;
  PORTJ |= B01111000; 
  

  delay(200);
  DDRJ &= !(B01111000);
  PORTJ &= !(B01111000);

  DDRJ &= !(B01111000);
  PORTJ &= !(B01111000);
}
