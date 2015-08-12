#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>

// Example top-level functions. These functions demonstrate how to return various js types.
// Implementations are in functions.cc

NAN_METHOD(getHardwareMonitor);
NAN_METHOD(getVgaBacklight);
NAN_METHOD(setVgaBacklight);
NAN_METHOD(getGPIO);
NAN_METHOD(setGPIO);
NAN_METHOD(setWatchDog);

NAN_METHOD(getTemperature);
NAN_METHOD(getFanSpeed);
NAN_METHOD(getVoltage);

NAN_METHOD(getGPIOLevel);
NAN_METHOD(getGPIODirection);

NAN_METHOD(getVgaBacklightEnable);
NAN_METHOD(getVgaBacklightBrightness);
NAN_METHOD(getVgaBacklightFrequency);
NAN_METHOD(getVgaBacklightPolarity);

NAN_METHOD(aString);

#endif
