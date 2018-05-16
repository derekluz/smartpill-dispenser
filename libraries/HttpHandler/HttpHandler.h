/*
  HttpHandler.h
  Library for handling HTTP requests of the Smartpill Dispenser
  Created by Derek Luz, May 7, 2018.
  Released into the public domain.
*/
#ifndef HttpHandler_h
#define HttpHandler_h

class HttpHandler {
  private:
    // SSID of the Wi-Fi network
    static char *ssid;

    // Password of the Wi-Fi network
    static char *password;

    // User Id to send and retrieve specific data of the user from the API
    static char *userId;

    // Url of the API
    static char *smartpillApiUrl;

  public:
    // Configures the Wi-Fi connection
    static void wifiSetup();
    
    // GET method that returns array with number of pills to be taken in the 
    // current minute for each container
    static int* getPillsForCurrentMinute();

    // POST method that sends an alert when the medicine was not withdrawn
    // from the container after a given period of time
    static void sendAlert();
};

#endif