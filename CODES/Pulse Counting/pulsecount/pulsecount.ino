int rev=0;
int counter=0;
void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(2),count,RISING);
Serial.begin(9600);
  analogWrite(13,180);
  analogWrite(4,180);
}

void loop() {
  // put your main code here, to run repeatedly:
  
if(rev>=50)
{
  off(1);
  detachInterrupt(digitalPinToInterrupt(2));
}
Serial.print("PULSE ");
Serial.println(counter);
Serial.print("REV ");
Serial.println(rev);
}

void count()
{
  counter=counter+1;
    if(counter>=30)
  {
   rev=rev+1; 
   counter=0;
  }

}
void off(int a)
{
  if(a==1)
  {
      analogWrite(13,255);
      analogWrite(4,255);
  }
  else
  {
    analogWrite(13,180);
    analogWrite(4,180);
    }
}
