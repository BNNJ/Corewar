# Corewar

A compiler and virtual machine for a custom implementation of [Core War](https://en.wikipedia.org/wiki/Core_War)

## authors

asm (compiler): amanuel (Aurelien Manuel)\
corewar (vm): agesp (Artiom Gesp), pfragnou (Pascal Fragnoud)

## what is Core War ?

The original [Core War](https://en.wikipedia.org/wiki/Core_War) is a programming game in which two or more programs fight each other for the control of a machine.\
Those programs are written in an abstract assembly language called redcode, with very basic instructions.

In our version, the assembly code is slightly different and even more limited.

## compiler

The compiler takes a champion file, written in a simplified assembly language, as argument, and translates it to bytecode.\
input: .s file\
output: .cor file

## compiler usage

\> ./asm \<champion.s\>

## virtual machine

To make it as simple as possible:\
The virtual machine has an arena, which is a circular memory area of 4096 bytes.\
The competing programs (champions) are loaded into this arena, equally spaced.\
An initial process is created for each champion, with its own 16 registers and PC (program counter: a special register that stores the address of the byte the process is currently at). Additional processes can later be created by the fork instruction\
The virtual machine then runs each process, which means it reads the byte pointed at by the PC, executes the instruction if possible, then advances the PC.

Periodically, a check is made to see if the processes executed a live instruction. Those which have not are killed (regardless of which champion was declared alive).\ 
The game stops when no process remains, and the last player/champion to be declared alive wins.

## vm usage

\> ./corewar [options] \<champion1.cor\> \<champion2.cor\> [additional champions]

|option|effect|
|-|-|
|-h --help| display help|
|-g --debug| display debug informations|
|-v --viewer| graphic mode (in terminal, uses ncurses)|
|-d X --dump X| stop the execution and dump the memory after X cycles. Can be combined with -v to pause the viewer after X cycles.|
|-n X| assigns number X to the next champion|
|-c| display champions comments|

|viewer controls|effect|
|---------------|------|
|space| pause/run|
|d/e| increase/decrease execution speed|
|1/2/3| predefined speed modes (1: slower, 3: faster)|
|q| quit|

Note: For the viewer to work, the terminal window must be big enough to display it.\
If it's not, an error message is sent to the standard output, and the program exits

example:\
\> ./corewar -vd 56 ressources/champs/champion1 ressources/champs/champion2\
Runs a fight between champion1 and champion2, in viewer mode, and pauses after 56 cycles. 

## todo

Ask aurelien to complete the compiler doc.
