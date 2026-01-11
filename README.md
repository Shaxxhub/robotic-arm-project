# Gesture Controlled Robotic Arm using ESP32 and IR Sensor

##  Overview
This project presents a **low-cost, gesture-controlled robotic arm** that translates human hand movements into robotic arm actions using an **ESP32 microcontroller**, **MPU6050 IMU**, and an **IR sensor**.  
The system enables intuitive human–machine interaction with **minimal latency**, making it suitable for **industrial automation, assistive robotics, and hazardous material handling**.

Unlike conventional designs that rely on flex sensors, this project uses an **IR sensor for gripper control**, improving durability, reliability, and cost-effectiveness.

---

##  Objectives
- Design a real-time gesture-controlled robotic arm
- Replace flex sensors with IR sensors for improved durability
- Achieve low-latency and accurate motion tracking
- Provide a scalable and low-cost human–robot interface

---

##  System Architecture
- **Hand Glove Unit**
  - MPU6050 detects hand orientation (X, Y, Z axes)
  - IR sensor detects proximity for gripper control
- **Control Unit**
  - ESP32 processes sensor data
  - Servo motors replicate hand gestures
- **Robotic Arm**
  - Four servo motors for multi-axis movement

---

##  Materials Used
- ESP32 Microcontroller  
- MPU6050 Accelerometer & Gyroscope  
- IR Sensor  
- Servo Motors (4x)  
- Breadboard  
- Connecting Wires  
- Hand Gloves  
- Cardboard (Robotic Arm Structure)

---

##  Working Principle
1. The **MPU6050** mounted on the glove captures wrist orientation and motion.
2. Orientation data is mapped to servo angles controlling robotic arm movement.
3. The **IR sensor** detects hand proximity to open or close the gripper.
4. ESP32 processes the data and drives the servos in real time.
5. The system supports **wired and wireless (Wi-Fi/Bluetooth)** communication.

---

##  Applications
- **Industrial Automation** – Reduces manpower in repetitive tasks  
- **Assistive Robotics** – Helps individuals with physical disabilities  
- **Hazardous Environment Handling** – Remote operation in unsafe zones  

---

##  Results & Performance
- **Latency:** < 100 ms  
- **Gesture Accuracy:** ~95% over 200 trials  
- **IMU Accuracy:** ±2° variation on X, Y, Z axes  
- **Durability:**  
  - IR Sensor: 1000+ cycles with no degradation  
  - Flex Sensor (comparison): 15–20% drift after 500 cycles  

---

##  Discussion
- IR sensors outperform flex sensors in durability and maintenance
- Binary gripper control simplifies operation but limits force modulation
- Ambient light interference may affect IR readings
- ESP32 enables efficient real-time processing and wireless control

---

##  Future Improvements
- Machine learning-based adaptive gesture recognition
- Ambient light filtering algorithms
- Force-sensitive resistors (FSR) for analog grip control
- Full wireless implementation using ESP32 Wi-Fi/Bluetooth

---

##  Conclusion
The project successfully demonstrates a **robust, low-cost, and intuitive gesture-controlled robotic arm**.  
Replacing flex sensors with IR sensors significantly improves durability, responsiveness, and reliability while maintaining high accuracy.  
This system provides a scalable solution for **real-world human–robot interaction** in industrial and assistive applications.

---

##  References
1. Pramoth Thangavel, *Hand Gesture Controlled Robotic Arm using Arduino Nano*, Circuit Digest, 2021  
2. MPU6050 Datasheet – InvenSense  
3. ESP32 Official Documentation – Espressif Systems  
4. MPU6050 Interfacing with ESP32 – Circuit Digest  
5. Flex Sensor Based Robotic Arm Controller – ResearchGate  

---

##  Author
**Shashank**  
Electronics and Communication Engineering  
VIT Vellore  

---

*If you find this project useful, consider giving the repository a star!*
