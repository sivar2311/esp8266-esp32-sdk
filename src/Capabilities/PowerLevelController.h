#pragma once

#include "../EventLimiter.h"
#include "../SinricProNamespace.h"
#include "../SinricProRequest.h"
#include "../SinricProStrings.h"
namespace SINRICPRO_NAMESPACE {

FSTR(POWERLEVEL, setPowerLevel);     // "setPowerLevel"
FSTR(POWERLEVEL, powerLevel);        // "powerLevel"
FSTR(POWERLEVEL, adjustPowerLevel);  // "adjustPowerLevel"
FSTR(POWERLEVEL, powerLevelDelta);   // "powerLevelDelta"

/**
 * @brief Definition for setPowerLevel callback
 *
 * Gets called when device receive a `setPowerLevel` reuqest \n
 * @param[in]     deviceId        String which contains the ID of device
 * @param[in]     powerLevel      integer `0..100` new powerlevel the device should be set to
 * @param[out]    powerLevel      integer `0..100` report the powerlevel that the device have been set to
 * @return        the success of the request
 * @retval        true            request handled properly
 * @retval        false           request was not handled properly because of some error
 *
 * @section SetPowerLevelCallback Example-Code
 * @snippet callbacks.cpp onPowerLevel
 **/

using SetPowerLevelCallback = std::function<bool(const String &, int &)>;
/**
 * @brief Definition for onAdjustPowerLevel callback
 *
 * Gets called when device receive a `adjustPowerLevel` reuqest \n
 * @param[in]     deviceId      String which contains the ID of device
 * @param[in]     powerLevel    integer `-100..100` delta value which power level have to be changed
 * @param[out]    powerLevel    integer `0..100` report the absolute powerlevel that the device have been set to
 * @return        the success of the request
 * @retval true   request handled properly
 * @retval false  request can`t be handled properly because of some error
 *
 * @section AdjustPowerLevelCallback Example-Code
 * @snippet callbacks.cpp onAdjustPowerLevel
 **/
using AdjustPowerLevelCallback = std::function<bool(const String &, int &)>;

/**
 * @brief PowerLevelController
 * @ingroup Capabilities
 **/
template <typename T>
class PowerLevelController : public SinricProRequestHandler {
  public:
    PowerLevelController();

    void onPowerLevel(SetPowerLevelCallback cb);
    void onAdjustPowerLevel(AdjustPowerLevelCallback cb);
    bool sendPowerLevelEvent(int powerLevel, String cause = FSTR_SINRICPRO_PHYSICAL_INTERACTION);

  private:
    virtual bool    handleRequest(SinricProRequest &request);
    inline T       &getDevice();
    inline const T &getDevice() const;

  private:
    EventLimiter             event_limiter;
    SetPowerLevelCallback    setPowerLevelCallback;
    AdjustPowerLevelCallback adjustPowerLevelCallback;
};

template <typename T>
PowerLevelController<T>::PowerLevelController()
    : event_limiter(EVENT_LIMIT_STATE) {
    getDevice().registerRequestHandler(this);
}

/**
 * @brief Set callback function for setPowerLevel request
 *
 * @param     cb    Function pointer to a SetPowerLevelCallback function
 * @see       SetPowerLevelCallback
 **/
template <typename T>
void PowerLevelController<T>::onPowerLevel(SetPowerLevelCallback cb) {
    setPowerLevelCallback = cb;
}

/**
 * @brief Set callback function for adjustPowerLevel request
 *
 * @param     cb    Function pointer to a AdjustPowerLevelCallback function
 * @see       AdjustPowerLevelCallback
 **/
template <typename T>
void PowerLevelController<T>::onAdjustPowerLevel(AdjustPowerLevelCallback cb) {
    adjustPowerLevelCallback = cb;
}

/**
 * @brief Send `setPowerLevel` event to SinricPro Server indicating actual power level
 *
 * @param   powerLevel    integer `0..100` report the powerlevel that the device have been set to
 * @param   cause         (optional) Reason why event is sent (default = `"PHYSICAL_INTERACTION"`)
 * @return  the success of sending the event
 * @retval  true          event has been sent successfully
 * @retval  false         event has not been sent, maybe you sent to much events in a short distance of time
 **/
template <typename T>
bool PowerLevelController<T>::sendPowerLevelEvent(int powerLevel, String cause) {
    if (event_limiter) return false;

    DynamicJsonDocument eventMessage        = getDevice().prepareEvent(FSTR_POWERLEVEL_setPowerLevel, cause.c_str());
    JsonObject          event_value         = eventMessage[FSTR_SINRICPRO_payload][FSTR_SINRICPRO_value];
    event_value[FSTR_POWERLEVEL_powerLevel] = powerLevel;
    return getDevice().sendEvent(eventMessage);
}

template <typename T>
bool PowerLevelController<T>::handleRequest(SinricProRequest &request) {
    bool success = false;

    if (setPowerLevelCallback && request.action == FSTR_POWERLEVEL_setPowerLevel) {
        int powerLevel                                     = request.request_value[FSTR_POWERLEVEL_powerLevel];
        success                                            = setPowerLevelCallback(getDevice().deviceId, powerLevel);
        request.response_value[FSTR_POWERLEVEL_powerLevel] = powerLevel;
    }

    if (adjustPowerLevelCallback && request.action == FSTR_POWERLEVEL_adjustPowerLevel) {
        int powerLevelDelta                                = request.request_value[FSTR_POWERLEVEL_powerLevelDelta];
        success                                            = adjustPowerLevelCallback(getDevice().deviceId, powerLevelDelta);
        request.response_value[FSTR_POWERLEVEL_powerLevel] = powerLevelDelta;
    }
    return success;
}

template <typename T>
T &PowerLevelController<T>::getDevice() {
    return static_cast<T &>(*this);
}

template <typename T>
const T &PowerLevelController<T>::getDevice() const {
    return static_cast<const T &>(*this);
}

}  // namespace SINRICPRO_NAMESPACE

template <typename T>
using PowerLevelController = SINRICPRO_NAMESPACE::PowerLevelController<T>;