/*
 * TimeRelay.h
 *
 *  Created on: 2019 m. Vasario 09 d.
 *      Author: Vilius Bilinkevicius
 *
 */

#ifndef TIMERELAY_H_
#define TIMERELAY_H_

#include <Arduino.h>

// process relay state if time since last check is greater than milliseconds below
#define TIMERELAY_CHECK_INTERVAL 100

class TimeRelay{

	private:
	uint8_t _output_pin;
	uint16_t _relay_hold_time	= 0;
	unsigned long _loop_call_time = 0;
	unsigned long _fix_start_time = 0;


    bool _inverted		= false;
    bool _relay_state	= false;

    public:
	TimeRelay(uint8_t input);
	TimeRelay::TimeRelay(uint8_t output, bool state);
	virtual ~TimeRelay(){}
	void setup();
	void loop();

	bool isOn();
	void turnOn();
	void turnOff();

	inline uint8_t geHoldTime() const {
		return _relay_hold_time;
	}

	// set relay hold time in seconds, set to 0 if it's just on/off
	inline void setHoldTime(uint16_t seconds) {
		_relay_hold_time = seconds;
	}

	inline bool isInverted() const {
		return _inverted;
	}
	inline void setInverted(bool inverted) {		// Invert output value
		_inverted = inverted;
		_relay_state = inverted;
	}

	inline uint8_t getOutputPin() const {			//returns relay pin
		return _output_pin;
	}
	inline void setOutputPin(uint8_t outputPin) {	// sets relay pin
		_output_pin = outputPin;
	}

};

#endif
