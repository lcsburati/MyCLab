# Build

## Dependencies

- **CMake** >= 3.10
- **Raylib** (installed on the system)
- C99 compiler (GCC, Clang)

## How to Compile

```bash
mkdir build && cd build
cmake ..
make
./main
```

## CMake Configuration

```
C Standard: C99
Flags: -Wall -D_DEFAULT_SOURCE -Wno-missing-braces
```

### Platform Linking

| Platform | Libraries |
|----------|-----------|
| macOS | CoreVideo, IOKit, Cocoa, GLUT, OpenGL, libm, pthread |
| Windows | opengl32, gdi32, winmm |
| Linux | raylib, m, pthread, dl |

## Resources

The build automatically copies the `resources/` folder to the build directory (required for the font.ttf file).

## Current Development Environment

- Apple Clang 17.0.0 (arm64)
- macOS Darwin 24.5.0
