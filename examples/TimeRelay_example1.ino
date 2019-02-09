#include "Arduino.h"
#include <TimeRelay.h>

/**
 * TimeRelay() demo
 * turns relay on or off manually
 */

TimeRelay relay(13);

uint32_t time1 = 0;

//The setup function is called once at startup of the sketch
void setup()
{
//  sets to output
	relay.setup();
	relay.setHoldTime(0);
	relay.setInverted(false);


}

// The loop function is called in an endless loop
void loop()
{
	relay.loop();

	if (millis() - time1 > 1000){
		if (relay.isOn()){
			relay.turnOff();
		} else{
			relay.turnOn();
		}
		time1 = millis();
	}

}
