#include "SinricProStrings.h"

namespace SINRICPRO_NAMESPACE {

const char* FSTR_SINRICPRO_instanceId           = "instanceId";
const char* FSTR_SINRICPRO_message              = "message";
const char* FSTR_SINRICPRO_success              = "success";
const char* FSTR_SINRICPRO_response             = "response";
const char* FSTR_SINRICPRO_header               = "header";
const char* FSTR_SINRICPRO_payloadVersion       = "payloadVersion";
const char* FSTR_SINRICPRO_signatureVersion     = "signatureVersion";
const char* FSTR_SINRICPRO_payload              = "payload";
const char* FSTR_SINRICPRO_action               = "action";
const char* FSTR_SINRICPRO_cause                = "cause";
const char* FSTR_SINRICPRO_type                 = "type";
const char* FSTR_SINRICPRO_createdAt            = "createdAt";
const char* FSTR_SINRICPRO_deviceId             = "deviceId";
const char* FSTR_SINRICPRO_replyToken           = "replyToken";
const char* FSTR_SINRICPRO_event                = "event";
const char* FSTR_SINRICPRO_value                = "value";
const char* FSTR_SINRICPRO_clientId             = "clientId";
const char* FSTR_SINRICPRO_request              = "request";
const char* FSTR_SINRICPRO_signature            = "signature";
const char* FSTR_SINRICPRO_HMAC                 = "HMAC";
const char* FSTR_SINRICPRO_timestamp            = "timestamp";
const char* FSTR_SINRICPRO_PERIODIC_POLL        = "PERIODIC_POLL";
const char* FSTR_SINRICPRO_PHYSICAL_INTERACTION = "PHYSICAL_INTERACTION";
const char* FSTR_SINRICPRO_ALERT                = "ALERT";
const char* FSTR_SINRICPRO_OK                   = "OK";

const char* FSTR_AIRQUALITY_airQuality = "airQuality";
const char* FSTR_AIRQUALITY_pm1        = "pm1";
const char* FSTR_AIRQUALITY_pm2_5      = "pm2_5";
const char* FSTR_AIRQUALITY_pm10       = "pm10";

const char* FSTR_BRIGHTNESS_setBrightness    = "setBrightness";
const char* FSTR_BRIGHTNESS_brightness       = "brightness";
const char* FSTR_BRIGHTNESS_adjustBrightness = "adjustBrightness";
const char* FSTR_BRIGHTNESS_brightnessDelta  = "brightnessDelta";

const char* FSTR_CHANNEL_changeChannel = "changeChannel";
const char* FSTR_CHANNEL_channel       = "channel";
const char* FSTR_CHANNEL_name          = "name";
const char* FSTR_CHANNEL_number        = "number";
const char* FSTR_CHANNEL_skipChannels  = "skipChannels";
const char* FSTR_CHANNEL_channelCount  = "channelCount";

const char* FSTR_COLOR_setColor = "setColor";
const char* FSTR_COLOR_color    = "color";
const char* FSTR_COLOR_r        = "r";
const char* FSTR_COLOR_g        = "g";
const char* FSTR_COLOR_b        = "b";

const char* FSTR_COLORTEMPERATURE_colorTemperature         = "colorTemperature";
const char* FSTR_COLORTEMPERATURE_setColorTemperature      = "setColorTemperature";
const char* FSTR_COLORTEMPERATURE_increaseColorTemperature = "increaseColorTemperature";
const char* FSTR_COLORTEMPERATURE_decreaseColorTemperature = "decreaseColorTemperature";

const char* FSTR_CONTACT_setContactState = "setContactState";
const char* FSTR_CONTACT_state           = "state";
const char* FSTR_CONTACT_closed          = "closed";
const char* FSTR_CONTACT_open            = "open";

const char* FSTR_DOORBELL_DoorbellPress = "DoorbellPress";
const char* FSTR_DOORBELL_state         = "state";
const char* FSTR_DOORBELL_pressed       = "pressed";

const char* FSTR_DOOR_setMode = "setMode";
const char* FSTR_DOOR_mode    = "mode";
const char* FSTR_DOOR_Close   = "Close";
const char* FSTR_DOOR_Open    = "Open";

const char* FSTR_EQUALIZER_setBands       = "setBands";
const char* FSTR_EQUALIZER_bands          = "bands";
const char* FSTR_EQUALIZER_name           = "name";
const char* FSTR_EQUALIZER_value          = "value";
const char* FSTR_EQUALIZER_level          = "level";
const char* FSTR_EQUALIZER_adjustBands    = "adjustBands";
const char* FSTR_EQUALIZER_levelDelta     = "levelDelta";
const char* FSTR_EQUALIZER_levelDirection = "levelDirection";
const char* FSTR_EQUALIZER_DOWN           = "DOWN";
const char* FSTR_EQUALIZER_resetBands     = "resetBands";

const char* FSTR_INPUT_selectInput = "selectInput";
const char* FSTR_INPUT_input       = "input";

const char* FSTR_KEYPAD_sendKeystroke = "sendKeystroke";
const char* FSTR_KEYPAD_keystroke     = "keystroke";

const char* FSTR_LOCK_setLockState = "setLockState";
const char* FSTR_LOCK_state        = "state";
const char* FSTR_LOCK_LOCKED       = "LOCKED";
const char* FSTR_LOCK_UNLOCKED     = "UNLOCKED";
const char* FSTR_LOCK_lock         = "lock";
const char* FSTR_LOCK_JAMMED       = "JAMMED";

const char* FSTR_MEDIA_mediaControl = "mediaControl";
const char* FSTR_MEDIA_control      = "control";

const char* FSTR_MODE_setMode = "setMode";
const char* FSTR_MODE_mode    = "mode";

const char* FSTR_MOTION_motion      = "motion";
const char* FSTR_MOTION_state       = "state";
const char* FSTR_MOTION_detected    = "detected";
const char* FSTR_MOTION_notDetected = "notDetected";

const char* FSTR_MUTE_mute    = "mute";
const char* FSTR_MUTE_setMute = "setMute";

const char* FSTR_PERCENTAGE_setPercentage    = "setPercentage";
const char* FSTR_PERCENTAGE_percentage       = "percentage";
const char* FSTR_PERCENTAGE_adjustPercentage = "adjustPercentage";

const char* FSTR_POWERLEVEL_setPowerLevel    = "setPowerLevel";
const char* FSTR_POWERLEVEL_powerLevel       = "powerLevel";
const char* FSTR_POWERLEVEL_adjustPowerLevel = "adjustPowerLevel";
const char* FSTR_POWERLEVEL_powerLevelDelta  = "powerLevelDelta";

const char* FSTR_POWERSENSOR_powerUsage    = "powerUsage";
const char* FSTR_POWERSENSOR_startTime     = "startTime";
const char* FSTR_POWERSENSOR_voltage       = "voltage";
const char* FSTR_POWERSENSOR_current       = "current";
const char* FSTR_POWERSENSOR_power         = "power";
const char* FSTR_POWERSENSOR_apparentPower = "apparentPower";
const char* FSTR_POWERSENSOR_reactivePower = "reactivePower";
const char* FSTR_POWERSENSOR_factor        = "factor";
const char* FSTR_POWERSENSOR_wattHours     = "wattHours";

const char* FSTR_POWERSTATE_state         = "state";
const char* FSTR_POWERSTATE_On            = "On";
const char* FSTR_POWERSTATE_Off           = "Off";
const char* FSTR_POWERSTATE_setPowerState = "setPowerState";

const char* FSTR_PUSHNOTIFICATION_pushNotification = "pushNotification";
const char* FSTR_PUSHNOTIFICATION_alert            = "alert";

const char* FSTR_RANGE_setRangeValue    = "setRangeValue";
const char* FSTR_RANGE_rangeValue       = "rangeValue";
const char* FSTR_RANGE_adjustRangeValue = "adjustRangeValue";
const char* FSTR_RANGE_rangeValueDelta  = "rangeValueDelta";

const char* FSTR_SETTING_setSetting = "setSetting";
const char* FSTR_SETTING_id         = "id";
const char* FSTR_SETTING_value      = "value";

const char* FSTR_TEMPERATURE_currentTemperature = "currentTemperature";
const char* FSTR_TEMPERATURE_humidity           = "humidity";
const char* FSTR_TEMPERATURE_temperature        = "temperature";

const char* FSTR_THERMOSTAT_setThermostatMode       = "setThermostatMode";
const char* FSTR_THERMOSTAT_thermostatMode          = "thermostatMode";
const char* FSTR_THERMOSTAT_targetTemperature       = "targetTemperature";
const char* FSTR_THERMOSTAT_temperature             = "temperature";
const char* FSTR_THERMOSTAT_adjustTargetTemperature = "adjustTargetTemperature";

const char* FSTR_TOGGLE_setToggleState = "setToggleState";
const char* FSTR_TOGGLE_state          = "state";
const char* FSTR_TOGGLE_On             = "On";
const char* FSTR_TOGGLE_Off            = "Off";

const char* FSTR_VOLUME_setVolume     = "setVolume";
const char* FSTR_VOLUME_volume        = "volume";
const char* FSTR_VOLUME_adjustVolume  = "adjustVolume";
const char* FSTR_VOLUME_volumeDefault = "volumeDefault";

}  // namespace SINRICPRO_NAMESPACE