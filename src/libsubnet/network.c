#include <libsubnet/network.h>

#include <stdio.h>
#include <stdlib.h>

uint32_t dot2bin(char *s)
{
  uint32_t oct1, oct2, oct3, oct4;
  sscanf(s, "%u.%u.%u.%u", &oct1, &oct2, &oct3, &oct4);

  // TODO: Perform input validation & verify each octet is less than 255.

  // Pack each octet together into one 32-bit integer.
  return (oct1 << 24u) | (oct2 << 16u) | (oct3 << 8u) | oct4;
}

char *bin2dot(uint32_t i)
{
  // Allocate a string large enough to fit an IP with 4 three-digit octets and a null terminator.
  char *str = (char *) malloc(16 * sizeof(char));

  // Read the 32-bit int as 4 separate octets.
  uint8_t *octets = (uint8_t *) &i;

  // TODO: Perform input validation & verify each octet is less than 255.

  sprintf(str, "%d.%d.%d.%d", octets[3], octets[2], octets[1], octets[0]);

  return str;
}
