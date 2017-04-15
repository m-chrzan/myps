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

    return OK;
}
