#include<stdio.h>

int priority(char ch);
char stack[50];
int top= -1;

void main()
{
  	char infix[50],postfix[50],x,ch;
  	int i,j=0;
  	printf("Enter the infix expression\n");
  	scanf("%s",infix);
 	for(i=0;infix[i]!='\0';i++)
 	{
		ch=infix[i];
		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
			postfix[j++]=ch;
		 else if(ch=='(')
	 		stack[++top]=ch;
		 else if(ch==')')
	 	{
	   		while((x=stack[top--])!='(')
	   			postfix[j++]=x;
	 	}
	 	else
	 	{
	   		 while(priority(stack[top])>=priority(ch))
	    			postfix[j++]=stack[top--];
	    		stack[++top]=ch;
		 }

 	}
 	while(top!= -1)
 		postfix[j++]=stack[top--];
	 postfix[j]='\0';
 	printf("Infix expression = %s\n",infix);
	 printf("Postfix expression = %s\n",postfix);
 }

int priority(char ch)
{
 	 if(ch=='(')
  		return 0;
 	 if(ch=='+' || ch=='-')
  		return 1;
  	if(ch=='*' || ch=='/')
  		return 2;
	if(ch=='^' || ch=='%')
		return 3;

  	return -1;
 }
