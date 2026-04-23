#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";

const char* MQTT_SERVER = "broker.hivemq.com";
const int MQTT_PORT = 1883;

const char* MQTT_TOPIC = "asmaq/communication/sensor";

WiFiClient espClient;
PubSubClient mqttClient(espClient);

const int sensorPin = 34;

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void connectToMQTT() {
  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);

  while (!mqttClient.connected()) {
    String clientId = "ESP32Sensor-";
    clientId += String((uint32_t)ESP.getEfuseMac(), HEX);
    mqttClient.connect(clientId.c_str());
    delay(1000);
  }
}

void setup() {
  connectToWiFi();
  connectToMQTT();
}

void loop() {
  if (!mqttClient.connected()) {
    connectToMQTT();
  }

  mqttClient.loop();

  int value = analogRead(sensorPin);
  float mappedValue = (value / 4095.0) * 100.0;

  String payload = String(mappedValue);

  mqttClient.publish(MQTT_TOPIC, payload.c_str());

  delay(1000);
}