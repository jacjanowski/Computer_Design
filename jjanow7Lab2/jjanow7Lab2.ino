//******************************************************************************************
//Jacob Janowski - 672941241
//Lab 2 - Input and Output
//Description - This code is supposed to utilize 3 LED with 2 push buttons.
//              We have to light the LEDs in a 3-bit sequence formation. 
//              The program I have written ALLOWS for reading values past 7 bit.
//              It will remain consistent throughtout incrementing/decrementing.

//Assumptions - When it came to the coding, I foreshadowed having to
//              use what we had learned in previous classes, which consist
//              of bitwise manipulation. When it came to architecture,
//              I thought that I would add on top of what I had created
//              from the first lab(since we already had the lights set up).


//References - https://www.arduino.cc/en/Tutorial/Button
//             http://www.ladyada.net/learn/arduino/lesson5.html

//Video Link - https://youtu.be/JhVNMjA7sNM

//****************************************************************************************
int button2 = 2, //name of both buttons
    button3 = 3;    
    
int LED13 = 13, //name of lights that are on each pin
    LED12 = 12, 
    LED11 = 11;    

                     
int buttonUp = LOW, //increase button
    buttonLow = LOW, //decrese button
    currentLED = 0; 
    
bool lowLVL = true; //checks for status of LED
 

void setup() {
  // initialize pins for 7-bit sequence
  for(int i = 0; i < 6; i++){
    pinMode(i, OUTPUT);
  }
  
  // initialize buttons
  pinMode(button2, INPUT);
  pinMode(button3, INPUT); 
}

void loop() {

  //While the lights are off in the beginning, read values.
  do {
    if(buttonLow == LOW){
      buttonUp = digitalRead(button2);
      buttonLow = digitalRead(button3); 
    }
    break;
  }while (buttonUp == LOW);

  //Depending on what status is, make changes. Turn on lights.
  buttonUp == HIGH ? currentLED++ : lowLVL = true;
  buttonLow == HIGH ? currentLED-- : lowLVL =true;

  //reset LED values and mark them as LOW
  if(lowLVL){
    resetLED();
    lowLVL = false;
  }

  //Algorithm: right shift 2 and check if divisible
  //First LED.
  if (((currentLED >> 0) % 2) == 1) {
    digitalWrite(LED13, HIGH);
  }
  //Right shift one to the right and check if divisible
  //Second LED.
  if (((currentLED >> 1) % 2) == 1) {
    digitalWrite(LED12, HIGH);
  }
  //Right shift 2 to the right and check if divisible
  //Third LED.
  if (((currentLED >> 2) % 2) == 1) {
    digitalWrite(LED11, HIGH);
  }
  delay(200);

  //Read final values.
  if(!lowLVL){
    buttonUp = digitalRead(button2);
    buttonLow = digitalRead(button3);
  }

}
//Dim lights to LOW
void resetLED(){
  digitalWrite(LED13, LOW);
  digitalWrite(LED12, LOW);
  digitalWrite(LED11, LOW);
}
