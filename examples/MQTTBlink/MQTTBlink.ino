#include <QuickMQTT.h>

// Client ID: "Blink" - used for wifi client as well as for MQTT topic
char* ClientID = "Blink";

QuickMQTT mqtt = QuickMQTT(ClientID, "192.168.0.10", 1883, "username", "password");

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';

  if (!eq((byte *) topic, ClientID)) return;

  // receive mqtt message Blink/blink
  if (eq(payload, "blink")) {
    digitalWrite(BUILTIN_LED, HIGH);
    delay(1000);
    digitalWrite(BUILTIN_LED, LOW);
  } 
} 

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);  
  delay(10);
  digitalWrite(BUILTIN_LED, LOW);
  
  mqtt.SetWiFi("WIFI_SSID", "WiFiPassword");
  mqtt.setup(callback);
}

void loop() {
  mqtt.loop();
}
