#include <libsubnet/network.h>

#include <stdio.h>
#include <stdlib.h>

uint32_t dot2bin(char *s)
{
  uint32_t i1, i2, i3, i4;
  sscanf(s, "%u.%u.%u.%u", &i1, &i2, &i3, &i4);

  return (i1 << 24u) | (i2 << 16u) | (i3 << 8u) | i4;
}

char *bin2dot(uint32_t i)
{
  char *str = (char *) malloc(16 * sizeof(char));

  uint8_t *blocks = (uint8_t *) &i;
  sprintf(str, "%d.%d.%d.%d", blocks[3], blocks[2], blocks[1], blocks[0]);

  return str;
}
