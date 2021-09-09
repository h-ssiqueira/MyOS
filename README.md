# MyOS
![GitHub Repository Size](https://img.shields.io/github/repo-size/h-ssiqueira/MyOS?label=Repository%20Size&style=flat-square)
![Lines of code](https://img.shields.io/tokei/lines/github/h-ssiqueira/MyOS?label=Total%20Lines)

![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)

![Visual Studio Code](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

# Summary
* [How to execute](#How-to-execute)
* [Commands](#Commands)
    * [Color table](#Color-table)
* [References](#References)
## How to execute
This OS need to be compiled in a Linux/Mac distribution. If you are on Windows just use the `myos.iso` file in a virtual machine.

First install the required programs using `make install` on terminal.

Then compile the entire Operating System using `make`. After compiling, the OS will start in qemu program.

## Commands
Command | Description
:---: | :---:
`fgcolor -hexcolor`| Changes the foreground color of screen. Only one hexadecimal character is acceptec to change the color. Default: Light_Grey.
`bgcolor -hexcolor`| Changes the background color of screen. Only one hexadecimal character is accepted to change the color. Default: Black.
`clear`| Clears the screen.
`info`| Shows the information about the developer and the version of OS.
`reboot`| Restart the OS.

### Color table
Avaliable colors to change the foreground and background:

Color | Code
:---: | :---:
Black | 0 <br> black
Blue | 1 <br> blue
Green | 2 <br> green
Cyan | 3 <br> cyan
Red | 4 <br> red
Magenta | 5 <br> magenta
Brown | 6 <br> brown
Light Grey | 7 <br> light grey
Dark Grey | 8 <br> dark grey
Light Blue | 9 <br> light blue
Light Green | A <br> a <br> light green
Light Cyan | B <br> b <br> light cyan
Light Red | C <br> c <br> light red
Light Magenta | D <br> d <br> light magenta
Light Brown | E <br> e <br> light brown
White | F <br> f <br> white

## References
* [OsDev](https://wiki.osdev.org/)