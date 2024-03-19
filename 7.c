#include<stdio.h>
#include<stdlib.h>

struct stud
{
   char usn[ 10];
   char name[50];
   char branch[10];
   int sem;
   long long int phone;
   struct stud *link;
};

typedef struct stud *studlst;

studlst create(studlst);
studlst insert_first(studlst);
studlst insert_last(studlst);
studlst delete_first(studlst);
studlst delete_last(studlst);
studlst getnode();
void display(studlst);
void noofnodes(studlst);

int main()
{

   int ch;
   studlst lst;
   lst=NULL;

   for(;;)
   {
	printf("\n=========SINGLY LINKED LIST OPERATIONS==========\n");
	printf("\n1.CREATE LIST\n2.DISPLAY\n3.INSERT FIRST\n4.INSERT LAST\n5.DELETE FIRST\n6.DELETE LAST\n7.NODES COUNT\n8.EXIT\n");
      printf("Enter your choice:\n");
      scanf("%d",&ch);
      switch(ch)
      {
	case 1:lst=create(lst);
		break;
	case 2:display(lst);
		break;
	case 3:lst=insert_first(lst);
		break;
	case 4:lst=insert_last(lst);
		break;
	case 5:lst=delete_first(lst);
		break;
	case 6:lst=delete_last(lst);
		break;
	case 7:noofnodes(lst);
		break;
	case 8:exit(0);
	default: printf("Invalid choice\n");
     }
}

}

studlst create(studlst lst)
{
	studlst temp1,cur;
        int i,n;
	printf("Enter number of students\n");
	scanf("%d",&n);


        for(i=1;i<=n;i++)
	{
		temp1=getnode();
	   	temp1->link=lst;
		lst=temp1;
        }
        return lst;
}

studlst getnode()
{
    studlst temp;
   temp=(studlst)malloc(sizeof(struct stud));
   if(temp==NULL)
   {
      printf("Insufficient memory\n");
      exit(0);
    }
    else
    {
       printf("Enter the details\n");
       printf("USN: ");
       scanf("%s",temp->usn);
       printf("\nName: ");
       scanf("%s",temp->name);
       printf("\nBranch: ");
       scanf("%s",temp->branch);
       printf("\nSem: ");
       scanf("%d",&temp->sem);
       printf("\nPhone: ");
       scanf("%lld",&temp->phone);
       temp->link=NULL;
     }
    return temp;
}

studlst insert_first(studlst lst)
{
   studlst temp;
   temp=  getnode();
      if(lst==NULL)
	lst=temp;
       else
        {
           temp->link=lst;
	   lst=temp;
         }

 return lst;
}

studlst insert_last(studlst lst)
{
   studlst temp,cur;
   temp= getnode();

       if(lst==NULL)
	lst=temp;
       else
        {
		cur=lst;
		while(cur->link!=NULL)
			cur=cur->link;
	   	cur->link=temp;
         }

 return lst;
}

void display(studlst lst)
{
   studlst temp;
   if(lst==NULL)
   {
      printf("List is Empty\n");
      return;
    }
    else
    {
       temp=lst;
       printf("The contents of SLL are :\n");
   printf("USN\t\tName\tBranch\tSem\tPhone\n");
       while(temp!=NULL)
       {
            printf("%s\t\t%s\t%s\t%d\t%lld\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phone);
            temp=temp->link;
         }
    }
}

studlst delete_first(studlst lst)
{
  studlst temp;
  if(lst==NULL)

   printf("List is Empty\n");
 else
 {
    temp=lst;
    lst=temp->link;
    printf("Deleted node with USN %s\n",temp->usn);
    free(temp);
  }
  return lst;
}


studlst delete_last(studlst lst)
{
  studlst temp,cur;
  if(lst==NULL)

   printf("List is Empty\n");
 else
 {

	temp=lst;
        while(temp->link!=NULL)
        {
            cur=temp;
             temp=temp->link;
        }

    cur->link=NULL;
    printf("Deleted node with USN %s\n",temp->usn);
    free(temp);
  }
  return lst;
}

void noofnodes(studlst lst)
{
	studlst temp;
	int count=0;
	if(lst==NULL)
	{
     		printf("List is empty\n");
		return;
	}
	else
	{
          		temp=lst;
          		while(temp!=NULL)
	  	{
             		count=count+1;
			temp=temp->link;
	   	}
         	}
         	printf("No. of Nodes = %d\n",count);
}
