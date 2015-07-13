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
  exports->Set(NanNew<String>("getTemperature"),
    NanNew<FunctionTemplate>(getTemperature)->GetFunction());
  exports->Set(NanNew<String>("getFanSpeed"),
    NanNew<FunctionTemplate>(getFanSpeed)->GetFunction());
  exports->Set(NanNew<String>("getVoltage"),
    NanNew<FunctionTemplate>(getVoltage)->GetFunction());
  exports->Set(NanNew<String>("aString"),
    NanNew<FunctionTemplate>(aString)->GetFunction());

}

NODE_MODULE(node_SUSI, InitAll)
