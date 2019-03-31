#include <libsubnet/subnet.h>
#include <libsubnet/network.h>

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: Add validation during creation.
subnet *subnet_new(char *address, char *mask) {
  subnet *sn = (subnet *) malloc(sizeof(subnet));
  sn->addr = dot2bin(address);
  sn->mask = dot2bin(mask);

  return sn;
}

// TODO: Add validation during creation.
subnet *subnet_new_cidr(char *cidr) {
  uint32_t i1, i2, i3, i4;
  int mask_len;

  sscanf(cidr, "%u.%u.%u.%u/%d", &i1, &i2, &i3, &i4, &mask_len);

  uint32_t mask = 0xFFFFFFFF;
  for (int i = 0; i < 32 - mask_len; i++) {
    mask = mask << 1u;
  }

  subnet *sn = (subnet *) malloc(sizeof(subnet));
  sn->addr = (i1 << 24u) | (i2 << 16u) | (i3 << 8u) | i4;
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

  uint32_t mask = sn->mask;
  while (mask != 0) {
    mask = mask << 1u;
    length++;
  }

  return length;
}

char *subnet_cidr(subnet *sn) {
  char *str = (char *) malloc(19 * sizeof(char));

  char *addr = subnet_addr(sn);
  sprintf(str, "%s/%d", addr, subnet_mask_length(sn));
  free(addr);

  return str;
}

unsigned int subnet_num_hosts(subnet *sn) {
  return (unsigned int) (0xFFFFFFFFU ^ sn->mask) + 1;
}

unsigned int subnet_num_usable_hosts(subnet *sn) {
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