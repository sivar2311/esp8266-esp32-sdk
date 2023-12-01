/*
 *  Copyright (c) 2019 Sinric. All rights reserved.
 *  Licensed under Creative Commons Attribution-Share Alike (CC BY-SA)
 *
 *  This file is part of the Sinric Pro (https://github.com/sinricpro/)
 */

#pragma once

#if defined(ESP8266)
    #include <ESP8266WiFi.h>
#elif defined(ESP32) || defined(ARDUINO_ARCH_RP2040)
    #include <WiFi.h>
#endif

#include <ArduinoJson.h>
#include <WebSocketsClient.h>

#include "SinricProConfig.h"
#include "SinricProDebug.h"
#include "SinricProInterface.h"
#include "SinricProNamespace.h"
#include "SinricProQueue.h"
namespace SINRICPRO_NAMESPACE {

enum class ConnectionState;

#if !defined(WEBSOCKETS_VERSION_INT) || (WEBSOCKETS_VERSION_INT < 2003005)
#error "Wrong WebSockets Version! Minimum Version is 2.3.5!!!"
#endif

using wsConnectedCallback    = std::function<void(void)>;
using wsDisconnectedCallback = std::function<void(void)>;
using wsPongCallback         = std::function<void(uint32_t)>;

class WebsocketListener : protected WebSocketsClient {
  public:
    WebsocketListener();
    ~WebsocketListener();

    void begin(String server, String appKey, String deviceIds, SinricProQueue_t* receiveQueue);
    void handle();
    void stop();
    void setRestoreDeviceStates(bool flag);

    void sendMessage(String& message);

    void onConnected(wsConnectedCallback callback);
    void onDisconnected(wsDisconnectedCallback callback);
    void onPong(wsPongCallback callback);
    
    using WebSocketsClient::disconnect;
    using WebSocketsClient::isConnected;

  protected:
    bool _begin;
    bool restoreDeviceStates;
    ConnectionState connectionState;

    wsConnectedCallback    _wsConnectedCb;
    wsDisconnectedCallback _wsDisconnectedCb;
    wsPongCallback         _wsPongCb;

    virtual void runCbEvent(WStype_t type, uint8_t* payload, size_t length) override;

    void              setExtraHeaders();
    SinricProQueue_t* receiveQueue;
    String            deviceIds;
    String            appKey;
};

}  // namespace SINRICPRO_NAMESPACE