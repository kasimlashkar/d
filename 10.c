#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *tree;

tree getnode();
tree create(tree);
void inorder(tree);
void preorder(tree);
void postorder(tree);
void search(tree,int);

int main()
{
	tree t = NULL;
	int ch,key,i,n,ele;

    	printf("Enter number of nodes\n");
               scanf("%d", &n);
    	printf("Enter %d numbers\n", n);
    	for(i=0;i<n;i++)
    		t=create(t);
    
	for(;;)
	{
		printf("\n===========BINARY SEARCH TREE OPERATIONS==========\n");
		printf("\n1.PREORDER\n2.INORDER\n3.POSTORDER\n4.SEARCH\n5.EXIT\n");
		printf("Enter your choice: \n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: preorder(t);
				break;
			case 2: inorder(t);
				break;
			case 3: postorder(t);
				break;
			case 4: printf("Enter the searching element\n");
				scanf("%d",&key);
				search(t,key);
				break;
				
			case 5: exit(0);

			default: printf("Invalid choice\n");
		
		}

	}

}

tree getnode()
{
	tree temp;
	temp = (tree ) malloc (sizeof(struct node));
	if(temp==NULL)
	{
		printf("Insufficient memory\n");
		exit(0);
	}
	else
	{
		printf("Enter the node value\n");
		scanf("%d",&temp->data);
		temp->llink=NULL;
		temp->rlink=NULL;
	}
	return temp;
} 

tree create(tree t)
{
	tree temp,prev,cur;
	temp=getnode();
	if(t==NULL)
		return temp;
	prev = NULL;
	cur = t;

	while(cur != NULL)
	{
		prev = cur;

		if(temp->data == cur->data)
		{
			printf("Duplicate items not allowed\n");
			free(temp);
			return t;
		}

		if(temp->data < cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}

	if(temp->data < prev->data)
		prev->llink = temp;
	else
		prev->rlink = temp;

	return t;

}


void preorder(tree t)
{
	if(t != NULL)
	{
		printf("%d\t",t->data);
		preorder(t->llink);
		preorder(t->rlink);
	}
}

void inorder(tree t)
{
	if(t != NULL)
	{
		inorder(t->llink);
		printf("%d\t",t->data);
		inorder(t->rlink);
	}
}

void postorder(tree t)
{
	if(t != NULL)
	{
		postorder(t->llink);
		postorder(t->rlink);
		printf("%d\t",t->data);
	}
}

void search(tree t, int key)
{
	if(t != NULL)
	{
		if(key < t->data)
			search(t->llink, key);
		else if(key > t->data)
			search(t->rlink, key);
		else
			printf("Successful Search\n");
	}
	else

		printf("Unsuccessful Search\n");
}
