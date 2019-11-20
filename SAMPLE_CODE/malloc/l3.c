///printing malloc meta

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mcheck.h>
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
struct my_p *p2;
struct malloc_chunk *mc;
	mtrace();
	int *aa;
	p = malloc (sizeof(struct my_p));
	p1 = malloc (sizeof(struct my_p));
	p2 = malloc (sizeof(struct my_p));
	mc = malloc (sizeof(struct malloc_chunk));
	p->a=1;
	p->b=19;
	p->c=3;
	p->d=4;
	p->e=5;
	p->f=8;
	printf("%p\n",p);
	printf("%p\n",p1);
	printf("%p\n",p2);
//	printf("size %ld\n",sizeof(struct my_p));
//	printf("p:%p\n",&p->a);
//	printf("%p\n",&p->b);
//	printf("%p\n",&p->c);
//	memcpy((void *)p1,(void *)p,32);
	aa  = &(p->a);
//	printf("%d\n",*(&(p->a)));
//	printf("%d\n",*(&(p->a)+1));
//	printf("%d\n",*(&(p->a)+2));
//	printf("%d\n",*(&(p->f)));
	memcpy((void *)mc,(void *)(&(p->a)+6),8);
	printf("%p\n",&p->a);
	printf("priv_size: %ld\n",mc->prev_size);
	memcpy((void *)mc,(void *)(&(p1->a)+6),8);
	printf("%p\n",&p1);
	printf("priv_siz1: %ld\n",mc->prev_size);
	memcpy((void *)mc,(void *)(&(p2->a)+6),8);
	printf("%p\n",&p2);
	printf("priv_siz2: %ld\n",mc->prev_size);
}
