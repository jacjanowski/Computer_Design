//*************************************************************************
//Jacob Janowski - 672941241
//Lab 7 - Serial Communication
//
//Description: I took the first option, which was to have 2 arduinos utilizing
//             serial communication with one another. It's important to note 
//             that we are supposed to use pins 0 and 1, which is done in this lab.
//             We must have two buttons and LEDs that communicate with one another 
//             using the other arduino.
//
//Assumptions: My assumptions initially was me questioning how to geet the code 
//             to be associated with one another. I wasn't sure if I would have 
//             to 'include' the other .ino file and have them run asynchronously,
//             but that wasn't the case. I was able to use the same code for both 
//             arduions, which was a question I had asked and received an answer from Theys.


//References:  https://www.arduino.cc/en/Tutorial/LibraryExamples/TwoPortReceive


//Youtube link: https://youtu.be/R5bFL59zEx0
//*************************************************************************


int button = 8;
int LEDpin = 13;

void setup() {
  pinMode(button, INPUT_PULLUP); // push button
  pinMode(LEDpin, OUTPUT);      // set LED pin as output
  digitalWrite(LEDpin, LOW);    // switch off LED pin

  Serial.begin(9600);       
}

//Sending the information in this loop will be transferred through the pins Rx/Tx or 0 and 1.
//RX on one arduino is linked to the TX on the other arduino  ------> TX on one arduino is linked to the RX on the other arduino.
void loop() {
  if (Serial.available()) {
    char serialData = Serial.read();   // read in the serial software data and check whether it's a '1' or '0'.


    //Switch lights on/off based on the serial reading.
    if (serialData == '1') digitalWrite(LEDpin, HIGH); // switch LED On
    if (serialData == '0') digitalWrite(LEDpin, LOW);  // switch LED Off
  }

  if (digitalRead(button) == HIGH) Serial.write('0');   //If the button is NOT pressed, send a '0' to the arduino.
  else Serial.write('1');                           // If the button is pressed, send a '1' to the arduino.
}
