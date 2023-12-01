#include "SinricProQueue.h"
#include <Arduino.h>

namespace SINRICPRO_NAMESPACE {

SinricProMessage::SinricProMessage(interface_t interface, const char* message) : 
  _interface(interface) { 
  _message = strdup(message); 
};

SinricProMessage::~SinricProMessage() { 
  if (_message) free(_message); 
};

const char* SinricProMessage::getMessage() const { 
  return _message; 
};

interface_t SinricProMessage::getInterface() const { 
  return _interface; 
};

}