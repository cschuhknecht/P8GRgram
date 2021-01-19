# P8GRgram
Code for ESP8266 to send a Notification via Telegram when an alarm goes off.

## About P8GRgram

This Project is useful if you own an Airbus P8GR or another Pager that has a USB Port that's powered if it receives an alarm and you don't get an official notification on your mobile phone.

The Project uses an ESP8266 (if you don't know what that is, you could call it a Wi-Fi-Chip) and the messenger app Telegram to send this Notification to your phone manually.

Telegram is a good choice because it has an open API that can be easily accessed and because there are bots in Telegram. When an alarm comes in, the ESP is powered and the program flashed to it runs once. The program accesses our bot and it can then post a message to a private chat, group or channel.

## Dependencies / how to flash
Obvious dependency number one: 1x ESP8266 (I used a WeMos D1 mini)

Obvious dependency number two: 1x Pager meeting the requirements

### Board Manager
In order to flash the code on your ESP you also need the Arduino IDE. You need to install the ESP8266 Board Manager. To do this, go to *File/Preferences* in the IDE and paste the following URL into the board manager URL line. http://arduino.esp8266.com/stable/package_esp8266com_index.json Then go to *Tools/Board: ...* and at the top on *Board Manager...* Search for esp8266 by ESP8266 Community and install the newest version.  The last step is to select the board under *Tools/Board*. For example *LOLIN(WEMOS) D1 R2 & mini* if you use a WeMos D1 mini. If you have problems with the code. Try to use esp8266 in Version 2.7.4.

### Libraries
You also need to install two libraries that are used.
- ArduinoJson by Benoit Blanchon (tested with version 6.17.2)
- CTBot by Steffano Ledda (tested with version 2.1.3) https://github.com/shurillu/CTBot

Here is how to install them. Go to *Tools/Manage Libraries...* and search for the Libraries. Then click install.

### Flash it
If you selected your board like mentioned above then all there's left is to choose the USB Port the ESP is connected to. You can do that by Tools/Port. Then flash it via the arrow button at the top. Done.


## Future Content
- Create a Telegram Bot
- Create a Telegram Channel
- Create a Telegram Group
- Short explanation of ESP8266
- ...

There are a lot of descriptions on how to do the above, but my own descriptions will come soon. If you need help with the IDs have a look at https://github.com/GabrielRF/telegram-id
