/*
ArduLab Plant Growth
 */

#include <OneWire.h> 

//Start Temperature Sensor Code
int DS18S20_Pin = 10; //DS18S20 Signal pin on digital 10

//Temperature chip i/o
OneWire ds(DS18S20_Pin); 

unsigned long startTime;
unsigned long currentTime;

//End temperature Code

// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600);  

  //Pin for controlling HACK HD Camera  
  pinMode(25,OUTPUT);
       //Keep  pin 25 high (HACK HD Disabled)
    digitalWrite(25, HIGH);
  
  startTime = millis();
  Serial.println(startTime);
}

void loop() {
  
 
  
  currentTime = millis();
  
  
  if (currentTime > startTime + 20000){
  
    //Enable HACK HD Camera / The four lines are signal drop to enable/disable the camera

    digitalWrite(25, LOW);
    delay(500);
    digitalWrite(25, HIGH);
    float temperature = getTemp();
    Serial.println(temperature);
    
    startTime = millis();
    Serial.println(startTime);
  }
  


}



float getTemp(){
 //returns the temperature from one DS18S20 in DEG Celsius

 byte data[12];
 byte addr[8];

 if ( !ds.search(addr)) {
   //no more sensors on chain, reset search
   ds.reset_search();
   return -1000;
 }

 if ( OneWire::crc8( addr, 7) != addr[7]) {
   Serial.println("CRC is not valid!");
   return -1000;
 }

 if ( addr[0] != 0x10 && addr[0] != 0x28) {
   Serial.print("Device is not recognized");
   return -1000;
 }

 ds.reset();
 ds.select(addr);
 ds.write(0x44,1); // start conversion, with parasite power on at the end

 byte present = ds.reset();
 ds.select(addr);  
 ds.write(0xBE); // Read Scratchpad

 
 for (int i = 0; i < 9; i++) { // we need 9 bytes
  data[i] = ds.read();
 }
 
 ds.reset_search();
 
 byte MSB = data[1];
 byte LSB = data[0];

 float tempRead = ((MSB << 8) | LSB); //using two's compliment
 float TemperatureSum = tempRead / 16;
 
 return TemperatureSum;
 
}
