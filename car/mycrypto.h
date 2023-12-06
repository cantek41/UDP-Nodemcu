#ifndef MYCRYPTO_H
#define MYCRYPTO_H

#include <Arduino.h>
class MyCrypto{
  public:    
    char* encrypt(char val[]);
    char* decrypt(char val[]);  
};
#endif