//////////////////
// ATTENTION!! //
////////////////

// Before you try this example, you sould wirte HTML & JS files to M5's EEPROM by Upload tool.
// Upload tool's url: https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/latest
// Usage of tool(Japanese): https://www.technoveins.co.jp/tvblog/index.php/all-contents/93-electronic-work/56-esp-wroom-02-html

#include <M5Stack.h> 
#include <HaLakeM5StackLibrary.h>

HaLakeM5StackLibrary halake;

// webserver's callback
void lighton(String *response){
 M5.update();
 if(m5.BtnA.isPressed()){
   *(response) += "\nButton A Pushed.";
 }
 digitalWrite(2, HIGH);
}

// webserver's callback
void lightoff(String *response){
 M5.update();
 if(m5.BtnA.isPressed()){
   *(response) += "\nButton A Pushed."; 
 }
 digitalWrite(2, LOW);
}

void setup() {
  String ip = "";
  
  // initialize
  halake.begin();
  M5.begin();
  M5.Lcd.clear();
  pinMode(2, OUTPUT);

  // connect to WiFi
  M5.Lcd.println("Connecting Wifi");
  ip = halake.connectWifi("SSID", "PASSWD");

  // server settings
  if(ip != ""){
    M5.Lcd.println("Connected");
    M5.Lcd.print("IP: ");
    M5.Lcd.println(ip);   

    // writing to SPIFFS
    halake.SPIFFS_writeFile("/test.html", "hogehoge");

    // set NotFound page
    halake.webServer_setNotFound("Sorry uri isn't correct");

    // add Services for web-server
    halake.webServer_addService("/on", "on", lighton);
    halake.webServer_addService("/off", "off", lightoff);
    halake.webServer_addService("/index", halake.SPIFFS_readFile("/index.html"));
    halake.webServer_addService("/index.js", halake.SPIFFS_readFile("/index.js"));
    halake.webServer_addService("/test", halake.SPIFFS_readFile("/test.html"));
    halake.webServer_open();

    M5.Lcd.println("Server opened");
  }
}

void loop() {
  // if you use webserver, mandatory.
  halake.webServer_requestHandle();
}