#pragma once

#include "SinricProNamespace.h"
namespace SINRICPRO_NAMESPACE {

extern const char* FSTR_SINRICPRO_instanceId;            // "instanceId"
extern const char* FSTR_SINRICPRO_message;               // "message"
extern const char* FSTR_SINRICPRO_success;               // "success"
extern const char* FSTR_SINRICPRO_response;              // "response"
extern const char* FSTR_SINRICPRO_header;                // "header"
extern const char* FSTR_SINRICPRO_payloadVersion;        // "payloadVersion"
extern const char* FSTR_SINRICPRO_signatureVersion;      // "signatureVersion"
extern const char* FSTR_SINRICPRO_payload;               // "payload"
extern const char* FSTR_SINRICPRO_action;                // "action"
extern const char* FSTR_SINRICPRO_cause;                 // "cause"
extern const char* FSTR_SINRICPRO_type;                  // "type"
extern const char* FSTR_SINRICPRO_createdAt;             // "createdAt"
extern const char* FSTR_SINRICPRO_deviceId;              // "deviceId"
extern const char* FSTR_SINRICPRO_replyToken;            // "replyToken"
extern const char* FSTR_SINRICPRO_event;                 // "event"
extern const char* FSTR_SINRICPRO_value;                 // "value"
extern const char* FSTR_SINRICPRO_clientId;              // "clientId"
extern const char* FSTR_SINRICPRO_request;               // "request"
extern const char* FSTR_SINRICPRO_signature;             // "signature"
extern const char* FSTR_SINRICPRO_HMAC;                  // "HMAC"
extern const char* FSTR_SINRICPRO_timestamp;             // "timestamp"
extern const char* FSTR_SINRICPRO_PERIODIC_POLL;         // "PERIODIC_POLL"
extern const char* FSTR_SINRICPRO_PHYSICAL_INTERACTION;  // "PHYSICAL_INTERACTION"
extern const char* FSTR_SINRICPRO_ALERT;                 // "ALERT"
extern const char* FSTR_SINRICPRO_OK;                    // "OK"

extern const char* FSTR_AIRQUALITY_airQuality;  // "airQuality"
extern const char* FSTR_AIRQUALITY_pm1;         // "pm1"
extern const char* FSTR_AIRQUALITY_pm2_5;       // "pm2_5"
extern const char* FSTR_AIRQUALITY_pm10;        // "pm10"

extern const char* FSTR_BRIGHTNESS_setBrightness;     // "setBrightness"
extern const char* FSTR_BRIGHTNESS_brightness;        // "brightness"
extern const char* FSTR_BRIGHTNESS_adjustBrightness;  // "adjustBrightness"
extern const char* FSTR_BRIGHTNESS_brightnessDelta;   // "brightnessDelta"

extern const char* FSTR_CHANNEL_changeChannel;  // "changeChannel"
extern const char* FSTR_CHANNEL_channel;        // "channel"
extern const char* FSTR_CHANNEL_name;           // "name"
extern const char* FSTR_CHANNEL_number;         // "number"
extern const char* FSTR_CHANNEL_skipChannels;   // "skipChannels"
extern const char* FSTR_CHANNEL_channelCount;   // "channelCount"

extern const char* FSTR_COLOR_setColor;  // "setColor"
extern const char* FSTR_COLOR_color;     // "color"
extern const char* FSTR_COLOR_r;         // "r"
extern const char* FSTR_COLOR_g;         // "g"
extern const char* FSTR_COLOR_b;         // "b"

extern const char* FSTR_COLORTEMPERATURE_colorTemperature;          // "colorTemperature"
extern const char* FSTR_COLORTEMPERATURE_setColorTemperature;       // "setColorTemperature"
extern const char* FSTR_COLORTEMPERATURE_increaseColorTemperature;  // "increaseColorTemperature"
extern const char* FSTR_COLORTEMPERATURE_decreaseColorTemperature;  // "decreaseColorTemperature"

extern const char* FSTR_CONTACT_setContactState;  // "setContactState"
extern const char* FSTR_CONTACT_state;            // "state"
extern const char* FSTR_CONTACT_closed;           // "closed"
extern const char* FSTR_CONTACT_open;             // "open"

extern const char* FSTR_DOORBELL_DoorbellPress;  // "DoorbellPress"
extern const char* FSTR_DOORBELL_state;          // "state"
extern const char* FSTR_DOORBELL_pressed;        // "pressed"

extern const char* FSTR_DOOR_setMode;  // "setMode"
extern const char* FSTR_DOOR_mode;     // "mode"
extern const char* FSTR_DOOR_Close;    // "Close"
extern const char* FSTR_DOOR_Open;     // "Open"

extern const char* FSTR_EQUALIZER_setBands;        // "setBands"
extern const char* FSTR_EQUALIZER_bands;           // "bands"
extern const char* FSTR_EQUALIZER_name;            // "name"
extern const char* FSTR_EQUALIZER_value;           // "value"
extern const char* FSTR_EQUALIZER_level;           // "level"
extern const char* FSTR_EQUALIZER_adjustBands;     // "adjustBands"
extern const char* FSTR_EQUALIZER_levelDelta;      // "levelDelta"
extern const char* FSTR_EQUALIZER_levelDirection;  // "levelDirection"
extern const char* FSTR_EQUALIZER_DOWN;            // "DOWN"
extern const char* FSTR_EQUALIZER_resetBands;      // "resetBands"

extern const char* FSTR_INPUT_selectInput;  // "selectInput"
extern const char* FSTR_INPUT_input;        // "input"

extern const char* FSTR_KEYPAD_sendKeystroke;  // "sendKeystroke"
extern const char* FSTR_KEYPAD_keystroke;      // "keystroke"

extern const char* FSTR_LOCK_setLockState;  // "setLockState"
extern const char* FSTR_LOCK_state;         // "state"
extern const char* FSTR_LOCK_LOCKED;        // "LOCKED"
extern const char* FSTR_LOCK_UNLOCKED;      // "UNLOCKED"
extern const char* FSTR_LOCK_lock;          // "lock"
extern const char* FSTR_LOCK_JAMMED;        // "JAMMED"

extern const char* FSTR_MEDIA_mediaControl;  // "mediaControl"
extern const char* FSTR_MEDIA_control;       // "control"

extern const char* FSTR_MODE_setMode;  // "setMode"
extern const char* FSTR_MODE_mode;     // "mode"

extern const char* FSTR_MOTION_motion;       // "motion"
extern const char* FSTR_MOTION_state;        // "state"
extern const char* FSTR_MOTION_detected;     // "detected"
extern const char* FSTR_MOTION_notDetected;  // "notDetected"

extern const char* FSTR_MUTE_mute;     // "mute"
extern const char* FSTR_MUTE_setMute;  // "setMute"

extern const char* FSTR_PERCENTAGE_setPercentage;     // "setPercentage"
extern const char* FSTR_PERCENTAGE_percentage;        // "percentage"
extern const char* FSTR_PERCENTAGE_adjustPercentage;  // "adjustPercentage"

extern const char* FSTR_POWERLEVEL_setPowerLevel;     // "setPowerLevel"
extern const char* FSTR_POWERLEVEL_powerLevel;        // "powerLevel"
extern const char* FSTR_POWERLEVEL_adjustPowerLevel;  // "adjustPowerLevel"
extern const char* FSTR_POWERLEVEL_powerLevelDelta;   // "powerLevelDelta"

extern const char* FSTR_POWERSENSOR_powerUsage;     // "powerUsage"
extern const char* FSTR_POWERSENSOR_startTime;      // "startTime"
extern const char* FSTR_POWERSENSOR_voltage;        // "voltage"
extern const char* FSTR_POWERSENSOR_current;        // "current"
extern const char* FSTR_POWERSENSOR_power;          // "power"
extern const char* FSTR_POWERSENSOR_apparentPower;  // "apparentPower"
extern const char* FSTR_POWERSENSOR_reactivePower;  // "reactivePower"
extern const char* FSTR_POWERSENSOR_factor;         // "factor"
extern const char* FSTR_POWERSENSOR_wattHours;      // "wattHours"

extern const char* FSTR_POWERSTATE_state;          // "state"
extern const char* FSTR_POWERSTATE_On;             // "On"
extern const char* FSTR_POWERSTATE_Off;            // "Off"
extern const char* FSTR_POWERSTATE_setPowerState;  // "setPowerState"

extern const char* FSTR_PUSHNOTIFICATION_pushNotification;  // "pushNotification"
extern const char* FSTR_PUSHNOTIFICATION_alert;             // "alert"

extern const char* FSTR_RANGE_setRangeValue;     // "setRangeValue"
extern const char* FSTR_RANGE_rangeValue;        // "rangeValue"
extern const char* FSTR_RANGE_adjustRangeValue;  // "adjustRangeValue"
extern const char* FSTR_RANGE_rangeValueDelta;   // "rangeValueDelta"

extern const char* FSTR_SETTING_setSetting;  // "setSetting"
extern const char* FSTR_SETTING_id;          // "id"
extern const char* FSTR_SETTING_value;       // "value"

extern const char* FSTR_TEMPERATURE_currentTemperature;  // "currentTemperature"
extern const char* FSTR_TEMPERATURE_humidity;            // "humidity"
extern const char* FSTR_TEMPERATURE_temperature;         // "temperature"

extern const char* FSTR_THERMOSTAT_setThermostatMode;        // "setThermostatMode"
extern const char* FSTR_THERMOSTAT_thermostatMode;           // "thermostatMode"
extern const char* FSTR_THERMOSTAT_targetTemperature;        // "targetTemperature"
extern const char* FSTR_THERMOSTAT_temperature;              // "temperature"
extern const char* FSTR_THERMOSTAT_adjustTargetTemperature;  // "adjustTargetTemperature"

extern const char* FSTR_TOGGLE_setToggleState;  // "setToggleState"
extern const char* FSTR_TOGGLE_state;           // "state"
extern const char* FSTR_TOGGLE_On;              // "On"
extern const char* FSTR_TOGGLE_Off;             // "Off"

extern const char* FSTR_VOLUME_setVolume;      // "setVolume"
extern const char* FSTR_VOLUME_volume;         // "volume"
extern const char* FSTR_VOLUME_adjustVolume;   // "adjustVolume"
extern const char* FSTR_VOLUME_volumeDefault;  // "volumeDefault"

}  // namespace SINRICPRO_NAMESPACE