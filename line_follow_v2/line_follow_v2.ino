const int MLDIR = 4;
const int MLPWM = 5;
const int MRDIR = 2;
const int MRPWM = 3;

const int leftPR = A1;
const int rightPR = A2;

const float THRESH = 1.5;

int ml_speed = 255;
int ml_direction = HIGH;

int mr_speed = 255;
int mr_direction = HIGH;
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
  Serial.print("left: ");
  Serial.print(leftVal);
  Serial.print(" right: ");
  Serial.println(rightVal);
  if (0){
    ml_speed = 255;
    mr_speed = 255;
    ml_direction = LOW;
    mr_direction = LOW;
  }
  else if((float) leftVal /(float) rightVal > THRESH){
    mr_speed = 150;
    ml_speed = 150;
    mr_direction = LOW;
    ml_direction = HIGH;
    
  }
  else if((float)rightVal / (float) leftVal > THRESH){
    mr_speed = 150;
    ml_speed = 150;
    mr_direction = HIGH;
    ml_direction = LOW;
  }
  else {
    mr_speed = 255;
    ml_speed = 255;
    mr_direction = HIGH;
    ml_direction = HIGH;
    
  }

}
