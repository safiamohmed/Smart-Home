# Smart Home Security System

## Overview
This project implements a **Smart Home Security System** using an ATmega32 microcontroller. The system allows users to enter a password via a 4x4 keypad to unlock a door (controlled by a DC motor). If the password is entered correctly, the door opens (motor rotates clockwise and then counterclockwise). If the password is entered incorrectly three times, an alarm (buzzer) is triggered. The system also features an LCD to display messages and user feedback.

## Features
- **Password Entry:** Users can enter a 4-digit password using a 4x4 keypad.
- **LCD Display:** A 16x2 LCD displays system messages (e.g., "Enter Your Pass", "ALARM ON").
- **Motor Control:** A DC motor simulates opening/closing a door (clockwise and counterclockwise rotation).
- **Buzzer Alarm:** A buzzer sounds continuously if the password is entered incorrectly three times. The alarm can be stopped by pressing the '#' key on the keypad.
- **SPI Communication:** The system includes SPI communication (though not fully utilized in the current implementation).

## Hardware Components
- **ATmega32 Microcontroller:** The main controller for the system.
- **16x2 LCD:** Used to display messages and system status.
- **4x4 Keypad:** For entering the password.
- **DC Motor:** Simulates a door mechanism (controlled via an H-bridge or similar driver).
- **Buzzer:** For sounding an alarm (connected to PD5 via a transistor).
- **Transistor (2N1711):** Used to drive the buzzer.
- **Resistor (1kΩ):** Limits the base current to the transistor.
- **Crystal Oscillator:** For the ATmega32 clock (not specified, but typically 8MHz).
- **Power Supply:** 5V DC to power the system.

## Circuit Connections
- **LCD:**
  - RS: PD0
  - RW: PD1
  - E: PD2
  - Data pins (D4-D7): Connected to PORTC (pins PC0-PC3).
- **Keypad:** Connected to PORTA (specific pins depend on the keypad library configuration).
- **DC Motor:** Controlled via PORTB (specific pins depend on the motor driver used).
- **Buzzer:**
  - Connected to PD5 through a transistor (2N1711).
  - A 1kΩ resistor connects PD5 to the transistor base.
  - The buzzer is powered by VCC (5V) and grounded through the transistor.
- **SPI:** Configured for master mode (pins PB5-PB7), though not actively used in this implementation.

## Software Requirements
- **AVR-GCC:** For compiling the code.
- **AVRDUDE:** For uploading the code to the ATmega32.
- **Custom Libraries:**
  - `DIO_INTERFACE.h`: For digital I/O operations.
  - `LCD_INTERFACE.h`: For LCD control.
  - `keypad.h`: For keypad input.
  - `SPI_INTERFACE.h`: For SPI communication.
  - `motor.h`: For motor control.
  - `main_confgration.h`: Configuration file (not detailed in the project).
  - `STD_TYPES.h` and `BIT_MATH.h`: For standard types and bit manipulation.

## Setup Instructions
1. **Hardware Setup:**
   - Connect the ATmega32 to the components as described in the "Circuit Connections" section.
   - Ensure the buzzer is connected to PD5 (not PD0, to avoid conflict with the LCD).
   - Power the circuit with a 5V DC supply.

2. **Software Setup:**
   - Clone this repository to your local machine:
     ```
     git clone <repository-url>
     ```
   - Open the project in your preferred IDE (e.g., Atmel Studio or VS Code with AVR-GCC setup).
   - Ensure all required libraries (`DIO_INTERFACE.h`, `LCD_INTERFACE.h`, etc.) are included in the project directory.

3. **Compile and Upload:**
   - Compile the code using AVR-GCC:
     ```
     avr-gcc -mmcu=atmega32 -o main.elf main.c
     ```
   - Convert the ELF file to HEX:
     ```
     avr-objcopy -O ihex main.elf main.hex
     ```
   - Upload the HEX file to the ATmega32 using AVRDUDE:
     ```
     avrdude -c <programmer> -p m32 -U flash:w:main.hex
     ```
     Replace `<programmer>` with your programmer type (e.g., `usbasp`).

## Usage
1. Power on the system.
2. The LCD will display a welcome message: "HOLA, IN UR SMART HOME".
3. The LCD will then prompt: "Enter Your Pass".
4. Enter the 4-digit password using the keypad (default password: "1234").
   - If the password is correct:
     - The LCD displays: "HEY!! YOU'Re Good Man".
     - The motor rotates clockwise for 2 seconds, then counterclockwise for 2 seconds (simulating door opening/closing).
   - If the password is incorrect:
     - The LCD displays: "WRONG PASSWORD".
     - You have 3 attempts to enter the correct password.
   - After 3 failed attempts:
     - The LCD displays: "SORRY, You Tried 3 Times", followed by "ALARM ON".
     - The buzzer sounds continuously.
     - Press the '#' key on the keypad to stop the alarm and reset the system.

## Code Structure
- **main.c:** The main program file containing the system logic.
- **Libraries:**
  - `DIO_INTERFACE.h`: Handles digital I/O operations.
  - `LCD_INTERFACE.h`: Controls the LCD display.
  - `keypad.h`: Manages keypad input.
  - `SPI_INTERFACE.h`: Configures SPI communication.
  - `motor.h`: Controls the DC motor.
  - `main_confgration.h`: Configuration settings (e.g., pin definitions).
  - `STD_TYPES.h` and `BIT_MATH.h`: Utility libraries for type definitions and bit manipulation.

## Notes
- The default password is hardcoded as "1234". You can modify it in the `pass` array in `main.c`.
- The buzzer is assumed to be an Active Buzzer (sounds with a constant HIGH signal). If your buzzer is Passive (requires PWM), modify the code to use PWM (refer to previous discussions for PWM implementation).
- Ensure the ATmega32 clock frequency matches your crystal oscillator (typically 8MHz). Adjust the F_CPU definition in the code if necessary.

## Future Improvements
- Add EEPROM storage to save the password, allowing users to change it dynamically.
- Implement a more sophisticated alarm system (e.g., different sound patterns for the buzzer).
- Add a real-time clock (RTC) to log access attempts.
- Utilize SPI communication to connect to additional modules (e.g., a remote server).

