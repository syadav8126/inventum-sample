#include <stdio.h>
int a,b,c,d,hero,villain,i;
int main(){

	printf("Enter the no of outputs to be taken\n");
	scanf("%d",&a);
	for(i=0;i<a;i++){
		printf("Enter the number of Characters\n");
		scanf("%d",&b);
		for(i=0;i<b;i++)
		{
			scanf("%d",&c);
			hero += c;
		}
		for(i=0;i<b;i++)
		{
			scanf("%d",&d);
			villain += d;
		}
		if (hero > villain)
			printf("WIN\n");
		else if (hero < villain)
			printf("LOSE\n");
		else
			printf("TIE\n");
		}
}
