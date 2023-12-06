#ifndef MESURE_H
#define MESURE_H

#include <Arduino.h>
class Mesure{
  public:
    Mesure(int triqPin, int echoPin);
    char* run();
  private:
    int _triqPin;
    int _echoPin;
    float duration;
    float distance;
    char buff[5];
};
#endif