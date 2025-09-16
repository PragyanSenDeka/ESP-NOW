/*Transmitter side code for data transmission using esp now
sends dht 11 data to a receiver esp
*/


// Include required libraries
#include <WiFi.h>
#include <esp_now.h>
#include <DHT.h>

// Define DHT11 parameters
#define DHTPin 4
#define DHTType DHT11

// Create DHT Object
DHT dht(DHTPin, DHTType);

// Variables for temperature and humidity
float temp;
float humid;

// Integer for identification (make unique for each transmitter)
int ident = 3;   //2-b     3-a

// Responder MAC Address (Replace with your responders MAC Address)
uint8_t broadcastAddress[] = {0x7C, 0x2C, 0x67, 0x55, 0xDA, 0x00};

// Define data structure
typedef struct struct_message {
  float a;
  float b;
  int c;
} struct_message;

// Create structured data object
struct_message myData;

// Register peer
esp_now_peer_info_t peerInfo;

// Sent data callback function

void OnDataSent(const wifi_tx_info_t *mac_addr, esp_now_send_status_t status)
{
  Serial.print("Last Packet Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void setup() {
  // Setup Serial monitor
  Serial.begin(115200);
  delay(100);

  // Initiate DHT11
  dht.begin();

  // Set ESP32 WiFi mode to Station temporarily
  WiFi.mode(WIFI_STA);

  // Print MAC address for reference
  Serial.print("Transmitter MAC Address: ");
  Serial.println(WiFi.macAddress());

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Define callback
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("ESP-NOW DHT11 Transmitter Ready");
  Serial.print("Transmitter ID: ");
  Serial.println(ident);
}

void loop() {
  // Read DHT11 module values
  temp = dht.readTemperature();
  delay(10);
  humid = dht.readHumidity();
  delay(10);

  // Check if readings are valid
  if (isnan(temp) || isnan(humid)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Humid: ");
  Serial.print(humid);
  Serial.println("%");

  // Add to structured data object
  myData.a = temp;
  myData.b = humid;
  myData.c = ident;

  // Send data
  esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &myData, sizeof(myData));
  
  // Check send result
  if (result == ESP_OK) {
    Serial.println("Data sent successfully");
  } else {
    Serial.print("Error sending data: ");
    Serial.println(result);
  }

  Serial.println("---");

  // Delay for DHT11 sensor
  delay(2000);
}