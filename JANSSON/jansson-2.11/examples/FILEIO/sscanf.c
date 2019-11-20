#include <stdio.h>
#include <string.h>
int main(){

	int date, year;
	char weekday[20], month[20], dtm[100];
	
	strcpy(dtm, "thursday  21 june 2018");
	sscanf(dtm, "%s %d %s %d\n",weekday, &date, month, &year);

	printf("%s %d %s =%d",month, date, weekday, year);
	return 0;
}
