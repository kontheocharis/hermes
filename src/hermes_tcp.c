#include "../include/hermes_tcp.h"
#include "tun.h"

char *herm_get_tun_name()
{
    struct tun *t = tun_new();
    return tun_name(t);
}
