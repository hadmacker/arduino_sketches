int buttonPin = 4;
int inA = 2;
int inB = 3;
int statusLed = 9;
int buttonState = 0;
int shortDelay = 10;
int longDelay = 60;
int lastState = 0;
int resetDelay = 2000;

void setup() {
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(statusLed, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {

  digitalWrite(statusLed, HIGH);
  
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH 
    && lastState == 0) {
    jiggle(3);    
    lastState = 1;
    delay(resetDelay);
  }
  if (buttonState == LOW) {
   lastState = 0; 
  }
}

void jiggle(int count) {
  digitalWrite(inA, HIGH);
  delay(longDelay);
  digitalWrite(inA, LOW);
  delay(shortDelay);
  digitalWrite(inB, HIGH);
  delay(longDelay);
  digitalWrite(inB, LOW);
  delay(shortDelay);
  if(count > 0) {
    jiggle(--count);
  }
}
