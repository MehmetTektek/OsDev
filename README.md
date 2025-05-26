# OsDev

A hobby operating system.

## Building

To build the OS, run:

```sh
make
```

## Running

To run the OS in QEMU, use the provided script:

```sh
./run.sh
```

Or, you can run QEMU directly:

```sh
qemu-system-i386 -fda build/main_floppy.img
```

## Project Structure

```
.
├── Makefile        # Build instructions
├── README.md       # This file
├── run.sh          # Script to run the OS in QEMU
├── src/            # Source code
│   ├── bootloader/   # Bootloader code
│   └── kernel/       # Kernel code
├── build/          # Build artifacts
└── tools/          # Host-side tools
```