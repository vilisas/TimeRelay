
# TimeRelay is relay control class for Arduino

Relay can be set to manual or automatic operation. Relay state can be inverted.

* Mode 1 - manually turn relay on or off
* Mode 2 - turn relay on and it automatically switches off after predefined time


to use it:

```
#include <TimeRelay.h>

TimeRelay relay(13);

setup() {
    relay.setup();		// sets pin to output
    relay.setHoldTime(5);
}

loop(){
    relay.loop();
    if ( sometrigger ){
	relay.turnOn();
    }
}

```

See examples folder for more

