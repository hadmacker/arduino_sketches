/*

*/

int currentLed = -1;

char letterIndex[] = "HAPYBIRTDJOS";
// HAPYBIRTDJOS
// @@@@ @@@@@@@@
// @@@@@@@@@@@@@
int positions[] = { 
  /* H */ 12,
  /* A */ 13,
  /* P */ 2,
  /* Y */ 3,
  /* B */ 4,
  /* I */ 5,
  /* R */ 6,
  /* T */ 7,
  /* D */ 8,
  /* J */ 9,
  /* O */ 10,
  /* S */ 11
};

int ledCnt = 13;
int letterDelay = 500;
int blankDelay = 250;
char message[] = "HAPPY BIRTHDAY JOSH";
int currentPosition = 0;
int letterIndexLength = sizeof(letterIndex);
int messageLength = sizeof(message);

int lastLetterLED = 0;
int currentLetterLED = 0;
void setup() {
  Serial.begin(9600);
  Serial.println(message);
  for (int i = 0; i <= ledCnt; i++) {
   pinMode(i, OUTPUT); 
   digitalWrite(i, LOW);
  }
}

void loop() {
  char currentLetter = message[currentPosition];
  int currentLetterPosition = positionOfLetter(currentLetter);
  Serial.println(currentLetter);
  Serial.println(currentLetterPosition);
  
  if(currentLetterPosition > -1){
    currentLetterLED = positions[currentLetterPosition];
    Serial.println(currentLetterLED);
    digitalWrite(lastLetterLED, LOW); 
    delay(blankDelay);
    digitalWrite(currentLetterLED, HIGH);
    delay(letterDelay);
    lastLetterLED = currentLetterLED;
  }
  currentPosition++;
  if(currentPosition >= messageLength)
  {
    currentPosition = 0;
    Serial.println("restart");
  }
}

int positionOfLetter(char letter) {
  for(int i = 0; i < letterIndexLength; i++) {
    if(letterIndex[i] == letter) {
      return i;
    }
  }
  return -1;
}
