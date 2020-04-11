#define trigPin 8
#define echoPin 9
#define buzzer 11
#define led 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  delay(1000);

  if (duration > 2500) {
    noTone(buzzer);
    digitalWrite(led, LOW);
    Serial.println(duration);
    Serial.println("OFF!");
  }
    if (duration < 2500) {
    tone(buzzer, 50);
    digitalWrite(led, HIGH);
    Serial.println("ON!");
    Serial.println(duration);
  }
}
