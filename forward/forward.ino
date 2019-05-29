const int M1DIR = 2;
const int M1PWM = 3;
const int M2DIR = 4;
const int M2PWM = 5;

void setup() {
  pinMode(M1DIR, OUTPUT);
  pinMode(M1PWM, OUTPUT);
  pinMode(M2DIR, OUTPUT);
  pinMode(M2PWM, OUTPUT);

}

void loop() {
  digitalWrite(M1DIR,HIGH);
  digitalWrite(M2DIR,HIGH);
  analogWrite(M1PWM,255);
  analogWrite(M2PWM,255);
  Serial.println("forward");
  delay(1000);

  
  digitalWrite(M1PWM,0);
  digitalWrite(M2PWM,0);
  Serial.println("stop");
  delay(1000);

  digitalWrite(M1DIR,LOW);
  digitalWrite(M2DIR,LOW);
  analogWrite(M1PWM,255);
  analogWrite(M2PWM,255);
  Serial.println("backward");
  delay(1000);

  digitalWrite(M1PWM,0);
  digitalWrite(M2PWM,0);
  Serial.println("stop");
  delay(1000);

  

}
