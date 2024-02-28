#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void push();
void pop();
void display();
void overflow();
void underflow();
void palindrome();

int stack[20],top=-1;

int main()
{
   int ch;
   for(;;)
   {
       printf("---------------STACK OPERATIONS---------------------\n");
     printf("1.PUSH\n2.POP\n3.DISPLAY\n4.OVERFLOW\n5.UNDERFLOW\n6.PEEK\n7.PALINDROME\n8.EXIT\n");
       printf("Enter your choice:\n");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:push();
		 break;
	  case 2:pop();
		 break;
	  case 3:display();
		 break;
	  case 4:overflow();
		 break;
	  case 5:underflow();
		 break;
	  case 6:if(top==-1)
		    printf("Stack is empty\n");
		 else
		    printf("Peek of stack: %d\n",stack[top]);
		 break;
	  case 7:palindrome();
		 break;
	  case 8:exit(0);
	  default:printf("Invalid choice\n");
       }
   }
  return 0;
}

void push()
{
   int e;
   if(top==MAX-1)
   {
	printf("Stack is full\n");
	return;
   }
   else
   {
      printf("\nEnter the element to be pushed \n");
      scanf("%d",&e);
      top=top+1;
      stack[top]=e;
   }
}

void pop()
{
 if(top==-1)
 {
    printf("Stack is empty\n");
    return;
 }
 else
 {
   printf("Popped element: %d\n",stack[top]);
   top=top-1;
 }
}

void display()
{
  int i;
  if(top==-1)
  {
     printf("Stack is empty\n");
     return;
  }
  else
  {
    	printf("Stack Contents are:\n");
for(i=top;i>=0;i--)
      		printf("%d\n",stack[i]);
  }
 }

void overflow()
{
  	int i;
printf("\nThere are currently %d elements in Stack\nPush %d elements for Stack to Overflow", top+1, MAX - (top+1));
  	for(i=top;i<MAX;i++)
     		push();
 	 printf("Stack overflow\n");
}

void underflow()
{
  	int i;
printf("\nThere are currently %d elements in Stack\nPop out %d elements for Stack to Underflow", top+1, MAX - (top+1));
  	
  	for(i=top;i>=0;i--)
      		pop();
  	printf("Stack underflow\n");
}

void palindrome()
{
  int i,t[20],j=0;
  if(top==-1)
  {
     printf("Stack is empty\n");
     return;
   }
   else
   {
     for(i=top;i>=0;i--)
     t[j++]=stack[i];

     for(i=0;i<=top;i++)
     {
	if(stack[i]!=t[i])
	   break;
      }
      if(i==top+1)
       printf("Stack elements form palindrome\n");
      else
	printf("Stack elements doesnot form palindrome\n");
     }
}
