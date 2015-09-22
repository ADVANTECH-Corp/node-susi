//#include <node.h>
#include <nan.h>
#include "node-SUSI.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

// NativeExtension.cc represents the top level of the module. 
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(Init) {
	NAN_EXPORT(target, getHardwareMonitor);
	NAN_EXPORT(target, getHardwareMonitorString);
	NAN_EXPORT(target, getVgaBacklight);
	NAN_EXPORT(target, setVgaBacklight);
	NAN_EXPORT(target, getGPIO);
	NAN_EXPORT(target, setGPIO);
	NAN_EXPORT(target, getWatchDog);
	NAN_EXPORT(target, setWatchDog);
	NAN_EXPORT(target, aString);
}

NODE_MODULE(node_SUSI, Init)
