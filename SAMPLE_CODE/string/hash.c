#include <stdio.h>
#define HASHWORDBITS 32


#ifndef _LIBC
# ifdef IN_LIBINTL
#  define __hash_string libintl_hash_string
# else
#  define __hash_string hash_string
# endif
#endif


unsigned long int
__hash_string (const char *str_param)
{
  unsigned long int hval, g;
  const char *str = str_param;

  /* Compute the hash value for the given string.  */
  hval = 0;
  while (*str != '\0')
    {
      hval <<= 4;
      hval += (unsigned char) *str++;
      g = hval & ((unsigned long int) 0xf << (HASHWORDBITS - 4));
      if (g != 0)
  {
    hval ^= g >> (HASHWORDBITS - 8);
    hval ^= g;
  }
    }
  return hval;
}
int main(){
	printf("%ld\n",__hash_string("lodalehsun"));

}
