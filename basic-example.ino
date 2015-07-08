//https://tiny-circuits.com/learn/tinyshield-led16

void setup()
{
  // uncomment to setup logging to the Tools > Serial Monitor
  // Serial.begin(9600);

  // pass a zero to turn all LEDs off
  LedOn(0);
}

void loop()
{
  // run the functions you want here...
  // everyOtherOneOddClockWise(20);
  // everyOtherOneOddCounterClockWise(20);
  // everyOtherOneEvenClockWise(20);
  // everyOtherOneEvenCounterClockWise(20);
  // clockWiseCircle(20);
  // counterClockWiseCircle(20);
}

void everyOtherOneOddClockWise(int delayTime)
{
  LedOn(1);
  delay(delayTime);
  LedOn(3);
  delay(delayTime);
  LedOn(5);
  delay(delayTime);
  LedOn(7);
  delay(delayTime);
  LedOn(9);
  delay(delayTime);
  LedOn(11);
  delay(delayTime);
  LedOn(13);
  delay(delayTime);
  LedOn(15);
  delay(delayTime);

}

void everyOtherOneOddCounterClockWise(int delayTime)
{
  LedOn(15);
  delay(delayTime);
  LedOn(13);
  delay(delayTime);
  LedOn(11);
  delay(delayTime);
  LedOn(9);
  delay(delayTime);
  LedOn(7);
  delay(delayTime);
  LedOn(5);
  delay(delayTime);
  LedOn(3);
  delay(delayTime);
  LedOn(1);
  delay(delayTime);
}

void everyOtherOneEvenClockWise(int delayTime)
{
  LedOn(2);
  delay(delayTime);
  LedOn(4);
  delay(delayTime);
  LedOn(6);
  delay(delayTime);
  LedOn(8);
  delay(delayTime);
  LedOn(10);
  delay(delayTime);
  LedOn(12);
  delay(delayTime);
  LedOn(14);
  delay(delayTime);
  LedOn(16);
  delay(delayTime);
}

void everyOtherOneEvenCounterClockWise(int delayTime)
{
  LedOn(16);
  delay(delayTime);
  LedOn(14);
  delay(delayTime);
  LedOn(12);
  delay(delayTime);
  LedOn(10);
  delay(delayTime);
  LedOn(8);
  delay(delayTime);
  LedOn(6);
  delay(delayTime);
  LedOn(4);
  delay(delayTime);
  LedOn(2);
  delay(delayTime);
}

void clockWiseCircle(int delayTime)
{
  for (int i=1; i<=16; i++) {
    LedOn(i);
    delay(delayTime);
  }
}

void counterClockWiseCircle(int delayTime)
{
  for (int i=16; i>=1; i--) {
    LedOn(i);
    delay(delayTime);
  }
}

void LedsOff()
{
  for (int i=5; i<10; i++) {
    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  }
}

void LedOn(int ledNum)
{
  for (int i=5; i<10; i++) {
    // uncomment to setup logging to the Tools > Serial Monitor
    // Serial.print(i);

    pinMode(i, INPUT);
    digitalWrite(i, LOW);
  }

  if (ledNum<1 || ledNum>16) {
    return;
  }

  char highpin[16] = {
    5,6,5,7,6,7,6,8,5,8,8,7,9,7,9,8
  };

  char lowpin[16] = {
    6,5,7,5,7,6,8,6,8,5,7,8,7,9,8,9
  };

  ledNum--;

  digitalWrite(highpin[ledNum],HIGH);
  digitalWrite(lowpin[ledNum],LOW);

  pinMode(highpin[ledNum],OUTPUT);
  pinMode(lowpin[ledNum],OUTPUT);
}
