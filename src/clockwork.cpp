/*
 Clockwork
*/
#include "clockwork.h"

Clockwork::Clockwork(unsigned int ms) {
  _base = ms;
}

void Clockwork::start() {
  _last_start = micros();
}

bool Clockwork::stop() {
  _last_stop = micros();
  _tet = _last_stop - _last_start;
  micros_t time_to_wait = last_delay();
  
  if (time_to_wait < 0) {
    return false;
  }
  if (time_to_wait > 1000) {
    delay(time_to_wait / 1000);
  }
  delayMicroseconds(time_to_wait % 1000);
  return true;
}

