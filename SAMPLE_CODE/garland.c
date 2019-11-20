#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct a{
	int dead;
	char *s;
	char* cons;
	int str_l;
	char *full_string;
	int *dead_colour;
};
struct a *g = NULL;
void * ct()
{
	int index=0;
	for(int i=0;i<g->str_l;i++)
	{
		index = i%4;
		g->full_string[i] = g->cons[index];
		if(g->s[i] != g->full_string[i])
			g->dead_colour[index]++;
		printf("%d,%d\n",index,g->dead_colour[index]);
	}
	printf("%d %d %d %d",g->dead_colour[0],g->dead_colour[1],g->dead_colour[2],g->dead_colour[3]);
}	
int main(int argc, char* argv[])
{
	g = malloc(sizeof(struct a));
	g->s = malloc(100);
	g->cons = malloc(0);
	g->full_string = malloc(1000);
	g->dead_colour = (int *)malloc(1000);
	scanf("%s",g->s);
	g->str_l = strlen(g->s);
	for (int i=0;i<g->str_l;i++)
	{
		int index=0;
		if (g->s[i] == '!')
			continue;
		index = i%4;
		g->cons[index] = g->s[i];
	}
	ct();
}
