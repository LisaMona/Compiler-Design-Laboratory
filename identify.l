/* 
Write a flex program that will identify character string & string constants as defined in C language.
*/

%{
int string = 0;
int char = 0;
}%

%%
["].*["]				{	printf("String\n");		} 
['].*[']				{	printf("character\n");	} 
.*						{	printf("invalid\n");	} 
%%

main(int argc, char **argv)
{
	yylex();
}

