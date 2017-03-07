#include <Servo.h>
Servo myservo;

/**
 * 棕色: GND
 * 橙色: 5V
 * 黄色: pin9
 */


int pos = 0;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(0);
}

void loop() {
  while (Serial.available() > 0) {
    int num = Serial.parseInt();
    Serial.println(num);
    
    myservo.write(num);
  }
//  for (pos = 0; pos < 90; pos += 1) {
//    myservo.write(pos);
//    delay(15);
//  }
  
//  for (pos = 90; pos > 1; pos -= 1) {
//    myservo.write(pos);
//    delay(15);
//  }
  
}
