// Lex program to count the number of lines, words, characters and punctuations in a given input.


%{
	int chars=0;
	int words=0;
	int lines=0;
	int punc=0;
%}

%%
[a-zA-Z0-9]+				{words++; chars+=strlen(yytext);}
\n 							{chars++; lines++;}
[. , : ; ? '\"' '\'']			{punc++; chars++;}
%%
main(int argc, char **argv)
{
	yylex();
	printf("%8d%8d%8d%8d\n", lines, words, chars, punc);
}
