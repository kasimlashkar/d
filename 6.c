#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert();
void cdelete();
void display();
void overflow();
void underflow();

int queue[20];
int r=-1,f=0,cnt=0;

int main()
{
   int ch;
   for(;;)
   {
       printf("\n-------Queue Operations---------\n");

             printf("1.INSERT\n2.DELETE\n3.DISPLAY\n4.OVERFLOW\n5.UNDERFLOW\n6.EXIT\n");
       printf("Enter your choice:\n");
       scanf("%d",&ch);
       switch(ch)
       {
	  case 1:insert();
		 break;
	  case 2:cdelete();
		 break;
	  case 3:display();
			 break;
	  case 4:overflow();
		 break;
	  case 5:underflow();
		 break;
	  case 6:exit(0);
	  default:printf("Invalid choice\n");
       }
   }
return 0;
}

void insert()
{
   int e;
   if(cnt==MAX)
   {
	printf("Queue is full\n");
	return;
   }
   else
   {
      printf("Enter an element : \n");
      scanf("%d",&e);
      r=(r+1)%MAX;
      queue[r]=e;
      cnt=cnt+1;
   }
}

void cdelete()
{
 if(cnt==0)
 {
    printf("Queue is empty\n");
    return;
 }
 else
 {
   printf("Deleted element is %d\n",queue[f]);
   f=(f+1)%MAX;
   cnt=cnt-1;
 }
}

void display()
{
  int i;
  if(cnt==0)
  {
     printf("Queue is empty\n");
     return;
  }
  else
  {
    printf("Contents of the Queue is\n");
    if(f<r)
    {
    for(i=f;i<=r;i++)
      printf("|%d",queue[i]);
    }
    else
    {
      for(i=f;i<MAX;i++)
	   printf("|%d",queue[i]);
      for(i=0;i<=r;i++)
	  printf("|%d",queue[i]);
    }
  }
 }

void overflow()
{
  int i;
  for(i=cnt;i<=MAX;i++)
     insert();
  printf("Queue overflow\n");
}

void underflow()
{
  int i;
  for(i=cnt;i>=0;i--)
      cdelete();
  printf("Queue underflow\n");
}
