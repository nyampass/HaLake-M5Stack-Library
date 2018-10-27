# HaLake-M5Stack-Library
## Usage
  Look example: https://github.com/nyampass/HaLake-M5Stack-Library/blob/master/examples/WebServer/WebServer.ino

## Methods
### begin(unsigned long serial_rate = 115200, bool spiffs = true): bool
  * Caution!!: You should call this method before other methods on this library.
### connectWifi(char *ssid, char *pass): String
### webServer_addService(String uri, String resp, void (*callback)(String*) = nullptr): void
  * Set response & callback with path for access.
### webServer_setNotFound(String resp): void
  * Set response for when accessed to path you were never set.(for 404)
### webServer_open(): void
  * To start server.
  * If you never call it, you can't access services you were set.
### webServer_requestHandle(): void
  * Caution!!: You Should call this method in Loop if you use web-server.
### SPIFFS_readFile(String path): String
### SPIFFS_writeFile(String path, String value): bool
### SPIFFS_removeFile(String path): void