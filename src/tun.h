#pragma once
#include <stddef.h>
#include <stdint.h>

/**
 * Contains information about the network tunnel.
 */
struct tun;

/**
 * Allocate a new tunnel.
 *
 * @returns - The allocated tunnel.
 */
struct tun *tun_new();

/**
 * Get the name of the given tunnel.
 *
 * @param t - The tunnel.
 */
char *tun_name(struct tun const *t);

/**
 * Receive a packet from the given tunnel.
 *
 * Make sure that the provided buffer is large enough because the packet will
 * be truncated if its size exceeds n.
 *
 * @param t - The tunnel.
 * @param buffer - The buffer to store the received data in.
 * @param n - The size of the buffer, in bytes.
 * @returns - An error code, 0 for success, non-zero for failure.
 *
 * @Todo: better return code.
 */
int *tun_recv(struct tun const *t, void *buffer, size_t n);

/**
 * Send a packet to the given tunnel.
 *
 * @param t - The tunnel.
 * @param buffer - The buffer to read the packet data from.
 * @param n - The size of the buffer, in bytes.
 * @returns - An error code, 0 for success, non-zero for failure.
 *
 *  @Todo: better return code.
 */
int *tun_send(struct tun const *t, void const *buffer, size_t n);
