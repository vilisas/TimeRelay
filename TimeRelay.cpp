/*
 * TimeRelay.cpp
 *
 *  Created on: 2019 m. Vasario 09 d.
 *      Author: Vilius Bilinkevicius
 *
 */

#include <TimeRelay.h>

/*
 * Default constructor, takes arduino input PIN as parameter
 */
TimeRelay::TimeRelay(uint8_t output) {
	_output_pin		= output;
	_relay_state = false;
	_fix_start_time = 0;

}

TimeRelay::TimeRelay(uint8_t output, bool inverted) {
	_output_pin		= output;
	_inverted		= inverted;
	_relay_state 	= inverted;
	_fix_start_time = 0;
}


/**
 * sets pin mode to output
 */
void TimeRelay::setup() {
	if (_output_pin == 0) return;
	pinMode(_output_pin, OUTPUT);
}

/**
 * call this from your main loop
 */
void TimeRelay::loop() {

	unsigned long ms = millis();

	//	call only if start timer not zero and time since last call is > 100 ms
	if ((_relay_hold_time > 0) && (_fix_start_time > 0) && (ms - _loop_call_time >= TIMERELAY_CHECK_INTERVAL)) {
		if ((ms - _fix_start_time > _relay_hold_time * 1000) && (this->isOn())) {
			turnOff();
		}
		_loop_call_time = ms;
	}
}

/**
 * Turns relay on and starts timer
 * by default when output is LOW - state is ON
 */
void TimeRelay::turnOn(){
	_relay_state = !_inverted;
	_fix_start_time = millis();
	digitalWrite(_output_pin,_relay_state);
}

/**
 * Turns relay off and stops timer
 * by default when output is HIGH - state is OFF
 */
void TimeRelay::turnOff(){
	_relay_state = _inverted;
	_fix_start_time = 0;
	digitalWrite(_output_pin,_relay_state);
}

/**
 * returns LOGICAL relay state.
 * true - on, false - off
 */
bool TimeRelay::isOn(){
	return (_relay_state == !_inverted);
}

