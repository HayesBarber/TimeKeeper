# TimeKeeper

TimeKeeper is a simple Arduino library for tracking epoch time in seconds and formatting it as a 12-hour clock string. It supports setting the current time from a C-string, unsigned long, or Arduino String, and provides a utility to determine if a given time is considered night (11:00 PM to 8:00 AM).

## Usage Example

```cpp
#include <TimeKeeper.h>

TimeKeeper tk;

void setup() {
  Serial.begin(9600);

  // Set epoch time in seconds
  tk.setEpochSeconds("1692000000");

  // Optionally, you can also set using unsigned long
  // tk.setEpochSeconds(1692000000);

  // Or using a String
  // tk.setEpochSeconds(String("1692000000"));
}

void loop() {
  String time = tk.getTime12Hour();
  Serial.println(time);

  if (TimeKeeper::isNight(time)) {
    Serial.println("It's night!");
  } else {
    Serial.println("It's day!");
  }

  delay(1000);
}
```
