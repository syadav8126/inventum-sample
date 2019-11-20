#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
    int flags, opt, c,cind;
    int nsecs, tfnd;

   nsecs = 0;
    tfnd = 0;
    flags = 0;
    while ((c = getopt(argc, argv, "n")) != -1) {
        switch (c) {
        case 'n':
            flags = 1;
            break;
        default: /* '?' */
		printf("wrong use ");
            exit(EXIT_FAILURE);
        }
    }

   printf("flags=%d; tfnd=%d; optind=%d\n", flags, tfnd, optind);

   if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }

   printf("argument is  ` = %s\n", argv[optind]);

   /* Other code omitted */

   exit(EXIT_SUCCESS);
}
