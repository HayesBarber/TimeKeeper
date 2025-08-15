# TimeKeeper

TimeKeeper is a simple Arduino library for tracking epoch time in seconds and formatting it as a 12-hour clock string. It supports setting the current time from a C-string, unsigned long, or Arduino String.

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
  delay(1000);
}
```
