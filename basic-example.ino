//https://tiny-circuits.com/learn/tinyshield-led16

void setup()
{
  // uncomment to setup logging to the Tools > Serial Monitor
  // Serial.begin(9600);

  // pass a zero to turn all LEDs off
  setLed(0);
}

void loop()
{
  // run the functions you want here...
  // setEveryOtherOddLedClockwise(20);
  // setEveryOtherOddLedCounterClockwise(20);

  // setEveryOtherEvenLedClockwise(20);
  // setEveryOtherEvenLedCounterClockwise(20);

  // stepClockwiseCircle(20);
  // stepCounterClockwiseCircle(20);

  // stepLedGaugeRangeClockwiseFromStart(1, 16);
  // stepLedGaugeRangeClockwiseFromEnd(16, 1);
}

void setLedRaw (int px, int wx, int py, int wy, int m5, int m6, int m7, int  m8, int m9)
{
  digitalWrite(px, wx);
  digitalWrite(py, wy);
  pinMode(5, m5);
  pinMode(6, m6);
  pinMode(7, m7);
  pinMode(8, m8);
  pinMode(9, m9);
}

void setLed (int i)
{
  switch (i) {
    case 1: setLedRaw(5, HIGH, 6, LOW, OUTPUT, OUTPUT, INPUT, INPUT, INPUT); break;
    case 2: setLedRaw(6, HIGH, 5, LOW, OUTPUT, OUTPUT, INPUT, INPUT, INPUT); break;
    case 3: setLedRaw(5, HIGH, 7, LOW, OUTPUT, INPUT, OUTPUT, INPUT, INPUT); break;
    case 4: setLedRaw(7, HIGH, 5, LOW, OUTPUT, INPUT, OUTPUT, INPUT, INPUT); break;
    case 5: setLedRaw(6, HIGH, 7, LOW, INPUT, OUTPUT, OUTPUT, INPUT, INPUT); break;
    case 6: setLedRaw(7, HIGH, 6, LOW, INPUT, OUTPUT, OUTPUT, INPUT, INPUT); break;
    case 7: setLedRaw(6, HIGH, 8, LOW, INPUT, OUTPUT, INPUT, OUTPUT, INPUT); break;
    case 8: setLedRaw(8, HIGH, 6, LOW, INPUT, OUTPUT, INPUT, OUTPUT, INPUT); break;
    case 9: setLedRaw(5, HIGH, 8, LOW, OUTPUT, INPUT, INPUT, OUTPUT, INPUT); break;
    case 10: setLedRaw(8, HIGH, 5, LOW, OUTPUT, INPUT, INPUT, OUTPUT, INPUT); break;
    case 11: setLedRaw(8, HIGH, 7, LOW, INPUT, INPUT, OUTPUT, OUTPUT, INPUT); break;
    case 12: setLedRaw(7, HIGH, 8, LOW, INPUT, INPUT, OUTPUT, OUTPUT, INPUT); break;
    case 13: setLedRaw(9, HIGH, 7, LOW, INPUT, INPUT, OUTPUT, INPUT, OUTPUT); break;
    case 14: setLedRaw(7, HIGH, 9, LOW, INPUT, INPUT, OUTPUT, INPUT, OUTPUT); break;
    case 15: setLedRaw(9, HIGH, 8, LOW, INPUT, INPUT, INPUT, OUTPUT, OUTPUT); break;
    case 16: setLedRaw(8, HIGH, 9, LOW, INPUT, INPUT, INPUT, OUTPUT, OUTPUT); break;
    default: setLedRaw(5, LOW, 6, LOW, OUTPUT, OUTPUT, INPUT, INPUT, INPUT); // off
  }
}

void setEveryOtherOddLedClockwise(int delayTime)
{
  setLed(1);
  delay(delayTime);
  setLed(3);
  delay(delayTime);
  setLed(5);
  delay(delayTime);
  setLed(7);
  delay(delayTime);
  setLed(9);
  delay(delayTime);
  setLed(11);
  delay(delayTime);
  setLed(13);
  delay(delayTime);
  setLed(15);
  delay(delayTime);
}

void setEveryOtherOddLedCounterClockwise(int delayTime)
{
  setLed(15);
  delay(delayTime);
  setLed(13);
  delay(delayTime);
  setLed(11);
  delay(delayTime);
  setLed(9);
  delay(delayTime);
  setLed(7);
  delay(delayTime);
  setLed(5);
  delay(delayTime);
  setLed(3);
  delay(delayTime);
  setLed(1);
  delay(delayTime);
}

void setEveryOtherEvenLedClockwise(int delayTime)
{
  setLed(2);
  delay(delayTime);
  setLed(4);
  delay(delayTime);
  setLed(6);
  delay(delayTime);
  setLed(8);
  delay(delayTime);
  setLed(10);
  delay(delayTime);
  setLed(12);
  delay(delayTime);
  setLed(14);
  delay(delayTime);
  setLed(16);
  delay(delayTime);
}

void setEveryOtherEvenLedCounterClockwise(int delayTime)
{
  setLed(16);
  delay(delayTime);
  setLed(14);
  delay(delayTime);
  setLed(12);
  delay(delayTime);
  setLed(10);
  delay(delayTime);
  setLed(8);
  delay(delayTime);
  setLed(6);
  delay(delayTime);
  setLed(4);
  delay(delayTime);
  setLed(2);
  delay(delayTime);
}

void stepClockwiseCircle(int delayTime)
{
  for (int i = 1; i <= 16; i++) {
    setLed(i);
    delay(delayTime);
  }
}

void stepCounterClockwiseCircle(int delayTime)
{
  for (int i = 16; i >= 1; i--) {
    setLed(i);
    delay(delayTime);
  }
}

void setLedGauge (int value)
{
  const int dt = 100;
  for (int t = 0; t < dt; t++) {
    for (int i = 1; i <= value; i++) {
      setLed(i);
    }
  }
}

void stepLedGaugeRangeClockwiseFromStart(int start, int stop)
{
  for (int i = start; i <= stop; i++) {
    setLedGauge(i);
  }
}

void stepLedGaugeRangeClockwiseFromEnd(int start, int stop)
{
  for (int i = start; i >= stop; i--) {
    setLedGauge(i);
  }
}
