int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;
int wait = 1000;
long duration;
int distance;

const int trigPin = 10;
const int echoPin = 11;

void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo duration
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Reset all LEDs first
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);

  // LED logic based on distance
  if (distance < 50) {
    digitalWrite(pin2, HIGH);
    delay(wait);
  } else if (distance >= 50 && distance < 100) {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    delay(wait);
  } else if (distance >= 100 && distance < 200) {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
    delay(wait);
  } else if (distance >= 200) {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
    digitalWrite(pin5, HIGH);
    delay(wait);
  }
}
