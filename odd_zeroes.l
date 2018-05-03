/*
Write a flex application that will recognise strings of odd numbers of 0's and even number of 1's.
*/

%{
int zero = 0;
int one = 0;
%}

%%
0			{zero++;}
1			{one++;}
%%

main(int argc, char **argv)
{
	yylex();
	printf("%8d%8d\n", zero,one);
	if (((one % 2) == 0) && ((zero % 2) != 0))
		printf("valid string\n");

	else
		printf("invalid string\n");
}
