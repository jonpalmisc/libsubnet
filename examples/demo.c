#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <libsubnet/subnet.h>

int main(int argc, char *argv[]) {
  subnet *snc = subnet_new_cidr("192.168.0.0/16");

  if (snc == NULL) {
    printf("%s\n", "Error: Invalid input. Please make sure you have provided a valid IP and subnet mask.");
    return EXIT_FAILURE;
  }

  char *mask = subnet_mask(snc);
  char *cidr = subnet_cidr(snc);
  char *min_host = subnet_min_host(snc);
  char *max_host = subnet_max_host(snc);
  char *network_addr = subnet_network_addr(snc);
  char *broadcast_addr = subnet_broadcast_addr(snc);

  printf("Mask: %s  /%d\n", mask, subnet_mask_length(snc));
  printf("Range: %s to %s  (%d)\n", min_host, max_host, subnet_num_usable_hosts(snc));
  printf("Network: %s  Broadcast: %s\n", network_addr, broadcast_addr);

  free(mask);
  free(cidr);
  free(min_host);
  free(max_host);
  free(network_addr);
  free(broadcast_addr);

  free(snc);

  return EXIT_SUCCESS;
}