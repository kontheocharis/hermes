#include "../tun.h"
#include "../log.h"
#include <stdlib.h>
#include <net/if_utun.h>
#include <string.h>
#include <sys/ioctl.h> // ioctl
#include <sys/socket.h>
#include <sys/sys_domain.h>
#include <sys/kern_control.h> // struct socketaddr_ctl
#include <unistd.h>
#include <net/if.h>


int tun_open(struct in6_addr *addr, struct in6_addr *mask)
{
    // Open a datagram socket
    int fd = socket(PF_SYSTEM, SOCK_DGRAM, SYSPROTO_CONTROL);
    if (fd == -1) {
        log_error("Failed to open socket");
        return -1;
    }
    log_info("Successfully opened socket with fd=%i", fd);

    // Setup ctl_info for utun
    struct ctl_info utun_ctl_info;
    strlcpy(utun_ctl_info.ctl_name, UTUN_CONTROL_NAME, sizeof(utun_ctl_info.ctl_name));
    if (ioctl(fd, CTLIOCGINFO, &utun_ctl_info) == -1) {
        close(fd);
        log_error("Unexpected error from ioctl");
        return -1;
    }
    log_info("utun ctl info: ctl_id=%i, ctl_name=%s", utun_ctl_info.ctl_id, utun_ctl_info.ctl_name);

    // Create a sockaddr_ctl
    struct sockaddr_ctl sockaddr = {
        .sc_id = utun_ctl_info.ctl_id,
        .sc_len = sizeof(struct sockaddr_ctl),
        .sc_family = AF_SYSTEM,
        .ss_sysaddr = AF_SYS_CONTROL,
        .sc_unit = 0, // 0 means dynamically allocated, see https://developer.apple.com/forums/thread/85473.
    };
    if (connect(fd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
        close(fd);
        log_error("Could not connect to socket");
        return -1;
    }
    log_info("Successfully connected to socket with fd=%i", fd);

    // Get interface name
    char ifname[IFNAMSIZ];
    socklen_t ifname_len = IFNAMSIZ;
    if (getsockopt(fd, SYSPROTO_CONTROL, UTUN_OPT_IFNAME, ifname, &ifname_len) == -1) {
        close(fd);
        log_error("Could get utun interface name");
        return -1;
    }
    log_info("Interface name is %s", ifname);

    return fd;
}
