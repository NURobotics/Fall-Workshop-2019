

const int leftPR = A1;
const int rightPR = A2;

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
