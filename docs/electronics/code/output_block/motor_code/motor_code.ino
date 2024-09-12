/*
ce code permet le controle des moteurs 
*/

#include <ServoEasing.hpp>
#include <AccelStepper.h>


#define ch2 A1 // Avant-arriere : pour les moteurs


int s=0;// speed
int ch2Value;


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

// Cette fonction permet de lire la valeur des entrées analogiques (Les joysticks de la telecommandes)  
// cecode receptionne la valeurs des joystick de la telecommande et les faits correcpondre à dans une autre plage

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){  
  int ch = pulseIn(channelInput, HIGH, 30000);  
  if (ch < 100) return defaultValue;  
  //ici la valeur envoyer par les joystick se trouvent entre 1000 et 2000 (ces valeurs peuvent différer en fonction de la telecommande utilisé)
  //une fois les valeurs recus la fonction map trouve leur correspondance dans une autre plage qu'on aura précisée et retourne la valeur [minLimit maxLimit]
  return map(ch, 1000, 2000, minLimit, maxLimit);  
}  


int motorSpeed = 0; // Variable to store the speed of the motor

void setup() {
  Serial.begin(115200);
  
  // Initialize channels as inputs
  
  pinMode(ch2, INPUT);

 

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
}

void loop() {
  // Read channel values
  // Récupérer les valeurs de chaque entrée 
  ch2Value = readChannel(ch2, -100, 100, 0);


 // faire afficher la valeur des channels 

 //Serial.print("ch2");
 //Serial.println(ch2Value);




  // Map the ch2Value to a speed value for the motor
  motorSpeed = map(abs(ch2Value), 0, 100, 0, 255);

  // Forward or backward motion based on ch2Value
  if (ch2Value > 15) {
    //analogWrite(EnA, motorSpeed);
    analogWrite(EnA,motorSpeed);
    digitalWrite(motor1Pin1,1);
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
    digitalWrite(motor3Pin2,1);

    analogWrite(EnD, motorSpeed);
    digitalWrite(motor4Pin1,0);
    digitalWrite(motor4Pin2, 1);


    analogWrite(EnE, motorSpeed);
    digitalWrite(motor5Pin1, 0);
    digitalWrite(motor5Pin2,1);


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
    analogWrite(EnC , 0);

    digitalWrite(motor4Pin1, 0);
    digitalWrite(motor4Pin2, 0);
    analogWrite(EnD , 0);

    digitalWrite(motor5Pin1, 0);
    digitalWrite(motor5Pin2, 0);
    analogWrite(EnE , 0);

    digitalWrite(motor6Pin1, 0);
    digitalWrite(motor6Pin2, 0);
    analogWrite(EnF , 0);
  }




}
