const int MLDIR = 2;
const int MLPWM = 3;
const int MRDIR = 4;
const int MRPWM = 5;

const int leftPR = A1;
const int rightPR = A2;

const float THRESH = 1.25;

int ml_speed = 255;
int ml_direction = HIGH;

int mr_speed = 255;
int mr_direction = HIGH;

float prevratio =1;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(MLDIR, OUTPUT);
  pinMode(MLPWM, OUTPUT);
  pinMode(MRDIR, OUTPUT);
  pinMode(MRPWM, OUTPUT);

  pinMode(leftPR, INPUT);
  pinMode(rightPR, INPUT);

  Serial.println("The device has started");

}

void loop() {
  digitalWrite(MLDIR, ml_direction);
  analogWrite(MLPWM, ml_speed);
  digitalWrite(MRDIR, mr_direction);
  analogWrite(MRPWM, mr_speed);

  int leftVal, rightVal;
  leftVal = analogRead(leftPR);
  rightVal = analogRead(rightPR);
  Serial.print("L: ");
  Serial.print(ml_speed);
  Serial.print("\tR: ");
  Serial.print(mr_speed);
  Serial.print("left: ");
  Serial.print(leftVal);
  Serial.print(" right: ");
  Serial.print(rightVal);
  float ratio = (float) leftVal / (float) rightVal;
  Serial.print(" ratio: ");
  Serial.print(ratio);
  Serial.print(" prevratio: ");
  Serial.println(prevratio-ratio);
  if (0){
    ml_speed = 255;
    mr_speed = 255;
    ml_direction = LOW;
    mr_direction = LOW;
  }
  else if(ratio > 1.2){
    mr_speed = max((int)(200-(50*ratio)-200*(ratio-prevratio)),0);
    ml_speed = 200;
    mr_direction = HIGH;
    ml_direction = HIGH;
    
  }
  else if(ratio < 0.83){
    mr_speed = 200;
    ml_speed = max((int)(200-(50/ratio)-200*(prevratio-ratio)),0);
    mr_direction = HIGH;
    ml_direction = HIGH;
  }
  else {
    mr_speed = 200;
    ml_speed = 200;
    mr_direction = HIGH;
    ml_direction = HIGH;
  }

  prevratio = ratio;

}
