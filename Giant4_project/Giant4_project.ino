#define RELLAY 0 //Реле 0-низкого уровня 1-высокого уровня


#include <Servo.h>
Servo myservo;

int pos = 0;
void setup() {
  myservo.attach(3);
  pinMode(4, INPUT);
  pinMode(5, OUTPUT);
  digitalWrite(5, RELLAY);
  Serial.begin(9600);
}
void loop() {
  Serial.println(digitalRead(4));
  if (RELLAY == 0){
    digitalWrite(5, digitalRead(4));
  }
  else {
    digitalWrite(5, !digitalRead(4));
  }
  if (digitalRead(4) == LOW){
    if (pos <= 180){
      pos += 20;
    }
    else{
      myservo.write(0);
      pos = 0;
    }
    delay(1000);
    myservo.write(pos);
  }
}
