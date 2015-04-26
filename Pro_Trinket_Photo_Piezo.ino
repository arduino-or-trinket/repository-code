#define SPEAKER   8
#define PHOTOCELL 1
#define SCALE     2

void setup() {
  pinMode(SPEAKER,OUTPUT);
}

void loop() {
  int reading=analogRead(PHOTOCELL);
  
  int freq=220+(int)(reading*SCALE);
  beep(SPEAKER,freq,400);
  delay(50);
}

void beep (unsigned char speakerPin,
int frequencyInHertz,
long timeInMilliseconds) {
  int x;
  long delayAmount = (long)(1000000/frequencyInHertz);
  long loopTime = (long) ((timeInMilliseconds*1000)/(delayAmount*2));
  
  for (x=0; x<loopTime; x++) {
    digitalWrite(speakerPin,HIGH);
    delayMicroseconds(delayAmount);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(delayAmount);
  }
}
