#include "../include/hermes_tcp.h"
#include "tun.h"
#include "log.h"
#include <unistd.h>
#include <ifaddrs.h>
#include <stdlib.h>
#include <string.h>

char *herm_get_tun_name()
{
    int fd = tun_open(NULL, NULL);
    system("ifconfig utun2 inet 10.0.0.0 10.0.0.0");
    if (fd == -1) {
        return "Bad";
    }

    char buf[4096];
    while (1) {
        read(fd, buf, sizeof(buf));
        log_info("%s", buf);
        memset(buf, 0, sizeof(buf));
        sleep(1);
    }

    close(fd);
    return "Hello, world!";
}
