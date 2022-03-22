int s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0,s8=0;
void setup() {
  // put your setup code here, to run once:
  
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
s1 = analogRead(A0);
s2 = analogRead(A1);
s3 = analogRead(A2);
s4 = analogRead(A3);
s5 = analogRead(A4);
s6 = analogRead(A5);
s7 = analogRead(A6);
s8 = analogRead(A7);
Serial.println("*****************************************************");
Serial.print("1 = ");
Serial.println(s1);
Serial.print("2 = ");
Serial.println(s2);
Serial.print("3 = ");
Serial.println(s3);
Serial.print("4 = ");
Serial.println(s4);
Serial.print("5 = ");
Serial.println(s5);
Serial.print("6 = ");
Serial.println(s6);
Serial.print("7 = ");
Serial.println(s7);
Serial.print("8 = ");
Serial.println(s8);
Serial.println("*****************************************************");
delay(2000);
}
