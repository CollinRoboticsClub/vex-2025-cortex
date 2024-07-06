# Contributing
- Of course, this document is subject to change :P

## Formatting
- Use clang-format.

## Note about header files
- Use #pragma once to guard against multiple inclusion.

## Global variables
- Little bit complicated here :C
  - This is due to "link-time shenanigans", as Arian likes to call it.
  - The entry point for a PROS 2.x program isn't visible to the user, so you have to use global variables.
1. **Declare** your variable in one spot -- likely `init.cpp`:
```c
#include "subsystems/drivetrain.hpp"
Drivetrain drivetrain(MOTOR_PIN, [params here...]);
```
2. **Refer** to it with `extern` in other files, such as `auto.cpp` and `opcontrol.cpp`:
```c
extern Drivetrain drivetrain;
void autonomous()
{
  // drivetrain is now visible in this file's scope!
  drivetrain.arcadeDrive(127, 0);
}
```