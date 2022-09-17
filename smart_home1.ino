// C++ code
//
int a=2;int b=3;
void setup()
{ 
  Serial.begin(9600);
  pinMode(a,OUTPUT); 
  pinMode(b,INPUT); 
  pinMode(12,OUTPUT);
} 
void loop()
{ 
  //ultrasonic sensor 
  digitalWrite(a,LOW); 
  digitalWrite(a,HIGH); 
  delayMicroseconds(10); 
  digitalWrite(a,LOW); 
  float dur=pulseIn(b,HIGH);
  float dis=(dur*0.0343)/2; 
  Serial.print("Distance is: "); 
  Serial.println(dis); 
  //LED ON 
  if(dis>=100) 
  { 
    digitalWrite(8,HIGH);
  }
  else
  {
    digitalWrite(8,LOW);
  } 
  //Buzzer For ultrasonic Sensor 
  if(dis>=100) 
  { 
    digitalWrite(12,HIGH);
    delay(500);
  }
  else
  {
    digitalWrite(12,LOW);
    delay(500);
  } 
  //Temperate Sensor
  double a= analogRead(A4); 
  double t=(((a/1024)*5)-0.5)*100; 
  Serial.print("Temp Value: "); 
  Serial.println(a);
  //LED ON 
  if(t>=100) 
  { 
    digitalWrite(7,HIGH);
  }
  else
  {
    digitalWrite(7,LOW);
  } 
  //Buzzer for Temperature Sensor 
  if(t>=100)
  { 
    digitalWrite(12,HIGH);
    delay(500);
  }
  else{
    digitalWrite(12,LOW);
    delay(500);
  } 
}