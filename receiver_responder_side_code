/*
  ESP-NOW Remote Sensor - Receiver with LCD Display
  Receives Temperature & Humidity data from other ESP32 via ESP-NOW
  Displays data of dht 11 on 16x2 LCD
*/

// Include required libraries
#include <WiFi.h>
#include <esp_now.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define data structure (must match transmitter)
typedef struct struct_message {
    float a;  // Temperature
    float b;  // Humidity
    int c;    // Transmitter ID
} struct_message;

// Create structured data object
struct_message myData;

// Format MAC address for display
void formatMacAddress(const uint8_t *macAddr, char *buffer, int maxLength) {
  snprintf(buffer, maxLength, "%02x:%02x:%02x:%02x:%02x:%02x", 
           macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);
}

// Callback function - runs when data is received
void OnDataRecv(const esp_now_recv_info_t *recv_info, const uint8_t *incomingData, int len) 
{
  // Get incoming data
  memcpy(&myData, incomingData, sizeof(myData));
  
  // Format sender MAC address
  char macStr[18];
  formatMacAddress(recv_info->src_addr, macStr, 18);
  
  // Print received data to Serial Monitor
  Serial.print("Data received from: ");
  Serial.println(macStr);
  Serial.print("Sensor ID: ");
  Serial.println(myData.c);
  Serial.print("Temperature: ");
  Serial.print(myData.a);
  Serial.println("°C");
  Serial.print("Humidity: ");
  Serial.print(myData.b);
  Serial.println("%");
  Serial.println("---");

  // Display data on LCD
  lcd.clear();
  
  // Line 1: Temperature with sensor ID
  lcd.setCursor(0, 0);
  lcd.print("S");
  lcd.print(myData.c);
  lcd.print(" T:");
  lcd.print(myData.a, 1);  // Show 1 decimal place
  lcd.print("C");
  
  // Line 2: Humidity with sensor ID
  lcd.setCursor(0, 1);
  lcd.print("S");
  lcd.print(myData.c);
  lcd.print(" H:");
  lcd.print(myData.b, 1);  // Show 1 decimal place
  lcd.print("%");
}
 
void setup() {
  // Set up Serial Monitor
  Serial.begin(115200);
  delay(1000);

  Serial.println("ESP-NOW DHT22 Receiver Starting...");

  // Initialize I2C and LCD
  Wire.begin(4,5);  // 4 is SDA 5 is SCL pin
  lcd.init();
  lcd.backlight();
  
  // Display startup message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ESP-NOW Receiver");
  lcd.setCursor(0, 1);
  lcd.print("Waiting for data");

  // Start ESP32 in Station mode
  WiFi.mode(WIFI_STA);

  // Print receiver MAC address
  Serial.print("Receiver MAC Address: ");
  Serial.println(WiFi.macAddress());

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ESP-NOW Error!");
    return;
  }

  Serial.println("ESP-NOW initialized successfully");
   
  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);

  Serial.println("Receiver ready - waiting for data...");
  Serial.println("===================================");
}

void loop() {
  // Nothing to do here - everything is handled by the callback
  // The LCD will update automatically when data is received
}
