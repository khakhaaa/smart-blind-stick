// Rakha Adrian Nur Tanaya SMK TELKOM MALANG
//deklarasi pin
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

//variabel
long duration;
int distance;
int safetyDistance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // hapus trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Set trigPin pada HIGH state 10ms
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // read echoPin
  duration = pulseIn(echoPin, HIGH);
  // menghitung jarak/distance
  distance = duration * 0.034 / 2;
  safetyDistance = distance;
  if (safetyDistance <= 100) {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }
  // Print distance di serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
