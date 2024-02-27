#ifndef ServoGB
#define ServoGB

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ServoGB {
   public:
   ServoGB();
   uint8_t attach(int pin); 
   uint8_t write(int pos);   

   private:
};

#endif