#pragma once

class TimeKeeper {
public:
  TimeKeeper();
  void setEpochTime(String epochTime);
  unsigned long getEpochTime();

private:
  unsigned long _epochTime;
  unsigned long _lastUpdate;
};
