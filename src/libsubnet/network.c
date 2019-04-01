#include <libsubnet/network.h>

#include <stdio.h>
#include <stdlib.h>

uint32_t dot2bin(char *s)
{
  uint32_t oct1, oct2, oct3, oct4;
  sscanf(s, "%u.%u.%u.%u", &oct1, &oct2, &oct3, &oct4);

  // Pack each octet together into one 32-bit integer.
  return (oct1 << 24u) | (oct2 << 16u) | (oct3 << 8u) | oct4;
}

char *bin2dot(uint32_t i)
{
  // Allocate a string large enough to fit an IP with 4 three-digit octets and a null terminator.
  char *str = (char *) malloc(16 * sizeof(char));

  // Reads the 32-bit int as 4 separate octets & formats them in dot notation.
  uint8_t *octets = (uint8_t *) &i;
  sprintf(str, "%d.%d.%d.%d", octets[3], octets[2], octets[1], octets[0]);

  return str;
}
