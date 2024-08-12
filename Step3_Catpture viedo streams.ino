#include <WiFi.h>
#include "esp_camera.h"

// 确保SSID和密码准确无误
const char* ssid = "hot";  // 替换为你的Wi-Fi网络名称
const char* password = "12345678";  // 替换为你的Wi-Fi密码

void setup() {
    Serial.begin(115200);
    Serial.println("Starting ESP32-CAM...");

    // 确保没有遗留的连接状态
    WiFi.disconnect();

    // 连接到Wi-Fi
    Serial.println("Connecting to Wi-Fi...");
    WiFi.begin(ssid, password);

    int maxAttempts = 20;
    int attempts = 0;

    while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {
        delay(500);
        Serial.print("Attempting to connect, status: ");
        
        switch (WiFi.status()) {
            case WL_IDLE_STATUS:
                Serial.println("WL_IDLE_STATUS: Wi-Fi is idle.");
                break;
            case WL_NO_SSID_AVAIL:
                Serial.println("WL_NO_SSID_AVAIL: SSID is not available.");
                break;
            case WL_CONNECT_FAILED:
                Serial.println("WL_CONNECT_FAILED: Connection failed.");
                break;
            case WL_CONNECTION_LOST:
                Serial.println("WL_CONNECTION_LOST: Connection lost.");
                break;
            case WL_DISCONNECTED:
                Serial.println("WL_DISCONNECTED: Disconnected from Wi-Fi.");
                break;
            default:
                Serial.println("Unknown status.");
                break;
        }
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("WiFi connected.");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println("Failed to connect to Wi-Fi. Restarting ESP32-CAM.");
        delay(1000);
        ESP.restart();  // 复位ESP32-CAM
    }
}

void loop() {
    // 空循环
}
