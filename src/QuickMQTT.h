#ifndef QUICK_MQTT_H
#define QUICK_MQTT_H
#include <Arduino.h>

class QuckMQTT {
private:
    char* _wifi_ssid;
    char* _wifi_pass;
    char* _client_id;
    char* _mqtt_host;
    int _mqtt_port;
    char* _mqtt_user;
    char* _mqtt_pass;

public:
    QuckMQTT(char* client_id, char* mqtt_host, int mqtt_port, char* mqtt_user, char* mqtt_pass)
        : _client_id(client_id), _mqtt_host(mqtt_host), _mqtt_port(mqtt_port), _mqtt_user(mqtt_user), _mqtt_pass(mqtt_pass) {
    }

    void SetWiFi(char* wifi_ssid, char* wifi_pass);
    void setup(void (*)(char*, byte*, unsigned int));
    void reconnect();
    void loop();
};

bool eq(byte* payload, const char* key);

#endif