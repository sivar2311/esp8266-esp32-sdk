#pragma once

#include "../EventLimiter.h"
#include "../SinricProNamespace.h"
#include "../SinricProRequest.h"
#include "../SinricProStrings.h"
namespace SINRICPRO_NAMESPACE {

FSTR(COLOR, setColor);  // "setColor"
FSTR(COLOR, color);     // "color"
FSTR(COLOR, r);         // "r"
FSTR(COLOR, g);         // "g"
FSTR(COLOR, b);         // "b"

/**
 * @brief Callback definition for onColor function
 *
 * Gets called when device receive a `setColor` request \n
 * @param[in]   deviceId    String which contains the ID of device
 * @param[in]   r           Byte value for red
 * @param[in]   g           Byte value for green
 * @param[in]   b           Byte value for blue
 * @param[out]  r           Byte value for red
 * @param[out]  g           Byte value for green
 * @param[out]  b           Byte value for blue
 * @return      the success of the request
 * @retval      true        request handled properly
 * @retval      false       request was not handled properly because of some error
 * @section ColorCallback Example-Code
 * @snippet callbacks.cpp onColor
 **/
using ColorCallback = std::function<bool(const String &, byte &, byte &, byte &)>;

/**
 * @brief ColorController
 * @ingroup Capabilities
 **/
template <typename T>
class ColorController : public SinricProRequestHandler {
  public:
    ColorController();

    void onColor(ColorCallback cb);
    bool sendColorEvent(byte r, byte g, byte b, String cause = FSTR_SINRICPRO_PHYSICAL_INTERACTION);

  private:
    virtual bool handleRequest(SinricProRequest &request);
    inline T       &getDevice();
    inline const T &getDevice() const;

  private:
    EventLimiter  event_limiter;
    ColorCallback colorCallback;
};

template <typename T>
ColorController<T>::ColorController()
    : event_limiter(EVENT_LIMIT_STATE) {
    getDevice().registerRequestHandler(this);
}

/**
 * @brief Set callback function for `setColor` request
 *
 * @param cb Function pointer to a `ColorCallback` function
 * @return void
 * @see ColorCallback
 **/
template <typename T>
void ColorController<T>::onColor(ColorCallback cb) {
    colorCallback = cb;
}

/**
 * @brief Send `setColor` event to SinricPro Server indicating actual color
 *
 * @param r       Byte value for red
 * @param g       Byte value for green
 * @param b       Byte value for blue
 * @param cause   (optional) `String` reason why event is sent (default = `"PHYSICAL_INTERACTION"`)
 * @return the success of sending the even
 * @retval true   event has been sent successfully
 * @retval false  event has not been sent, maybe you sent to much events in a short distance of time
 **/
template <typename T>
bool ColorController<T>::sendColorEvent(byte r, byte g, byte b, String cause) {
    if (event_limiter) return false;

    DynamicJsonDocument eventMessage = getDevice().prepareEvent(FSTR_COLOR_setColor, cause.c_str());
    JsonObject          event_color  = eventMessage[FSTR_SINRICPRO_payload][FSTR_SINRICPRO_value].createNestedObject(FSTR_COLOR_color);
    event_color[FSTR_COLOR_r]        = r;
    event_color[FSTR_COLOR_g]        = g;
    event_color[FSTR_COLOR_b]        = b;
    return getDevice().sendEvent(eventMessage);
}

template <typename T>
bool ColorController<T>::handleRequest(SinricProRequest &request) {
    bool success = false;

    if (colorCallback && request.action == FSTR_COLOR_setColor) {
        unsigned char r, g, b;
        r       = request.request_value[FSTR_COLOR_color][FSTR_COLOR_r];
        g       = request.request_value[FSTR_COLOR_color][FSTR_COLOR_g];
        b       = request.request_value[FSTR_COLOR_color][FSTR_COLOR_b];
        success = colorCallback(getDevice().deviceId, r, g, b);
        request.response_value.createNestedObject(FSTR_COLOR_color);
        request.response_value[FSTR_COLOR_color][FSTR_COLOR_r] = r;
        request.response_value[FSTR_COLOR_color][FSTR_COLOR_g] = g;
        request.response_value[FSTR_COLOR_color][FSTR_COLOR_b] = b;
    }

    return success;
}

template <typename T>
T& ColorController<T>::getDevice() {
    return static_cast<T&>(*this);
}

template <typename T>
const T& ColorController<T>::getDevice() const {
    return static_cast<const T&>(*this);
}

}  // namespace SINRICPRO_NAMESPACE

template <typename T>
using ColorController = SINRICPRO_NAMESPACE::ColorController<T>;