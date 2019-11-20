#include <stdio.h>
#include <stdlib.h>
size_t
strlen (const char *str)
{
		const char *char_ptr;
		const unsigned long int *longword_ptr;
		unsigned long int longword, himagic, lomagic;
		for (char_ptr = str; ((unsigned long int) char_ptr
								& (sizeof (longword) - 1)) != 0;
						++char_ptr){
						fprintf(stdout, "char_ptr::%ld\n", (unsigned long int ) char_ptr);
					//	fprintf(stderr, "%ld\n", (unsigned long int) char_ptr & (sizeof (longword) - 1));
					//	fprintf(stderr, "lw:%ld\n", (sizeof (longword) - 1));
				if (*char_ptr == '\0'){
						return char_ptr - str;
				}
		}
		longword_ptr = (unsigned long int *) char_ptr;
		himagic = 0x80808080L;
		lomagic = 0x01010101L;
		if (sizeof (longword) > 4)
		{
				/* 64-bit version of the magic.  */
				/* Do the shift in two steps to avoid a warning if long has 32 bits.  */
				himagic = ((himagic << 16) << 16) | himagic;
				lomagic = ((lomagic << 16) << 16) | lomagic;
		}
		if (sizeof (longword) > 8){
				fprintf(stderr,"JUST AN ERROR\n");
				abort ();
		}
		for (;;)
		{
				longword = *longword_ptr++;
						printf("longword       :%ld\n",longword);
						printf("longword-lomagic%ld\n",longword-lomagic);
						printf("%ld\n",((longword - lomagic) & ~longword & himagic));
				if (((longword - lomagic) & ~longword & himagic) != 0)
				{
						/* Which of the bytes was the zero?  If none of them were, it was
						   a misfire; continue the search.  */
						printf("i is :\n");
						const char *cp = (const char *) (longword_ptr - 1);

						if (cp[0] == 0)
								return cp - str;
						if (cp[1] == 0)
								return cp - str + 1;
						if (cp[2] == 0)
								return cp - str + 2;
						if (cp[3] == 0)
								return cp - str + 3;
						if (sizeof (longword) > 4)
						{
								if (cp[4] == 0)
										return cp - str + 4;
								if (cp[5] == 0)
										return cp - str + 5;
								if (cp[6] == 0)
										return cp - str + 6;
								if (cp[7] == 0)
										return cp - str + 7;
						}
				}
		}
}
int main(){

	char *p="1";
	long int s = strlen(p);
	printf("%ld\n",s);

}

