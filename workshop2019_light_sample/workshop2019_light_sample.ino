// workshop2019_light_sample.ino
// This sample code reads phototransistor readings and prints it on the serial monitor

// PT (analog input from phototransistor) goes to A1 
const int PT = A1;

// declare a integer variable that stores analogRead value                        
int val;         
                         
// the setup routine will run only once when the program starts
void setup() { 
  pinMode(PT, INPUT);                     // initialize PT as an input
  Serial.begin(9600);                     // start the serial monitor
  Serial.println("The device started");   // print test line onto the serial monitor
}

// the loop routine will run over and over again forever
void loop() { 
  val = analogRead(PT);                   // read the sensor and store it in val
  Serial.print("Light sensor val: ");     // print the val onto the serial monitor
  Serial.println(val);                    // println() starts a new line after printing
  delay(50);                              // wait for 50 ms
}
