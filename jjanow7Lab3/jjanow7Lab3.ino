#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int stringLength = 0;
String NAME = "Jacob Janowski";

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  firstRowInitialize();
  scroll(1, "Homo homini lupus [man is wolf to man]. - Sigmund Freud ");
}

//Initialize the first line as my name
void firstRowInitialize() {
  lcd.setCursor(0, 0);
  lcd.print(NAME);

}
void scroll(int line, String string) {
  stringLength = string.length();
  
  for (int itr = 16; itr >= 0; itr--) {
    lcd.setCursor(itr, line);
    lcd.print(string.substring(0, 16));
    delay(200);
  }
  
  for(int i = 0; i < stringLength; i++){
    lcd.setCursor(0, line);
    lcd.print(string.substring(i,i+16));
    delay(200);
  }

}
