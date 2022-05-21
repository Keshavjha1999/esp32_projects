#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H

#include "esp_netif.h"

// Wifi application settings
#define WIFI_AP_SSID                "ESP32_AP"          // Access Point Name
#define WIFI_AP_PASSWORD            "password"          // Access Point Password
#define WIFI_AP_CHANNEL             1                   // Access Point Channel
#define WIFI_AP_SSID_HIDDEN         0                   // Access Point Visibility
#define WIFI_AP_MAX_CONNECTIONS     5                   // Access Point Max Number of Clients
#define WIFI_AP_BEACON_INTERVAL     100                 // Access Point beacon: 100 milliseconds recommended
#define WIFI_AP_IP                  "192.168.0.1"       // Access Point default IP
#define WIFI_AP_GATEWAY             "192.168.0.1"       // Access Point default gateway (should be the same as IP  Address)
#define WIFI_AP_NETMASK             "255.255.255.0"     // Access Point Netmask
#define WIFI_AP_BANDWIDTH           WIFI_BW_HT20        // Access Point Bandwidth 20MHz (40MHz is the other option)
#define WIFI_STA_POWER_SAVE         WIFI_PS_NONE        // Power save not used
#define MAX_SSID_LENGTH             32                  // IEEE standard maximum
#define MAX_PASSWORD_LENGTH         64                  // IEEE standard maximum
#define MAX_CONNECTION_RETRIES      5                   // Retry number on disconnect


// netif object for the station and Access Point
extern esp_netif_t* esp_netif_sta;
extern esp_netif_t* esp_netif_ap;


/** 
 * Message IDs for the WIFI application task
 * @note Expand this based on your application requirements
 * 
 */
typedef enum wifi_app_message {
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_app_message_e;

/**
 * @brief
 * Structure from the message queue
 * @note Expand this based on your application requirements e.g. add another type and parameter as required 
 */

typedef struct wifi_app_queue_message {
    wifi_app_message_e msgID;

} wifi_app_queue_message_t;

/**
 * @brief
 * Sends a message to the queue
 * @param msgID message ID from the wifi_app_message_e enum.
 * @return pdTrue if an item successfully sent to the queue else pdFALSE
 * @note Expand the parameter based on your requirements e.g. how you've expanded the wifi_app_queue_message_t. 
 */

BaseType_t wifi_app_send_message(wifi_app_message_e msgID);

/**
 * @brief 
 * Starts the WiFi RTOS task
 */

void wifi_app_start(void);


#endif /* MAIN_WIFI_APP_H_ */
