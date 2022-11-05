#pragma once

#include "../SinricProNamespace.h"
#include "../SinricProRequest.h"
#include "../SinricProStrings.h"
namespace SINRICPRO_NAMESPACE {

using SetSettingCallback = std::function<bool(const String&, const String&, String&)>;

FSTR(SETTING, setSetting);  // "setSetting"
FSTR(SETTING, id);          // "id"
FSTR(SETTING, value);       // "value"

template <typename T>
class SettingController : public SinricProRequestHandler {
  public:
    SettingController();
    void onSetSetting(SetSettingCallback cb);

  private:
    virtual bool handleRequest(SinricProRequest& request);
    inline T       &getDevice();
    inline const T &getDevice() const;

  private:
    SetSettingCallback setSettingCallback;
};

template <typename T>
SettingController<T>::SettingController() {
    getDevice().registerRequestHandler(this);
}

template <typename T>
void SettingController<T>::onSetSetting(SetSettingCallback cb) {
    setSettingCallback = cb;
}

template <typename T>
bool SettingController<T>::handleRequest(SinricProRequest& request) {
    bool success = false;

    if (setSettingCallback && request.action == FSTR_SETTING_setSetting) {
        String settingId                           = request.request_value[FSTR_SETTING_id] | "";
        String settingValue                        = request.request_value[FSTR_SETTING_value] | "";
        success                                    = setSettingCallback(getDevice().deviceId, settingId, settingValue);
        request.response_value[FSTR_SETTING_id]    = settingId;
        request.response_value[FSTR_SETTING_value] = settingValue;
        return success;
    }

    return success;
}

template <typename T>
T& SettingController<T>::getDevice() {
    return static_cast<T&>(*this);
}

template <typename T>
const T& SettingController<T>::getDevice() const {
    return static_cast<const T&>(*this);
}

}  // namespace SINRICPRO_NAMESPACE

template <typename T>
using SettingController = SINRICPRO_NAMESPACE::SettingController<T>;