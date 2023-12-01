#pragma once

#include "SinricProConfig.h"
#include "SinricProNamespace.h"

namespace SINRICPRO_NAMESPACE {

class EventLimiter {
  public:
    EventLimiter(unsigned long minimum_distance = 1000);
    operator bool();
  private:
    unsigned long minimum_distance;
    unsigned long next_event;
    unsigned long extra_distance;
    unsigned long fail_counter;
};

} // SINRICPRO_NAMESPACE