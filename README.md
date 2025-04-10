
# Smart Irrigation System: README

## 1. Project Overview

The **Smart Irrigation System** is an automated system designed to control the irrigation of plants based on the soil moisture level. The system uses the **ESP32** microcontroller, a **DHT11/DHT22** sensor (for temperature and humidity), and a **soil moisture sensor**. The system is remotely controlled using the **Blynk App**. When the soil moisture drops below a certain threshold, the system turns on the water pump to irrigate the plants. The system is connected to Wi-Fi and can be monitored and controlled from anywhere via the Blynk app.

---

## 2. Prerequisites

Before running the Smart Irrigation System, ensure that you have the following:

### Hardware Requirements:
1. **ESP32 Development Board**
2. **DHT11 or DHT22 Sensor** (for temperature and humidity readings)
3. **Soil Moisture Sensor**
4. **Relay Module** (for controlling the water pump)
5. **Water Pump** (for irrigation)
6. **RGB LED Strip** (optional, for status indication)
7. **Jumper Wires and Breadboard**
8. **Power Supply** (for ESP32 and water pump)

### Software Requirements:
1. **Visual Studio Code (VS Code)** with the **PlatformIO** extension (for programming the ESP32)
2. **Blynk App** (for remote control of the irrigation system)
3. **Libraries**:
   - `Blynk`
   - `DHT sensor library`
   - `FastLED` (for the RGB LED)
   - `WiFi` (for ESP32 Wi-Fi connectivity)
   - `ESP32 Board Library` (for programming the ESP32)

---

## 3. Installation Instructions

### 3.1 Install VS Code and PlatformIO

1. Download and install **[Visual Studio Code (VS Code)](https://code.visualstudio.com/)**.
2. Install the **PlatformIO IDE** extension from the VS Code marketplace.

### 3.2 Install Blynk Library

1. Open **VS Code**.
2. Open your **PlatformIO** project folder.
3. In the **platformio.ini** file, add the following dependency for the Blynk library:

```ini
lib_deps = Blynk
```

### 3.3 Install Other Libraries

In **platformio.ini**, also add the following dependencies:

```ini
lib_deps = 
    Blynk
    DHT sensor library
    FastLED
```

PlatformIO will automatically install these libraries for your project.

---

## 4. Project Setup

### 4.1 Hardware Connections

1. **DHT11/DHT22 Sensor:**
   - Connect the **VCC** pin to **3.3V** on the ESP32.
   - Connect the **GND** pin to **GND** on the ESP32.
   - Connect the **Data** pin to a digital I/O pin (e.g., **D2**) on the ESP32.

2. **Soil Moisture Sensor:**
   - Connect the **VCC** pin to **3.3V** on the ESP32.
   - Connect the **GND** pin to **GND** on the ESP32.
   - Connect the **Analog Out** pin to an analog input pin (e.g., **A0**) on the ESP32.

3. **Relay Module:**
   - Connect the **VCC** pin to **5V** on the ESP32 (if required, depending on your relay).
   - Connect the **GND** pin to **GND** on the ESP32.
   - Connect the **IN** pin to a digital I/O pin (e.g., **D5**) on the ESP32 to control the relay.

4. **Water Pump:**
   - Connect the **water pump** to the relay, which will control the on/off status of the pump based on moisture levels.

5. **RGB LED Strip (Optional):**
   - Connect the **RGB LED strip** to one of the PWM-capable pins on the ESP32 (e.g., **D9**) if you want visual feedback.

---

### 4.2 Blynk Setup

1. **Create a Blynk Project:**
   - Open the Blynk app on your phone and create a new project.
   - Select **ESP32** as the device and choose the **Wi-Fi** connection type.
   - Once the project is created, you will receive a **Blynk Authentication Token** (This will be used in the code).

2. **Configure the App:**
   - Add necessary widgets to control and monitor the system:
     - **Value Display** for soil moisture, temperature, and humidity.
     - **Button** to manually control the water pump (optional).

3. **Get the Template ID and Auth Token** from the Blynk project and replace the placeholders in your code with the actual values.

---

## 5. Code Setup

1. Clone or download the project repository from GitHub.
2. Open the `smart_irrigation.ino` file in **VS Code** with the **PlatformIO** extension enabled.
3. In the code, replace the following placeholders with your **Blynk Auth Token**, **Template ID**, and **Template Name**:
   ```cpp
   #define BLYNK_TEMPLATE_ID    "YourTemplateID"
   #define BLYNK_TEMPLATE_NAME  "SmartIrrigationSystem"
   #define BLYNK_AUTH_TOKEN     "YourAuthToken"
   ```

4. Select the correct **ESP32 board** and **port** in **VS Code** (under **PlatformIO** settings).
5. Upload the code to the ESP32 by clicking on the **Upload** button in PlatformIO.

---

## 6. Running the Project

1. After uploading the code to the ESP32, open the **Blynk app** on your phone.
2. Tap **Play** in the Blynk app to start interacting with the Smart Irrigation System.
3. Monitor real-time data such as soil moisture, temperature, and humidity.
4. The system will automatically water the plants based on the soil moisture level.

---

## 7. Troubleshooting

- **No Wi-Fi Connection:** Ensure the ESP32 is within range of your Wi-Fi network, and check your Wi-Fi credentials.
- **Incorrect Data from Sensors:** Verify the wiring and ensure the correct libraries are used for the sensors.
- **Relay Not Working:** Double-check the relay wiring and ensure the relay is rated for the water pump you are using.

---

## 8. Future Enhancements

- Integration with **weather APIs** to predict future irrigation requirements.
- Logging of sensor data for analysis and optimization of irrigation schedules.
- Remote notifications (e.g., via email or Blynk push notifications) when irrigation occurs.

---

## 9. Conclusion

The Smart Irrigation System helps automate the process of watering plants based on real-time soil moisture readings. With the integration of the **ESP32** and **Blynk app**, this system can be controlled and monitored remotely, making irrigation more efficient and ensuring plants are properly cared for.

```

