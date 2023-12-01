/*
 *  Copyright (c) 2019 Sinric. All rights reserved.
 *  Licensed under Creative Commons Attribution-Share Alike (CC BY-SA)
 *
 *  This file is part of the Sinric Pro (https://github.com/sinricpro/)
 */

#pragma once
#include <Arduino.h>
#include "SinricProNamespace.h"
namespace SINRICPRO_NAMESPACE {

class MessageID {
public:
  MessageID();
  const String& getID() { return _id; }
private:
  String _id;
};

} // SINRICPRO_NAMESPACE