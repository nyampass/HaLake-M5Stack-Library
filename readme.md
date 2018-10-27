# HaLake-M5Stack-Library
------
## Usage
  Look example: https://github.com/nyampass/HaLake-M5Stack-Library/blob/master/examples/WebServer/WebServer.ino

## Methods
------
### begin(unsigned long serial_rate = 115200, bool spiffs = true): bool
------
  Caution!!: You should call this method before other methods on this library.
### connectWifi(char *ssid, char *pass): String
### webServer_addService(String uri, String resp, void (*callback)(String*) = nullptr)
------
  Set response & callback with path for access.
### void webServer_setNotFound(String resp);
------
  Set response for when accessed to path you were never set.(for 404)
### void webServer_open();
------
  Start server.
  If you never call it, you can't access services you were set.
### void webServer_requestHandle();
------
  Caution!!: You Should call this method in Loop if you use web-server.
br
### String SPIFFS_readFile(String path);
### bool SPIFFS_writeFile(String path, String value);
### void SPIFFS_removeFile(String path);