// BitsyBoard Petting Zoo
// Jeffrey Stephens 
// Darkious Fanious

// Darkious Fanious likes to have white noise when he sleeps
// When it gets dark, he turns on a fan to keep him calm

int photoPin = A1;  //photoresistor connected to pin A1
int fan = 1;       //DC motor to control fan connected to pin 1

int lightVal;     //Photoresistor Variable
int lightCal;     //Photoresistor Variable


void setup() {
  // put your setup code here, to run once:
  pinMode (LED, OUTPUT);
  lightCal = analogRead(photoPin);
  pinMode(fan, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:

 
  lightVal = analogRead(photoPin);

  //If the PhotoResistor is Darker than when it started, turn fan on 
  if (lightVal < lightCal - 50) {
    digitalWrite(fan, HIGH);
  } else {
    digitalWrite(fan, LOW);
  }

}
