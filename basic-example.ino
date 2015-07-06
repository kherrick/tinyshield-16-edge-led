/*
TinyDuino Edge LED Demo
  
April 9 2014, by Ben Rose

This example code is in the public domain.

http://www.tiny-circuits.com

*/

void setup()
{
  LedOn(0);//Pass a zero to turn all LEDs off
}

void loop()
{
  for(int i=1;i<16;i++){
    LedOn(i);
    delay(20);
  };
  for(int i=16;i>1;i--){
    LedOn(i);
    delay(20);
  };
}

void LedOn(int ledNum)
{
  for(int i=5;i<10;i++){
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  };
  if(ledNum<1 || ledNum>16) return;
  char highpin[16]={5,6,5,7,6,7,6,8,5,8,8,7,9,7,9,8};
  char lowpin[16]= {6,5,7,5,7,6,8,6,8,5,7,8,7,9,8,9};
  ledNum--;
  digitalWrite(highpin[ledNum],HIGH);
  digitalWrite(lowpin[ledNum],LOW);
  pinMode(highpin[ledNum],OUTPUT);
  pinMode(lowpin[ledNum],OUTPUT);
}