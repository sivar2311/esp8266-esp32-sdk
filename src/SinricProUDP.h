/*
 *  Copyright (c) 2019 Sinric. All rights reserved.
 *  Licensed under Creative Commons Attribution-Share Alike (CC BY-SA)
 *
 *  This file is part of the Sinric Pro (https://github.com/sinricpro/)
 */

#pragma once

#if defined ESP8266
  #include <ESP8266WiFi.h>
#endif
#if defined ESP32
  #include <WiFi.h>
#endif

#include <WiFiUdp.h>
#include "SinricProQueue.h"
#include "SinricProConfig.h"
#include "SinricProDebug.h"

#include "SinricProNamespace.h"
namespace SINRICPRO_NAMESPACE {

class UdpListener {
  public:
    void              begin(SinricProQueue_t* receiveQueue);
    void              handle();
    void              sendMessage(String &message);
    void              stop();

  private:
    WiFiUDP           _udp;
    SinricProQueue_t* receiveQueue;
};

} // SINRICPRO_NAMESPACE