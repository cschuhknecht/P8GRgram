// ArduinoJson Version 6.17.2
// ESP8266 core for Arduino Version 2.7.4
#include "CTBot.h" // a Telegram Bot Library Version 2.1.3
// #include "Utilities.h" // for int64ToAscii() helper function
                          // only needed for serials including the chat id

String ssid  = "mySSID"; // REPLACE mySSID WITH YOUR WIFI SSID
String pass  = "myPassword"; // REPLACE myPassword YOUR WIFI PASSWORD, IF ANY
String token = "myToken"; // REPLACE myToken WITH YOUR TELEGRAM BOT TOKEN
int64_t chat_id = myId; // REPLACE myId WITH YOUR TELEGRAM CHAT ID


int test_break = 40; // How often you want to try to connect to telegram
                     // Usually it takes 0 to 10 tries

String text = "myText"; // REPLACE myText WITH YOUR MESSAGE TEXT

CTBot myBot; // create a Bot object to work with



void setup() {
  // initialize the Serial
  Serial.begin(115200);
  Serial.println("Starting TelegramBot...");

  // connect the ESP8266 to the desired access point
  myBot.wifiConnect(ssid, pass);

  // set the telegram bot token
  myBot.setTelegramToken(token);

  int test_count = 0;
  while (test_count != test_break){ // tests the connection up to [value of test_break] times
    
    if (myBot.testConnection()){
      Serial.println("\ntestConnection OK");
  
      TBMessage msg; // if connection is ok a Message Object is created
      msg.group.id = chat_id; // hand the id
      //Serial.println(int64ToAscii(msg.group.id));
      msg.text = text; // and the text you set
      myBot.sendMessage(msg.group.id, msg.text); // send the message
  
      test_count = test_break; // break the while loop
    }
      
    else{ // if connection is nok, while will run until it is true or till its end 
      Serial.println("\ntestConnection NOK");
      test_count += 1; 
      Serial.println(test_count);
      delay(500);
    }
  }
}

void loop() {} // empty loop for a functional prog
