#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int c,l,i,j;
	int c_sum=0,l_sum=0;
	int max_sum=0,max_prev=0,max_cur=0;
	printf("Enter the number of fruit for c\n");
	scanf("%d",&c);
	printf("Enter the number of fruit for l\n");
	scanf("%d",&l);
	if (c >= argc )
	{
		printf("Enter a lesser quantity\n");
	}
	if (l >= argc )
	{
		printf("Enter a lesser quantity\n");
	}
	
	for (i=1; i<argc-c+1;i++)
	{
		c_sum=0;
		for (j=i;j<(i+c);j++)
		{
			c_sum += atoi(argv[j]);
		}
		printf("c_sum=%d  ",c_sum);
		for(int m=1;m<argc-l+1;m++){
			l_sum = 0;
			for (int k=m;k<(m+l);k++)
			{
				l_sum += atoi(argv[k]);
			}
				printf("l_sum=%d  ",l_sum);
			max_cur = c_sum + l_sum;
			printf("max_cur:%d ",max_cur);
			max_sum =  max_cur > max_prev ? max_cur : max_sum;
			printf("max_prev:%d ",max_prev);
			printf("max_sum:%d ",max_sum);
			max_prev = max_cur;
		}
	printf("Max till now: %d\n",max_sum);
	printf("\n\n");
	}	
}
