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

## CONCLUSION (How to Use the Library):

Here's a detailed step-by-step guide on how to install the ServoGB library for Arduino, starting from downloading the files from GitHub:
Download the Library from GitHub:

### 1.Download the Library from GitHub:
Select "Download ZIP" to download the entire library as a compressed file onto your computer. 

### 2.Locate Arduino Libraries Folder: 
Open the Arduino IDE (Integrated Development Environment) on your computer.
Navigate to the Sketch menu and select "Include Library" > "Manage Libraries...".
This will open the Library Manager window.

### 3.Add the Library to Arduino IDE:
In the Library Manager window, click on the "Add .ZIP Library..." button.
Browse to the location where you extracted the ServoGB library files and select the folder containing the library.
Click "Choose" or "Open" to add the library to the Arduino IDE.


