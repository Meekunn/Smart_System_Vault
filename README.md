# Smart Room/Vault Monitoring System.
This is an Arduino-based project that utilizes an LED, an ultrasonic sensor, and a temperature sensor. The project involves controlling the LED, reading data from the sensors, and transmitting the collected data to a computer through the Arduino's serial port. Additionally, a QT application is developed to read the data from the serial port and display it in real-time on a graphical user interface (GUI).

## Hardware Components
<ol>
  <li><b>Arduino board:</b> The project requires an Arduino board to serve as the microcontroller.</li>
  <li><b>LED:</b> A light-emitting diode (LED) is used to indicate the status of the system.</li>
  <li><b>Ultrasonic Sensor:</b> The ultrasonic sensor is employed to measure distance by emitting ultrasonic waves and calculating the time it takes for the waves to bounce back.</li>
  <li><b>Temperature Sensor:</b> The temperature sensor used is thermistor, which can accurately measure object temperatures.</li>
</ol>

## Arduino Code
The Arduino code consists of two main parts: sensor data reading and serial communication.
<ol>
  <li><b>Sensor Data Reading</b></li>
  <li><b>Serial Communication</b></li>
</ol>

### Screenshot of Arduino Code
<div style="display: flex; flex-direction: row; justify-content: space-around; width: 100% gap: 1rem">
  <img src="/readme_images/Screenshot from 2023-06-13 11-09-38.png" width="450px"/>
  <img src="/readme_images/Screenshot from 2023-06-13 11-10-58.png" width="450px"/>
</div>

### Arduino Set Up
<div align="center">
  <img src="/readme_images/IMG-20230613-WA0000(1).jpg" width="500px"/>
</div>

## GUI
The graphical user interface (GUI) was designed using QT components, namely QLabel and QLCDNumber, to provide a user-friendly interface for real-time visualization of sensor data. To store the most recent 100 sensor data readings, a Data class was implemented. Additionally, the application computes and presents real-time mean, median, and mode values for the stored data.
At regular intervals, the application checks for available data to be read from the serial port. If data is found, it is read and then parsed. The received data is specifically parsed to extract the LED status, distance, and temperature values. The GUI LCD number objects are subsequently updated with the received data, including the computed mean, median, and mode values for both the ultrasonic and temperature sensors.
<div align="center">
  <img src="/readme_images/Screenshot from 2023-06-12 13-05-24.png" />
</div>
