# Electronics ⚡
In the electronic parts, we used the following software and components.

## Software 💻
| Designation | Logos | Usages |
| ------ | ------ | ------ |
| Arduino IDE | ![Arduino ide](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/software/IDE%20arduino.jpeg) | Using the Arduino IDE made programming the Arduino Mega easier. |
| KiCad | ![KiCad](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/software/Kicad_logo_new.png) | The entry of the electrical diagram and the creation of the printed circuit were carried out on KiCad, which is a suite of free software for drawing electronic diagrams and designing printed circuits, offering a 3D visualization of our PCB and other tools necessary for the design of electronic circuits. |
| Fritzing | ![Fritzing](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/software/fritzing.png) | Using Fritzing, an electronic circuit design software, allowed us to create an overview of the different connections between the project components. |

## Materials 🛠️
| Designation | Number | Picture | Links/Price |
| ------ | ------ | ------ | ------ |
| Arduino MEGA | 01 | ![arduino mega](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/arduinomega.jpg) | [YoupiLab](https://youpilab.com/components/product/arduino-mega-2560) |
| Arduino NANO | 01 | ![arduino nano](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/arduino_nano.jpg) | [YoupiLab](https://youpilab.com/components/product/arduino-nano-ch340) |
| Raspberry pi 4 Model B | 02 | ![raspberry pi](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/raspberry.jpg) | [YoupiLab](https://youpilab.com/components/product/raspberry-pi4-model-ram-8giga) |
| Servo-motor REV-41-1097 | 05 | ![servo-motor](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/rev-41-1097.jpg) | [REV Robotics](https://www.revrobotics.com/rev-41-1097/) |
| Stepper motor | 01 | ![stepper motor](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/Moteur_pas_%C3%A0_pas_Nema_17.png) | [YoupiLab](https://youpilab.com/components/product/moteur-pas-a-pas-nema-17-42hs48) |
| Continuous Motor (XD37GB-555YSY 50rpm)  | 06 | ![motor](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/motor.jpg) | [YoupiLab]() |
| Camera | 01 | ![camera](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/camera.jpg) | [YoupiLab]() |
| Flysky FS-i6 RC | 01 | ![Flysky FS-i6 RC](https://raw.githubusercontent.com/benrover-24/docs/main/docs/electronics/images/materials/flysky_tx.jpg) | [Link]() |
| Flysky FS-iA6 (receiver) | 01 | ![Flysky FS-iA6 (receiver)](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/receiver_flysky.jpg) | [Link]() |
| A4988 stepper motor driver | 01 | ![A4988](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/A4988_Stepper_Motor_Driver.jpeg) | [YoupiLab](https://youpilab.com/components/product/a4988-stepper-motor-driver) |
| TIP 122 | 06 | ![TIP](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/TIP122.jpg) | [YoupiLab](https://youpilab.com/components/product/transistor-darlington-tip122) |
| Terminal block | 30 | ![T-block](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/T-block.jpg) | [YoupiLab](https://youpilab.com/components/product/bornier-2-broches) |
| Header pin male | 30 | ![Header pin male](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/header_pin_mal.jpg) | [YoupiLab]() |
| Header pin female | 30 | ![Header pin male](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/header_pin_femel.jpg) | [YoupiLab]() |
| Flexible Heat Resistant Electrical Wire | 06 | ![Flexible Heat Resistant Electrical Wire](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/Fil_%C3%A9lectrique_r%C3%A9sistant_%C3%A0_la_chaleur.jpg) | [YoupiLab](https://youpilab.com/components/product/fil-electrique-resistant-a-la-chaleur-jaune-metre) |
| Alimentation | 06 | ![Alimentation](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/batterie_de_moto.jpg) | [Link]() |
| LCD screen + i2c module | 02 | ![LCD_screen_i2c_module](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/lcd_modul_i2c.png) | [YoupiLab](https://youpilab.com/components/product/ecran-lcd-16x02-avec-iLink2c) |
| LM35 temperature sensor | 02 | ![LM35_temperature_sensor](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/lm35.jpg) | [YoupiLab](https://youpilab.com/components/product/capteur-de-temperature-lm35dz) |
| MPU6050 | 02 | ![MPU6050_sensor](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/mpu.png) | [ici]() |


# Power Management System
For efficient power system management, we have opted for the following configuration:

*  The rover's power supply consists of two parallel-connected 12-volt batteries, each rated at 5 Ah.
*  An Arduino nano manages this power supply and displays on I2C LCD screen the temperature of the block via an LM35 sensor and the battery charge level using a resistor bridge. 
*  An emergency stop button is integrated between the power pack batteries and the rest of the system. This button allows you to shut down the entire system if necessary. 

With our current power supply we have a capacity of 10 Ah (Capacity = current * time), offering a maximum autonomy of 5 hours if the system consumption reaches 2A. However, this autonomy can be reduced by various factors, such as variations in component consumption, circuit losses, and temperature fluctuations.

![battery block](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/materials/ems_block2.jpg)


# Command System
To control the actuators such as the 5 servo motors, the 6 continuous motors, the stepper motors we used an Arduino Mega.

The servomotors from REV ROBOTICS which we supplied with a voltage of 12V and which require a maximum dropout current of 2A, we used TIP122 transistors to amplify the low current of 20 mA supplied by the Arduino Mega. 

To reduce electrical interference, we have added capacitors which filter the noise produced by the motors which are powered through their drivers by 12V.


## Servo motors interfacing with Arduino mega board through TIP122 transistors

The wheels at the corners of the Benrover are equiped with four Rev Smart Robotic Servos

![rev-41-1097](https://raw.githubusercontent.com/Mahudjro369/MyBenrover2024/main/docs/electronics/images/materials/rev-41-1097.jpg) 

Those servo motors that we are using as specified by the constructor in the electrical specifications's table on the following page [Smart Robot Servo Specifications](https://docs.revrobotics.com/rev-crossover-products/servo/srs), have a stall current of 2 A at 6V. 
This means that each one can take 2 A current at maximum load from the supply source. They need a PWM pulse range from 500 µs to 2500 µs from a microcontroller to be driven.
As the Arduino mega board is only able to source 20 mA of current on his pins as notified in the datasheet of the Atmega2560’s screenshot below to produce the PWM signal.This current is enough to drive one servo, but as we are using four of then and due to some electrical constraints of the Atmega2560 itself, we need to amplify it.

![Datasheet ATmega 2560](https://raw.githubusercontent.com/Mahudjro369/MyBenrover2024/main/docs/electronics/images/other/Datasheet%20ATmega%202560%20.jpg)

We want to ensure that all the servo-motors work correctly at the same time on the Arduino mega board to make the rover wheels turn into any desired direction.  

To hit our target we decide to make an interfacing circuit between the signal pin of the servo-motors and the Atmega2560's PWM pins. The circuit we’ve chosen use a TIP122 transistors to amplify the 20 mA current from the Arduino Mega pin.  

The TIP 122 is a Darlington transistor able to amplify by 1000 the current received at his base with a collector current of 0.5 A at 3 V as mentioned in a table of the datasheet where below. Note that the current limit is of 5 A.

![Datasheet TIP122](https://raw.githubusercontent.com/Mahudjro369/MyBenrover2024/main/docs/electronics/images/other/Datasheet%20TIP122.jpg)

Additionally, the TIP122 can switch signal at a maximum frequency of 1 MHz. This is enough to transmit while amplifying the PWM pulses from the Arduino Mega board to the servo-motors. Where is the schematic realized on each signal pin.

![Servo motor interfacing schematic](https://raw.githubusercontent.com/Mahudjro369/MyBenrover2024/main/docs/electronics/images/other/Servo%20motor%20interfacing%20schematic.jpg)



# Navigation System : Radio Command

Waiting for the integration of ROS (Robot Operating System) and the implementation of the Rover management software, which will be installed on the Rover control station server, we used the Flysky FS-i6 remote control and its Flysky FS receiver -iA6 to set up the code logic and carry out the various tests (motor tests, servo-motor tests, etc.). Later, after the integration of ROS, the Flysky FS-i6 remote control and its Flysky FS-iA6 receiver will be replaced by the Xbox controller, which will be connected to the management software to allow remote control of the Rover via WI-FI.

![flysky joystick](https://raw.githubusercontent.com/iudhael/benrover-docs/electrical/Electrical/images/fs-i6.gif)

## How the Flysky FS-I6 works? 🎮
| Channel | Usages |
| ------ | ------ |
| Channel 1 – Right Joystick, Left/Right | Controls four (04) servo motors, each connected to the Rover's front and rear wheels to enable turning movements |
| Channel 2 – Right Joystick, Up/Down | Controls six (06) motors, each connected to the Rover's wheels to allow the rover to move forward and backward |
| Channel 3 – Left Joystick, Up/Down | Controls the rotation (in two directions: clockwise and counterclockwise) of the stepper motor connected to the Rover's neck for a 360° rotation of the camera |
| Channel 4 – Left Joystick, Left/Right | Controls one (01) servo motor connected to the Rover camera block to allow tilt movements (up-down) |

## How Does the Rover Handle Turns? 🔄
### Ackermann Steering Geometry ⚙️

The four steerable wheels (the two front and rear wheels) have individual steering mechanisms equipped with REV-41-1097 servo motors from REV ROBOTICS. To enhance the rover's maneuverability during turns, we applied Ackermann steering geometry to the steerable wheels. Ackermann steering geometry, widely used in the steering principles of many cars, allows the wheels to turn at different angles, optimizing turning performance and reducing tire wear.

Ackermann steering geometry suggests that during a turn, the inner wheels have a larger steering angle than the outer wheels. Thus, the outer wheels describe a larger arc than the inner wheels.

![Ackermann geometry](https://raw.githubusercontent.com/BenRover-24/docs/refs/heads/main/docs/electronics/images/Ackermann-Steering-Geometry-for-Mars-Rover-with-rocker-bogie-suspension.png)

### Mathematical principle behind Ackermann steering geometry 📐

![Ackermann geometry](https://raw.githubusercontent.com/BenRover-24/docs/main/docs/electronics/images/formule_ackermann.png)

* L: wheelbase;
* R: turning radius;
* W: track width;

# Navigation System : Sensors

A Raspberry Pi 4 model B controls the sensors (MPU6050, USB Camera )
The MPU6050 is connected via I2C and sends temperature, gyroscope and accelerometer data. This data, plus data from the power supply received via i2c (temperature, battery level), is sent to an online database.

The vision will be assured by a USB camera connected to the Raspberry Pi. The package ‘motion’ installed on the Raspberry Pi will then be used to stream video via Wi-Fi. 

The control station will be connected on the same network as the Raspberry Pi which gives us access to the continu video feed through a web browser at the Raspberry Pi Ip address with the port onto which the video feed is playing. (example : 10.10.10.5:9000). After some tests, we got images with an appropriate resolution.



## Configuring the Raspberry Pi with the USB camera
* Install the motion package with the command : sudo apt-get install motion
* Execute the command:  sudo service motion status
* In the event of an error saying that the Motion folders located at /var/lib/ and /var/log/motion are not found, you must create the folders with the commands sudo mkdir /var/log/motion and sudo mkdir /var/lib/motion
* Check if folders have been created by moving to their location or typing : ls -ld /var/log/motion and ls -ld /var/lib/motion
* Then give permissions : sudo chmod -R 777 /var/log/motion and sudo chmod -R 777 /var/lib/motion
* Execute command :  sudo service motion status
* If we have an access denied error, we rerun : sudo chmod -R 777 /var/log/motion and sudo chmod -R 777 /var/lib/motion
* Run the command again : sudo service motion status
* this time we are supposed to have no more errors
* Run the command : sudo cp /etc/motion/motion.conf /etc/motion/motion.conf.bckp sudo nano /etc/motion/motion.conf to make a copy of the motion package configuration file
* Run sudo service motion start then sudo service motion status to check if the motion service is activated
* If enabled, run the command sudo nano ~/.motion/motion.log and modify the following parameters:
  *  webcontrol_port : 8080
  *  webcontrol_localhost: on
  *  stream_port : 8081
  *  stream_localhost : off
  *  output_movie :on
  *  stream_quality : 100
  *  Width : 1280
  *  Height : 720

![Live feed from camera](https://github.com/iudhael/benrover-docs/blob/electrical/Electrical/images/cam.png)

![Live feed from camera](https://github.com/iudhael/benrover-docs/blob/electrical/Electrical/images/live1.png)

![Live feed from camera](https://github.com/iudhael/benrover-docs/blob/electrical/Electrical/images/live2.png)







