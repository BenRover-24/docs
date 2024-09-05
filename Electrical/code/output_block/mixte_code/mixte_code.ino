/*
ce code regroupe pour l'instant le code de controle des 4 servo moteur(servo_code), le code de controle de 6 moteurs (motor_code)
le code de controle des mouvement de la caméra
*/

#include <ServoEasing.hpp>
#include <AccelStepper.h>

ServoEasing servoW1;
ServoEasing servoW2;
ServoEasing servoW3;
ServoEasing servoW4;


//channels utilisés (connexion du recepteur de la telecommande à l'arduino)
#define ch1 A0  //Gauche-Droite : pour les servos-moteurs
#define ch2 A1  // Avant-arriere : pour les moteurs
#define ch3 A2  // camera
#define ch4 A3  // camera

int r = 0;  // turning raduis
int s = 0;  // speed

int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value;

//angle qui sera calculé et utilisé pour donner un angle individuel à chaque servo-moteur lors des virages
float thetaInnerFront, thetaInnerBack, thetaOuterFront, thetaOuterBack = 0;

float L_Front = 600;  //distance en mm
float L_Back = 600;
float W_Front = 590.4;
float W_Back = 590.4;


// J1
int EnA =4;
// J2
int EnB =7;
// J3
int EnC =10;
// J4
int EnD=11;
// J5
int EnE=12;
// J6
int EnF=13;


// Motor1_left_front  J1
const int motor1Pin1 = 2;  
const int motor1Pin2 = 3;  
// Motor2_left_middle J2
const int motor2Pin1 = 5;
const int motor2Pin2= 6;
// Motor3_left_back J3
const int motor3Pin1 = 8;
const int motor3Pin2 = 9;
//Motor4_right_front J4
const int motor4Pin1 = 33;
const int motor4Pin2 = 35;
// Motor5_right_middle  J5
const int motor5Pin1 = 37;
const int motor5Pin2 = 39;
// Motor6_right_back J6
const int motor6Pin1 = 45;
const int motor6Pin2 = 47;

ServoEasing servoCamTilt;
AccelStepper camPanStepper(1, 22, 24);  //(Type:driver, STEP, DIR) - Stepper1

int camTilt = 90;  //pour l'inclinaison de la caméra haut-bas la position initile du servo moteur est de 90 degree
int camPan = 0;    // vitesse du moteur pas à pas

//blocage 1 et blocage 2 conditionne le sens de rotation du moteur pas à pas
bool blocage1 = false;
bool blocage2 = false;


// Cette fonction permet de lire la valeur des entrées analogiques (Les joysticks de la telecommandes)
// cecode receptionne la valeurs des joystick de la telecommande et les faits correcpondre à dans une autre plage

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue) {
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  //ici la valeur envoyer par les joystick se trouvent entre 1000 et 2000 (ces valeurs peuvent différer en fonction de la telecommande utilisé)
  //une fois les valeurs recus la fonction map trouve leur correspondance dans une autre plage qu'on aura précisée et retourne la valeur [minLimit maxLimit]
  return map(ch, 1000, 2000, minLimit, maxLimit);
}


int motorSpeed = 0;  // Variable to store the speed of the motor

void setup() {
  Serial.begin(115200);

  // Initialize channels as inputs
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ch3, INPUT);
  pinMode(ch4, INPUT);

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




  // Initialize motor pins
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);

  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);

  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);

  pinMode(motor5Pin1, OUTPUT);
  pinMode(motor5Pin2, OUTPUT);

  pinMode(motor6Pin1, OUTPUT);
  pinMode(motor6Pin2, OUTPUT);



  servoCamTilt.attach(31);
  servoCamTilt.write(90);           //angle initial 90
  servoCamTilt.setSpeed(200);       //vitesse
  camPanStepper.setMaxSpeed(1000);  //vitesse max du moteur pas à pas
  camPan = 0;
  camTilt = 90;
}

void loop() {
  // Read channel values
  ch1Value = readChannel(ch1, -100, 100, 0);
  ch2Value = readChannel(ch2, -100, 100, 0);
  ch3Value = readChannel(ch3, -100, 100, -100);
  ch4Value = readChannel(ch4, -100, 100, 0);

  // Calculate turning radius based on ch1Value
  //determination de langle de braquage
  // ch1Value se retrouve entre 10 et 100 ou -10 et -100, 100 et -100 y compris
  // map fait correcpondre ch1Value àune nouvelle valeur dans la plage 2400-950 (2400 et 950 compris)
  // virage à droite
  if (ch1Value > 10) {
    r = map(ch1Value, 10, 100, 2400, 950);  // turining radius from 2400 to 950
  }
  // virage à gauche
  else if (ch1Value < -10) {
    r = map(ch1Value, -10, -100, 2400, 950);  // turining radius from 2400 to 950
  }
  //Serial.print("r=");
  //Serial.println(r);

  // faire afficher la valeur des channels

  //Serial.print("ch2");
  //Serial.println(ch2Value);
  //Serial.print("ch1Value ");
  //Serial.println(ch1Value);


  calculateServoAngle();

  // Map the ch2Value to a speed value for the motor
  motorSpeed = map(abs(ch2Value), 0, 100, 0, 255);

  // Forward or backward motion based on ch2Value
  if (ch2Value > 15) {
    //analogWrite(EnA, motorSpeed);
    analogWrite(EnA, motorSpeed);
    digitalWrite(motor1Pin1, 1);
    digitalWrite(motor1Pin2, 0);

    analogWrite(EnB, motorSpeed);
    digitalWrite(motor2Pin1, 1);
    digitalWrite(motor2Pin2, 0);

    analogWrite(EnC, motorSpeed);
    digitalWrite(motor3Pin1, 1);
    digitalWrite(motor3Pin2, 0);


    analogWrite(EnD, motorSpeed);
    digitalWrite(motor4Pin1, 1);
    digitalWrite(motor4Pin2, 0);

    analogWrite(EnE, motorSpeed);
    digitalWrite(motor5Pin1, 1);
    digitalWrite(motor5Pin2, 0);

    analogWrite(EnF, motorSpeed);
    digitalWrite(motor6Pin1, 1);
    digitalWrite(motor6Pin2, 0);


  } else if (ch2Value < -15) {

    analogWrite(EnA, motorSpeed);
    digitalWrite(motor1Pin1, 0);
    digitalWrite(motor1Pin2, 1);

    analogWrite(EnB, motorSpeed);
    digitalWrite(motor2Pin1, 0);
    digitalWrite(motor2Pin2, 1);

    analogWrite(EnC, motorSpeed);
    digitalWrite(motor3Pin1, 0);
    digitalWrite(motor3Pin2, 1);

    analogWrite(EnD, motorSpeed);
    digitalWrite(motor4Pin1, 0);
    digitalWrite(motor4Pin2, 1);


    analogWrite(EnE, motorSpeed);
    digitalWrite(motor5Pin1, 0);
    digitalWrite(motor5Pin2, 1);


    analogWrite(EnF, motorSpeed);
    digitalWrite(motor6Pin1, 0);
    digitalWrite(motor6Pin2, 1);


  } else {

    digitalWrite(motor1Pin1, 0);
    digitalWrite(motor1Pin2, 0);
    analogWrite(EnA, 0);

    digitalWrite(motor2Pin1, 0);
    digitalWrite(motor2Pin2, 0);
    analogWrite(EnB, 0);

    digitalWrite(motor3Pin1, 0);
    digitalWrite(motor3Pin2, 0);
    analogWrite(EnC, 0);

    digitalWrite(motor4Pin1, 0);
    digitalWrite(motor4Pin2, 0);
    analogWrite(EnD, 0);

    digitalWrite(motor5Pin1, 0);
    digitalWrite(motor5Pin2, 0);
    analogWrite(EnE, 0);

    digitalWrite(motor6Pin1, 0);
    digitalWrite(motor6Pin2, 0);
    analogWrite(EnF, 0);
  }


  if (ch1Value > 10) {
    // Servo motors

    servoW1.startEaseTo(90 - thetaOuterFront);  // front wheel steer right
    servoW2.startEaseTo(90 + thetaOuterBack);   // back wheel steer left for overall steering to the right of the rover
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
  else if (ch1Value < -10) {
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


  // Camera head steering
  if (ch4Value < -15) {
    if (camTilt >= 15) {
      camTilt--;
      delay(20);
    }
  }
  if (ch4Value > 15) {
    if (camTilt <= 165) {
      camTilt++;
      delay(20);
    }
  }
  servoCamTilt.startEaseTo(camTilt);  // Camera tilt
  //Serial.print("Servo Calmtilt ");
  Serial.println(servoCamTilt.read());


  if ((ch3Value >= -80 && ch3Value < -15) && blocage1 == false) {
    camPan = map(ch3Value, -80, -15, 500, 0);
    if (camPanStepper.currentPosition() >= 0 && camPanStepper.currentPosition() < 200) {

      blocage1 == false;

    } else if (camPanStepper.currentPosition() >= 200) {
      camPan = 0;
      blocage1 == true;
    }

  } else if (ch3Value > 15 && ch3Value <= 100 && blocage2 == false) {
    camPan = map(ch3Value, 15, 100, 0, -500);
    if (camPanStepper.currentPosition() >= 0 && camPanStepper.currentPosition() < 200) {

      blocage2 == false;

    } else if (camPanStepper.currentPosition() < 0) {
      camPan = 0;

      blocage2 == true;
    }
  } else {

    camPan = 0;
  }

  camPanStepper.setSpeed(camPan);
  camPanStepper.run();

  //Serial.print("camPanStepper current position ");
  //Serial.println(camPanStepper.currentPosition());

  
}



// cette fonction permet le calcule des angles theta necessaire au calcule des angles de chaque servo
// cette fonction suit le principe  de la geometrie d'Ackermann
//géométrie d'Ackerman
//Angle intérieur theta1 = arctan(L_Front / (r - (W_Front / 2)))
//Angle extérieur theta2 = arctan(L_Back / (r + (W_Back / 2)))

void calculateServoAngle() {
  // Calculate the angle for each servo for the input turning radius "r"
  thetaInnerFront = round((atan((L_Front / (r - (W_Front / 2))))) * 180 / PI);  //alcule et conversion de l'angle en degre
  thetaInnerBack = round((atan((L_Back / (r - (W_Back / 2))))) * 180 / PI);
  thetaOuterFront = round((atan((L_Front / (r + (W_Front / 2))))) * 180 / PI);
  thetaOuterBack = round((atan((L_Back / (r + (W_Back / 2))))) * 180 / PI);
}
