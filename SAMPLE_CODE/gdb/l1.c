#include<stdio.h>

#define addnum(a,b) ((a)+(b))
#define max(a,b) (a)>(b)?(addnum(a,100)):(addnum(b,50))

int a1=10,a2=20;

void f2()
{
		printf("X");
}

void print_dbg()
{
		char buf[15];
		printf("a1=%d a2=%d \n",a1,a2);

		strcpy(buf, "hello world");

}

int add(int a, int b)
{
		int c;
		c= max(a+90,b+20);
		c+=b;
		return c;
}

void f1()
{
		int i;
		int *p=NULL;
		print_dbg();
		i=add(80,90);
		for(i=0;i<100;i++)
		{
				if(i % 20 == 0)
						a1++;
				f2();
		}
		*p=100;
}
int arr[1000];

void main()
{
		arr[0]=1;
		f1();
		printf("hello %d\n",arr[0]);
}
