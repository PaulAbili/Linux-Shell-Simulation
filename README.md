# C Shell

### Contact

**Author:** Paul Abili <br>
**Campus ID:** QD36016 <br>
**Email:** pabili1@umbc.edu <br>

### Overview

Created a simple c shell. Used the fork() and exec() family of functions the file .421sh is stored within the main directory

### Installation and Setup
#### Libraries used:

#include <stdio.h><br>
#include <stdlib.h><br>
#include <string.h><br>
#include <unistd.h><br>
#include <sys/wait.h><br>
#include <ctype.h><br>
#include "utils.h"<br>

### Build and Compile

Build & run this program with: make run<br>

NOTE<br>

Only cat /proc/... is supported<br>
not /proc/... <br>
Additionally no spaces <br>

### User-Space Drivers

Driver used: [main.c](main.c) <br>
This is the only file used in this program, this is the renamed template file <br>

### Testing

<p>I tested common linux commands in the my shell and compared the answer to the actual command within the vm<br>
Ex. ls, ls -la, pwd, nano main.c, etc.<br>
Also non commands ex: 1, 2, 3, 4, 5, 6, 7, aa, papas, etc.</p>

### Troubleshooting

<p> It was super difficult to read the linux manual, so using getline was a lot more difficult than it should have been. <br>

It found it difficult to anticipate how large I should make the ** (when I started it was a *[] but that soon changed) <br>

Note on parsing, I initially started using strncpy() and strcpy(), however when it looped the second time, weird stuff started happening to the memory. Eventually after fine tuning my indexes and numbers with my algorithm, I attempted to use memcpy() and it finally worked. <br>

Because of the issues with parsing (the mem issues within the ** was not always apparent) <br>
It took a really long time to understand how the exec family of functions worked. <br>
Additionally, when looking at the example output for the parse_command method: ["ls", "-la", NULL]. <br>

This also added to the time it took to figure out the exec() family of functions <br>

Finally implementing the history command was difficult <br>
For some reason, my program would write to the files super oddly <br>
I ended up running the -tail command using exec to circumvent this odd issue</p>

### References
#### External Sources

<p>I spent a lot of time googling answers for questions so it would be impossible to list every source I visited
The main source: geeksforgeeks.org // It was so much easier to understand how these functions worked from this page rather than reading the c documentation, often those documentations pages were super long and didn’t have a lot of examples(if any)
I looked at a lot of pages: strlen, strcpy, strncpy, file handling, exec family of functions,fprint, fgets, fputs and fputc, sprintf, fseek, differences between a, a+, w, w+, r, r+, how to read line by line in , exit abort and assert functions, isspace in c, memcpy, pointer to pointer, fork, c arrays, making your own linux shell, c arrays, wait system call in c, realloc, strcat, null pointer in c, git diff, derefence pointer in c </p>

#### Videos

https://www.youtube.com/watch?v=HEEzZ7fA9Oo&t=243s
https://www.youtube.com/watch?v=HqADRbshBF4
https://www.youtube.com/watch?v=Lx5r2XQvpVA
https://www.youtube.com/watch?v=2ybLD6_2gKM
https://www.youtube.com/watch?v=cex9XrZCU14&t=1s
https://www.youtube.com/watch?v=tcYo6hipaSA
https://www.youtube.com/watch?v=OVFEWSP7n8c
https://www.youtube.com/watch?v=uh2FqejQRk8

