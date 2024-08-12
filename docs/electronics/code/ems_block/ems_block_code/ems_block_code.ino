/*
 
arduino nano : esclave
Ce code permet d'afficher  la tension de la batterie et la température au niveau de labatterie sur 
un ecran LCD connecte par i2c à l'arduino nano

le code doit retourner au block central le niveau de la batterie et la température au niveau du block par une connxion i2c


*/

//Arduino  librairie Wire pour I2C
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define pin_battery A0
#define pin_temperature A1

//lcd
#define LCD_ADDR 0x27 //adresse i2c de l'écran 
LiquidCrystal_I2C lcd_battery(LCD_ADDR, 16, 2);

// adresse i2c de l'arduino nano
//#define ARDUINO_NANO_ADDR //pas encore identifier


float tension_battery, temperature_battery = 0;


void setup() {

  Serial.begin(9600);

  lcd_battery.init();
  lcd_battery.backlight();
  lcd_battery.print("Test lcd ");

  pinMode(pin_battery, INPUT);
  pinMode(pin_temperature, INPUT);
  delay(1000);
  
}

void loop() {

  /* niveau de tension de la batterie*/

  float niveau = analogRead(pin_battery);
  tension_battery = (niveau * 5) / 1023;
  //Serial.print("tension_battery ");
  //Serial.println( tension_battery);

  /* temperature au niveau de la batterie le capteur produit 10mV par °C 
  Temp = voltage(mV) / 10 
  0,01 v ---- 1°C
  Temp = Voltage(V) *100 */
  float temp_voltage = (analogRead(pin_temperature) * 5 )/1023;
  temperature_battery = temp_voltage * 100;
  //Serial.println("temperature_battery ");
  //Serial.println(temperature_battery);
  delay(500);


//affichage des données sur l'écran lcd 
lcd_battery.setCursor(0, 0);
lcd_battery.print("T : ");
lcd_battery.print(temperature_battery);
lcd_battery.print((char)223);
lcd_battery.print("C");
delay(500);

lcd_battery.setCursor(0, 1);
lcd_battery.print("Bat : ");
lcd_battery.print(tension_battery);
lcd_battery.print("V");
delay(500);







}
