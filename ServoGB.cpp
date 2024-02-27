#include "Arduino.h"
#define constant1 0.1
#define constant2 3.1

volatile uint8_t overflowCounter = 0;
volatile uint8_t count = 0;
volatile int value = 0; 
int desiredOverflowCount = 1;
int pin;

ServoGB::ServoGB(){

} 

void setupTimer() {
  TCCR2A = 0x00; 
  TCCR2B = 0x00; 
  TCCR2B |= (1 << CS21); 
  TIMSK2 |= (1 << TOIE2);
}

void ServoGB::attach(int servoPin) { 
  ::pin = servoPin; 
  setupTimer();
  pinMode(pin, OUTPUT);
  sei(); 
}

ISR(TIMER2_OVF_vect) { 
  overflowCounter++; 

  if (overflowCounter >= desiredOverflowCount) {
    count++;

    if (count < value) {
      digitalWrite(pin, HIGH); 
    } else {
      digitalWrite(pin, LOW);
    }

    if (count >= 50) { 
      count = 0;
    }

    overflowCounter = 0;
  }
}

int ServoGB::write(int pos) {
 value = (constant1 )*pos+ constant2;
}
