int rightmotorspeed=0;
int leftmotorspeed=0;
int rbs=125,lbs=125;
long distance1=0;
int kp=10;
int ki=0.5;

#define trigPin 22
#define echoPin 24


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //delay(1000); //For testing 
}

void loop() {
  long duration1;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration1 = pulseIn(echoPin, HIGH);
  distance1 = (duration1/2) / 29.1;
pid();


  Serial.println(distance1);
 }
 void pid()
 {
  int setpoint=30;
  int currentposition=distance1;
  int error;
  int sped;
  int k;
  k=k+1;
  int E;
  E=E+error*k;
  error=currentposition-setpoint;
if(E>12)
E=12;
if(E<-12)
E=-12;
   
  sped= kp*error + ki*E;

  rightmotorspeed=rbs+sped;
  leftmotorspeed=lbs+sped;
 
     if(rightmotorspeed>=245)
  rightmotorspeed=245;
    if(leftmotorspeed>=245)
  leftmotorspeed=245;
    if(rightmotorspeed<=0)
  rightmotorspeed=15;
    if(leftmotorspeed<=0)
  leftmotorspeed=15;



  analogWrite(13,rightmotorspeed);
  analogWrite(4,leftmotorspeed);
  }
  



