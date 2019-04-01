#include <libsubnet/subnet.h>
#include <libsubnet/network.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

subnet *subnet_new(char *address, char *mask) {
  uint32_t oct1a, oct2a, oct3a, oct4a, oct1m, oct2m, oct3m, oct4m;

  sscanf(address, "%u.%u.%u.%u", &oct1a, &oct2a, &oct3a, &oct4a);
  sscanf(address, "%u.%u.%u.%u", &oct1m, &oct2m, &oct3m, &oct4m);

  // Return a null pointer if the provided input was invalid.
  if (oct1a > 255 || oct2a > 255 || oct3a > 255 || oct4a > 255 || oct1m > 255 || oct2m > 255 || oct3m > 255 || oct4m > 255) {
    return NULL;
  }

  subnet *sn = (subnet *) malloc(sizeof(subnet));

  // Pack each octet together into one 32-bit integer.
  sn->addr = (oct1a << 24u) | (oct2a << 16u) | (oct3a << 8u) | oct4a;
  sn->mask = (oct1m << 24u) | (oct2m << 16u) | (oct3m << 8u) | oct4m;

  return sn;
}

subnet *subnet_new_cidr(char *cidr) {
  uint32_t oct1, oct2, oct3, oct4;
  int mask_len;

  sscanf(cidr, "%u.%u.%u.%u/%d", &oct1, &oct2, &oct3, &oct4, &mask_len);

  // Return a null pointer if the provided input was invalid.
  if (oct1 > 255 || oct2 > 255 || oct3 > 255 || oct4 > 255 || mask_len > 31) {
    return NULL;
  }

  uint32_t mask = 0xFFFFFFFF;
  for (int i = 0; i < 32 - mask_len; i++) {
    mask = mask << 1u;
  }

  subnet *sn = (subnet *) malloc(sizeof(subnet));

  // Pack each octet together into one 32-bit integer.
  sn->addr = (oct1 << 24u) | (oct2 << 16u) | (oct3 << 8u) | oct4;
  sn->mask = mask;

  return sn;
}

char *subnet_addr(subnet *sn) {
  return bin2dot(sn->addr);
}

char *subnet_mask(subnet *sn) {
  return bin2dot(sn->mask);
}

int subnet_mask_length(subnet* sn)
{
  int length = 0;

  // Determine mask length in bits by shifting the mask bits left until the mask is "zero".
  uint32_t mask = sn->mask;
  while (mask != 0) {
    mask = mask << 1u;
    length++;
  }

  return length;
}

char *subnet_cidr(subnet *sn) {
  char *str = (char *) malloc(19 * sizeof(char));

  // Temporarily allocate then free our address to avoid a memory leak.
  char *addr = subnet_addr(sn);
  sprintf(str, "%s/%d", addr, subnet_mask_length(sn));
  free(addr);

  return str;
}

int subnet_num_hosts(subnet *sn) {
  return (unsigned int) (0xFFFFFFFFU ^ sn->mask) + 1;
}

int subnet_num_usable_hosts(subnet *sn) {
  return (unsigned int) (0xFFFFFFFFU ^ sn->mask) - 1;
}

char *subnet_min_host(subnet *sn) {
  return bin2dot(((sn->addr & sn->mask) | 0) + 1);
}

char *subnet_max_host(subnet *sn) {
  return bin2dot((sn->addr | (sn->mask ^ 0xFFFFFFFF)) - 1);
}

char *subnet_network_addr(subnet *sn) {
  return bin2dot(((sn->addr & sn->mask) | 0));
}

char *subnet_broadcast_addr(subnet *sn) {
  return bin2dot((sn->addr | (sn->mask ^ 0xFFFFFFFF)));
}