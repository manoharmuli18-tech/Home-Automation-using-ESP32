#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Manohar";           //same hotsot connect to both esp32 and phone or else some issues come
const char* password = "Manohar";

WebServer server(80);

const int led1 = 16;
const int led2 = 17;
const int led3 = 18;
const int led4 = 19;

void handleRoot() {
  String html = "<html><body>";
  html += "<h2>ESP32 LED Control</h2>";

  html += "<p><a href='/led1on'><button>LED1 ON</button></a>";
  html += "<a href='/led1off'><button>LED1 OFF</button></a></p>";

  html += "<p><a href='/led2on'><button>LED2 ON</button></a>";
  html += "<a href='/led2off'><button>LED2 OFF</button></a></p>";

  html += "<p><a href='/led3on'><button>LED3 ON</button></a>";
  html += "<a href='/led3off'><button>LED3 OFF</button></a></p>";

  html += "<p><a href='/led4on'><button>LED4 ON</button></a>";
  html += "<a href='/led4off'><button>LED4 OFF</button></a></p>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());         //use this ip address in phone to open control portal

  server.on("/", handleRoot);

  server.on("/led1on", [](){ digitalWrite(led1, HIGH); handleRoot(); });
  server.on("/led1off", [](){ digitalWrite(led1, LOW); handleRoot(); });

  server.on("/led2on", [](){ digitalWrite(led2, HIGH); handleRoot(); });
  server.on("/led2off", [](){ digitalWrite(led2, LOW); handleRoot(); });

  server.on("/led3on", [](){ digitalWrite(led3, HIGH); handleRoot(); });
  server.on("/led3off", [](){ digitalWrite(led3, LOW); handleRoot(); });

  server.on("/led4on", [](){ digitalWrite(led4, HIGH); handleRoot(); });
  server.on("/led4off", [](){ digitalWrite(led4, LOW); handleRoot(); });

  server.begin();
}

void loop() {
  server.handleClient();
}
