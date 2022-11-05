#pragma once

#include "../EventLimiter.h"
#include "../SinricProStrings.h"

#include "../SinricProNamespace.h"
namespace SINRICPRO_NAMESPACE {

FSTR(PUSHNOTIFICATION, pushNotification);  // "pushNotification"
FSTR(PUSHNOTIFICATION, alert);             // "alert"

/**
 * @brief PushNotification
 * @ingroup Capabilities
 **/
template <typename T>
class PushNotification {
  public:
    PushNotification();
    bool sendPushNotification(String notification);

  private:
    inline T       &getDevice();
    inline const T &getDevice() const;

  private:
    EventLimiter event_limiter;
};

template <typename T>
PushNotification<T>::PushNotification()
: event_limiter (EVENT_LIMIT_SENSOR_VALUE) {}

/**
 * @brief Sending push notifications to SinricPro App
 * 
 * @param   notification `String` with the notification
 * @return  the success of sending the event
 * @retval  true          event has been sent successfully
 * @retval  false         event has not been sent, maybe you sent to much events in a short distance of time
 **/
template <typename T>
bool PushNotification<T>::sendPushNotification(String notification) {
  if (event_limiter) return false;
  
  DynamicJsonDocument eventMessage = getDevice().prepareEvent(FSTR_PUSHNOTIFICATION_pushNotification, FSTR_SINRICPRO_ALERT);
  JsonObject event_value = eventMessage[FSTR_SINRICPRO_payload][FSTR_SINRICPRO_value];

  event_value[FSTR_PUSHNOTIFICATION_alert] = notification;

  return getDevice().sendEvent(eventMessage);
}

template <typename T>
T& PushNotification<T>::getDevice() {
    return static_cast<T&>(*this);
}

template <typename T>
const T& PushNotification<T>::getDevice() const {
    return static_cast<const T&>(*this);
}

} // SINRICPRO_NAMESPACE

template <typename T>
using PushNotification = SINRICPRO_NAMESPACE::PushNotification<T>;