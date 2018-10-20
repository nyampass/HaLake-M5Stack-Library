#include "./HaLakeM5StackLibrary.h"

WiFiServer Server(80);

void HaLakeM5StackLibrary::begin(unsigned long serial_rate){
  Serial.begin(serial_rate);
}

String HaLakeM5StackLibrary::connectWifi(char *ssid, char *pass){
  uint8_t cnt = 0;

  WiFi.disconnect(true);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED && cnt < TRY_CONNECT_AP){
    delay(500);
    Serial.print(".");
    cnt += 1;
  }
  if(WiFi.status() != WL_CONNECTED) return "";

  Serial.println("\nWiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  return WiFi.localIP().toString(); 
}

void HaLakeM5StackLibrary::webServer_addService(String uri, String resp, void (*callback)(String*)){  
  ServiceObject newService = {uri, resp, callback};
  services[service_amount] = newService;
  service_amount += 1;
}

void HaLakeM5StackLibrary::webServer_open(){
  Server.begin();
}

void HaLakeM5StackLibrary::webServer_requestHandle(){
  uint8_t serverPos = 0;
  String line = "";
  String path = "";
  String response = "";
  ChainArray request;
  ChainArray queries;
  WiFiClient client;
  std::vector<String> keys;
  client = Server.available();

  if(client){
    if(client.connected()){
      delay(100);
      Serial.println("New Client");
      while(client.available()){
        line = client.readStringUntil('\r');
        path = "";

        if(line.indexOf("GET") >= 0){
          request = utils->analyzeGetRequest(line);
          path = request.get("path");
          queries = utils->analyzeQuery(request.get("params"));
          keys = queries.keys();

          Serial.print("Path: ");
          Serial.println(path);

          for(int i = 0; i < service_amount; i++){
            if(path == services[i].uri){
              response = services[i].html;
              services[i].callback(&response);
              sendGetResponse(&client, response, "200");
              break;
            }
            if(i >= service_amount - 1) sendGetResponse(&client, "404", "404");
          }
          request.clear();
          queries.clear();
        }
      }
    }
  }
}

void HaLakeM5StackLibrary::sendGetResponse(WiFiClient *client, String html, String status){
    String contentLength = String(html.length());
    String statusResp = "HTTP/1.1 " + status + " OK";
    String contentLengthResp = "Content-Length: " + contentLength;
    String connectionResp = "Connection: close";
    String contentTypeResp = "Content-Type: text/html";
    String newLine = "\r\n";

    client->print(statusResp + newLine + contentLengthResp + newLine + connectionResp + newLine +contentTypeResp + newLine + newLine + html);
    client->stop();
  }