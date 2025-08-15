#pragma once

#include <Arduino.h>

/**
 * @class TimeKeeper
 * @brief A simple Arduino class to track epoch time in seconds and format time.
 *
 * Supports setting the current epoch time via different input types and
 * retrieving the time in seconds or as a 12-hour formatted string.
 */
class TimeKeeper {
public:
  /**
   * @brief Construct a new TimeKeeper instance.
   */
  TimeKeeper();

  /**
   * @brief Set the epoch time in seconds from a C-style string.
   * @param epochTimeSeconds Null-terminated string representing seconds since
   * Unix epoch.
   */
  void setEpochSeconds(const char *epochTimeSeconds);

  /**
   * @brief Set the epoch time in seconds from an unsigned long.
   * @param epochTimeSeconds Epoch time in seconds.
   */
  void setEpochSeconds(const unsigned long epochTimeSeconds);

  /**
   * @brief Set the epoch time in seconds from an Arduino String.
   * @param epochTimeSeconds Epoch time as a String.
   */
  void setEpochSeconds(const String epochTimeSeconds);

  /**
   * @brief Get the current epoch time in seconds.
   * @return Current epoch time in seconds.
   */
  unsigned long getEpochSeconds();

  /**
   * @brief Get the current time formatted as 12-hour string with AM/PM.
   * @return String formatted as "HH:MM AM/PM".
   */
  String getTime12Hour();

  /**
   * @brief Determine if the given 12-hour formatted time string is considered
   * night. Nighttime is defined as between 11:00 PM and 6:45 AM.
   * @param currentTime String in the format "HH:MM AM/PM".
   * @return true if night, false otherwise.
   */
  static bool isNight(String &currentTime);

private:
  unsigned long _epochSeconds;
  unsigned long _lastUpdateMillis;
};
