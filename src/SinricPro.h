/*
 *  Copyright (c) 2019 Sinric. All rights reserved.
 *  Licensed under Creative Commons Attribution-Share Alike (CC BY-SA)
 *
 *  This file is part of the Sinric Pro (https://github.com/sinricpro/)
 */

#pragma once

#include "SinricProDeviceInterface.h"
#include "SinricProInterface.h"
#include "SinricProMessageid.h"
#include "SinricProNamespace.h"
#include "SinricProQueue.h"
#include "SinricProSignature.h"
#include "SinricProStrings.h"
#include "SinricProUDP.h"
#include "SinricProWebsocket.h"
#include "Timestamp.h"
namespace SINRICPRO_NAMESPACE {

/**
 * @brief Callback definition for onConnected function
 *
 * Gets called when device is connected to SinricPro server
 * @param void
 * @return void
 */
using ConnectedCallbackHandler = std::function<void(void)>;

/**
 * @brief Callback definition for onDisconnected function
 *
 * Gets called when device is disconnected from SinricPro server
 * @param void
 * @return void
 */
using DisconnectedCallbackHandler = std::function<void(void)>;

using PongCallback = std::function<void(uint32_t)>;

/**
 * @class SinricProClass
 * @ingroup SinricPro
 * @brief The main class of this library, handling communication between SinricPro Server and your devices
 **/
class SinricProClass : public SinricProInterface {
    friend class SinricProDevice;

  public:
    class Proxy;

  public:
    void          begin(String appKey, String appSecret, String serverURL = SINRICPRO_SERVER_URL);
    void          handle();
    void          stop();
    bool          isConnected();
    void          onConnected(ConnectedCallbackHandler cb);
    void          onDisconnected(DisconnectedCallbackHandler cb);
    void          onPong(PongCallback cb);
    void          restoreDeviceStates(bool flag);
    void          setResponseMessage(String&& message);
    unsigned long getTimestamp() override;
    Proxy         operator[](const String deviceId);

  protected:
    template <typename DeviceType>
    DeviceType& add(String deviceId);

    void add(SinricProDeviceInterface& newDevice);
    void add(SinricProDeviceInterface* newDevice);

    DynamicJsonDocument prepareResponse(JsonDocument& requestMessage);
    DynamicJsonDocument prepareEvent(String deviceId, const char* action, const char* cause) override;
    void                sendMessage(JsonDocument& jsonMessage) override;

  private:
    void handleReceiveQueue();
    void handleSendQueue();

    void handleRequest(DynamicJsonDocument& requestMessage, interface_t Interface);
    void handleResponse(DynamicJsonDocument& responseMessage);

    DynamicJsonDocument prepareRequest(String deviceId, const char* action);

    void connect();
    void disconnect();
    void reconnect();

    void onConnect();
    void onDisconnect();

    void extractTimestamp(JsonDocument& message);

    SinricProDeviceInterface* getDevice(String deviceId);

    template <typename DeviceType>
    DeviceType& getDeviceInstance(String deviceId);

    std::vector<SinricProDeviceInterface*> devices;

    String appKey;
    String appSecret;
    String serverURL;

    WebsocketListener _websocketListener;
    UdpListener       _udpListener;
    SinricProQueue_t  receiveQueue;
    SinricProQueue_t  sendQueue;

    Timestamp timestamp;

    bool   _begin             = false;
    String responseMessageStr = "";
};

class SinricProClass::Proxy {
  public:
    Proxy(SinricProClass* ptr, const String& deviceId);

    template <typename DeviceType>
    operator DeviceType&();

  protected:
    SinricProClass* ptr;
    String          deviceId;
};

template <typename DeviceType>
SinricProClass::Proxy::operator DeviceType&() {
    return ptr->getDeviceInstance<DeviceType>(deviceId);
}

template <typename DeviceType>
DeviceType& SinricProClass::getDeviceInstance(String deviceId) {
    DeviceType* tmp_device = (DeviceType*)getDevice(deviceId);
    if (tmp_device) return *tmp_device;

    DEBUG_SINRIC("[SinricPro]: Device \"%s\" does not exist. Creating new device\r\n", deviceId.c_str());
    DeviceType& tmp_deviceInstance = add<DeviceType>(deviceId);

    if (isConnected()) {
        DEBUG_SINRIC("[SinricPro]: Reconnecting to server.\r\n");
        reconnect();
    }

    return tmp_deviceInstance;
}

template <typename DeviceType>
DeviceType& SinricProClass::add(String deviceId) {
    DeviceType* newDevice = new DeviceType(deviceId);
    DEBUG_SINRIC("[SinricPro:add()]: Adding device with id \"%s\".\r\n", deviceId.c_str());
    newDevice->begin(this);

    devices.push_back(newDevice);
    return *newDevice;
}

}  // namespace SINRICPRO_NAMESPACE

extern SINRICPRO_NAMESPACE::SinricProClass SinricPro;