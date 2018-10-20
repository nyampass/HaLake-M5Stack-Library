#include "./HaLakeM5StackLibrary.h"

void HaLakeM5StackLibrary::begin(unsigned long serial_rate){
  Serial.begin(serial_rate);
}

bool HaLakeM5StackLibrary::connectWifi(char *ssid, char *pass){
  uint8_t cnt = 0;

  WiFi.disconnect(true);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED && cnt < TRY_CONNECT_AP){
    delay(500);
    Serial.print(".");
    cnt += 1;
  }
  if(WiFi.status() != WL_CONNECTED) return false;

  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  return true;
}

void HaLakeM5StackLibrary::webserver_open(){

}