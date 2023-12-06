#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include "DHT.h"

#include "mesure.h"
#include "direction.h"
#include "mycrypto.h"

#define DHTPIN 4    // GPIO2 NodeMCU kart üzerinde D4 Pini !
#define LEDPIN 0    // GPIO2 NodeMCU kart üzerinde D4 Pini !
#define DHTTYPE DHT11   // Kullandığımız sensörün tipi DHT 11

#ifndef STASSID
#define STASSID "...."
#define STAPSK "...."
#endif

#define TRIGPIN 16 
#define ECHOPIN 5 

#define LEFTFORWARDPIN 2 
#define LEFTBACKWARDPIN 0 
#define RIGHTFORWARDPIN 15 
#define RIGHTBACKWARDPIN 13 
#define LEFTENBPIN 14 
#define RIGHTENBPIN 12 

float h,t;

unsigned int localPort = 8888;  // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE + 1];  // buffer to hold incoming packet,
char ReplyBuffer[] = "acknowledged\r\n";        // a string to send back

char buff[10];
char * dataCrp;

WiFiUDP Udp;

DHT dht(DHTPIN, DHTTYPE); 
Mesure _mesure(TRIGPIN,ECHOPIN);
Direction _direction(LEFTFORWARDPIN,RIGHTFORWARDPIN,LEFTBACKWARDPIN,RIGHTBACKWARDPIN,RIGHTENBPIN,LEFTENBPIN);
MyCrypto _crypto;
void sendData(char data[]){ 
    dataCrp= _crypto.encrypt(data);
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(dataCrp);
    Udp.endPacket();
}

void readDHT()
{
  h = dht.readHumidity();
  t = dht.readTemperature();   
  //Sensör verisi alınamaz ise
   if (isnan(h) || isnan(t)) {
    Serial.println("DHT Sensor okuma hatasi!");
    return;
  }
  dtostrf(t,6,2,buff);
  buff[6]='T';
  sendData(buff);
  dtostrf(h,6,2,buff);
  buff[6]='H';
  sendData(buff);
  
}


void setup() {
  Serial.begin(115200);
  WiFi.hostname("ESP-host");
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf("UDP server on port %d\n", localPort);
  Udp.begin(localPort);
  dht.begin();
}


void reciver(char data[])
{
  if (strcmp(data,"stop")==0)
    _direction.stop();
  else if (strcmp(data,"forward")==0)
    _direction.forward();
  else if (strcmp(data,"backward")==0)
    _direction.backward();
  else if (strcmp(data,"left")==0)
    _direction.left();
  else if (strcmp(data,"right")==0)
    _direction.right();
}

void loop() {
  
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    Serial.printf("Received packet of size %d from %s:%d\n    (to %s:%d, free heap = %d B)\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort(), Udp.destinationIP().toString().c_str(), Udp.localPort(), ESP.getFreeHeap());

    // read the packet into packetBufffer
    int n = Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    packetBuffer[n] = 0;

    dataCrp= _crypto.decrypt(packetBuffer);
    Serial.print("Contents:");
    Serial.println(dataCrp);
    reciver(dataCrp);

  }
  readDHT();
  sendData(_mesure.run());

}

