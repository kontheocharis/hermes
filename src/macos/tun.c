#include "../tun.h"
#include <stdlib.h>

struct tun
{
    char *name;
};

struct tun *tun_new()
{
    struct tun *t = malloc(sizeof(struct tun));
    t->name = "tun0";
    return t;
}

char *tun_name(struct tun const *t)
{
    return t->name;
}

int *tun_recv(struct tun const *t, void *buffer, size_t n)
{
    return 0;
}

int *tun_send(struct tun const *t, void const *buffer, size_t n)
{
    return 0;
}
