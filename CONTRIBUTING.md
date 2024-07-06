# Contributing
- Interestingly, the initial commit of this repo didn't even have consistency between tabs and spaces LOL -- so here's a quick dump of what I've been doing. - Josh :)
- Of course, this document is subject to change :P It's also horribly ill-defined but who cares
- By the way, consider viewing this in a Markdown renderer.

## Formatting
- Simply put: use Tab size 4, and if in VSCode, use the default formatter: `"C_Cpp.formatting": "default"`. This runs clang-format.
> `default`: By default, `clang-format` will be used to format the code. However, the Visual C++ formatting engine will be used if an `.editorconfig` file with relevant settings is found nearer to the code being formatted and `#C_Cpp.clang_format_style#` is the default value: `file`.

- Sorry about the Allman braces
```c
for (int i = 10; i > 0; i--)
{
    
}
```

## Documentation
- Doxygen docs should be written in .h files. Your editor probably has a tool for it...

## Note about header files
- Use #pragma once to guard against multiple inclusion.
  - It is not 1992. Don't use an #ifdef guard. LOL

## C structs and functions:
- Define the struct in the corresponding .h file:
```c
typedef struct Wheel
{
    int diameter;
    int width;
} Wheel;
```
- Define functions that take in pointers, similar to Python's `self`
```c
void initWheel(Wheel* wheel, int diameter, int width);
void spin(Wheel* wheel); // runs an animation or something... lol

// example usage, even though this is a sort of redundant function:
Wheel w;
initWheel(&w, 10, 3);
spin(&wheel);
```

## Global variables
- Little bit complicated here :C
  - This is due to "link-time shenanigans", as Arian likes to call it.
  - The entry point for a PROS 2.x program isn't visible to the user, so you have to use global variables.
  - This is one of many correct ways of writing it -- in theory, you could hardcore the definition into `drivetrain.c` in this example.
1. **Declare** your variable in one spot -- likely `init.c`:
```c
#include "subsystems/drivetrain.h"
Drivetrain drivetrain;
```
2. **Initialize** it in `init.c`:
```c
initDrivetrain(&drivetrain, [your params...]);
// or just use the raw struct fields when appropriate
```
3. **Refer** to it with `extern` in other files, such as `auto.c` and `opcontrol.c`:
```c
extern Drivetrain drivetrain;
```