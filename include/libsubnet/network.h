/**
 * @file
 * @details General-purpose network related functions.
 */

#ifndef LIBSUBNET_NETWORK_H
#define LIBSUBNET_NETWORK_H

#include <stdint.h>

/** @brief Converts a network address/mask from dot notation into packed bytes.
 * @param s The address or mask to convert.
 * @return A byte-packed network address/mask. */
uint32_t dot2bin(char *s);

/** @brief Converts the binary/in-memory representation of network address or subnet mask into a dot notation string.
 * @param i The address or mask to convert.
 * @return A dot-notation string. */
char *bin2dot(uint32_t i);

#endif // LIBSUBNET_NETWORK_H
