#ifndef HaLakeM5StackLibrary_h 
#define HaLakeM5StackLibrary_h 

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <vector>

#include "./ChainArray.h"
#include "Utils.h"

#define TRY_CONNECT_AP 50
#define WEBSERVER_SERVICE_LIMIT 128

class HaLakeM5StackLibrary{
  private:
    struct ServiceObject{
      String uri;
      String html;
      void (*callback)(String*);
    };

    void sendGetResponse(WiFiClient *client, String html, String status);

    uint8_t service_amount = 0;
    ServiceObject services[WEBSERVER_SERVICE_LIMIT];
    Utils *utils = new  Utils();

  public:
    void begin(unsigned long serial_rate = 115200);
    String connectWifi(char *ssid, char *pass);
    void webServer_addService(String uri, String resp, void (*callback)(String*) = nullptr);
    void webServer_open();
    void webServer_requestHandle();
};

#endif