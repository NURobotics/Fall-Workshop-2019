

const int leftPR = A6;
const int rightPR = A7;

void setup() {
  Serial.begin(9600);
  pinMode(leftPR, INPUT);
  pinMode(rightPR, INPUT);
  Serial.println("The device started");
}

void loop() {
  int leftVal, rightVal;
  leftVal = analogRead(leftPR);
  rightVal = analogRead(rightPR);
  Serial.print("left: ");
  Serial.print(leftVal);
  Serial.print(" right: ");
  Serial.println(rightVal);
  delay(50);
}
