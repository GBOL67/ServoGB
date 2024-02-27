# ServoGB Library Documentation

## Introduction
ServoGB is a C++ library designed for Arduino microcontroller boards to facilitate the control of servo motors. The library offers an efficient and interrupt-driven approach to control servo motors using 8-bit timers (specifically Timer2 of an ATmega328P chip). By utilizing interrupts, it enables precise control over servo motor movements, making it suitable for various robotics and automation projects.To use this library:

```
#include <ServoGb.h>
```
## Circuit
The circuit connection for using the ServoGB library is straightforward. Connect the signal wire of the servo motor to the desired Arduino pin (e.g., pin 9). Ensure that the servo motor is powered appropriately based on its specifications. No additional components are required for basic servo motor control.

## Methodology
The ServoGB library employs an interrupt-driven methodology to pulse the servo motor at regular intervals. It utilizes Timer2 of the Arduino (specifically, an ATmega328P chip) to generate interrupts. The overflow counter within the interrupt service routine (ISR) ensures that the correct frequency is maintained for controlling the servo motor.

The pulse width for the servo motor is determined by a linear equation, which relates the desired position (pos) to the on pulse width. This linear equation enables smooth and proportional movement of the servo motor. The maximum pulse width is set to ensure that the servo motor operates within its specified range.

## Methods
attach(int pin): This method attaches the servo motor to the specified pin on the Arduino board, initializing the necessary configurations for servo control.

```
ServoGB myservo;
myservo.attach(9); // Attaches the servo to digital pin 9
```
write(int pos): Sets the servo angle in degrees based on the provided position.

```
myservo.write(90); // Sets the servo angle to 90 degrees
```
read(): This method returns the current angle of the servo motor in degrees.

```
int currentAngle = myservo.read();
Serial.println(currentAngle); // Prints the current angle of the servo
```
