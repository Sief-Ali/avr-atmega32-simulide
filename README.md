# AVR ATmega32 Minimal Starter

This is a minimal starter for ATmega32 using `avr-gcc` and CMake.
`src/main.c` is a simple blink program using `<avr/io.h>`.

## Requirements

- `avr-gcc`
- `avr-binutils` (for `avr-objcopy`, `avr-size`)
- `avr-libc`
- `cmake` (3.16+)
- `make`

## Build

```bash
cmake -S . -B build
cmake --build build
```

Build outputs:
- `build/src/avr-atmega32-simulide.elf`
- `build/src/avr-atmega32-simulide.hex`

## Editor / IntelliSense fix

If `<avr/io.h>` still shows red in the editor:

1. Run one build (`cmake -S . -B build && cmake --build build`)
2. In Cursor/VS Code, run command: `C/C++: Reset IntelliSense Database`
3. Reopen `src/main.c`

## Flash (example)

```bash
avrdude -c usbasp -p m32 -U flash:w:build/src/avr-atmega32-simulide.hex:i
```

Adjust programmer (`-c`) and MCU (`-p`) as needed for your setup.
