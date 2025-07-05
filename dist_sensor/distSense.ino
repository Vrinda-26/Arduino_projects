long duration;
int distance;
const int trigPin=11;
const int echoPin=10;
void setup()
{ 
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration=pulseIn(echoPin,HIGH);
  distance=duration*(0.034/2);
  
  Serial.print("Distance :");
  Serial.println(distance);
  

 }