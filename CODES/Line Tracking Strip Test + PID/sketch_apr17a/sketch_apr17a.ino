void setup() {
  // put your setup code here, to run once:
//int myeraser=7;
//TCCR2B &= ~myeraser;
//int myprescaler=3;
//TCCR2B |= myprescaler;
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(4,235);
analogWrite(13,235);
}
