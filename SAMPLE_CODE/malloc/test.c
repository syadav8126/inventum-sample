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
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
};
int main(){
struct my_p *p;
struct my_p *p1;
struct malloc_chunk *mc;
	int *aa;
	p = malloc (sizeof(struct my_p));
	p1 = malloc (sizeof(struct my_p));
	mc = malloc (sizeof(struct malloc_chunk));
	p->a=1;
	p->b=19;
	p->c=3;
	p->d=4;
	p->e=5;
	p->f=8;
	printf("%p\n",&p->a);
	printf("%p\n",&p->b);
	printf("%p\n",&p->c);
	memcpy((void *)p1,(void *)p,32);
	aa  = &(p->a);
	printf("%d\n",*(&(p->a)));
	printf("%d\n",*(&(p->a)+1));
	printf("%d\n",*(&(p->a)+2));
	printf("%d\n",*(&(p->f)));
	memcpy((void *)mc,(void *)(&(p->a)+6),8);
	printf("priv_size: %ld\n",mc->prev_size);
	free(p);
	memcpy((void *)mc,(void *)(&(p1->a)+6),8);
	printf("priv_size: %ld\n",mc->prev_size);
}
