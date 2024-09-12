#include <AccelStepper.h> //biblio de controle du moteur pas à pas de la caméra
#include <ServoEasing.hpp> //biblio de controle du servomoteur de la caméra


ServoEasing servoCamTilt; 
AccelStepper camPanStepper(1, 22, 24);  //(Type:driver, STEP, DIR) - Stepper1


int camTilt = 90; //pour l'inclinaison de la caméra haut-bas la position initile du servo moteur est de 90 degree
int camPan = 0; // vitesse du moteur pas à pas 

#define ch3 A2  // camera
#define ch4 A3  // camera

//blocage 1 et blocage 2 conditionne le sens de rotation du moteur pas à pas 
bool blocage1 = false; 
bool blocage2 = false;


int ch3Value;  
int ch4Value; 

// Cette fonction permet de lire la valeur des entrées analogiques (Les joysticks de la telecommandes)  
// cecode receptionne la valeurs des joystick de la telecommande et les faits correcpondre à dans une autre plage

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){  
  int ch = pulseIn(channelInput, HIGH, 30000);  
  if (ch < 100) return defaultValue;  
  //ici la valeur envoyer par les joystick se trouvent entre 1000 et 2000 (ces valeurs peuvent différer en fonction de la telecommande utilisé)
  //une fois les valeurs recus la fonction map trouve leur correspondance dans une autre plage qu'on aura précisée et retourne la valeur [minLimit maxLimit]
  return map(ch, 1000, 2000, minLimit, maxLimit);  
}  


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(ch3, INPUT);  
  pinMode(ch4, INPUT); 
  
  

  servoCamTilt.attach(31);

  servoCamTilt.write(90); //angle initial 90

  servoCamTilt.setSpeed(200); //vitesse

  camPanStepper.setMaxSpeed(1000); //vitesse max du moteur pas à pas
  camPan = 0;
  camTilt = 90;



}

void loop() {
  // put your main code here, to run repeatedly:

  ch3Value = readChannel(ch3, -100, 100, -100);  
  ch4Value = readChannel(ch4, -100, 100, 0);


  //ch3Value=100;
  //ch4Value=100;
  //Serial.print("ch3Value ");
  //Serial.println(ch3Value);

  //Serial.print("ch4Value ");
  //Serial.println(ch4Value);

// Camera head steering
  if (ch4Value < -15 ) {
    if (camTilt >= 15) {
      camTilt--;
      delay(20);
    }
  }
  if (ch4Value > 15 ) {
    if (camTilt <= 165) {
      camTilt++;
      delay(20);
    }
  }
  servoCamTilt.startEaseTo(camTilt); // Camera tilt
  //Serial.print("Servo Calmtilt ");
  Serial.println(servoCamTilt.read());

  

  if ( (ch3Value >= -80 && ch3Value < -15) && blocage1 == false )  
  { 
    camPan = map(ch3Value, -80, -15, 500, 0); 
    if(camPanStepper.currentPosition() >= 0 && camPanStepper.currentPosition() < 200)
    {
      
      blocage1 == false;
      
      
    }
    else if (camPanStepper.currentPosition() >= 200){
      camPan = 0;
      blocage1 == true;
      
    }
   
  }
  else if (ch3Value > 15 && ch3Value <= 100 && blocage2 == false)
  {  
    camPan = map(ch3Value, 15, 100, 0, -500); 
    if(camPanStepper.currentPosition() >= 0 && camPanStepper.currentPosition() < 200)
    {
      
      blocage2 == false;
      
    }
    else if (camPanStepper.currentPosition() < 0) 
    {
      camPan = 0;
      
      blocage2 == true;
    }
  }
  else {

   camPan = 0;

}



  camPanStepper.setSpeed(camPan);
  camPanStepper.run();


  
  //Serial.print("camPanStepper current position ");
  //Serial.println(camPanStepper.currentPosition());






}







