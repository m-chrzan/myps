#include <lib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <minix/rs.h>

int myps(int uid) {
    endpoint_t pm_ep;
    message m;

    if (minix_rs_lookup("pm", &pm_ep) != 0) {
        errno = ENOSYS;
        return -1;
    }

    return _syscall(pm_ep, PM_MYPS, &m);
}

