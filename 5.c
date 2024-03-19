#include<stdio.h>
#include<math.h>

void main()
{
  char postfix[50],ch;
  int i,top=-1;
  float op1,op2,res=0,stack[20];
  printf("Enter a valid postfix expression\n");
  scanf("%s",postfix);
 for(i=0;postfix[i]!='\0';i++)
 {
	ch=postfix[i];
	if(ch>='0' && ch<='9')
	 stack[++top]=ch-'0';
	else
	{
	  op2=stack[top--];
	  op1=stack[top--];

	 switch(ch)
	 {
	   	case '+':res=op1+op2;
			break;
	  	 case '-':res=op1-op2;
			break;
	  	 case '*':res=op1*op2;
			break;
	   	case '/':res=op1/op2;
			break;
	   	case '^':res=pow(op1,op2);
			break;
	   	case '%':res=(int)op1%(int)op2;
			break;
	   	default:printf("Invalid Operator\n");
	   }
	   stack[++top]=res;
       }
     }
     printf("Value of %s expression is %f\n",postfix,res);
  }
