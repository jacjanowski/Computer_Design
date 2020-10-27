 //********************************************************************************
//Jacob Janowski - 672941241 
//Lab 5 - Multiple Inputs and Outputs
//
//Description: In this lab, we are asked to produce a noise 
//             output utilizing our buzzer at the same time 
//             creating another output with 4 LEDs. Our input
//             will use a photoresistor that will read in values
//             and display a specific amount of lights to illuminate.
//
//Assumption: I assumed that we would somehow relate this lab with lab 1
//            in that we will flash certain LEDs at a certain time. I thought 
//            that I would have to somehow grab my values from the light and make
//            an 'if else' statement that checks how much light is being produced.
//        
//References: https://www.arduino.cc/en/Reference/AnalogWrite
//            https://www.arduino.cc/en/Reference/AnalogRead
//
//Youtube video link: https://youtu.be/tyrbZSo6egM
//
//**********************************************************************************

const int ledPin13 = 13;
const int ledPin11 = 11;
const int ledPin10 = 10;
const int ledPin5 = 5;
int value = 0;
const int buzzer = 12;

const int photoResistor = A0;

void setup () {
  
  pinMode(ledPin13, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(photoResistor, INPUT);

} 
 void loop() {

  value = analogRead(photoResistor);
  LEDsensorValues(value); 
}

void LEDsensorValues(int value) { 
  if (value <= 205) {
    digitalWrite(ledPin13, LOW);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin5, LOW);
 
  }
  
  else if (value <= 410) {
    tone(buzzer, 100);
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin11, LOW);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin5, LOW);
    delay(100);
    noTone(buzzer);
  }
  
  else if (value <= 550) {
    tone(buzzer, 200);
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin10, LOW);
    digitalWrite(ledPin5, LOW);
    delay(100);
    noTone(buzzer);
  }
  
  else if (value <= 690) {
    tone(buzzer, 300);
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin5, LOW);
    delay(100);
    noTone(buzzer);    
  }
  
  else if (value <= 800) {
    tone(buzzer, 400);
    digitalWrite(ledPin13, HIGH);
    digitalWrite(ledPin11, HIGH);
    digitalWrite(ledPin10, HIGH);
    digitalWrite(ledPin5, HIGH);
    delay(100);
    noTone(buzzer);    
  }
} 
