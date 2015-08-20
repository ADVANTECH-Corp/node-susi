#include <node.h>
#include <nan.h>
#include "node-SUSI.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;

// NativeExtension.cc represents the top level of the module. 
// C++ constructs that are exposed to javascript are exported here

void InitAll(Handle<Object> exports) {
  exports->Set(NanNew<String>("getHardwareMonitor"),
    NanNew<FunctionTemplate>(getHardwareMonitor)->GetFunction());
  exports->Set(NanNew<String>("getHardwareMonitorString"),
    NanNew<FunctionTemplate>(getHardwareMonitorString)->GetFunction());
  exports->Set(NanNew<String>("getVgaBacklight"),
    NanNew<FunctionTemplate>(getVgaBacklight)->GetFunction());
  exports->Set(NanNew<String>("setVgaBacklight"),
    NanNew<FunctionTemplate>(setVgaBacklight)->GetFunction());
  exports->Set(NanNew<String>("getGPIO"),
    NanNew<FunctionTemplate>(getGPIO)->GetFunction());
  exports->Set(NanNew<String>("setGPIO"),
    NanNew<FunctionTemplate>(setGPIO)->GetFunction());
  exports->Set(NanNew<String>("getWatchDog"),
    NanNew<FunctionTemplate>(getWatchDog)->GetFunction());
  exports->Set(NanNew<String>("setWatchDog"),
    NanNew<FunctionTemplate>(setWatchDog)->GetFunction());
  exports->Set(NanNew<String>("aString"),
    NanNew<FunctionTemplate>(aString)->GetFunction());

}

NODE_MODULE(node_SUSI, InitAll)
