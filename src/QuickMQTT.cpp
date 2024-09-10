#include "QuickMQTT.h"
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void QuckMQTT::SetWiFi(char* wifi_ssid, char* wifi_pass) {
    _wifi_ssid = wifi_ssid;
    _wifi_pass = wifi_pass;
}

void QuckMQTT::setup(void (*fn)(char*, byte*, unsigned int)) {
    delay(10);
    WiFi.begin(_wifi_ssid, _wifi_pass);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
    delay(10);
    randomSeed(micros());
    client.setServer(_mqtt_host, _mqtt_port);
    client.setCallback(fn);
}

void QuckMQTT::reconnect() {
    while (!client.connected()) {
        if (client.connect(_client_id, _mqtt_user, _mqtt_pass)) {
            client.publish(_client_id, "online");
            client.subscribe(_client_id);
        } else {
            delay(5000);
        }
    }
}

void QuckMQTT::loop() {
    if (!client.connected()) reconnect();
    client.loop();
}

bool eq(byte* payload, const char* key) {
  return strcmp((char *) payload, key) == 0;
}