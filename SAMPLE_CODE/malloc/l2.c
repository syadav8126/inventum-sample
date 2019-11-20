///printing malloc meta

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct malloc_chunk {
             size_t  prev_size;
             size_t  size;
             struct malloc_chunk *fd;
             struct malloc_chunk *bk;            
};
struct my_p
{
	char a;
};
int main(){
//struct malloc_chunk *mc;
struct my_p *p;
	p = malloc (sizeof(struct my_p));
//	mc = malloc (sizeof(struct malloc_chunk));
	p->a=9;
	printf("p   :%p\n",p);
	printf("*p  :%d\n",*p);
	printf("&p  :%p\n",&p);
	printf("&p->a:%p\n",&p->a);
//	printf("%ld\n",**(&p));
//	memcpy((void *)mc,(void *)(&(p->a)+6),16);
//	printf("priv_siz: %ld\n",mc->prev_size);
//	printf("siz: %ld\n",mc->size);
}
