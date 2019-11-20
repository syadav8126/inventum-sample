//use case of array[0]

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct malloc_chunk {
             size_t  prev_size;
             size_t  size;
             struct malloc_chunk *fd;
             struct malloc_chunk *bk;            
};

struct my_p1
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
};
struct my_p
{
	int a;
	int b;
	int c;
	int e;
};
int main(){
struct my_p *p;
struct my_p1 *p1;
struct malloc_chunk *mc;
	int *aa;
	p = malloc (sizeof(struct my_p));
	p1 = malloc (sizeof(struct my_p1));
	mc = malloc (sizeof(struct malloc_chunk));
	p1->a=21;
	p1->b=19;
	p1->c=373;
	p1->d=44;
	p1->e=5;
	p1->f=2;
	memcpy((void*)p,(void*)p1,24);
	printf("p  :%p\n",p);
	printf("p  :%p\n",p1);
	printf("p  :%p\n",mc);
//	printf("add p  :%p\n",p);
//	printf("add p1 :%p\n",p1);
	memcpy((void *)mc,(void *)(&(p->a)+5),4);
//	printf("arr[0]:%d\n",p->arr[0]);
//	printf("arr[0]:%d\n",p->arr[1]);
//	printf("arr[0]:%d\n",p->arr[2]);
//	printf("arr[0]:%d\n",p->arr[3]);
//	printf("arr[0]:%d\n",p->arr[4]);
//	printf("address of %p\n",&p->arr[4]);
//	printf("6th value is %ld\n",mc->prev_size);
//	free(p);
}
