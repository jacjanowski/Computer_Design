//*************************************************************************
//Jacob Janowski - 672941241
//Lab 6 - Communication
//
//Description: The purpose of this lab consists of constructing the LCD screen
//             so that we are able to input a date and time from the serial output
//             and display it on the screen. The prompt will ask for a user to put
//             in a date and time. If the date is incorrect, it will error handle and
//             ask for input again.
//
//Assumptions: My assumptions were that maybe I would have to somehow find a way to 
//             convert the serial output onto the LCD screen and was confused on how to. 
//             After looking at the references posted below, I was able to find out how to do that.


//References:  http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E
//             http://arduino.cc/en/Serial/Available#.UwYy2PldV8E
//             http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E

//Youtube link: https://youtu.be/fHip2Xnmbe4
//*************************************************************************

#include <TimeLib.h>
#include <LiquidCrystal.h>

//
int hoursLED ,minutesLED, secondsLED;

//variables for Date
int months, years, days;
bool correctDateForm = true;
bool correctTimeForm;
//User prompt and format
String Date = "Enter Date to display: mm/dd/yyyy.";
String Time = "Enter Time to display: hh:mm:ss.";



LiquidCrystal LCD(12, 11, 5, 4, 3, 2);

//LCD Setup
void setup()
{
  LCD.begin(16, 2);
  Serial.begin(9660);
}

void loop()
{
  Serial.println(Date);
  
  //Get user input
  while (true)
  {
    if (Serial.available() == 1){ break; }
  }

  if (Serial.available() > 0)
  {
    validateDate(Serial.readString());
    
      //Check if  input is too long
    if (Serial.readString().length() > 10){ 
      Serial.println("Error in date format."); 
     }
    Serial.println(Serial.readString());


  }
  
  Serial.println(Time);

  //Get input and validate the correct format of the time and date.
  while (true)
  {
  
    if (Serial.available() > 0)
    {  
      //true if valid date, else get user input again.
      correctTimeForm = validateTime(Serial.readString());
      String inputString = Serial.readString();
      if(correctTimeForm){
        
          setTime(hoursLED, minutesLED, secondsLED, days, months, years);
          setLCDTime(inputString);
          
          Serial.print(hoursLED);
          Serial.print(":");
          Serial.print(minutesLED);
          Serial.print(":");
          Serial.println(secondsLED);
      } else {
        validateTime(Serial.readString());
      }
      

    }
  }
}


void validateDate(String Date)
{
  String month, day, year;

  month = Date.substring(0, Date.indexOf("/"));
  months = month.toInt();
  
  day = Date.substring(5, Date.indexOf("/") + 1);
  days = day.toInt();

  year = Date.substring(6);
  years = year.toInt();

//Check if the date is in correct format and make sure the correct dates for the months.
//Return true if the form is correct, otherwise get user input again until correct.
  if ((months > 12) || (months < 1))
  {
    correctDateForm = false;
    
  }
  else if ((months == 4) || (months == 6) || (months == 9) || (months == 11))
  {
    correctDateForm = true ? ((days < 31) && (days > 0)) : false;
  } 
  else if ((months == 1) || (months == 3) || (months == 5) || (months == 7) || (months == 8) || (months == 10) || (months == 12))
  {
      correctDateForm = true ? ((days < 32) && (days > 0)) : false;

  }

  else if (months == 2)
  {
    correctDateForm = true ? (days < 29) : false;
  }

  if(!correctDateForm) {
    Serial.println("Error in date format. Try again.");
    loop();
  }
}

//Make sure the time is in the correct format: hours/minutes/seconds
bool validateTime(String input)
{
  String hours, minutes, seconds;
  int strLen = input.length();
  
  hours = input.substring(0, input.indexOf(":"));
  minutes = input.substring(strLen - 4, input.indexOf(":") + 1);
  seconds = input.substring(6);
  
  hoursLED = hours.toInt();
  minutesLED = minutes.toInt();
  secondsLED = seconds.toInt();

  //If the times are out of range, get another input from the user.  
  if ((hoursLED < 0) || (hoursLED > 23) || (minutesLED < 0) || (minutesLED > 59) || (secondsLED < 0) || (secondsLED > 59))
  {
    
    Serial.println("Not In Range. Try Again !");
    Serial.println(Time);
        return false;
   
  } else {
      return true;
  }


  
}

void setLCDTime(String inputString)
{
  int strLength = inputString.length();
  
  do {
    
    
    time_t t = now();
    Serial.print(hour(t));
    Serial.print(minute(t));
    Serial.print(second(t));
    Serial.println();
    Serial.println(day(t));
    Serial.println(month(t));
    Serial.println(year(t));
    delay(1000);
    LCD.clear();
    LCD.setCursor(11, 0);
    LCD.print(year(t));
    LCD.setCursor(10, 0);
    LCD.print("/");
    LCD.setCursor(8, 0);
    LCD.print(day(t));  
    LCD.setCursor(6, 0);
    LCD.print("/");    
    LCD.setCursor(4, 0);
    LCD.print(month(t));


    LCD.setCursor(11, 1);
    LCD.print(second(t));
    LCD.setCursor(10, 1);
    LCD.print(":");
    LCD.setCursor(8, 1);
    LCD.print(minute(t));
    LCD.setCursor(6, 1);
    LCD.print(":");
    LCD.setCursor(4, 1);
    LCD.print(hour(t));
  }while(true);
  
}
