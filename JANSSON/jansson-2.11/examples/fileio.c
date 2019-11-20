/*#include <stdio.h>
int main(){
FILE *fp;
fp = fopen("/home/saurabh/make1","w+");
fprintf(fp,"fprintf functioning\n");
fputs("fputs is functioning",fp);
//fclose(fp);
return 0;
}*/
#include <stdio.h>

int main() {

	FILE *fp;
	char buff[255];
	fp = fopen("/proc/cpuinfo","r");
	if(fp){
	fgets(buff,255, (FILE*)fp);
	printf("%s",buff);}

return 0;
}
