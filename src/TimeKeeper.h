#pragma once

#include <Arduino.h>

class TimeKeeper {
public:
  TimeKeeper();
  void setEpochSeconds(const char *epochTimeSeconds);
  unsigned long getEpochSeconds();
  String getTime12Hour();

private:
  unsigned long _epochSeconds;
  unsigned long _lastUpdateMillis;
};
