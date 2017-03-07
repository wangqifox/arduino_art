
int switchPin1 = 6;
int switchPin2 = 7;

int directionPin = 8;
int DIRECTION = HIGH;
int speedPin = 9;
int SPEED = 255;

void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(directionPin, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

  
}

void loop() {
  go();
  if (reach1()) {
    DIRECTION = HIGH;
    digitalWrite(directionPin, DIRECTION);
    Serial.print("DIRECTION ");
    Serial.println(DIRECTION);
    stop();
    delay(5000);
    go();
    delay(1000);
  } else if (reach2()) {
    DIRECTION = LOW;
    digitalWrite(directionPin, DIRECTION);
    Serial.print("DIRECTION ");
    Serial.println(DIRECTION);
    stop();
    delay(5000);
    go();
    delay(1000);
  }
  Serial.print("DIRECTION ");
  Serial.println(DIRECTION);
//  delay(1000);
}

void go() {
  analogWrite(speedPin, SPEED);
}

void stop() {
  analogWrite(speedPin, 0);
}

boolean reach1() {
  int value1 = digitalRead(switchPin1);
  Serial.print("value1 ");
  Serial.println(value1);
  return value1 == HIGH;
}

boolean reach2() {
  int value2 = digitalRead(switchPin2);
  Serial.print("value2 ");
  Serial.println(value2);
  return value2 == HIGH;
}

