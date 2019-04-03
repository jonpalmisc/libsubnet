/*
 * This file is part of libsubnet.
 * libsubnet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libsubnet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libsubnet.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file
 * @brief Subnet type and functions
 * @details This file contains the definition of the subnet type and its methods.
 */

#ifndef LIBSUBNET_SUBNET_H
#define LIBSUBNET_SUBNET_H

#include <stdint.h>

/** @struct subnet
 * @brief Represents a subnet.
 * @var subnet::addr
 * The subnet's base address
 * @var subnet::mask
 * The subnet's mask */
typedef struct {
  uint32_t addr;
  uint32_t mask;
} subnet;

/** @brief Constructs a new subnet object from a network address and a subnet mask. <b>Returns NULL if invalid input is
 * received!</b>
 * @param address The network address for the subnet
 * @param mask The mask for the subnet
 * @return A new subnet object with the given parameters */
subnet *subnet_new(char *address, char *mask);

/** @brief Constructs a new subnet object from a CIDR notation. <b>Returns NULL if invalid input is received!</b>
 * @param cidr The CIDR notation of the desired subnet
 * @return A new subnet object that can be represented by the given CIDR notation */
subnet *subnet_new_cidr(char *cidr);

/** @brief Returns the base address of a given subnet as a string in dot notation.
 * @return The base address as a string in dot notation */
char *subnet_addr(subnet *sn);

/** @brief Returns the subnet mask of a given subnet as a string in dot notation.
 * @return The subnet mask as a string in dot notation */
char *subnet_mask(subnet *sn);

/** @brief Returns the length of the subnet mask in bits.
 * @return The length of the subnet mask in bits */
int subnet_mask_length(subnet* sn);

/** @brief Returns the CIDR notation of a given subnet.
 * @return The CIDR notation of the subnet, including the base address. */
char *subnet_cidr(subnet *sn);

/** @brief Returns the number of hosts (addresses) contained within the subnet.
 * @return The number of hosts contained within the subnet */
int subnet_num_hosts(subnet *sn);

/** @brief Returns the number of usable hosts (addresses) contained within the subnet.
 * @return The number of usable hosts contained within the subnet */
int subnet_num_usable_hosts(subnet *sn);

/** @brief Returns the lowest-numbered host within the bounds of the subnet.
 * @return The lowest-numbered host within the bounds of the subnet */
char *subnet_min_host(subnet *sn);

/** @brief Returns the highest-numbered host within the bounds of the subnet.
 * @return The highest-numbered host within the bounds of the subnet */
char *subnet_max_host(subnet *sn);

/** @brief Gets the network address of a given subnet and returns it as a string in dot notation.
 * @return The network address of the subnet in dot notation */
char *subnet_network_addr(subnet *sn);

/** @brief Gets the broadcast address of a given subnet and returns it as a string in dot notation.
 * @return The broadcast address of the subnet in dot notation */
char *subnet_broadcast_addr(subnet *sn);

#endif // LIBSUBNET_SUBNET_H
