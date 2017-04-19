# myps system call

A new MINIX system call that prints information about processes being run.

## Installation

Run `myps.sh`. This will copy the necessary files into the correct
subdirectories of `/usr` and recompile the kernel. Reboot to make use of the new
system call and its library function.

## myps

    #include <unistd.h>

    int myps(int uid)

### Description

`myps()` prints information about the currently running processes owned a
specific user. Specifically, the processes' PID, PPID, and UID will
be printed (similar to `ps lx`).

### Input

`uid` is the UID of the user whose processes are to be considered. A `uid` of 0
will print information about the processes of the current user, rather than
`root`'s (unless the current user *is* `root`). A negative `uid` is considered
invalid input.


### Return Value

0 on success, -1 on error. `errno` will be set appropriately on error.
