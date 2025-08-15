#include "TimeKeeper.h"

TimeKeeper::TimeKeeper() : _lastUpdateMillis(0), _epochSeconds(0) {}

void TimeKeeper::setEpochSeconds(const char *epochTimeSeconds) {
  if (epochTimeSeconds == nullptr || epochTimeSeconds[0] == '\0') {
    return;
  }

  _epochSeconds = strtoul(epochTimeSeconds, nullptr, 10);
  _lastUpdateMillis = millis();
}

unsigned long TimeKeeper::getEpochSeconds() {
  if (_lastUpdateMillis == 0)
    return 0;

  return _epochSeconds + ((millis() - _lastUpdateMillis) / 1000);
}
