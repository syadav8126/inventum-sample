#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
int data;
struct Node *left, *right;
}node;

void insert(node ** tree, int val, char a)
{
	node *temp;
	if(!(*tree))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		if (a == 'l')
			printf("%d\n",val);
		else if (a == 'r')
			printf("\t\t%d\n",val);
		else
			printf("\t%d\n",val);
		return;
	}
	if((*tree)->data < val)
	{
//		printf("Adding right\t");
		insert(&(*tree)->right,val,'r');
//		printf("Added right->%d\n",val);
	}
	else if((*tree)->data > val)
	{
//		printf("Adding Left\t");
		insert(&(*tree)->left,val,'l');
//		printf("Added Left->%d\n",val);
	}
}

void print(node *tree, char a)
{
	if(tree)
	{
	printf("%c:%d\n",a,(tree)->data);
	print(tree->left,'l');
	print(tree->right,'r');
	}
}
int main()
{
	node *root = NULL;
	char R = 'R';
	insert(&root, 9,'R');
	insert(&root, 4,'R');
	insert(&root, 15,'R');
	insert(&root, 6,'R');
	insert(&root, 12,'R');
	insert(&root, 17,'R');
	insert(&root, 2,'R');

	print(root,R);
}
