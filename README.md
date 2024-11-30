# Temperature-Based Fan Control System

This project implements a temperature-based fan control system using an Arduino, a DS18B20 temperature sensor, and a relay module. The system reads the ambient temperature and adjusts fan operation based on a user-defined threshold set via a potentiometer. An LCD display is used to show the current temperature and threshold settings.

## Features

- **Real-Time Temperature Monitoring**: Reads temperature data from the DS18B20 sensor.
- **Threshold-Based Control**: Allows users to set the temperature threshold using a potentiometer.
- **Relay Control**: Automatically turns the fan on/off based on the temperature threshold.
- **LCD Display**: Displays the current temperature and threshold settings for easy monitoring.
- **Error Handling**: Detects and indicates sensor disconnection or failure.

---

## Hardware Requirements

1. **Arduino Board**: Compatible with Uno, Nano, or any Arduino-based microcontroller.
2. **DS18B20 Temperature Sensor**: For temperature sensing.
3. **Relay Module**: To control the fan.
4. **Potentiometer**: To adjust the temperature threshold.
5. **16x2 I2C LCD Module**: To display temperature and settings.
6. **Fan (or Load)**: Controlled by the relay.
7. **Connecting Wires and Breadboard**.

---

## Software Requirements

1. **Arduino IDE**: To write and upload the source code.
2. **Libraries**: 
   - `OneWire`
   - `DallasTemperature`
   - `LiquidCrystal_I2C`

---

## Circuit Diagram

![Circuit Diagram Placeholder](![image](https://github.com/user-attachments/assets/176b1277-13b8-4732-a102-edd363f58679)
)  
(Replace with your actual circuit diagram.)

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/imvikramathithan/IOT-TEMPERATURE-CONTROLLED-FAN.git
   ```
2. Install the required libraries:
   - Open the Arduino IDE.
   - Go to **Sketch > Include Library > Manage Libraries**.
   - Search for `OneWire`, `DallasTemperature`, and `LiquidCrystal_I2C` and install them.

3. Connect the components as per the circuit diagram.

---

## Usage

1. Upload the code (`temp_fan_control.ino`) to your Arduino board using the Arduino IDE.
2. Power the system and observe the LCD display.
3. Adjust the potentiometer to set the desired temperature threshold.
4. The fan will automatically turn on/off based on the temperature readings.

---

## Code

The complete source code is in the [main.ino](main.ino) file.

---

## Future Enhancements

- Add support for multiple sensors.
- Integrate with IoT platforms for remote monitoring and control.
- Implement fan speed control using PWM.

---

## License

This project is licensed under the [MIT License](LICENSE).

---

## Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.

---

**Author**: [Vikramathithan M]  
**Email**: [imvikramathithan@gmail.com]  
**GitHub Profile**: [Your GitHub Profile](https://github.com/imvikramathithan)

---
