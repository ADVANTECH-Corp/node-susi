#include <nan.h>
#include "node-SUSI.h"
#include "Susi4.h"

NAN_METHOD(getHardwareMonitor) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
	
    SusiId_t id;
    uint32_t getVal;

	int offset = 0;
	int type = 0;
	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		type = info[0]->Uint32Value();
		offset = info[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			id = SUSI_ID_HWM_TEMP_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetValue(Temperature) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>(SUSI_DECODE_CELCIUS((float)getVal)));
			break;
		case 1:
			id = SUSI_ID_HWM_FAN_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetValue(Fan) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((float)getVal));
			break;
		case 2:
			id = SUSI_ID_HWM_VOLTAGE_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetValue(Voltage) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal / (float)1000));
			break;
		case 3:
			id = SUSI_ID_HWM_CURRENT_BASE;
			if (SusiBoardGetValue(id + offset, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetValue(Current) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal / (float)1000));
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(getHardwareMonitorString) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
	
    SusiId_t id;
    uint32_t tmplength = 32;

	int offset = 0;
	int type = 0;
	char pName[32];
	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		type = info[0]->Uint32Value();
		offset = info[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			id = SUSI_ID_HWM_TEMP_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetString(Temperature) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>(pName).ToLocalChecked());
			break;
		case 1:
			id = SUSI_ID_HWM_FAN_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetString(Fan) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>(pName).ToLocalChecked());
			break;
		case 2:
			id = SUSI_ID_HWM_VOLTAGE_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetString(Voltage) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>(pName).ToLocalChecked());
			break;
		case 3:
			id = SUSI_ID_HWM_CURRENT_BASE + offset;
			if (SusiBoardGetStringA(SUSI_ID_MAPPING_GET_NAME_HWM(id), pName, &tmplength) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiBoardGetString(Current) failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>(pName).ToLocalChecked());
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(getVgaBacklight) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());

    SusiId_t id;
    uint32_t getVal;
	int type = 0;

	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		id = info[0]->Uint32Value();
		type = info[1]->Uint32Value();
	}

	switch (type)
	{
		case 0:
			if (SusiVgaGetBacklightEnable(id, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaGetBacklightEnable failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		case 1:
			if (SusiVgaGetBacklightBrightness(id, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaGetBacklightBrightness failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		case 2:
			if (SusiVgaGetFrequency(id, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaGetFrequency failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		case 3:
			if (SusiVgaGetPolarity(id, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaGetPolarity failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(setVgaBacklight) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());

    SusiId_t id;
	int type;
	int value;

	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		id = info[0]->Uint32Value();
		type = info[1]->Uint32Value();
		value = info[2]->Uint32Value();
	}

	switch (type)
	{
		case 0:
			if (SusiVgaSetBacklightEnable(id, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetBacklightEnable failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetBacklightEnable success").ToLocalChecked());
			break;
		case 1:
			if (SusiVgaSetBacklightBrightness(id, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetBacklightBrightness failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetBacklightBrightness success").ToLocalChecked());
			break;
		case 2:
			if (SusiVgaSetFrequency(id, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetFrequency failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetFrequency success").ToLocalChecked());
			break;
		case 3:
			if (SusiVgaSetPolarity(id, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetPolarity failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiVgaSetPolarity success").ToLocalChecked());
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(getGPIO) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());

	int type = 0;
	int offset = 0;
	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		type = info[0]->Uint32Value();
		offset = info[1]->Uint32Value();
	}

    uint32_t getVal;
	SusiId_t id = SUSI_ID_GPIO(offset);

	switch (type)
	{
		case 0:
			if (SusiGPIOGetDirection(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOGetDirection failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		case 1:
			if (SusiGPIOGetLevel(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOGetLevel failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		case 2:
			if (SusiGPIOGetCaps(id, 1, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOGetCaps failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(setGPIO) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());

	int type;
	int offset;
	int value;
	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		type = info[0]->Uint32Value();
		offset = info[1]->Uint32Value();
		value = info[2]->Uint32Value();
	}

	SusiId_t id = SUSI_ID_GPIO(offset);

	switch (type)
	{
		case 0:
			if (SusiGPIOSetDirection(id, 1, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOSetDirection failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOSetDirection success").ToLocalChecked());
			break;
		case 1:
			if (SusiGPIOSetLevel(id, 1, value) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOSetLevel failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiGPIOSetLevel success").ToLocalChecked());
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(getWatchDog) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
	
    SusiId_t id;
	int type;
	uint32_t getVal;

	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		id = info[0]->Uint32Value();
		type = info[1]->Uint32Value();
	}
	
	switch (type)
	{
		case 0:
			if (SusiWDogGetCaps(id, SUSI_ID_WDT_SUPPORT_FLAGS, &getVal) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogGetCaps failed").ToLocalChecked());
			else
    		info.GetReturnValue().Set(Nan::New<v8::Number>((int32_t)getVal));
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(setWatchDog) {
    Nan::HandleScope scope;
	if (SusiLibInitialize() != SUSI_STATUS_SUCCESS)
		info.GetReturnValue().Set(Nan::New<v8::String>("SusiLibInitialize() failed").ToLocalChecked());
	
    SusiId_t id;
	int delaytime, resettime, eventtype, eventtime, control;

	if (info.Length() < 1)
		info.GetReturnValue().Set(Nan::New<v8::String>("info.Length() < 1").ToLocalChecked());
	else
	{
		id = info[0]->Uint32Value();
		delaytime = info[1]->Uint32Value();
		resettime = info[2]->Uint32Value();
		eventtype = info[3]->Uint32Value();
		eventtime = info[4]->Uint32Value();
		control = info[5]->Uint32Value();
	}
	
	switch (control)
	{
		case 0:
			if (SusiWDogStart(id, delaytime, eventtime, resettime, eventtype) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogStart failed").ToLocalChecked());
			else
    		info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogStart success").ToLocalChecked());
			break;
		case 1:
			if (SusiWDogTrigger(id) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogTrigger failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogTrigger success").ToLocalChecked());
			break;
		case 2:
			if (SusiWDogStop(id) != SUSI_STATUS_SUCCESS)
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogStop failed").ToLocalChecked());
			else
    			info.GetReturnValue().Set(Nan::New<v8::String>("SusiWDogStop success").ToLocalChecked());
			break;
		default:
			info.GetReturnValue().Set(Nan::New<v8::String>("Not support").ToLocalChecked());
			break;
	}
}

NAN_METHOD(aString) {
    Nan::HandleScope scope;
    info.GetReturnValue().Set(Nan::New<v8::String>("This is a thing.").ToLocalChecked());
}

