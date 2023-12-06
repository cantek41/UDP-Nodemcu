#ifndef DIRECTION_H
#define DIRECTION_H

#include <Arduino.h>
class Direction{
  public:
    Direction(int leftMotorForward, int rightMotorForward,int leftMotorBackward,int rightMotorBackward,int rightMotorENB, int leftMotorENB);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
  private:
    int _leftMotorForward;
    int _rightMotorForward;
    int _leftMotorBackward;
    int _rightMotorBackward;
    int _rightMotorENB;
    int _leftMotorENB; 
    
};
#endif