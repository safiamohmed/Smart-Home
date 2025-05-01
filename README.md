# Smart Home Security and Control System

## Project Overview and Real-Time Support

The Smart Home Security and Control System is an embedded system designed to enhance home security and provide device control using two ATmega32 microcontrollers configured as a Master-Slave architecture. The system integrates security features with smart home automation, allowing users to secure their home and control devices in real-time.

### System Components:
- **Master:** The Master unit handles security operations. It allows users to enter a 4-digit password via a 4x4 keypad to unlock a door, simulated by a DC motor rotating clockwise and counterclockwise. Feedback is displayed on a 16x2 LCD (e.g., "Enter Your Pass", "ALARM ON"). If the password is entered incorrectly three times, a buzzer alarm is triggered, which can be stopped by pressing the '#' key on the keypad. The Master communicates with the Slave via SPI to control home devices.
- **Slave:** The Slave unit manages device control and environmental monitoring. It receives commands from the Master via SPI to control devices like LEDs (lighting), AC units, and TVs in two rooms (Room 1 and Room 2). Additionally, the Slave measures temperature using an LM35 sensor, displays it on the LCD, and triggers a warning if the temperature exceeds 50°C.

### Real-Time Support:
- **Instant Input Processing (Master):** The Master continuously polls the keypad using the `KPD_u8GetPressedKey()` function, ensuring key presses are detected and processed without noticeable delays. Each key press is instantly reflected on the LCD as an asterisk (*).
- **Immediate Feedback (Master):** Upon entering the password, the Master compares it with the stored password ("1234") in real-time. If correct, the motor activates immediately to simulate door movement; if incorrect, the LCD displays "WRONG PASSWORD" within milliseconds.
- **Alarm Activation (Master):** After three failed password attempts, the Master triggers the buzzer alarm instantly, providing real-time security alerts. The buzzer can be stopped by pressing the '#' key, which is also detected in real-time.
- **Real-Time Communication (Master-Slave via SPI):** The Master sends commands to the Slave via SPI with high speed (SPI Prescaler = 16). The Slave receives and executes commands (e.g., turning on/off LEDs, AC, or TVs) in less than a millisecond, ensuring real-time device control. The Slave also returns device status to the Master when requested.
- **Temperature Monitoring (Slave):** The Slave uses Timer0 in CTC mode to measure temperature every second (approximately 4000 overflows with OCR0 = 250 and Prescaler = 8). The LM35 sensor reading is processed via the ADC (taking less than 100µs at 8MHz), and the temperature is displayed on the LCD immediately. If the temperature exceeds 50°C, a warning ("WARNING", "TEMPERATURE INCREASED") is displayed, and an alarm (PA6 pin) is activated in real-time.
- **Efficient Design:** The system uses a combination of polling (for keypad input in the Master) and interrupts (Timer0 in the Slave for temperature monitoring), ensuring predictable and deterministic behavior. The ATmega32's 8MHz clock frequency ensures that tasks like password validation, device control, and temperature monitoring are executed with minimal latency.

This real-time capability makes the system reliable for security and smart home applications, where immediate responses to user actions, device control, and environmental changes are critical.

## Features
- **Password Entry (Master):** Users can enter a 4-digit password using a 4x4 keypad to unlock a door.
- **LCD Display (Both Units):** A 16x2 LCD displays system messages (e.g., "Enter Your Pass", "ALARM ON" on the Master; temperature and warnings on the Slave).
- **Motor Control (Master):** A DC motor simulates door opening/closing (clockwise and counterclockwise rotation).
- **Buzzer Alarm (Master):** A buzzer sounds continuously if the password is entered incorrectly three times, stopped by pressing the '#' key.
- **Device Control (Slave):** Controls LEDs, AC units, and TVs in two rooms via SPI commands from the Master.
- **Temperature Monitoring (Slave):** Measures temperature using an LM35 sensor and displays it on the LCD; triggers a warning if the temperature exceeds 50°C.
- **SPI Communication:** The Master and Slave communicate via SPI for real-time device control and status updates.

## System Architecture (Class Diagram)

The following diagram illustrates the main modules of the system and their interactions:

- **Master Controller (ATmega32):** Handles security operations and sends commands to the Slave.
- **Slave Controller (ATmega32):** Manages device control and temperature monitoring.
- **Keypad Module (Master):** Handles user input (password entry).
- **LCD Module (Both):** Displays system messages and temperature.
- **Motor Module (Master):** Controls the door mechanism.
- **Buzzer Module (Master):** Sounds an alarm on failed password attempts.
- **SPI Module:** Facilitates communication between Master and Slave.
- **LM35 Module (Slave):** Measures temperature.
- **Device Control Module (Slave):** Controls LEDs, AC units, and TVs.

![Class Diagram]([class diagram.png](https://drive.google.com/file/d/1lImYSE5bosB1kEqoDCLOMBrpM6WST2rQ/view?usp=drive_link))

## Hardware Components
- **2x ATmega32 Microcontrollers:** One for the Master, one for the Slave.
- **16x2 LCD (Both Units):** Displays messages and system status (Master: security messages; Slave: temperature and warnings).
- **4x4 Keypad (Master):** For entering the password.
- **DC Motor (Master):** Simulates a door mechanism (controlled via an H-bridge or similar driver).
- **Buzzer (Master):** For sounding an alarm (connected to PD5 via a transistor).
- **LM35 Temperature Sensor (Slave):** Connected to PA0 for temperature measurement.
- **Transistor (2N1711, Master):** Used to drive the buzzer.
- **Resistor (1kΩ, Master):** Limits the base current to the transistor.
- **Crystal Oscillator:** For the ATmega32 clock (typically 8MHz).
- **Power Supply:** 5V DC to power the system.

## Circuit Connections
### Master:
- **LCD:**
  - RS: PD0, RW: PD1, E: PD2, Data pins (D4-D7): PC0-PC3.
- **Keypad:** Connected to PORTA (specific pins depend on the keypad library configuration).
- **DC Motor:** Controlled via PORTA (PA4, PA5 for motor pins).
- **Buzzer:**
  - Connected to PD5 through a transistor (2N1711).
  - A 1kΩ resistor connects PD5 to the transistor base.
  - The buzzer is powered by VCC (5V) and grounded through the transistor.
- **SPI:** Configured for master mode (PB4: SS, PB5: MOSI, PB6: MISO, PB7: SCK).

### Slave:
- **LCD:**
  - Data port: PORTD, Control port: PORTA (RS: PA1, RW: PA2, E: PA3).
- **LM35:** Connected to PA0 (ADC Channel 0).
- **Device Control Pins:**
  - Room 1: LED (PC0), TV (PC1), AC (PC2, with PA5 for additional control).
  - Room 2: LED (PC3), TV (PC4), AC (PC5, with PA4 for additional control).
- **Temperature Warning Pins:** PA6 (HIGH for warning), PA7 (HIGH for normal state).
- **SPI:** Configured for slave mode (PB4: SS, PB5: MOSI, PB6: MISO, PB7: SCK).

## Software Requirements
- **AVR-GCC:** For compiling the code.
- **AVRDUDE:** For uploading the code to the ATmega32.
- **Custom Libraries:**
  - `DIO_INTERFACE.h`: For digital I/O operations.
  - `LCD_INTERFACE.h`: For LCD control.
  - `keypad.h`: For keypad input (Master).
  - `SPI_INTERFACE.h`: For SPI communication.
  - `motor.h`: For motor control (Master).
  - `ADC_interface.h`: For ADC operations (Slave).
  - `LM35.h`: For temperature measurement (Slave).
  - `TIMER_INTERFACE.h`: For Timer0 operations (Slave).
  - `options.h`: For device control functions (Slave).
  - `GIE_INTERFACE.h`: For global interrupt enable.
  - `STD_TYPES.h` and `BIT_MATH.h`: For standard types and bit manipulation.

## Setup Instructions
1. **Hardware Setup:**
   - Connect the ATmega32 microcontrollers (Master and Slave) to the components as described in the "Circuit Connections" section.
   - Ensure the buzzer (Master) is connected to PD5 and the LM35 (Slave) to PA0.
   - Power the circuit with a 5V DC supply.

2. **Software Setup:**
   - Clone this repository to your local machine:
     ```
     git clone <repository-url>
     ```
   - Open the project in your preferred IDE (e.g., Atmel Studio or VS Code with AVR-GCC setup).
   - Ensure all required libraries (`DIO_INTERFACE.h`, `LCD_INTERFACE.h`, etc.) are included in the project directory.

3. **Compile and Upload:**
   - Compile the code for both Master and Slave using AVR-GCC:
     ```
     avr-gcc -mmcu=atmega32 -o main.elf main.c
     ```
   - Convert the ELF file to HEX:
     ```
     avr-objcopy -O ihex main.elf main.hex
     ```
   - Upload the HEX file to the respective ATmega32 using AVRDUDE:
     ```
     avrdude -c <programmer> -p m32 -U flash:w:main.hex
     ```
     Replace `<programmer>` with your programmer type (e.g., `usbasp`).

## Usage
### Master:
1. Power on the Master unit.
2. The LCD will display a welcome message: "HOLA, IN UR SMART HOME".
3. The LCD will then prompt: "Enter Your Pass".
4. Enter the 4-digit password using the keypad (default password: "1234").
   - If correct:
     - The LCD displays: "HEY!! YOU'Re Good Man".
     - The motor rotates clockwise for 2 seconds, then counterclockwise for 2 seconds (simulating door opening/closing).
   - If incorrect:
     - The LCD displays: "WRONG PASSWORD".
     - You have 3 attempts to enter the correct password.
   - After 3 failed attempts:
     - The LCD displays: "SORRY, You Tried 3 Times", followed by "ALARM ON".
     - The buzzer sounds continuously.
     - Press the '#' key to stop the alarm and reset the system.

### Slave:
1. Power on the Slave unit.
2. The Slave continuously monitors temperature using the LM35 sensor and displays it on the LCD every second (e.g., "Temperature= 25c").
3. If the temperature exceeds 50°C:
   - The LCD displays: "WARNING", followed by "TEMPERATURE INCREASED".
   - Pin PA6 is set HIGH as an alarm, and PA7 is set LOW.
   - If the temperature drops below 50°C, PA7 is set HIGH, and PA6 is set LOW.
4. The Slave receives commands from the Master via SPI to control devices:
   - **Room 1:** LED (PC0), TV (PC1), AC (PC2, PA5).
   - **Room 2:** LED (PC3), TV (PC4), AC (PC5, PA4).
   - Commands include turning devices on ('1') or off ('2').

## Code Structure
- **main.c (Master):** Main program for the Master, handling password entry, motor control, and SPI communication.
- **main.c (Slave):** Main program for the Slave, handling device control and temperature monitoring.
- **Libraries:**
  - `DIO_INTERFACE.h`: Handles digital I/O operations.
  - `LCD_INTERFACE.h`: Controls the LCD display.
  - `keypad.h`: Manages keypad input (Master).
  - `SPI_INTERFACE.h`: Configures SPI communication.
  - `motor.h`: Controls the DC motor (Master).
  - `ADC_interface.h`: Manages ADC operations (Slave).
  - `LM35.h`: Handles temperature measurement (Slave).
  - `TIMER_INTERFACE.h`: Configures Timer0 for periodic temperature checks (Slave).
  - `options.h`: Implements device control functions (Slave).
  - `GIE_INTERFACE.h`: Manages global interrupts.
  - `STD_TYPES.h` and `BIT_MATH.h`: Utility libraries for type definitions and bit manipulation.

## Notes
- The default password (Master) is hardcoded as "1234". Modify it in the `pass` array in `main.c` (Master).
- The buzzer (Master) is assumed to be an Active Buzzer. If using a Passive Buzzer, modify the code to use PWM.
- The temperature threshold (Slave) is set to 50°C. Adjust this value in the `ISR()` function in `main.c` (Slave) if needed.
- Ensure the ATmega32 clock frequency matches your crystal oscillator (typically 8MHz). Adjust the F_CPU definition if necessary.

## Troubleshooting
- **Buzzer Not Working (Master):**
  - Ensure the buzzer is connected to PD5.
  - Test the buzzer by connecting it directly to VCC (5V) and Ground.
  - Check the transistor (2N1711) for proper operation using a multimeter.
- **LCD Not Displaying (Both Units):**
  - Verify the LCD connections (Master: RS: PD0, RW: PD1, E: PD2, D4-D7: PC0-PC3; Slave: Data: PORTD, RS: PA1, RW: PA2, E: PA3).
  - Ensure the LCD contrast is adjusted properly (via a potentiometer on the V0 pin).
- **Keypad Not Responding (Master):**
  - Check the keypad connections to PORTA.
  - Test the keypad by displaying pressed keys on the LCD.
- **Motor Not Moving (Master):**
  - Verify the motor connections and driver circuit (PA4, PA5).
  - Ensure the motor power supply is adequate.
- **Temperature Not Displaying (Slave):**
  - Ensure the LM35 is connected to PA0 and powered correctly (5V).
  - Check the ADC configuration in `ADC_config.h`.
- **Devices Not Responding (Slave):**
  - Verify SPI connections (PB4-PB7) between Master and Slave.
  - Ensure the device control pins (PC0-PC5, PA4-PA5) are connected correctly.

## Future Improvements
- Add EEPROM storage to save the password (Master), allowing dynamic changes.
- Implement a real-time clock (RTC) to log access attempts (Master) and temperature readings (Slave).
- Add more sophisticated device control (e.g., dimming LEDs, setting AC temperature).
- Integrate wireless communication (e.g., via UART or I2C) for remote control.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributors
- [Your Name] - Developer
