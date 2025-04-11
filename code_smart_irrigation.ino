
#define BLYNK_AUTH_TOKEN "j-PNWSyHRwMDFRXCLOQmjZ3tVUlJ7a8A"  // Your Blynk Auth Token
#define BLYNK_TEMPLATE_ID "TMPL3yXgFsrqq"  // Add your Blynk Template ID
#define BLYNK_TEMPLATE_NAME "Smart Irrigation System"  // Your Blynk Template Name

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Replace with your network credentials
char ssid[] = "vivo 1938";
char pass[] = "lucky965";

// Define DHT11 sensor pin and type
#define DHTPIN 2               // DHT11 connected to GPIO2 (D4)
#define DHTTYPE DHT11          // Define DHT type as DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define Soil Moisture pin
#define SOIL_MOISTURE_PIN A0   // Soil Moisture Sensor on A0
#define RELAY_PIN 5            // Relay connected to GPIO5 (D1)

BlynkTimer timer;  // Blynk timer for sensor updates

// Function to read sensor data and send to Blynk
void sendSensorData() {
  // Read temperature and humidity from DHT11 sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  // Read soil moisture value from the analog pin A0
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // If DHT11 fails, display error
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Send temperature and humidity data to Blynk (Virtual Pin V1 and V2)
  Blynk.virtualWrite(V1, temperature);  // V1 for temperature
  Blynk.virtualWrite(V2, humidity);     // V2 for humidity

  // Send soil moisture value to Blynk (Virtual Pin V3)
  Blynk.virtualWrite(V3, soilMoistureValue);  // V3 for soil moisture

  // Control relay based on soil moisture level (automatically)
  if (soilMoistureValue > 400) {  // If soil is dry
    digitalWrite(RELAY_PIN, LOW);  // Turn pump ON
    Serial.println("Pump ON - Soil Dry");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn pump OFF
    Serial.println("Pump OFF - Soil Wet");
  }

  // Debugging output on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print("°C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Soil Moisture: ");
  Serial.println(soilMoistureValue);
}

// Manual control of the pump using the Blynk button
BLYNK_WRITE(V4) {
  int pumpState = param.asInt();  // Read button value (0 or 1)
  if (pumpState == 1) {
    digitalWrite(RELAY_PIN, LOW);  // Turn pump ON
    Serial.println("Pump ON - Button Pressed");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Turn pump OFF
    Serial.println("Pump OFF - Button Released");
  }
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize DHT sensor
  dht.begin();

  // Set Relay pin as output and keep it OFF initially
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relay is active LOW

  // Connect to WiFi and Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Setup a timer to send sensor data to Blynk every 2 seconds
  timer.setInterval(2000L, sendSensorData);
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run the timer
}




