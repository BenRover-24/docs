#include <Wire.h>

#define I2C_SLAVE_ADDRESS 14

// Union pour convertir des octets en float et vice-versa
union FloatUnion {
  float value;
  uint8_t bytes[4];
};


FloatUnion sensorDataToPi[2];    // Simule des données de capteurs à envoyer à la Raspberry Pi




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

  Wire.begin(I2C_SLAVE_ADDRESS);
  Serial.begin(9600);
  Wire.onRequest(requestEvents);  // Appelée lors de la demande des données

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

  sensorDataToPi[0].value = temperature; //temperature
  sensorDataToPi[1].value = percent ;//percent; //niveau de la batterie en pourcentage

  //delay(1000);  // Mise à jour toutes les secondes

  Serial.println(percent);
 
}



// Fonction appelée lorsque la Raspberry Pi demande des données
void requestEvents() {
  Serial.println(F("---> Requête de la Raspberry Pi pour des données Arduino"));

  // Envoi des données des capteurs Arduino (3 capteurs ici)
  for (int i = 0; i < 4; i++) {  // Boucle sur les 3 capteurs
    for (int j = 0; j < 4; j++) {  // Chaque float est de 4 octets
      Wire.write(sensorDataToPi[i].bytes[j]);

      
    }
  }
}





