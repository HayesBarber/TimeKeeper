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

String TimeKeeper::getTime12Hour() {
  String period = "AM";
  unsigned long epoch = getEpochSeconds();
  int hours = ((epoch % 86400) / 3600);
  int minutes = ((epoch % 3600) / 60);
  int hour12 = hours;

  if (hours == 0) {
    hour12 = 12;
  } else if (hours == 12) {
    period = "PM";
  } else if (hours > 12) {
    hour12 = hours - 12;
    period = "PM";
  }

  String formattedTime =
      String(hour12) + ":" +
      (minutes < 10 ? "0" + String(minutes) : String(minutes)) + " " + period;

  return formattedTime;
}
