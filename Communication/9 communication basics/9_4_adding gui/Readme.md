Exercise 4 – GUI Communication

For this task, I implemented a graphical user interface using the HiveMQ Web MQTT Client.

I connected to the public MQTT broker:
broker.hivemq.com

I used the topic:
asmaq/communication/button

Using the GUI, I was able to:
- Send messages ("ON" and "OFF")
- Control an ESP32 remotely
- Observe real-time communication between GUI and device

When I sent:
"ON" → LED turned ON
"OFF" → LED turned OFF

This demonstrates successful GUI-based MQTT communication.

Note:
I used a web-based GUI instead of Python tkinter due to compatibility issues on macOS, but the functionality is the same.