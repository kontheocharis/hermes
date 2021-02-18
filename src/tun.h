#pragma once
#include <netinet/in.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Allocate a new tunnel bound at the given range of IPs..
 *
 * @param addr - The IP address to bind the tunnel to.
 * @param addr - A mask for the IP address.
 * @returns - A file descriptor of the allocated tunnel, or negative in case of error.
 */
int tun_open(struct in6_addr *addr, struct in6_addr *mask);
