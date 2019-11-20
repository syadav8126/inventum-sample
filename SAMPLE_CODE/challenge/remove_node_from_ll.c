/*
	delete the nth element of a linked_list
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};

void print(struct node *ref)
{
	while(ref)
        {
                printf("%d-",ref->data);
                ref = ref->next;
        }
        printf("\n\n");
}


void insert(struct node** ref, int data)
{
	struct node* head = *ref;
	if(!head)
	{
		head = malloc(sizeof(struct node));
		head->data = data;
		head->next = NULL;
		*ref = head;
		return;
	}
	while(head->next)
		head = head->next;
	head->next = malloc(sizeof(struct node));
	head->next->data = data;
	head->next->next = NULL;
	return;
}

void remov(struct node** ref, int nu)
{
	struct node* head = *ref,*tmp;
	for(int i=1;i<nu-1;i++)
		if(head->next)
			head = head->next;
	tmp = head->next;
	head->next = tmp->next;
	free(tmp);
	
}

int main()
{
	struct node* root=NULL;
	insert(&root,0);
	insert(&root,1);
	insert(&root,2);
	insert(&root,3);
	insert(&root,4);
	insert(&root,5);
	insert(&root,6);
	print(root);
	printf("Enter the node to be deleted\n");
	int nu=0;
	scanf("%d",&nu);
	remov(&root,nu);
	print(root);
}
