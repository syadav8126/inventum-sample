#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
 
jmp_buf resume_here;
 
void hello(void);
 
int main(void)
{
    int ret_val;
 
    if (setjmp(resume_here)) {
        printf("After \'longjump()\', back in \'main()\'\n");
        printf("\'jump buffer variable \'resume_here\'\' becomes "
                  "INVALID!\n");
    }
    else {
        printf("\'setjmp()\' returns first time\n");
        hello();
    }
 
    return 0;
}
 
void hello(void)
{
    printf("Hey, I'm in \'hello()\'\n");
    longjmp(resume_here, 0);
 
    printf("can't be reached here because I did longjmp!\n");
}
