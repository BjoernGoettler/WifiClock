# WifiClock
A small prototype that queries an NTP server, and displays the time as a SSID
![Top notch representation of what it looks like, on an iPhone](images/wifi.jpeg)

## What is this

It's an esp8266 that connects to wifi, queries a NTP server and goes into AP mode with a SSID saying what time it is. There is no loop, everything is done in the setup() function. After a 60 second power nap, the module resets and starts over

## What I wish I had done, or at least investigated

- I find it less than ideal that the module sleeps and then resets. NTP returns the time, so there is information on when the minut turns next time, and that could have been utilized somehow
- For now the offset between UTC and danish time, is hardcoded to 7200...and one would have to recompile when summertime is over with. It could have been nice with something that queries if it's summertime or not. Maybe even some sassy geolocation, that tells you your current offset from UTC...if possible

## What I used

### Hardware
- [Wemos D1 Mini lite](https://docs.wemos.cc/en/latest/d1/d1_mini_lite.html)

### Software
- [PlatformIO](https://platformio.org/)
- [Visual Studio Code](https://code.visualstudio.com/)

## How to:

Clone this repo, open main.cpp in VSCode (or whatever), configure your Wifi-credentials and upload to your esp8266
