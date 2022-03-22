volatile unsigned long pcount=0;
float rev=0,rpm=0,RPM=0,pps=0,rps=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),p_isr,RISING);
}

void loop() {
//  attachInterrupt(digitalPinToInterrupt(2),p_isr,RISING);
  analogWrite(13,210);      //rightmotor
  analogWrite(4,187);      //left motor 
  // put your main code here, to run repeatedly:
  delay(20);
  RPM=rpm_cal();
  Serial.println(pcount);
}

void p_isr() {  
            // pulse ISR for interrupt
  pcount=pcount+1;
}


float rpm_cal() 
{
  
  pps=pcount/0.02;   // pulsespersec
  rps=pps/400;
  rpm=rps*60;
  pcount=0;
  //rpm=rev*3000;   // 1 min=3000-->> 20ms's
  return rpm;
}

