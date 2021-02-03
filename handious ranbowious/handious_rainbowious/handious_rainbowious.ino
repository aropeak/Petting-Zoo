// BitsyBoard Petting Zoo
// Jeffrey Stephens 
// Handious Rainbowious

//Handious Rainbowious likes all kinds of colors
//When he moves his head, he changes colors

int r = 2;  //rgb led, red led connected topin 2
int g = 0;  //rgb led, green led connected to pin 0
int b = 1;  //rgb led, blue led connected to pin 1

int vrx = A3;     //Xaxis of joystick connected to pin A3
int vry = A2;     //Yaxis of joystick connected to pin A2
int xPosition = 0;   //variable that reads vrx
int yPosition = 0;   //variable that reads vry
int mapX = 0;     //mapped value of xPosition
int mapY = 0;     /mapped value of yPosition


void setup() {
  // put your setup code here, to run once:
  pinMode (r, OUTPUT);
  pinMode (g, OUTPUT);
  pinMode (b, OUTPUT);

  pinMode(vrx, INPUT);
  pinMode(vry, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //reads the values of the joysticks and maps them to readable values for LEDs
  xPosition = analogRead(vrx);
  yPosition = analogRead(vry);
  mapX = map(xPosition, 0, 1023, -255, 255);
  mapY = map(yPosition, 0, 1023, -225, 225);


//If joystick is pointing forward, turn green LED on
//If joystick is pointing backwards, turn red LED on
  if(mapX >= 0) {
    analogWrite(g, mapX);
  } else {
    digitalWrite(g, LOW);
  }
  if (mapX < -20) {
    digitalWrite(r, HIGH);
  } else {
    digitalWrite(r, LOW);
  }

  
//If joystick is pointing right, turn blue LED on
//If joystick is pointing left, turn red LED on
    if(mapY >= 0) {
    analogWrite(b, mapY);
  } else {
    digitalWrite(b, LOW);
  }
  if (mapY < -20) {
    digitalWrite(r, HIGH);
  } else {
    digitalWrite(r, LOW);
  }

}
