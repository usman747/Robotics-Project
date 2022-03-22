//// ---------------------------------------------------------------------------
//// Example NewPing library sketch that does a ping about 20 times per second.
//// ---------------------------------------------------------------------------
//
//#include <NewPing.h>
//
//#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
//
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
//
//void setup() {
//  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
//}
//
//void loop() {
//  delay(100);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
//  Serial.print("Ping: ");
//  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
//  Serial.println("cm");
//}

#define trigPin 22
#define echoPin 24


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
//  pinMode(11, OUTPUT);
//  pinMode(10, INPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration1,duration2, distance1,distance2;
  digitalWrite(trigPin, LOW);  // Added this line
 // digitalWrite(11, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  //digitalWrite(11, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  //digitalWrite(11, LOW);
  duration1 = pulseIn(echoPin, HIGH);
 
  distance1 = (duration1/2) / 29.1;
  



//delay(5);
//
//  digitalWrite(11, LOW);  // Added this line
//  delayMicroseconds(2); // Added this line
//  digitalWrite(11, HIGH);
////  delayMicroseconds(1000); - Removed this line
//  delayMicroseconds(10); // Added this line
//
// duration2 = pulseIn(10, HIGH);
// distance2 = (duration2/2) / 29.1;



  Serial.println("SENSOR 1");
   Serial.print(distance1);
  Serial.println(" cm");
//  Serial.println("SENSOR 2");
//  Serial.print(distance2);
//  Serial.println(" cm");
 }
