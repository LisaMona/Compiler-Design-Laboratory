/*
Remove left recursion of any grammar
*/

#include<stdio.h>
#include<string.h>
void main()  
{
	char input[100],*l,*r,*temp,tempprod[20],productions[25][50];
	int n,k;
	int i=0,flag=0,j=0;
	printf("enter no. of productions:");
	scanf("%d",&n);	

	printf("Enter the productions: ");
	for(k=0;k<n;k++)
	{	
	scanf("%s",input);
	l = strtok(input,"->");			//The C library function char *strtok(char *str, const char *delim) 							breaks string str into a series of tokens using the delimiter delim.

	r = strtok(NULL,"->");
	temp = strtok(r,"|");
	while(temp)  
	{
		if(temp[0] == l[0])
		{
			flag = 1;
			sprintf(productions[i++],"%s'->%s%s'\0",l,temp+1,l);		//The C library function int sprintf(char *str, 											const char *format, ...) sends formatted output 											to a string pointed to, by str.
		}
		else
			sprintf(productions[i++],"%s->%s%s'\0",l,temp,l);
			
			temp = strtok(NULL,"|");
			
			
	}
	sprintf(productions[i++],"%s'->null\n",l);
	if(flag == 0 && k==n-1)
		printf("The given productions don't have Left Recursion");
	else
		for(j=0;j<i;j++)
		{
			printf("\n%s",productions[j]);
		}
	}
}
