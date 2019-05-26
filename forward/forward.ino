#include <Servo.h>

const int PWM1pin = 3;//A0;   // GPIO pin 14
const int PWM2pin = 5;
const int DIR1pin = 2;   // GPIO pin 32
const int DIR2pin = 4;
const int PWM1Channel = 1;
const int PWM2Channel = 0;
const int freq = 5000;
const int resolution = 8;
const int dutyCycle = 5000;

Servo left;
Servo right;
void setup() {
  Serial.begin(9600);
  
  pinMode(DIR1pin, OUTPUT);
  pinMode(DIR2pin, OUTPUT);
  // put your setup code here, to run once:
  
  digitalWrite(DIR1pin, 1);
  digitalWrite(DIR2pin, 1);


  right.attach(PWM1pin);
  left.attach(PWM2pin);
}

void loop() {
  // put your main code here, to run repeatedly:

  right.write(180);
  left.write(180);
  digitalWrite(DIR1pin, HIGH);
  digitalWrite(DIR2pin, HIGH);
  Serial.println("forward");

  delay(750);
  right.write(0);
  left.write(0);
  digitalWrite(DIR1pin, 1);
  digitalWrite(DIR2pin, 1);
  Serial.println("stop");

  delay(750);
  right.write(180);
  left.write(180);
  digitalWrite(DIR1pin, LOW);
  digitalWrite(DIR2pin, LOW);
  Serial.println("backward");
//
//  delay(750);
//  right.write(0);
//  left.write(0);
//  digitalWrite(DIR1pin, 1);
//  digitalWrite(DIR2pin, 1);
//  Serial.println("stop");

  delay(750);

}
