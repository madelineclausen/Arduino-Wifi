#include <WiFi.h>
// #include <HTTPClient.h>
// #include <ESP8266HTTPClient.h>


char ssid[] = "iPhone-00"; // your network SSID (name)
char pass[] = "update1234"; // your network password (use for WPA, or use as key for WEP)

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("?");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client;
  
  if (client.connect("http://18.119.19.51:5000/?var=receivedat200", 80)) {
    Serial.println("Connected to server");
    
    client.println("GET /path/to/your/resource HTTP/1.1");
    client.print("Host: ");
    client.println("http://18.119.19.51:5000/?var=receivedat200");
    client.println("Connection: close");
    client.println();
    
    // while (client.connected()) {
    //   String line = client.readStringUntil('\n');
    //   Serial.println(line);
    // }
    
    Serial.println("Server disconnected");
  } else {
    Serial.println("Could not connect to server");
  }
  
  delay(5000);
}