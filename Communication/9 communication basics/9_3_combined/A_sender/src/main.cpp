#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* MQTT_SERVER = "broker.hivemq.com";
const int MQTT_PORT = 1883;

const char* MQTT_TOPIC = "asmaq/communication/button";

WiFiClient espClient;
PubSubClient mqttClient(espClient);

const int buttonPin = 4;
int lastState = HIGH;

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void connectToMQTT() {
  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);

  while (!mqttClient.connected()) {
    String clientId = "ESP32Sender-";
    clientId += String((uint32_t)ESP.getEfuseMac(), HEX);
    mqttClient.connect(clientId.c_str());
    delay(1000);
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  connectToWiFi();
  connectToMQTT();
}

void loop() {
  if (!mqttClient.connected()) {
    connectToMQTT();
  }

  mqttClient.loop();

  int currentState = digitalRead(buttonPin);

  if (currentState != lastState) {
    if (currentState == LOW) {
      mqttClient.publish(MQTT_TOPIC, "ON");
    } else {
      mqttClient.publish(MQTT_TOPIC, "OFF");
    }
    lastState = currentState;
    delay(50);
  }
}