/* 
Write a flex application that will recognise valid identifiers having symbols a-z, A-Z, 0-9 and
underscore(_). Each identifier should not start with a symbols from 0-9.
Any other symbols like decimal point/full stop(.), comma(,), semicolon(;), 
colon(:), +, -, *, /, @, $, & etc. are considered as invalid symbols.
*/


%{
int valid = 0;
int invalid = 1;
int symbols = 0;
%}

%%
[a-zA-Z_]+[a-zA-Z0-9_]*										{symbols+=strlen(yytext); valid++;}
[0-9]+[a-zA-Z0-9_]*													{symbols++; invalid++;}
([a-zA-Z0-9_]*[:.;,="\<""\>"`~+*"\(""\)"-/@$&#!%^"\'""\""?]+[a-zA-Z0-9_]*)*						{symbols++; invalid++;}
%%

main(int argc, char **argv)
{
  yylex();
  if (invalid ==1)
    printf("valid\n");
  else
    printf("invalid\n");
  printf("%d\n", symbols);
}






