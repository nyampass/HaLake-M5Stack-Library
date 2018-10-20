#ifndef HaLakeM5StackLibrary_h 
#define HaLakeM5StackLibrary_h 

#include <Arduino.h>
#include <HTTPClient.h>

#define TRY_CONNECT_AP 50

class HaLakeM5StackLibrary{
  public:
    void begin(unsigned long serial_rate = 115200);
    bool connectWifi(char *ssid, char *pass);
    void webserver_open();
};

#endif