#include <stdio.h>
#include <string.h>
int main(){
	FILE *fp;
	int index,i;
	char buff[255],c,dtm[100], protocol[20],ignore1[100],ignore2[100], *p;
	fp = fopen ("/etc/protocols","r");
	fseek(fp, 302 ,SEEK_CUR);

	p =fgets(buff, 50, fp);
	while(p != '\0'){
	p = fgets(buff, 50, fp);
	strcpy(dtm, buff);
	sscanf(dtm,"%s %d %s %s",protocol, &index, ignore1, ignore2);
	printf("%s \t %d\n",protocol, index);}
	fclose(fp);
	return 0;	

}
