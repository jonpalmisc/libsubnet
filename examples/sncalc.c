#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <libsubnet/subnet.h>

int main(int argc, char *argv[]) {
  subnet *sn;

  if (argc == 2) {
    sn = subnet_new_cidr(argv[1]);
  } else if (argc == 3) {
    sn = subnet_new(argv[1], argv[2]);
  } else {
    printf("Usage: %s\n", "sncalc <cidr>");
    return EXIT_FAILURE;
  }

  if (sn == NULL) {
    printf("%s\n", "Error: Invalid input. Please make sure you have provided a valid IP and subnet mask.");
    return EXIT_FAILURE;
  }

  char *mask = subnet_mask(sn);
  char *cidr = subnet_cidr(sn);
  char *min_host = subnet_min_host(sn);
  char *max_host = subnet_max_host(sn);
  char *network_addr = subnet_network_addr(sn);
  char *broadcast_addr = subnet_broadcast_addr(sn);

  printf("Mask: %s  /%d\n", mask, subnet_mask_length(sn));
  printf("Range: %s to %s  (%d)\n", min_host, max_host, subnet_num_usable_hosts(sn));
  printf("Network: %s  Broadcast: %s\n", network_addr, broadcast_addr);

  free(mask);
  free(cidr);
  free(min_host);
  free(max_host);
  free(network_addr);
  free(broadcast_addr);

  free(sn);

  return EXIT_SUCCESS;
}