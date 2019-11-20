#include <stdio.h>
enum pus{
	zero,
	one,
	two,
	three
};
int main(){
enum pus count;
count =zero;
if(count){
	printf("1::%d\n",count);
}
	count ++;
if(count){
	printf("2::%d\n",count);
}
	count ++;
	printf("%d\n",count);


}
