#include <dht.h>

#define dht_dpin A2 //no ; here. Set equal to channel sensor is on

dht DHT;
const int powerPin = A0;
boolean powerOn = false;
const int tooHot = 26;
const int tooCold = 24;
int humidity = 0;
int temp = 0;

void setup(){
  Serial.begin(9600);
  Serial.println(F("starting up"));
  //Let system settle
  delay(300);
  
  pinMode(powerPin, OUTPUT);
  
  digitalWrite(powerPin, HIGH);
  Serial.println("Humidity and temperature\n\n");
  //Wait rest of 1000ms recommended delay before accessing sensor
  delay(700);
}

void loop(){
  //This is the "heart" of the program.
  DHT.read11(dht_dpin);
  humidity = DHT.humidity;
  temp = DHT.temperature;
    
    // if already on, check if too cold
    if (powerOn) {
      if (temp <= tooCold) {
          digitalWrite(powerPin, HIGH);
          Serial.println(F("OFF"));
          powerOn = false;
      }
    } else {
      // power is off, check if too hot
      if (temp >= tooHot) {
        digitalWrite(powerPin, LOW);
        Serial.println(F("ON"));
        delay(120000);
        powerOn = true; 
      } 
    }
    
    Serial.print("Current humidity = ");
    Serial.print(humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp); 
    Serial.println("C  ");
  
  delay(120000);//Don't try to access too frequently... in theory
  //should be once per two seconds, fastest,
  //but seems to work after 0.8 second.
}// end loop()
