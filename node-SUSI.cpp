#include <nan.h>
#include "node-SUSI.h"
#include "Susi4.h"

NAN_METHOD(getHardwareMonitor) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id;
    uint32_t getVal;

	int offset = 0;
	int type = 0;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		type = args[0]->Uint32Value();
		offset = args[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			id = SUSI_ID_HWM_TEMP_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Temperature) failed"));
			else
    			NanReturnValue(NanNew<v8::Number>(SUSI_DECODE_CELCIUS((float)getVal)));
			break;
		case 1:
			id = SUSI_ID_HWM_FAN_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Fan) failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((float)getVal));
			break;
		case 2:
			id = SUSI_ID_HWM_VOLTAGE_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Voltage) failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal / (float)1000));
			break;
		case 3:
			id = SUSI_ID_HWM_CURRENT_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetValue(Current) failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal / (float)1000));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(getHardwareMonitorString) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id;
    uint32_t tmplength = 32;

	int offset = 0;
	int type = 0;
	char pName[32];
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		type = args[0]->Uint32Value();
		offset = args[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			id = SUSI_ID_HWM_TEMP_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetString(Temperature) failed"));
			else
    			NanReturnValue(NanNew<v8::String>(pName));
			break;
		case 1:
			id = SUSI_ID_HWM_FAN_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetString(Fan) failed"));
			else
    			NanReturnValue(NanNew<v8::String>(pName));
			break;
		case 2:
			id = SUSI_ID_HWM_VOLTAGE_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetString(Voltage) failed"));
			else
    			NanReturnValue(NanNew<v8::String>(pName));
			break;
		case 3:
			id = SUSI_ID_HWM_CURRENT_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiBoardGetString(Current) failed"));
			else
    			NanReturnValue(NanNew<v8::String>(pName));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(getVgaBacklight) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));

    SusiId_t id;
    uint32_t getVal;
	int type = 0;

	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		id = args[0]->Uint32Value();
		type = args[1]->Uint32Value();
	}

	switch (type)
	{
		case 0:
			if (SusiVgaGetBacklightEnable(id, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaGetBacklightEnable failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		case 1:
			if (SusiVgaGetBacklightBrightness(id, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaGetBacklightBrightness failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		case 2:
			if (SusiVgaGetFrequency(id, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaGetFrequency failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		case 3:
			if (SusiVgaGetPolarity(id, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaGetPolarity failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(setVgaBacklight) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));

    SusiId_t id;
	int type;
	int value;

	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		id = args[0]->Uint32Value();
		type = args[1]->Uint32Value();
		value = args[2]->Uint32Value();
	}

	switch (type)
	{
		case 0:
			if (SusiVgaSetBacklightEnable(id, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetBacklightEnable failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetBacklightEnable success"));
			break;
		case 1:
			if (SusiVgaSetBacklightBrightness(id, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetBacklightBrightness failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetBacklightBrightness success"));
			break;
		case 2:
			if (SusiVgaSetFrequency(id, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetFrequency failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetFrequency success"));
			break;
		case 3:
			if (SusiVgaSetPolarity(id, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetPolarity failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiVgaSetPolarity success"));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(getGPIO) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));

	int type = 0;
	int offset = 0;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		type = args[0]->Uint32Value();
		offset = args[1]->Uint32Value();
	}

    uint32_t getVal;
	SusiId_t id = SUSI_ID_GPIO(offset);

	switch (type)
	{
		case 0:
			if (SusiGPIOGetDirection(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiGPIOGetDirection failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		case 1:
			if (SusiGPIOGetLevel(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiGPIOGetLevel failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		case 2:
			if (SusiGPIOGetCaps(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiGPIOGetCaps failed"));
			else
    			NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(setGPIO) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));

	int type;
	int offset;
	int value;
	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		type = args[0]->Uint32Value();
		offset = args[1]->Uint32Value();
		value = args[2]->Uint32Value();
	}

	SusiId_t id = SUSI_ID_GPIO(offset);

	switch (type)
	{
		case 0:
			if (SusiGPIOSetDirection(id, 1, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiGPIOSetDirection failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiGPIOSetDirection success"));
			break;
		case 1:
			if (SusiGPIOSetLevel(id, 1, value) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiGPIOSetLevel failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiGPIOSetLevel success"));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(getWatchDog) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id;
	int type;
	uint32_t getVal;

	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		id = args[0]->Uint32Value();
		type = args[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			if (SusiWDogGetCaps(id, SUSI_ID_WDT_SUPPORT_FLAGS, &getVal) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiWDogGetCaps failed"));
			else
    		NanReturnValue(NanNew<v8::Number>((int32_t)getVal));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(setWatchDog) {
    NanScope();
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		NanReturnValue(NanNew<v8::String>("SusiLibInitialize() failed"));
	
    SusiId_t id;
	int delaytime, resettime, eventtype, eventtime, control;

	if (args.Length() < 1)
		NanReturnValue(NanNew<v8::String>("args.Length() < 1"));
	else
	{
		id = args[0]->Uint32Value();
		delaytime = args[1]->Uint32Value();
		resettime = args[2]->Uint32Value();
		eventtype = args[3]->Uint32Value();
		eventtime = args[4]->Uint32Value();
		control = args[5]->Uint32Value();
	}
	
	switch (control)
	{
		case 0:
			if (SusiWDogStart(id, delaytime, eventtime, resettime, eventtype) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiWDogStart failed"));
			else
    		NanReturnValue(NanNew<v8::String>("SusiWDogStart success"));
			break;
		case 1:
			if (SusiWDogTrigger(id) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiWDogTrigger failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiWDogTrigger success"));
			break;
		case 2:
			if (SusiWDogStop(id) != SUSI_STATUS_SUCCESS)
    			NanReturnValue(NanNew<v8::String>("SusiWDogStop failed"));
			else
    			NanReturnValue(NanNew<v8::String>("SusiWDogStop success"));
			break;
		default:
			NanReturnValue(NanNew<v8::String>("Not support"));
			break;
	}
}

NAN_METHOD(aString) {
    NanScope();
    NanReturnValue(NanNew<v8::String>("This is a thing."));
}

