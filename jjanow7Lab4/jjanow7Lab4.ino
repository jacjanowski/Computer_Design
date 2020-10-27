//*************************************************************************************************
//Jacob Janowski - 672941241
//Lab 4 - More complicated input
//Description - This lab will take a photoresistor and have it return particular values
//              that will be read in. These values will display the luminosity of of the sensor
//              and dislpay the values onto the LCD screen. In here, I used a case switch statement
//              that will decipher which values will be assigned to which value string. I then 
//              map the values by supplying a range for the sensor to equip itself with,
//              as well as the bounds of my case statements.

//Assumptions - My inital assumption was thinking about my lab 3 
//              and how i had already finished the LCD screen already. 
//              I assumed that there would be a type of reaading involved with
//              the photoresistor, so my question was how to implement it.
                

//References - https://www.arduino.cc/reference/en/language/structure/control-structure/switchcase/
//             https://www.arduino.cc/en/Tutorial/BuiltInExamples/SwitchCase


//Youtube URL Video link:

//**************************************************************************************************

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int photoResistor = A0;   //value assigned with photo resistor
int LEDvalue = 0, range = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(photoResistor, INPUT);
}

void loop() {
  LEDvalue = analogRead(photoResistor);     //read in value
  range = map(LEDvalue, 0, 350, 0, 4);      //create a map with the sensor values and bounds for case statement.
  lcd.setCursor(0,0);   //initialize where to begin writing to screen.

  //Case-switch: depending on luminosity of sensor, display as follows:
  switch (range) {
  case 0:    // Room is dark; sensor is covered.
    lcd.print("Dark");
    break;
  case 1:    // Dimmly lit room; hand just above the sensor.
    lcd.print("Partially Dark");
    break;
  case 2:    // Medium lit room; hand few inches from sensor.
    lcd.print("Medium");
    break;
  case 3:    // Hand is not near sensor.
    lcd.print("Partially Light");
    break;
  case 4:
        //nothing blocking the senosr
    lcd.print("Fully Lit");
  }
  
  delay(100);

  //No interference with values being read in.
  int index = 0;
  while(index < 16) {
    lcd.print(" ");
    index++;
  }
}
