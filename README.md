# P8GRgram
Code for ESP8266 to send a Notification via Telegram when powered.

It uses the CTBot Library you can find here: https://github.com/shurillu/CTBot

A Wifi connection is established, then the connection to Telegram is checked until its established.
The next step is to send a custom Message to a custom chat ID.
After that it runs in an empty Loop until its disconnected from the power supply. So the Code runs only ones.
