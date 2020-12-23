// ArduinoJson Version 6.17.2
// ESP8266 core for Arduino Version 2.7.4
#include "CTBot.h" // Version 2.1.3
#include "Utilities.h" // for int64ToAscii() helper function

String ssid  = "mySSID"; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "myPassword"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "myToken"; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
int64_t chat_id = myID; // REPLACE myId WITH YOUR TELEGRAM CHAT ID



String text = "myText"; // REPLACE myText WITH YOUR MESSAGE TEXT

CTBot myBot;



void setup() {
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);


  if (myBot.testConnection()){
    Serial.println("\ntestConnection OK");
  }
      
  else{
    Serial.println("\ntestConnection NOK");  
  }
}


void loop() {
  
  TBMessage msg;
  msg.group.id = chat_id;
  Serial.println(int64ToAscii(msg.group.id));
  msg.text = text;
  myBot.sendMessage(msg.group.id, msg.text);
  delay(5000);
}
