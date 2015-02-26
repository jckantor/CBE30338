/*
 * Wrappers to make I/O functions available with C linkage. This allows C++
 * methods to be called from C code.
 *
 * Copyright 2011-2014 The MathWorks, Inc. */

#include <inttypes.h>
#include "Arduino.h"
#include "Servo.h"


#if (defined(_RTT_TCPIP_EXTMODE) && (_RTT_TCPIP_EXTMODE == 1)) || (defined(_RTT_UDP_) && (_RTT_UDP_ != 0)) || (defined(_RTT_TCP_) && (_RTT_TCP_ != 0) || defined(_RTT_THINGSPEAK_))
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>
#endif

#if (defined(_RTT_WIFI_EXTMODE) && (_RTT_WIFI_EXTMODE == 1)) || (defined(_RTT_WIFI_UDP_) && (_RTT_WIFI_UDP_ != 0)) || (defined(_RTT_WIFI_TCP_) && (_RTT_WIFI_TCP_ != 0))
#include <WiFi.h>
#include <WiFiUdp.h>
#include <SPI.h>
#endif

//#define that helps to stringify build flags
//Double evaluation is needed so that the double quotes can be derived out
//of the build flag and can be assigned to a character array
#define RTT_StringifyBuildFlag(x) RTT_StringParamExpanded(x)
#define RTT_StringParamExpanded(x)  #x

extern "C" {
    void __cxa_pure_virtual(void);
}

extern "C" void Serial_begin(int port, long r)
{
#if (defined(_ROTH_MEGA2560_) || defined(_ROTH_DUE_) || defined(_ROTH_MEGAADK_))
    switch(port) {
        case 0:
            Serial.begin(r);
            break;
        case 1:
            Serial1.begin(r);
            break;
        case 2:
            Serial2.begin(r);
            break;
        case 3:
            Serial3.begin(r);
            break;
    }
#else
    
    #if (defined(_ROTH_LEONARDO_))
    switch(port) {
        case 0:
           Serial.begin(r);
            break;
        case 1:
           Serial1.begin(r);
            break;
    }
    #else
        Serial.begin(r);
    #endif
#endif
}

extern "C" void Serial_read(int port, int showOutStatus, uint8_t *outData, int16_t *outStatus)
{
    int libFcnOutput;
#if (defined(_ROTH_MEGA2560_) || defined(_ROTH_DUE_) || defined(_ROTH_MEGAADK_))
    switch(port) {
        case 0:
            libFcnOutput = Serial.read();
            break;
        case 1:
            libFcnOutput = Serial1.read();
            break;
        case 2:
            libFcnOutput = Serial2.read();
            break;
        case 3:
            libFcnOutput = Serial3.read();
            break;
    }
#else

#if (defined(_ROTH_LEONARDO_))
    switch(port) {
        case 0:
            libFcnOutput = Serial.read();
            break;
        case 1:
            libFcnOutput = Serial1.read();
            break;
    }
#else
            
            libFcnOutput = Serial.read();
#endif
#endif
            *outData = (uint8_t) libFcnOutput;
            *outStatus = (libFcnOutput != -1);
    }
    
    extern "C" void Serial_write(int port, uint8_t * c, size_t s)
    {
#if (defined(_ROTH_MEGA2560_) || defined(_ROTH_DUE_) || defined(_ROTH_MEGAADK_))
        switch(port) {
            case 0:
                Serial.write(c, s);
                break;
            case 1:
                Serial1.write(c, s);
                break;
            case 2:
                Serial2.write(c, s);
                break;
            case 3:
                Serial3.write(c, s);
                break;
        }
#else
#if (defined(_ROTH_LEONARDO_))
        switch(port) {
            case 0:
                Serial.write(c, s);
                break;
            case 1:
                Serial1.write(c, s);
                break;
        }
#else
        Serial.write(c, s);
#endif
#endif
    }
    
#if _RTT_NUMSERVOS_ != 0
    Servo myservos[_RTT_NUMSERVOS_];
    
    extern "C" void MW_servoAttach(uint8_t nServo, uint8_t pinNumber)
    {
        myservos[nServo].attach(pinNumber);
    }
    
    extern "C" void MW_servoWrite(uint8_t nServo, uint8_t inValue)
    {
        myservos[nServo].write(inValue);
    }
    
    extern "C" int MW_servoRead(uint8_t nServo)
    {
        return myservos[nServo].read();
    }
#endif
    
#if _RTT_UDP_ != 0
    EthernetUDP Udp[_RTT_UDP_];
    IPAddress localIpAddress(_RTT_Local_IP1, _RTT_Local_IP2, _RTT_Local_IP3, _RTT_Local_IP4);
    byte mac[] = { _RTT_Local_MAC1, _RTT_Local_MAC2, _RTT_Local_MAC3, _RTT_Local_MAC4, _RTT_Local_MAC5, _RTT_Local_MAC6 };
    unsigned int localport[_RTT_UDP_] = _RTT_UDP_LOCAL_PORT_ORDERED;
    
    extern "C" uint8_t MW_EthernetAndUDPBegin(uint8_t udpindex, uint32_t localPort)
    {
        static int only_one_ethernet_begin;
        if (only_one_ethernet_begin==0)
        {
            Ethernet.begin(mac, localIpAddress);
            only_one_ethernet_begin++;
        }
        return (Udp[udpindex].begin(localport[udpindex]));
    }
    
    extern "C" int MW_UDPFinalWrite(uint8_t udpindex, uint8_t data, uint8_t remoteIPOctect1,uint8_t remoteIPOctect2,uint8_t remoteIPOctect3,uint8_t remoteIPOctect4, uint32_t remoteport)
    {
        IPAddress remoteIpAddress(remoteIPOctect1,remoteIPOctect2, remoteIPOctect3, remoteIPOctect4);
        Udp[udpindex].beginPacket(remoteIpAddress, remoteport);
        Udp[udpindex].write(data);
        return(Udp[udpindex].endPacket());
    }
    
    extern "C" void MW_UDPFinalRead(uint8_t udpindex, uint8_t *data, int32_t *outStatus)
    {
        int packetSize = Udp[udpindex].parsePacket();
        if(packetSize)
        {
            int libFcnOutput;
            libFcnOutput = Udp[udpindex].read();
            *data = (uint8_t) libFcnOutput;
            *outStatus = (libFcnOutput != -1);
        }
        
        else
        {
            //When the client is not connected the status flag is accordingly toggled.
            *outStatus = 0;
        }
    }
#endif
    
#if defined(_RTT_THINGSPEAK_) || (_RTT_TCP_ != 0)
    IPAddress localIpAddress(_RTT_Local_IP1, _RTT_Local_IP2, _RTT_Local_IP3, _RTT_Local_IP4);
    byte mac[] = { _RTT_Local_MAC1, _RTT_Local_MAC2, _RTT_Local_MAC3, _RTT_Local_MAC4, _RTT_Local_MAC5, _RTT_Local_MAC6 };
#if _RTT_TCP_ != 0 
    EthernetServer server[_RTT_TCP_] = _RTT_TCP_SERVER_PORT_ORDERED;
#endif
    extern "C" void MW_EthernetAndTCPServerBegin(uint8_t tcpindex, uint32_t serverport)
    {
    static int only_one_tcp_server_and_ethernet_begin = 0;
    
        if (only_one_tcp_server_and_ethernet_begin==0)
        {
            Ethernet.begin(mac, localIpAddress);
            
    #if _RTT_TCP_ != 0 
            // Begin all servers based on the number of different TCP ports.
            for (int i = 0;i < _RTT_TCP_;i++)
            {
                server[i].begin();
            }
    #endif
        only_one_tcp_server_and_ethernet_begin = 1;
        }
    }
#endif
#if _RTT_TCP_ != 0
    extern "C" void MW_TCPFinalread(uint8_t tcpindex, uint8_t *data, uint32_t serverport, int32_t *outStatus)
    {
        int libFcnOutput;
        EthernetClient client = server[tcpindex].available();
        if (int(client) == true) {
            libFcnOutput = client.read();
            *data = (uint8_t) libFcnOutput;
            *outStatus = (libFcnOutput != -1);
            
        }
        else
        {
            //When the client is not connected the status flag is accordingly toggled.
            *outStatus = 0;
        }
        
    }
    extern "C" void MW_TCPFinalWrite(uint8_t tcpindex, uint8_t data, uint32_t serverport)
    {
        server[tcpindex].write(data);
    }
#endif
    
#if _RTT_WIFI_UDP_ != 0
    WiFiUDP WifiUdpObj[_RTT_WIFI_UDP_];
    IPAddress wifiLocalIpAddress(_RTT_WIFI_Local_IP1, _RTT_WIFI_Local_IP2, _RTT_WIFI_Local_IP3, _RTT_WIFI_Local_IP4);
    unsigned int wifilocalport[_RTT_WIFI_UDP_] = _RTT_WIFI_UDP_LOCAL_PORT_ORDERED;
    char ssid[] = RTT_StringifyBuildFlag(_RTT_WIFI_SSID);
    
#ifdef _RTT_WIFI_WEP
    char key[] = RTT_StringifyBuildFlag(_RTT_WIFI_KEY);
    int keyIndex = _RTT_WIFI_KEY_INDEX;
#endif
    
#ifdef _RTT_WIFI_WPA
    char wpapass[] = RTT_StringifyBuildFlag(_RTT_WIFI_WPA_PASSWORD);
#endif
    
    extern "C" uint8_t MW_WifiAndUDPBegin(uint8_t wifiudpindex, uint32_t localPort)
    {
        static int only_one_wifi_begin;
        if (only_one_wifi_begin==0)
        {
            WiFi.config(wifiLocalIpAddress);
            
#ifdef _RTT_WIFI_WEP
            WiFi.begin(ssid,keyIndex,key);
#endif
            
#ifdef _RTT_WIFI_WPA
            WiFi.begin(ssid,wpapass);
#endif
            
#ifdef _RTT_WIFI_NONE
            WiFi.begin(ssid);
#endif
            
            //Wait for 10 seconds for Wifi connection to happen
            delay(10000);
            only_one_wifi_begin++;
            
        }
        return (WifiUdpObj[wifiudpindex].begin(wifilocalport[wifiudpindex]));
        
    }
    
    extern "C" int MW_WifiUDPFinalWrite(uint8_t wifiudpindex, uint8_t data, uint8_t remoteIPOctect1,uint8_t remoteIPOctect2,uint8_t remoteIPOctect3,uint8_t remoteIPOctect4, uint32_t remoteport)
    {
        IPAddress remoteIpAddress(remoteIPOctect1,remoteIPOctect2, remoteIPOctect3, remoteIPOctect4);
        WifiUdpObj[wifiudpindex].beginPacket(remoteIpAddress, remoteport);
        WifiUdpObj[wifiudpindex].write(data);
        return(WifiUdpObj[wifiudpindex].endPacket());
    }
    
    extern "C" void MW_WifiUDPFinalRead(uint8_t wifiudpindex, uint8_t *data, int32_t *outStatus)
    {
        int packetSize = WifiUdpObj[wifiudpindex].parsePacket();
        if(packetSize)
        {
            int libFcnOutput;
            libFcnOutput = WifiUdpObj[wifiudpindex].read();
            *data = (uint8_t) libFcnOutput;
            *outStatus = (libFcnOutput != -1);
        }
        
        else
        {
            //When the client is not connected the status flag is accordingly toggled.
            *outStatus = 0;
        }
        
    }
#endif
    
#if _RTT_WIFI_TCP_ !=0
    IPAddress wifiLocalIpAddress(_RTT_WIFI_Local_IP1, _RTT_WIFI_Local_IP2, _RTT_WIFI_Local_IP3, _RTT_WIFI_Local_IP4);
    WiFiServer server[_RTT_WIFI_TCP_]  = _RTT_WIFI_TCP_SERVER_PORT_ORDERED;
    char ssid[] = RTT_StringifyBuildFlag(_RTT_WIFI_SSID);
    
#ifdef _RTT_WIFI_WEP
    char key[] = RTT_StringifyBuildFlag(_RTT_WIFI_KEY);
    int keyIndex = _RTT_WIFI_KEY_INDEX;
#endif
    
#ifdef _RTT_WIFI_WPA
    char wpapass[] = RTT_StringifyBuildFlag(_RTT_WIFI_WPA_PASSWORD);
#endif
    
    extern "C" void MW_WifiAndWifiTCPServerBegin(uint8_t wifitcpindex, uint32_t serverport)
    {
        static int only_one_wifi_tcp_server_and_wifi_begin;
        if (only_one_wifi_tcp_server_and_wifi_begin==0)
        {
            WiFi.config(wifiLocalIpAddress);
            
#ifdef _RTT_WIFI_WEP
            WiFi.begin(ssid,keyIndex,key);
#endif
            
#ifdef _RTT_WIFI_WPA
            WiFi.begin(ssid,wpapass);
#endif
            
#ifdef _RTT_WIFI_NONE
            WiFi.begin(ssid);
#endif
            
            //Wait for 10 seconds for Wifi connection to happen
            delay(10000);
            
            // Begin all servers based on the number of different TCP ports.
            for (int i = 0;i < _RTT_WIFI_TCP_;i++)
            {
                server[i].begin();
            }
            only_one_wifi_tcp_server_and_wifi_begin ++;
        }
    }
    extern "C" void MW_WifiTCPFinalread(uint8_t wifitcpindex, uint8_t *data, uint32_t serverport, int32_t *outStatus)
    {
        int libFcnOutput;
        WiFiClient client = server[wifitcpindex].available();
        if (client == true) {
            libFcnOutput = client.read();
            *data = (uint8_t) libFcnOutput;
            *outStatus = (libFcnOutput != -1);
        }
        
        else
        {
            //When the client is not connected the status flag is accordingly toggled.
            *outStatus = 0;
        }
    }
    extern "C" void MW_WifiTCPFinalWrite(uint8_t wifitcpindex, uint8_t data, uint32_t serverport)
    {
        server[wifitcpindex].write(data);
    }
#endif
    
#if defined(_ROTH_LEONARDO_)
    extern "C" void MW_usbattach()
    {
        USBDevice.attach();
    }
#endif

    extern "C" void MW_pinModeAnalogInput(uint32_t pinNumber)
    {
       #if defined(_ROTH_DUE_)
         if (pinNumber < A0)
           pinNumber += A0;
         pinMode(pinNumber, INPUT);
      #else
         pinMode(pinNumber, INPUT);
      #endif
    }
         
    