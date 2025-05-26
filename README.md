OsDev Project
📖 Description
OsDev is a hobbyist operating system developed from scratch, primarily for learning and experimentation with low-level systems programming. The project aims to create a minimal 32-bit kernel that can boot, handle basic hardware interrupts, and gradually introduce more advanced OS features. Its philosophy is to provide hands-on experience with OS development, from bootloader to kernel and hardware interaction.

🌟 Current Status
Boots into protected mode using a custom bootloader.
Initializes Global Descriptor Table (GDT) and Interrupt Descriptor Table (IDT).
Handles keyboard interrupts and displays typed characters.
Supports VGA text mode output for basic screen interaction.
Source code is organized into C and Assembly for clarity and modularity.
✨ Features
Implemented
Bootloader (Custom, MBR-based)
Protected Mode Switching
GDT and IDT Setup
PS/2 Keyboard Driver
VGA Text Mode Output
Planned
Simple Memory Management (Paging)
Basic Filesystem Support
User Mode Functionality
🛠️ Tech Stack & Tools
Languages: Assembly (NASM/YASM), C
Build System: Make, custom scripts
Emulator/Testing: QEMU, Bochs, VirtualBox
Debugger: GDB
Target Architecture: x86 (32-bit)
⚙️ Prerequisites
You will need the following tools installed to build and run OsDev:

make
gcc (or i686-elf-gcc cross-compiler)
nasm or yasm
qemu
🚀 Building and Running
1. Clone the Repository
bash
git clone https://github.com/MehmetTektek/OsDev.git
cd OsDev
2. Build the OS
bash
make
3. Run in QEMU
Use the provided script:
bash
./run.sh
Alternatively, you can run QEMU directly with the built floppy image:
bash
qemu-system-i386 -fda build/main_floppy.img
📂 Project Structure
Code
.
├── src/            # Source code
│   ├── bootloader/   # Bootloader assembly code
│   └── kernel/       # Kernel assembly code
├── tools/          # Host-side tools (e.g., FAT utility)
│   └── fat/
│       └── fat.c
├── build/          # Build artifacts (binaries, floppy image)
├── Makefile        # Build instructions
├── run.sh          # Script to run the OS in QEMU
├── bochs_config    # Configuration file for Bochs emulator
└── README.md       # Project documentation
🤝 Contributing
Contributions and suggestions are welcome! Open an issue or submit a pull request if you want to help improve the project.

📝 License
This project is licensed under the MIT License. See LICENSE for details.