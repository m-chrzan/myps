#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("%u\n", getpid());
    int rv = myps(0);

    if (rv != 0) {
        printf("%s\n", strerror(errno));
    }

    return rv;
}
