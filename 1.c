#include<stdio.h>
#define noofdays 7
#include<stdlib.h>
#include<string.h>
struct day
{
   char dayname[20];
   int date;
   char activity[50];
};
typedef struct day *daylst;
void adddetails(daylst);
daylst createcal();
void display(daylst);
void main()
{
   daylst cal;
   cal=createcal();
   adddetails(cal);
   display(cal);

}

daylst createcal()
{
  daylst temp;
  int i;

  temp=(daylst)malloc(noofdays*sizeof(struct day));
  if(temp==NULL)
  {
    printf("Insufficient memory\n");
    exit(0);
  }
  else
  {
     for(i=0;i<noofdays;i++)
     {
       strcpy(temp[i].dayname,"-------");
       temp[i].date=0;
       strcpy(temp[i].activity,"No Activity");
     }
   }
   return temp;
}

void adddetails(daylst cal)
{
int i,ch;

printf("Enter Calendar details\n");
for(i=0;i<noofdays;i++)
{

  printf("1.Enter Details\n2.Skip Details\n");
  printf("Enter your choice\n");
  scanf("%d",&ch);
  switch(ch)
  {
   	case 1: printf("Details for Day %d\n",i+1);
	   	printf("Day name: ");
	  	 scanf("%s",cal[i].dayname);
	   	printf("\nDate: ");
	   	scanf("%d",&cal[i].date);
	   	printf("\nActivity: ");
	   	scanf("%s",cal[i].activity);
	   	break;
   	case 2:break;
   }
}

}
void display(daylst cal)
{
  	int i;
  	printf("----------CALENDAfR------------------\n");
  	printf("DAY NO\tDAY NAME\t\tDATE\tACTIVITY\n");
  	for(i=0;i<noofdays;i++)
  		printf("%d\t%s\t\t%d\t%s\n",i+1,cal[i].dayname,cal[i].date,cal[i].activity);
 }
