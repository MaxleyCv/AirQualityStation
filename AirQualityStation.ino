#include "HumiditySensor.h"
#include "TransmissionModule.h"
#include "DustSensor.h"

//HumiditySensor *humiditySensor = new HumiditySensor;
TransmissionModule transmissionModule;
DustSensor dust;

void setup() {
   Serial.begin(9600);
   delay(300);
   transmissionModule.setup_wifi();
   transmissionModule.init();
}

void loop() {
  /* Serial.print(humiditySensor -> getTemperature());
   Serial.println(" C");
   Serial.print(humiditySensor -> getHumidity());
   Serial.println(" %");
   
   
   delay(300);*/

if (!transmissionModule.client.connected()) {
   transmissionModule.reconnect();
   }
   transmissionModule.client.loop();
   
   transmissionModule.sendMessage("secterica/heysmell/sensors_info", "Some spam");
   transmissionModule.client.publish("secterica/heysmell/sensors_info", "Some spam 2");
   delay(3000);
}
//


//#include <WiFi.h>
//#include <PubSubClient.h>
//#include <Wire.h>
//
//// Replace the next variables with your SSID/Password combination
//const char* ssid = "TP-Link_EE0E";
//const char* password = "19248325";
//
//// Add your MQTT Broker IP address, example:
////const char* mqtt_server = "192.168.1.144";
//const char* mqtt_server = "broker.hivemq.com";
//
//WiFiClient espClient;
//PubSubClient client(espClient);
//long lastMsg = 0;
//char msg[50];
//int value = 0;
//
////uncomment the following lines if you're using SPI
///*#include <SPI.h>
//#define BME_SCK 18
//#define BME_MISO 19
//#define BME_MOSI 23
//#define BME_CS 5*/
//
//// LED Pin
//const int ledPin = 4;
//
//void setup() {
//  Serial.begin(115200);
//  // default settings
//  // (you can also pass in a Wire library object like &Wire2)
//  //status = bme.begin();  
//  setup_wifi();
//  client.setServer(mqtt_server, 1883);
//  client.setCallback(callback);
//
//  pinMode(ledPin, OUTPUT);
//}
//
//void setup_wifi() {
//  delay(10);
//  // We start by connecting to a WiFi network
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//
//  WiFi.begin(ssid, password);
//
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  Serial.println("");
//  Serial.println("WiFi connected");
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//}
//
//void callback(char* topic, byte* message, unsigned int length) {
//  Serial.print("Message arrived on topic: ");
//  Serial.print(topic);
//  Serial.print(". Message: ");
//  String messageTemp;
//  
//  for (int i = 0; i < length; i++) {
//    Serial.print((char)message[i]);
//    messageTemp += (char)message[i];
//  }
//  Serial.println();
//
//  // Feel free to add more if statements to control more GPIOs with MQTT
//
//  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off". 
//  // Changes the output state according to the message
//  if (String(topic) == "esp32/output") {
//    Serial.print("Changing output to ");
//    if(messageTemp == "on"){
//      Serial.println("on");
//      digitalWrite(ledPin, HIGH);
//    }
//    else if(messageTemp == "off"){
//      Serial.println("off");
//      digitalWrite(ledPin, LOW);
//    }
//  }
//}
//
//void reconnect() {
//  // Loop until we're reconnected
//  while (!client.connected()) {
//    Serial.print("Attempting MQTT connection...");
//    // Attempt to connect
//    if (client.connect("ESP8266Client")) {
//      Serial.println("connected");
//      // Subscribe
//      client.subscribe("esp32/output");
//    } else {
//      Serial.print("failed, rc=");
//      Serial.print(client.state());
//      Serial.println(" try again in 5 seconds");
//      // Wait 5 seconds before retrying
//      delay(5000);
//    }
//  }
//}
//void loop() {
//  if (!client.connected()) {
//    reconnect();
//  }
//  client.loop();
//
//  long now = millis();
//  if (now - lastMsg > 5000) {
//    lastMsg = now;
//    client.publish("secterica/heysmell/sensors_info", "Go 'n fuck yourself");
//  }
//}