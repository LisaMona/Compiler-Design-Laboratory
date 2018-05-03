/***
Design a scanner using flex to count the number of ASCII characters, words, lines and punctuations in a given string.
symbol set for words [a-zA-Z0-9]+
punctuation symbols - . , : ; ? " '
newline character \n
***/


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
