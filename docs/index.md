<p align="center">
  <img width="900" src="https://raw.githubusercontent.com/BenRover-24/.github/main/profile/assets/Banner.png">
</p>

<div align="center">

Bienvenue chez BenRover - une équipe d'ingénieurs et d'étudiants passionnés du Bénin, dédiée à la conception et à la construction d'un rover pour des missions martiennes dans le cadre de l'<a href="https://cars4mars.co.za/">Africa Rover Challenge - Cars4Mars</a>.

</div>



## Comprehensive Overview of the Rover architecture
![Comprehensive Overview of the Rover architecture](https://github.com/BenRover-24/docs/blob/main/docs/electronics/images/rover_architecture.jpg)

The Rover Architecture depicted in the image below is a diagram of how the different components of our Rover will interact together. We have 5 main types of components in our system. Here’s an explanation of each component and their interactions:

### Input Data Processing Block:
*	Components: This block utilizes an NVIDIA Jetson NANO platform to process inputs from various sensors, including a camera, temperature sensors, a magnetometer, a gyroscope, an accelerometer, as well as instruments for weighing, mapping, and spectroscopic analysis. We chose this powerful processor because in the future we want to implement an autonomous driving system for our Rover with a Computer Vision AI system in real-time.
*	Communication: The data collected by these sensors is transmitted via I2C to the central block.

### Central Computer:
* Components: Raspberry Pi 4, running a ROS (Robot Operating System) software framework which facilitates the programming of rover tasks. We will have a ROS Master on the Raspberry and Nodes to ensure communication between the others. Here’s a short description of the different nodes:
  *  Motion Control Node: Manages the rover's navigation and movement according to trajectory plans and manual commands.
	*  Sensor Processing Node: Processes data from sensors (e.g., cameras, lidars) to detect obstacles and map the environment.
	*  Communication Node: Manages wireless communications with the base station to send data and receive commands.
	*  Energy Management Node: Monitors and manages the rover's power systems to optimize consumption and battery life.
These nodes interact via the ROS Master, which facilitates the discovery and communication between nodes. Information such as steering commands or sensor data flows between nodes using dedicated topics.
*  Functionality: It receives data from sensors, executes processing and analysis algorithms, and sends commands to the output components.
* onnectivity: Uses Wi-Fi for network communication and supports internal and external communications via TCP/IP and I2C.

### Output Components Block:
*  Components: Arduino Mega controls various devices such as displays, servo motors, motors, status LEDs, and a remote receiver.
*  Functions: Acts upon the central computer's instructions to perform physical actions such as movement, device activation, and signaling via LEDs.

### Auxiliary Systems:
*  Energy Management (EMS): A crucial system that manages the rover’s power supply, ensuring energy efficiency and current distribution to different components.
*  Remote Control: Allows external manipulation of the rover for tasks that cannot be automated.
* mergency Stop: A safety device to immediately halt all operations of the rover if necessary.

### Software:
*  Components: Software written in C++ specifically designed to integrate the various hardware, software functionalities, view, and receive real-time values from the robot, making the rover fully controlled and monitored from the station.

Each component in this architecture works in an integrated manner to achieve the mission objectives of the rover, while providing the necessary flexibility to adapt to the changing requirements of simulated environments and assigned tasks.








## Notre mission 🚀

Chez BenRover, notre mission est claire :

### Innover et Explorer 🌌

- **Concevoir l'Avenir** : Nous visons à repousser les limites de l'ingénierie en développant un rover martien capable de naviguer dans des terrains difficiles et de mener des expériences scientifiques de manière autonome.

- **Inspirer la Prochaine Génération** : Nous nous engageons à inspirer les jeunes ingénieurs et scientifiques à travers le Bénin et l'Afrique, en leur montrant l'excitation et les possibilités de l'exploration spatiale.

### Bâtir un Héritage Technologique 🛠️

- **Développement des Talents Locaux** : À travers notre projet, nous cherchons à renforcer les compétences en ingénierie parmi les jeunes Béninois, en favorisant une nouvelle génération d'innovateurs dans le domaine de la technologie spatiale.

- **Collaboration et Excellence** : Nous nous efforçons de créer un environnement collaboratif qui encourage le partage des connaissances et l'expertise en robotique et en exploration spatiale.

### Promouvoir les STEM au Bénin

- **Sensibilisation Éducative** : Nous collaborons avec les écoles et les communautés locales pour promouvoir l'éducation STEM, dans le but d'habiliter les futurs leaders en science et technologie.

- **Avancer les Frontières Technologiques** : En participant à l'Africa Rover Challenge, nous contribuons à l'avancement des capacités technologiques et de la recherche dans notre région.



## Impliquez-vous 🤝

Que vous soyez ingénieur, passionné d'espace ou simplement curieux de notre mission, voici plusieurs façons de nous soutenir :

- **Suivez-nous** sur [GitHub](https://github.com/BenRover-24) pour les mises à jour sur le développement de notre rover et les progrès de la mission.
- **Rejoignez nos Ateliers** : Participez à nos workshops et sessions de formation pour en savoir plus sur la robotique et l'exploration spatiale.
- **Contribuez** : Si vous avez des compétences en ingénierie, en robotique ou en développement logiciel, envisagez de rejoindre notre équipe et de contribuer au succès de notre projet.

Ensemble, nous pouvons démontrer le potentiel de l'innovation africaine dans l'exploration spatiale et l'ingénierie.
