# Smart Study Focus Monitor

In this project, I created an IoT system that monitors study focus level using an ESP32.

A potentiometer is used to simulate the student's focus level. The ESP32 reads the sensor value and sends it using MQTT.

A Python program running on the computer receives the data and stores it in a SQLite database. The stored values are then visualized with a graph using matplotlib.

An LED is also connected to the ESP32 as an alert system. When the focus level is too low, the LED turns on.



commands to remember : 
source ~/myenv/bin/activate

python mqtt_db_receiver.py

python plot_data.py