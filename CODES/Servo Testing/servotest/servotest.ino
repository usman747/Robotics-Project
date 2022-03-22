void setup() {
  // put your setup code here, to run once:
  pinMode(22,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(22,HIGH);
delay(1);      //2 pe out   //1 pe inside
digitalWrite(22,LOW);
delay(18.5);    //18.5 pe out //18.5 pe in

}
