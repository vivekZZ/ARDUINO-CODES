#define START_CMD_CHAR '>'
#define END_CMD_CHAR '\n'
#define DIV_CMD_CHAR ','
String inText;
float value0, value1, value2;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
   
  Serial.flush();
}

void loop()
{
  Serial.flush();
  int inCommand = 0;
  int sensorType = 0;
  unsigned long logCount = 0L;

  char getChar = ' ';  //read serial

  // wait for incoming data
  if (Serial.available() < 1) return; // if serial empty, return to loop().

  // parse incoming command start flag 
  getChar = Serial.read();
  if (getChar != START_CMD_CHAR) return; // if no command start flag, return to loop().

  
  sensorType = Serial.parseInt(); 
  logCount = Serial.parseInt(); 
  value0 = Serial.parseFloat(); 
  value1 = Serial.parseFloat(); 
  value2 = Serial.parseFloat(); 

  Serial.println("***********************************************************");
  Serial.print("Sensor = ");
  Serial.println(sensorType);
  Serial.println(value0);
  Serial.println("************************************************************");
  if(value0>3)
  {digitalWrite(13,HIGH);}
  else if(value0<-3)
  {digitalWrite(13,LOW);}
  delay(10);
}



