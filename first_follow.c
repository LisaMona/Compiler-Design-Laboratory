#include<stdio.h>
#include<string.h>
int n,m=0,p,i=0,j=0;
char a[10][10],f[10];
void follow(char c);
void first(char c);
//For finding first
void Find_First(char* array, char ch);
void Array_Manipulation(char array[], char value);


int limit;
//char production[25][25];


int main()
{

	char option; 

	char array[25];
	int count;

	int i,z;
	char c,ch;
	//clrscr();
	printf("Enter the no of productions:\n");
	scanf("%d",&n);
	limit = n;
	printf("Enter the productions:\n");
	for(i=0;i<n;i++)
	scanf("%s%c",a[i],&ch);
	do
	{
		m=0;
		printf("Enter the elements whose first & follow is to be found:");
		scanf("%c",&c);
		 
		Find_First(array, c);
		printf("\nFirst Value of %c:\t{ ", c);
		for(count = 0; array[count] != '\0'; count++)
		{        
			printf(" %c ", array[count]);
		}
		printf("}\n");
		
		m=0;
		follow(c);
		printf("Follow of %c:\t{ ",c);
		for(i=0;i<m;i++)
		printf(" %c ",f[i]);

		printf("}\n");
		printf("Continue(0/1)?");
		scanf("%d%c",&z,&ch);
	}
	while(z==1);
	return(0);
}

void Find_First(char* array, char ch)
{
	int count, j, k;
	char temporary_result[20];
	int x;
	temporary_result[0] = '\0';
	array[0] = '\0';
	if(!(isupper(ch)))
      {
            Array_Manipulation(array, ch);
            return ;
      }
      for(count = 0; count < limit; count++)
      {
            if(a[count][0] == ch)
            {
                  if(a[count][2] == '$') 
                  {
                        Array_Manipulation(array, '^');
                  }
                  else
                  {
                        j = 2;
                        while(a[count][j] != '\0')
                        {
                              x = 0;
                              Find_First(temporary_result, a[count][j]);
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    Array_Manipulation(array,temporary_result[k]);
                              }
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    if(temporary_result[k] == '^')
                                    {
                                          x = 1;
                                          break;
                                    }
                              }
                              if(!x)
                              {
                                    break;
                              }
                              j++;
                        }
                  }     
            }
      }
      return;
}
 
void Array_Manipulation(char array[], char value)
{
      int temp;
      for(temp = 0; array[temp] != '\0'; temp++)
      {
            if(array[temp] == value)
            {
                  return;
            }
      }
      array[temp] = value;
      array[temp + 1] = '\0';
}

void first(char c)
 {
  int k;
   if(!isupper(c))
    f[m++]=c;
     for(k=0;k<n;k++)
      {
       if(a[k][0]==c)
 {
   if(a[k][2]=='$')
    follow(a[k][0]);
   else if(islower(a[k][2]))
    f[m++]=a[k][2];
   else first(a[k][2]);
 }
       }
     }
     
 void follow(char c)
  {
   if(a[0][0]==c)
    f[m++]='$';
   for(i=0;i<n;i++)
    {
     for(j=2;j<strlen(a[i]);j++)
      {
       if(a[i][j]==c)
 {
   if(a[i][j+1]!='\0')
     first(a[i][j+1]);
    if(a[i][j+1]=='\0' && c!=a[i][0])
     follow(a[i][0]);
  }
       }
     }
   }
 /* OUTPUT:
 Enter the no of prooductions:
5
Enter the productions:
S=AbCd
A=Cf
A=a
C=gE
E=h
Enter the elemets whose fisrt & follow is to be found:S
First(S)={ga}
Follow(S)={$}
Continue(0/1)?1
Enter the elemets whose fisrt & follow is to be found:A
First(A)={ga}
Follow(A)={b}
Continue(0/1)?1
Enter the elemets whose fisrt & follow is to be found:C
First(C)={g}
Follow(C)={df}
Continue(0/1)?1
Enter the elemets whose fisrt & follow is to be found:E
First(E)={h}
Follow(E)={df}
Continue(0/1)?0
*/

