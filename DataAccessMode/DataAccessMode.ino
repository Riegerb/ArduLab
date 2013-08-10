/*

This program will electronically switch an
ArduLab from Experiment Mode to Data Access
Mode. Once this program is uploaded, a
new drive will appear in 'My Computer'.

Make sure you have an SD Card plugged into
the ArduLab before uploading this program.

How this works:
Once this code is uploaded, the ArduLab will
remain in Experiment Mode for 30 seconds,
it will then switch to Data Access Mode and
a new drive will appear on your computer.
The ArduLab will stay in Data Access Mode for
30 seconds during which time you can access
everything on the SD card as you would any
USB Thumb Drive. After 30 seconds, the
ArduLab will switch back to Experiment Mode.

YOU CAN ONLY UPLOAD A PROGRAM TO THE ARDULAB
WHEN IT IS IN EXPERIMENT MODE.

When the ArduLab is in Data Access Mode, the
Blue LED next to the 'Data Acces' label on
the backside of the ArduLab will be
illuminated. Therefore, when the blue LED is
not illuminated, you can upload programs to
the ArduLab.

If you would like to change the time period
each mode is active, increase or decrease the
number inside the delay(##) function. The
number inside is in Milliseconds therefore,
every 1000 is equivalent to one second. To
change the time it stays in Experiment Mode,
modify the number inside the first delay(##)
function. If you would like to change how
long it stays in Data Access mode, change
the second delay(##) function.

For example, if you wanted the ArduLab to
stay in Experiment Mode for 10 seconds and
in Data Access for 1 minute, you would
modify the first delay(##) to 'delay(10000);'
and the second delay to 'delay(60000);'

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
