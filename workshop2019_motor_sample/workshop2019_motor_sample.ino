// workshop2019_motor_sample.ino
// This sample code runs the motor in both direction at full speed and half speed.

const int M1DIR = 2;              // DIR goes to 2, but this can be changed to any pin  
const int M1PWM = 3;              // PWM goes to 3, but this can be changed to any pin

void setup() {
  pinMode(M1DIR, OUTPUT);         // set direction pin to outputs
  pinMode(M1PWM, OUTPUT);         // set PWM pin to output
}

void loop() {
  digitalWrite(M1DIR,HIGH);       // cw/ccw
  analogWrite(M1PWM,255);         // full speed. 100% duty cycle
  delay(2000);                    // wait 2 seconds
  analogWrite(M1PWM,128);         // half speed. 50% duty cycle
  delay(2000);                    // wait 2 seconds

  digitalWrite(M1DIR,LOW);        // reverse direction
  analogWrite(M1PWM,255);         // full speed. 100% duty cycle
  delay(2000);                    // wait 2 seconds
  analogWrite(M1PWM,128);         // half speed. 50% duty cycle
  delay(2000);                    // wait 2 seconds
}

  

  
