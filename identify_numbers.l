/**
Write a flex application that will identify signed/unsigned integer and long integer constants in decimal,
hexadecimal, binary and octal representations as used in C lnguage.	
**/


%{

%}

%%


[+] { printf("unsigned");}
[-]        {printf("signed");}

0[xX][0-9a-fA-F]+ { printf("hexadecimal");return 0; }
[0-1]+ { printf("binary");return 0; }
0[0-7]+ { printf("octal");return 0; }
[0-9]+ { printf("decimal");return 0; }

. {printf("The word is invalid");return 0;}


%%
main(int argc, char **argv)
{
yylex();

}


