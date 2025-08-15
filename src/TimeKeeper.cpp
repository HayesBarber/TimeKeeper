#include "TimeKeeper.h"

TimeKeeper::TimeKeeper() : _lastUpdateMillis(0), _epochSeconds(0) {}

void TimeKeeper::setEpochSeconds(const char *epochTimeSeconds) {
  if (epochTimeSeconds == nullptr || epochTimeSeconds[0] == '\0') {
    return;
  }

  _epochSeconds = strtoul(epochTimeSeconds, nullptr, 10);
  _lastUpdateMillis = millis();
}

void TimeKeeper::setEpochSeconds(const unsigned long epochTimeSeconds) {
  _epochSeconds = epochTimeSeconds;
  _lastUpdateMillis = millis();
}

void TimeKeeper::setEpochSeconds(const String epochTimeSeconds) {
  if (epochTimeSeconds.length() == 0) {
    return;
  }

  _epochSeconds = epochTimeSeconds.toInt();
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
  int hours = (epoch % 86400) / 3600;
  int minutes = (epoch % 3600) / 60;
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

bool TimeKeeper::isNight(String &currentTime) {
  if (currentTime.length() == 0) {
    return false;
  }

  int hour = currentTime.substring(0, currentTime.indexOf(':')).toInt();
  int minute =
      currentTime
          .substring(currentTime.indexOf(':') + 1, currentTime.indexOf(' '))
          .toInt();
  String period = currentTime.substring(currentTime.indexOf(' ') + 1);

  if (period == "PM" && hour == 11) {
    return true;
  } else if (period == "AM") {
    if (hour < 7 || (hour == 6 && minute < 45)) {
      return true;
    }
  }

  return false;
}
