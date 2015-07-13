#include <nan.h>
#include "node-SUSI.h"
#include "Susi4.h"

NAN_METHOD(getTemperature) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id = SUSI_ID_HWM_TEMP_BASE;
    uint32_t getVal;


	int offset = 0;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
		offset = args[0]->Uint32Value();
	
    if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    	NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Temperature) failed"));
	else
    	NanReturnValue(NanNew<v8::Number>(SUSI_DECODE_CELCIUS((float)getVal)));
}

NAN_METHOD(getFanSpeed) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id = SUSI_ID_HWM_FAN_BASE;
    uint32_t getVal;


	int offset = 0;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
		offset = args[0]->Uint32Value();
	
    if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    	NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Fan) failed"));
	else
    	NanReturnValue(NanNew<v8::Number>((float)getVal));
}

NAN_METHOD(getVoltage) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id = SUSI_ID_HWM_VOLTAGE_BASE;
    uint32_t getVal;


	int offset = 0;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
		offset = args[0]->Uint32Value();
	
    if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    	NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Voltage) failed"));
	else
    	NanReturnValue(NanNew<v8::Number>((int32_t)getVal / (float)1000));
}

NAN_METHOD(aString) {
    NanScope();
    NanReturnValue(NanNew<v8::String>("This is a thing."));
}

