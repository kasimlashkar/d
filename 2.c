#include<stdio.h>
#include<string.h>

int main()
{
	char mainstr[200],patternstr[50],replacestr[50],resstr[200];
	int i,j,k,noofmatches=0,plen,rlen,t=0;

	printf("Enter the main string\n");
	fgets(mainstr,200,stdin);
	printf("Enter the pattern string\n");
	fgets(patternstr,100,stdin);
	printf("Enter the replace string\n");
	fgets(replacestr,100,stdin);
	printf("The input string is\n %s\n",mainstr);
	plen=strlen(patternstr)-1;
	rlen=strlen(replacestr)-1;

	for(i=0;i<strlen(mainstr)-plen;i++)
	{
		for(j=0;j<plen;j++)
		{
			if(mainstr[i+j]!=patternstr[j])
				break;
		}

		if(j==plen)
		{
			noofmatches++;
			t=0;
			for(k=0;k<i;k++)
				resstr[t++]=mainstr[k];
			for(k=0;k<rlen;k++)
				resstr[t++]=replacestr[k];
			for(k=i+plen;k<strlen(mainstr);k++)
				resstr[t++]=mainstr[k];
			resstr[t]='\0';
			for(k=0;k<strlen(resstr);k++)
				mainstr[k]=resstr[k];
			mainstr[k]='\0';
		}
	}
	if(noofmatches>0)
	{
		printf("%d matches occured in the input text\n",noofmatches);
		printf("After replacing the matched patterns the string is \n %s\n",resstr);
	}
	else
		printf("Pattern string not found in the input text\n");
	return 0;
}

