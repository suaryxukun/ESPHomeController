#ifndef RelayController_h
#define RelayController_h
#include <Arduino.h>
#include <ArduinoJson.h>
#include "BaseController.h"


struct RelayState
{
	bool isOn;
};
enum RelayCMD {
	RelayOn=1,
	RelayOff=2,
	Switch=4,
	Set=8,
	RelayRestore = 2048
};
class RelayController;
typedef CController<RelayController, RelayState, RelayCMD> Relay;
class RelayController: public Relay
{
	virtual String  serializestate();
	virtual bool  deserializestate(String jsonstate);
	virtual void setup();
	void loadconfig(JsonObject& json);
	virtual void run();
	virtual void set_state(RelayState state);
	virtual bool onpublishmqtt(String& endkey, String& payload);
	virtual void onmqqtmessage(String topic, String payload);
protected:
	uint pin;
};


#endif