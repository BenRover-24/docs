/*
ce code permet au rover de faire bouger ses deux roues avant et arrières afin d'entamer un virage aenfonction des insformations envoyer par la telecommande
04 servo-moteurs : pour diriger le rover dans les virages suivant le principe de la géométrie d'Ackermann

*/  


#include <ServoEasing.hpp>
#include <AccelStepper.h>


ServoEasing servoW1;
ServoEasing servoW2;
ServoEasing servoW3;
ServoEasing servoW4;

//channels utilisés (connexion du recepteur de la telecommande à l'arduino)
#define ch1 A0 //Gauche-Droite : pour les servos-moteurs


// Valeurs lues 
int ch1Value;  
 


int r = 0; // turning radius

//angle qui sera calculé et utilisé pour donner un angle individuel à chaque servo-moteur lors des virages
float thetaInnerFront, thetaInnerBack, thetaOuterFront, thetaOuterBack = 0;


float L_Front = 301.80732; //distance en mm
float L_Back = 301.80732; 
float W_Front = 335.878644; 
float W_Back = 335.878644; 



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

  // Mettre les pins en input  
  pinMode(ch1, INPUT);  

  //initialisation des pins de l'arduino pour chaque servomoteur

  //servo1 left-front
  servoW1.attach(23); //pin 23 de l'arduino
  //servo2 left-back
  servoW2.attach(25);
  //servo3 Right-front
  servoW3.attach(27);
  //servo4 Right-back
  servoW4.attach(29);

  //angle initial des servomoteur 90°
  servoW1.write(90);
  servoW2.write(90);
  servoW3.write(90);
  servoW4.write(90);

  //vitesse de mouvement des servomoteurs
  servoW1.setSpeed(550);
  servoW2.setSpeed(550);
  servoW3.setSpeed(550);
  servoW4.setSpeed(550);



}

void loop() {
  // put your main code here, to run repeatedly:

  // Récupérer les valeurs de chaque entrée  
  ch1Value = readChannel(ch1, -100, 100, 0);  





  //ch1Value=100;
  //Serial.print("ch1Value ");
  //Serial.println(ch1Value);

  //determination de langle de braquage
  // ch1Value se retrouve entre 10 et 100 ou -10 et -100, 100 et -100 y compris
  // map fait correcpondre ch1Value àune nouvelle valeur dans la plage 2400-950 (2400 et 950 compris)
  // virage à droite
  if (ch1Value > 10) {
    r = map(ch1Value, 10, 100, 2400, 950); // turining radius from 2400 to 950
  }
  // virage à gauche
  else if (ch1Value < -10) {
    r = map(ch1Value, -10, -100, 2400, 950); // turining radius from 2400 to 950
  }
 //Serial.print("r=");
 //Serial.println(r);



 calculateServoAngle();




  // virage à droite
  // à retester
  if (ch1Value    > 10) {
    // Servo motors
    
    servoW1.startEaseTo(90 - thetaOuterFront);// front wheel steer right
    servoW2.startEaseTo(90 + thetaOuterBack); // back wheel steer left for overall steering to the right of the rover
    servoW3.startEaseTo(90 - thetaInnerFront);
    servoW4.startEaseTo(90 + thetaInnerBack);


    /*Serial.print("servo 1");
    Serial.println(90 + thetaInnerFront);
    Serial.println(thetaInnerFront);
    Serial.print("servo 2");
    Serial.println(90 - thetaInnerBack);
    Serial.println(thetaInnerBack);
    Serial.print("servo 3");
    Serial.println(90 + thetaOuterFront);
    Serial.println(thetaOuterFront);
    Serial.print("servo 4");
    Serial.println(90 - thetaOuterBack);
    Serial.println(thetaOuterBack);
    */


  }
  // virage à gauche
  else if (ch1Value < -10 ) {
    // Servo motors
    servoW1.startEaseTo(90 + thetaInnerFront); 
    servoW2.startEaseTo(90 - thetaInnerBack); 
    servoW3.startEaseTo(90 + thetaOuterFront);
    servoW4.startEaseTo(90 - thetaOuterBack);


    /*Serial.print("servo 1");
    Serial.println(90 - thetaOuterFront);
    Serial.println(thetaOuterFront);

    Serial.print("servo 2");
    Serial.println(90 + thetaOuterBack);
    Serial.println(thetaOuterBack);

    Serial.print("servo 3");
    Serial.println(90 - thetaInnerFront);
    Serial.println(thetaInnerFront);

    Serial.print("servo 4");
    Serial.println(90 + thetaInnerBack);
    Serial.println(thetaInnerBack);*/

 

  }
  // aucun virage
  else {
    servoW1.startEaseTo(90);
    servoW2.startEaseTo(90);
    servoW3.startEaseTo(90);
    servoW4.startEaseTo(90);

  }



}



// cette fonction permet le calcule des angles theta necessaire au calcule des angles de chaque servo
// cette fonction suit le principe  de la geometrie d'Ackermann 
//géométrie d'Ackerman
//Angle intérieur theta1 = arctan(L_Front / (r - (W_Front / 2)))
//Angle extérieur theta2 = arctan(L_Back / (r + (W_Back / 2)))

void calculateServoAngle() {
  // Calculate the angle for each servo for the input turning radius "r"
  thetaInnerFront = round((atan((L_Front / (r - (W_Front / 2))))) * 180 / PI); //alcule et conversion de l'angle en degre
  thetaInnerBack = round((atan((L_Back / (r - (W_Back / 2))))) * 180 / PI);
  thetaOuterFront = round((atan((L_Front / (r + (W_Front / 2))))) * 180 / PI);
  thetaOuterBack = round((atan((L_Back / (r + (W_Back / 2))))) * 180 / PI);

}












