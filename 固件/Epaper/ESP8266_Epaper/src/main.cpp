/* Includes ------------------------------------------------------------------*/
#include <stdlib.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "mytime.h"

const char* ssid     = "Xiaomi_48A5";
const char* password = "15661851803";

static int Second = 0;

// 连接WiFi
void connectWiFi(){
  WiFi.begin(ssid, password);                  // 启动网络连接
  while (WiFi.status() != WL_CONNECTED) {      // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。 
    delay(1000);                               // 如果WiFi连接成功则返回值为WL_CONNECTED                       
    Serial.print('.');
  }
}

void setup()
{
  Serial.begin(115200);          
  Serial.println("");
  connectWiFi();
  Time_init();
  time_handler();
}

/* The main loop -------------------------------------------------------------*/
void loop()
{
  static long last_time = millis();
  if(millis() - last_time > (60-Second)*1000)
  {
    last_time = millis();
    Second = time_handler();
  }
}