#include <WiFi.h>

const char* ssid = "ESP";              //this is my mobile-hotspot name
const char* password = "darkking";       //it's password

#define LED1 13                  //led's long leg connected to esp32 (GPIO-13 pin)
#define LED2 12
#define LED3 14
#define LED4 15

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/LED1=ON") != -1) digitalWrite(LED1, HIGH);
    if (request.indexOf("/LED1=OFF") != -1) digitalWrite(LED1, LOW);
    if (request.indexOf("/LED2=ON") != -1) digitalWrite(LED2, HIGH);
    if (request.indexOf("/LED2=OFF") != -1) digitalWrite(LED2, LOW);
    if (request.indexOf("/LED3=ON") != -1) digitalWrite(LED3, HIGH);
    if (request.indexOf("/LED3=OFF") != -1) digitalWrite(LED3, LOW);
    if (request.indexOf("/LED4=ON") != -1) digitalWrite(LED4, HIGH);
    if (request.indexOf("/LED4=OFF") != -1) digitalWrite(LED4, LOW);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<!DOCTYPE html><html><body style='text-align:center;font-family:sans-serif;'>");
    client.println("<h1>ESP32-CAM 4-LED Control</h1>");

    client.println("<h3>LED 1</h3>");
    client.println("<a href=\"/LED1=ON\"><button style='padding:15px;font-size:18px;'>ON</button></a> ");
    client.println("<a href=\"/LED1=OFF\"><button style='padding:15px;font-size:18px;'>OFF</button></a>");

    client.println("<h3>LED 2</h3>");
    client.println("<a href=\"/LED2=ON\"><button style='padding:15px;font-size:18px;'>ON</button></a> ");
    client.println("<a href=\"/LED2=OFF\"><button style='padding:15px;font-size:18px;'>OFF</button></a>");

    client.println("<h3>LED 3</h3>");
    client.println("<a href=\"/LED3=ON\"><button style='padding:15px;font-size:18px;'>ON</button></a> ");
    client.println("<a href=\"/LED3=OFF\"><button style='padding:15px;font-size:18px;'>OFF</button></a>");

    client.println("<h3>LED 4</h3>");
    client.println("<a href=\"/LED4=ON\"><button style='padding:15px;font-size:18px;'>ON</button></a> ");
    client.println("<a href=\"/LED4=OFF\"><button style='padding:15px;font-size:18px;'>OFF</button></a>");

    client.println("</body></html>");
    client.stop();
  }
}
