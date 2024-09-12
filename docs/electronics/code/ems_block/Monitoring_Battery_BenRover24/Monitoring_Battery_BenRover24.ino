#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int Battery = A0;
const int LM35 = A1;
int temperature = 0;
float percent = 0;
float y;

byte degre[8] = {
  0b00000,
  0b01110,
  0b01010,
  0b01110,
  0b00000,
  0b00000,
  0b00000,
  0b00000};


void setup() {
 Serial.begin(9600);
  lcd.init();                 
  lcd.backlight(); 
  lcd.createChar(0,degre);           
}


void loop() 
{
  //Serial.println(analogRead(LM35));
  temperature = ((( analogRead(LM35) )* 5) / (1023*0.01));

 // Serial.print("Temperature = ");
  //Serial.println(temperature);
  lcd.setCursor(0,0); lcd.print("   Temp : ");
 
  
  lcd.setCursor(11,0); lcd.print(temperature);

  lcd.setCursor(14,0);lcd.write((byte)0);
  lcd.setCursor(15,0); lcd.print("C");
  
  delay(500); 

 // Serial.println(((analogRead(Battery)*5)/1023) + 7);
  y = ((analogRead(Battery)*5)/1023) + 7;
  percent = ((y * 100) / 13) ;
//  Serial.println(percent);
  delay(1000);
  lcd.setCursor(0,1); lcd.print("Batterie: ");
  
  lcd.setCursor(10,1); lcd.print(percent);

  lcd.setCursor(15,1); lcd.print("%");
 
}
