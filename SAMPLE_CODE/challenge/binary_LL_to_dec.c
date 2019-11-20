/*
	a linked_list having data a binary  numbers, convert it to a decimal number
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
struct node{
	int data;
	struct node* next;
};
extern int num1,num1;
int count=0;
static int minus=0;
void ll(struct node **head,int data)
{
	struct node* ref = *head;
	if(!ref)
	{
		ref = (struct node*) malloc(sizeof(struct node));
		ref->data = data;
		ref->next = NULL;
		*head = ref;
		return;
	}
	while(ref->next)
		ref = ref->next;
		ref->next = (struct node *) malloc(sizeof(struct node));
		ref->next->data = data;
		ref->next->next = NULL;
}

void print_ll(struct node *ref)
{
	while(ref)
	{
		printf("%d->",ref->data);
		ref = ref->next;
	}
}


void push_ll(struct node **root)
{
	
	int data=0;
	printf("Enter the nu of elements in ll\n");
	scanf("%d",&count);
	printf("Enter the Elements in binary  only\n");
	for (int i=0; i< count; i++)
	{
		scanf("%d",&data);
		ll(root,data);
	}
}

int8_t get_num(struct node *root)
{
	int8_t num=0,num1=0;
	for(int i=0; i<count; i++)
	{
		int num = root->data;
		num1 += (num)*(pow(2,(count-i-1)));
	//	if(i==0 && num == 1)
	//	{
	//		num1=0;
	//		minus=1;
	//		printf("coming\n");
	//	}
		root = root->next;
	}
	return num1;
}

int main()
{
	struct node* root=NULL;
	push_ll(&root);
	//print_ll(root);
	printf("\n%d\n",get_num(root));

}
