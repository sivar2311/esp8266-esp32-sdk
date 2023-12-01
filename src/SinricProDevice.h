/*
 *  Copyright (c) 2019 Sinric. All rights reserved.
 *  Licensed under Creative Commons Attribution-Share Alike (CC BY-SA)
 *
 *  This file is part of the Sinric Pro (https://github.com/sinricpro/)
 */

#pragma once

#include "SinricProRequest.h"
#include "SinricProDeviceInterface.h"
#include <map>

#include "SinricProNamespace.h"
namespace SINRICPRO_NAMESPACE {

/**
 * @class SinricProDevice
 * @brief Base class for all device types
 * 
 * Supporting base functions which needed by all device types to work with SinricProClass \n
 * Implements basic on/off functions like onPowerState and sendPowerStateEvent
 **/
class SinricProDevice : public SinricProDeviceInterface {
  friend class SinricProClass;
public:
  SinricProDevice(const String &deviceId, const String &productType = "");
  bool                                 operator==(const String& other);

  virtual String                       getDeviceId();
protected:
  virtual                              ~SinricProDevice();

  void                                 registerRequestHandler(const SinricProRequestHandler &requestHandler);
  unsigned long                        getTimestamp();
  virtual bool                         sendEvent(JsonDocument &event);
  virtual DynamicJsonDocument          prepareEvent(const char *action, const char *cause);

  virtual String                       getProductType();
  virtual void                         begin(SinricProInterface *eventSender);
  bool                                 handleRequest(SinricProRequest &request);

  String                               deviceId;
  std::vector<SinricProRequestHandler> requestHandlers;

private:
  SinricProInterface                   *eventSender;
  String                               productType;
};

} // SINRICPRO_NAMESPACE

using SinricProDevice = SINRICPRO_NAMESPACE::SinricProDevice;