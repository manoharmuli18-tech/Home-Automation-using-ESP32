# ESP32 Home Automation Using Mobile Control

## Project Overview:-

- This project demonstrates a Wi-Fi-based Home Automation System using an ESP32 microcontroller. The system allows users to control household appliances such as lights, fans, and other electrical devices directly from a mobile phone over Wi-Fi.

- The ESP32 acts as a web server, providing a simple control interface accessible through any smartphone browser. Relay modules are used to switch appliances safely.

---

## Features:-

- Control home appliances (bulb,fan,AC...etc) using a mobile phone
- Wi-Fi connectivity through ESP32✅💯
- Web-based control interface
- Supports multiple appliances
- Real-time ON/OFF switching
- Low-cost
- easy to build
- Expandable for IoT applications

## Components Required:-

- ESP32 Development Board (or ESP32 cam module)
- Wi-Fi Network(ESP,darkking--password)
- Mobile Phone
- Power Supply (6V)
- Connecting Wires
- Electrical Loads (Bulbs, Fans, etc.)

## Hardware connection:-
- connect GPIO-13 to LED-1 long leg
- connect GPIO-12 to LED-2 long leg
- connect GPIO-14 to LED-3 long leg
- connect GPIO-15 to LED-4 long leg
- connect all short leds of LED,ESP32 GPIO-0,TTl adaptor GND to ESP32 GND pin (for sharing same ground)
- connect ESP32-RX pin to TTl adaptor-TX pin
- connect ESP32-TX pin to TTl adaptor-RX pin
- connect ESP32-5V pin to TTl adaptor-5V pin
- connect TTL adaptor to PC
  
## Installation:-

- Open the project in Arduino IDE.
- Install Thimcker-AI ESP32 CAM  board support.
- Uploard speed is 115,200
- select port as COM-7
- Connect ESp32 to PC via USB cable (or)TTL adaptor
- compile and Upload code to ESP32
- Power the ESP32 and connect your mobile phone to the same Wi-Fi network.
- Open the ESP32 IP address in a browser and control the appliances.


## Working:-

- when ESP32 connect to wifi ,then it generate IP address like(it is mine---->192.168.137.89)
- when the ip address enter into browser on pc or mobile---> which it connect to same wifi as ESP32 connected
- then you can see the user interface.

## Testing:-

- check is it Front code is ok or not
- check is it button's appliance(bulb,fan) are on/off in time or not
- check for modifications

## My Experience:-
- Detailed explanation and my rectified mistakes:-
- https://homeautomationesp32.blogspot.com/2026/06/home-automation-using-esp32.html

## Licence:-

This project is licenced under the MIT License.
- see the [LICENSE](LICENSE) file.

---

## About the Developer:-

- **Name:** Venkata Manohar Reddy M
- **Email:** manoharmuli18@gmail.com
- **GitHub:** https://github.com/manoharmuli18-tech
- **LinkedIn:** https://www.linkedin.com/in/muli-manohar-57134a408
- **Portfolio:** https://manoharmuli18-tech.github.io/portifolio/
- **status:-** open to collaboration & freelance automation gigs!

---
---
## Acknowlegments:-
Thanks to the maker community and open source projects for inspiration.
