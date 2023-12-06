#include <Arduino.h>
#include "direction.h"

Direction::Direction(int leftMotorForward, int rightMotorForward,int leftMotorBackward,int rightMotorBackward,int rightMotorENB, int leftMotorENB)
{
  _leftMotorForward=leftMotorForward;
  _rightMotorForward=rightMotorForward;
  _leftMotorBackward=leftMotorBackward;
  _rightMotorBackward=rightMotorBackward;
  _rightMotorENB=rightMotorENB;
  _leftMotorENB=leftMotorENB; 
  
  pinMode(_leftMotorForward, OUTPUT);
  pinMode(_rightMotorForward, OUTPUT);
  pinMode(_leftMotorBackward, OUTPUT);
  pinMode(_rightMotorBackward, OUTPUT);
  pinMode(_leftMotorENB, OUTPUT);
  pinMode(_rightMotorENB, OUTPUT);
}

void Direction::forward(){
  digitalWrite(_leftMotorENB,HIGH);
  digitalWrite(_rightMotorENB,HIGH);
  digitalWrite(_leftMotorForward,HIGH);
  digitalWrite(_rightMotorForward,HIGH);
  digitalWrite(_leftMotorBackward,LOW);
  digitalWrite(_rightMotorBackward,LOW);
  Serial.println("forward");
}
void Direction::backward(){
  digitalWrite(_leftMotorENB,HIGH);
  digitalWrite(_rightMotorENB,HIGH);
  digitalWrite(_leftMotorBackward,HIGH);
  digitalWrite(_rightMotorBackward,HIGH);
  digitalWrite(_leftMotorForward,LOW);
  digitalWrite(_rightMotorForward,LOW);
  Serial.println("backward");

}
void Direction::left(){
  digitalWrite(_leftMotorENB,HIGH);
  digitalWrite(_rightMotorENB,HIGH);
  digitalWrite(_leftMotorBackward,HIGH);
  digitalWrite(_rightMotorBackward,LOW);
  digitalWrite(_leftMotorForward,LOW);
  digitalWrite(_rightMotorForward,HIGH);
  Serial.println("left");

}
void Direction::right(){
  digitalWrite(_leftMotorENB,HIGH);
  digitalWrite(_rightMotorENB,HIGH);
  digitalWrite(_leftMotorBackward,LOW);
  digitalWrite(_rightMotorBackward,HIGH);
  digitalWrite(_leftMotorForward,HIGH);
  digitalWrite(_rightMotorForward,LOW);
  Serial.println("right");
}
void Direction::stop(){
  digitalWrite(_leftMotorENB,LOW);
  digitalWrite(_rightMotorENB,LOW);
  digitalWrite(_leftMotorBackward,LOW);
  digitalWrite(_rightMotorBackward,LOW);
  digitalWrite(_leftMotorForward,LOW);
  digitalWrite(_rightMotorForward,LOW);
  Serial.println("stop");
}