/*

This program will electronically switch an
ArduLab from Experiment Mode to Data Access
Mode. Once this program is uploaded, a
new drive will appear in 'My Computer'.

Make sure you have an SD Card plugged into
the ArduLab before uploading this program.

NOTE: This program switches the ArduLab to
Data Access Mode Indefinitely, a jumper
must be removed to get back to Experiment
Mode and/or to upload a new program.

*/


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.

  
  DDRH |= B00000011;
  DDRJ |= B00001000;
}

// the loop routine runs over and over again forever:
void loop() 
{
  
  PORTH |= B00000011;
  PORTJ |= B00001000;
  delay(30000);
  
  PORTH &= !(B00000011);
  PORTJ &= !(B00001000);
  delay(30000);
  
}
