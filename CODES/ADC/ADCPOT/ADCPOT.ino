int potval=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
 potval=analogRead(A0);
//potval=val/4;
Serial.print("POTENIOMETERVALUE = ");
Serial.println(potval);
delay(200);
}
