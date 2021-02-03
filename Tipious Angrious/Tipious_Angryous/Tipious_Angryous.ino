// BitsyBoard Petting Zoo
// Jeffrey Stephens 
// Tipious Angryous

// Tipious Angryous likes to stay upright
// He will BUZZ and glow red when he is flipped


int LED = 3;           // led connected to pin 3
int buzz = 2;          // active buzzer connected to pin 2
int tilt = 4;          // tilt ball sensor connected to pin 4
int tiltVal;
int lastTiltState = HIGH;  //previous reading from tilt sensor

long lastDebounceTime = 0;  //debounce variable
long debounceDelay = 50;    //debounce variable 

void setup() {
  // put your setup code here, to run once:

  pinMode(LED, OUTPUT);
  pinMode(buzz, OUTPUT);

  pinMode(tilt, INPUT);
  digitalWrite(tilt, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tilt);   

  tiltChange();

  //Switches cases based off the Tilt Sensor 
  switch (tiltVal) {
    case 0:
      digitalWrite(LED, LOW);
      noTone(buzz);
      break;
    case 1:
      digitalWrite(LED, HIGH);
      tone(buzz, 600, 100);
      tone(buzz, 2000, 100);
      break;
  }
}

//Debounce for the Tilt Sensor
void tiltChange() {  

  if (tiltVal == lastTiltState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    lastTiltState = tiltVal;
  }
  delay(500);
}
