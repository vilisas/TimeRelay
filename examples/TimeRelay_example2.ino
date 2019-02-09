#include "Arduino.h"
#include <TimeRelay.h>

/**
 * TimeRelay() demo
 * if relay is in off state - turns it on. Relay turns off automatically after 3 seconds.
 * Using LED as demo.
 */

TimeRelay relay(13);

uint32_t time1 = 0;

//The setup function is called once at startup of the sketch
void setup()
{
//  sets to output
	relay.setup();
	relay.setHoldTime(3);
	relay.setInverted(false);


}

// The loop function is called in an endless loop
void loop()
{
	relay.loop();

	if (millis() - time1 > 1000){
		if (!relay.isOn()){
			relay.turnOn();
		}
		time1 = millis();
	}

}
