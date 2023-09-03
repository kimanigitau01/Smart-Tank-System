# Smart Tank System

The **Smart Tank System** is a DIY project that allows you to monitor and control the water level in a tank using an Arduino Nano/Uno, a water sensor, a 16x2 LCD with I2C interface, a relay, a pump, and three LEDs (red, green, yellow). This system is designed to efficiently manage your water resources by providing real-time water level information and automated pump control.
Functionality

*The Smart Tank System performs the following functions:*

    **Read Water Level:** The system reads the water level from the tank using a water sensor.

    **Control the Pump:** It controls a pump to either fill or empty the tank as needed based on the water level.

    **Display Readings:** The system prints the water level readings to the LCD, providing a clear and easy-to-read display of the current water level.

    **Indicate Water Level:** It uses LEDs to indicate the water level, with different colors representing different states of the water.

## Components Required

To build the Smart Tank System, you will need the following components:

    **Arduino Nano/Uno**
    **Water sensor**
    **16x2 LCD with I2C interface**
    **Relay**
    **Pump**
    **Three LEDs (red, green, yellow)**

### Pseudo Code

Here's the pseudo code outlining the system's behavior based on the water level readings:

when sensor is dry reading is 0
when water is partially immersed in water reading is 260 - 435
when water is fully immersed in water reading is 448 - 524
when the water is excess - > 525

1. When there's no water:
   - Turn the pump on
   - Turn all LEDs off
   - Print the current reading and the state of the water on the LCD

2. When the water is low:
   - Turn the pump on
   - Turn the red LED on
   - Print the current reading and the state of the water on the LCD

3. When the water is medium:
   - Turn the pump on
   - Turn the yellow LED on
   - Print the current reading and the state of the water on the LCD

4. When the water is full:
   - Turn the pump on
   - Turn the green LED on
   - Print the current reading and the state of the water on the LCD

5. When the water is in excess:
   - Turn the pump off
   - Blink all LEDs
   - Print the current reading and the state of the water on the LCD

## GitHub Repository

For detailed information on setting up and using the Smart Tank System, please refer to the README.md file in the GitHub repository. The README will include step-by-step instructions, wiring diagrams, and any additional details necessary for building and using the system.

Feel free to customize the system to meet your specific needs and expand upon the project as desired. Happy tinkering!