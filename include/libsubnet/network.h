/**
 * @file
 * @brief General-purpose network related functions.
 * @details These functions are mostly used internally, but can be used as part of your code. However, it should be
 * noted that none of these functions check for invalid input, and you must do that on your own.
 */

#ifndef LIBSUBNET_NETWORK_H
#define LIBSUBNET_NETWORK_H

#include <stdint.h>

/** @brief Converts a network address/mask from dot notation into packed bytes. <b>Does not check for invalid input!</b>
 * @param s The address or mask to convert.
 * @return A byte-packed network address/mask. */
uint32_t dot2bin(char *s);

/** @brief Converts the binary/in-memory representation of network address or subnet mask into a dot notation string.
 * <b>Does not check for invalid input!</b>
 * @param i The address or mask to convert.
 * @return A dot-notation string. */
char *bin2dot(uint32_t i);

#endif // LIBSUBNET_NETWORK_H
