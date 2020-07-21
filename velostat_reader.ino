//Variables for holding  virtual states
String currState = "OFF";
String prevState = "OFF";
String prevprevState = "OFF";
int state = 0; //Actual state fed to VESC
int waitTime = 500; //Time in between state checks
int count = 0; //For tracking consistency

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT_PULLUP);
  digitalWrite(A1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A1);
  float voltage = sensorValue;
  Serial.print(voltage);

  //Cycle virtual states backwards
  prevprevState = prevState;
  prevState = currState;

  //Get current virtual state
  if (voltage > 28){currState = "OFF";}
  else{currState = "ON";}

  Serial.print(" | CurrState: ");
  Serial.print(currState);

  //Conditional for setting actual state to OFF
  if (currState == "OFF" && prevState == "OFF" && prevprevState == "OFF"){
    state = 0;
    count++;
  }

  //Conditional for setting actual state to ON
  if (currState == "ON" && prevState == "ON" && prevprevState == "ON"){
    state = 1;
  }

  Serial.print(" | Status: ");
  Serial.print(state);

  Serial.print(" | Fails: ");
  Serial.println(count);
  delay(waitTime);
  
}
