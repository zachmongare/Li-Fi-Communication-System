const int photoPin = 2;
const int period = 5;
//Received byte counter
int byteCount = 0;
bool previous_state;
bool current_state;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(photoPin, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
   current_state = digitalRead(photoPin);

   if(!current_state && previous_state)
   {
    printByte(getByte());
   }
   previous_state = current_state;
}

char getByte(){
  char rxByte = 0;
  delay(1.5*period);
  for(int i = 0; i < 8; i++)
  {
    rxByte = rxByte | digitalRead(photoPin) << i;  
    delay(period);
  }
  return rxByte;
}

void printByte(char myByte) {
  lcd.print(myByte);
  byteCount++;
  if (byteCount>16){
    lcd.scrollDisplayLeft();
  }
  if (byteCount>32){
    lcd.clear();
    byteCount=0;
  }
}