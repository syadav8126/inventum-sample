#include <stdio.h>
int main()
{
	printf("Enter no of elements\n");
	int a,b;
	printf("Enter no of elements\n");
	scanf("%d",&a);
	int arr[a];
	printf("Enter elements\n");
	for (int i=0; i< a; i++){
		b = 0;
		scanf("%d",&b);
		arr[i] = b;
}
	for (int i=a-1; i>=0; i--){
		printf("%d ",arr[i]);
	}
}
