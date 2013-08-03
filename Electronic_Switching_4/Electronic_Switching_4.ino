int experimentTimeSeconds = 30;
int dataModeTimeSeconds = 30;
int ADG = 17;
int TS = 16;
int flag = 0;
unsigned long time;
unsigned long currenttime;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  time = millis();
  Serial.print(time);
  pinMode(ADG, OUTPUT);
  pinMode(TS, OUTPUT); 
   digitalWrite(TS, HIGH); 
  digitalWrite(ADG, HIGH); 
  
  
  
  
  
  
}

// the loop routine runs over and over again forever:
void loop() {
  
   currenttime = millis();  
  if (currenttime-time<dataModeTimeSeconds*1000){
  flag = 1;
  digitalWrite(TS, LOW);
  digitalWrite(ADG, LOW);

  }
  
 if (currenttime-time>experimentTimeSeconds*1000){
  digitalWrite(TS, HIGH); 
  digitalWrite(ADG, HIGH);
  flag=2;
  }
  
}
