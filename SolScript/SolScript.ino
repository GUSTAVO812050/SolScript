#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String page = "";

void handleRoot() {
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin("SEU_SSID", "SUA_SENHA");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
