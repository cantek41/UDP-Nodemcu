#include <Arduino.h>
#include "mesure.h"

Mesure::Mesure(int triqPin, int echoPin){
  _triqPin = triqPin;
  _echoPin = echoPin;
  pinMode(_triqPin,OUTPUT);
	pinMode(_echoPin, INPUT); 
}
char* Mesure::run(){
    digitalWrite(_triqPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_triqPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triqPin, LOW);
    duration = pulseIn(_echoPin, HIGH);
    distance = (duration*.0343)/2;
    dtostrf(distance,4,2,buff);
    return buff;
}