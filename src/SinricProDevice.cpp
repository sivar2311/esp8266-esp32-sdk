#include "SinricProDevice.h"
#include "SinricProDebug.h"
#include "SinricPro.h"

namespace SINRICPRO_NAMESPACE {

SinricProDevice::SinricProDevice(const String &deviceId, const String &productType) : 
  deviceId(deviceId),
  eventSender(nullptr),
  productType(productType) {
}

SinricProDevice::~SinricProDevice() {}

void SinricProDevice::begin(SinricProInterface* eventSender) {
  this->eventSender = eventSender;
}

String SinricProDevice::getDeviceId() {
  return deviceId;
}

bool SinricProDevice::operator==(const String &other) { 
  return other == deviceId; 
}

DynamicJsonDocument SinricProDevice::prepareEvent(const char* action, const char* cause) {
  if (eventSender) return eventSender->prepareEvent(deviceId, action, cause);
  DEBUG_SINRIC("[SinricProDevice:prepareEvent()]: Device \"%s\" isn't configured correctly! The \'%s\' event will be ignored.\r\n", deviceId.c_str(), action);
  return DynamicJsonDocument(1024);
}


bool SinricProDevice::sendEvent(JsonDocument& event) {
  if (!SinricPro.isConnected()) {
    DEBUG_SINRIC("[SinricProDevice::sendEvent]: The event could not be sent. No connection to the SinricPro server.\r\n");
    return false;
  }

  if (eventSender) {
    eventSender->sendMessage(event);
    return true;
  }
  
  return false;
}

void SinricProDevice::registerRequestHandler(const SinricProRequestHandler &requestHandler) {
  requestHandlers.push_back(requestHandler);
}

unsigned long SinricProDevice::getTimestamp() {
  if (eventSender) return eventSender->getTimestamp();
  return 0;
}

String SinricProDevice::getProductType()  { 
  return String("sinric.device.type.")+productType; 
}

bool SinricProDevice::handleRequest(SinricProRequest &request) {
  for (auto& requestHandler : requestHandlers) {
    if (requestHandler(request)) return true;
  }
  return false;
}

}