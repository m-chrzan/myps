#include "pm.h"
#include "mproc.h"
#include <stdio.h>
#include <sys/types.h>
#include <minix/config.h>

int do_myps() {
    uid_t uid;
    int int_uid = m_in.m1_i1;

    if (int_uid < 0) {
        errno = EINVAL;
        return -1;
    } else if (int_uid == 0) {
        uid = mp->mp_realuid;
    } else {
        uid = (uid_t) int_uid;
    }

    printf("%4s %4s %4s\n", "PID", "PPID", "UID");
    for (int i = 0; i < NR_PROCS; i++) {
        if ((mproc[i].mp_flags & IN_USE) && mproc[i].mp_realuid == uid) {
            printf("%4u %4u %4u\n", mproc[i].mp_pid,
                mproc[mproc[i].mp_parent].mp_pid, mproc[i].mp_realuid);
        }
    }

    return OK;
}
