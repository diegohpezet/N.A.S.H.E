#include <SoftwareSerial.h>
SoftwareSerial bt(8, 9); // RX, TX

#include <LiquidCrystal.h> 
#include "dht.h"
#define dataPin A0
dht DHT;

int temp;
int hum;

void setup() {
 
 Serial.begin(9600); 
 bt.begin(9600); 
 Serial.println("Ready");
 delay(2000); 
 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, HIGH);
}

void loop(){
  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
  
 Serial.println(String(temp) + ";" + String(hum) + ";"); //send distance to MIT App
 bt.println(String(temp) + ";" + String(hum) + ";"); //send distance to MIT App
}
