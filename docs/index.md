<p align="center">
  <img width="900" src="./assets/banner-home-docs.png">
</p>

<div align="center">
BenRover - a team of passionate engineers and students from Benin, dedicated to designing and building a rover for Mars missions as part of the <a href=“https://cars4mars.co.za/”>Africa Rover Challenge - Cars4Mars</a>.
</div>

## Comprehensive Overview of the Rover architecture
![Comprehensive Overview of the Rover architecture img](https://raw.githubusercontent.com/BenRover-24/docs/main/docs/electronics/images/rover_architecture.jpg)

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

---

## Our mission 🚀

Our mission is clear:

### Innovate and Explore 🌌

- **Designing the Future**: We aim to push the boundaries of engineering by developing a Mars rover capable of navigating challenging terrain and conducting scientific experiments autonomously.

- Inspire the Next Generation**: We are committed to inspiring young engineers and scientists across Benin and Africa, by showing them the excitement and possibilities of space exploration.

### Building a Technological Legacy 🛠️

- Local Talent Development**: Through our project, we aim to strengthen engineering skills among young Beninese, fostering a new generation of innovators in space technology.

- Collaboration and Excellence**: We strive to create a collaborative environment that encourages the sharing of knowledge and expertise in robotics and space exploration.

### Promoting STEM in Benin

- Educational Outreach**: We collaborate with schools and local communities to promote STEM education, with the aim of empowering future leaders in science and technology.

- Advancing Technological Frontiers**: By participating in the Africa Rover Challenge, we contribute to the advancement of technological capabilities and research in our region.

## Get involved 🤝

Whether you're an engineer, space enthusiast or just curious about our mission, here are several ways to support us:

- **Follow us** on [GitHub](https://github.com/BenRover-24) for updates on our rover development and mission progress.
- **Join our Workshops**: Attend our workshops and training sessions to learn more about robotics and space exploration.
- **Contribute**: If you have skills in engineering, robotics or software development, consider joining our team and contributing to the success of our project.

Together, we can demonstrate the potential of African innovation in space exploration and engineering.