#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

#define CONSOLE_IP "192.168.1.2"
#define CONSOLE_PORT 4210


/* your SSID & Password */
const char* ssid = "jamBox";
const char* password = "jambox1000";


const int trigPin = 13;
const int echoPin = 14;

float duration, distance;


IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP Udp;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Serial.begin(9600);
  
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  server.begin();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  Udp.beginPacket(CONSOLE_IP, CONSOLE_PORT);
  Udp.print(distance);
  Udp.print(" ");
  Udp.printf(String(touchRead(T0)).c_str());
  Udp.endPacket();
  /*
  Serial.print("Distance: ");
  Serial.println(distance);
  */
  delay(100);
}
