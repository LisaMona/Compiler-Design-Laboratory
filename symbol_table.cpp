/*
Design a DFA that will identify and display the code and values for valid tokens,
manage symbol table for identifiers and constants, and find errors.	
*/

#include<bits/stdc++.h>
using namespace std;
int check(string s)
{
        int l=s.length();
        for(int i=0;i<l;i++)
        {
     		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        		continue;
     		else
      			return 0;
        }
	return 1;
}

string temp="";
int main()
{
	char s[1000];
	cin.getline(s,1000);
	map<string,int>code;
	map<string,string>value;
	code["begin"]=1;
	code["end"]=2;
	code["if"]=3;
	code["else"]=4;
	code["then"]=5;
	code["identifier"]=6;
	code["constant"]=7;
	code["=="]=8;
	code["!="]=8;
	code[">="]=8;
	code["<="]=8;
	code["<"]=8;
	code[">"]=8;

	value["begin"]="-";
	value["end"]="-";
	value["if"]="-";
	value["else"]="-";
	value["then"]="-";
	value["identifier"]="(6,sym_tab_ptr)";
	value["constant"]="(7,sym_tab_ptr)";
	value["=="]="(8,1)";
	value["!="]="(8,2)";
	value[">="]="(8,3)";
	value["<="]="(8,4)";
	value["<"]="(8,5)";
	value[">"]="(8,6)";
	cout<<code["enda"];


	int i=0;
	int l =strlen(s);
	cout<<"token"<<"\t\t"<<"code"<<"\t\t"<<"value"<<"\n";
        while(i<=l)
        {
                if(s[i]==' '||s[i]=='\0')
                {
            		//cout<<temp<<" "<<code[temp]<<"\n";
                        if(code[temp]!=0)
                        	cout<<temp<<"\t\t"<<code[temp]<<"\t\t"<<value[temp]<<"\n";
                        else
                        {
                 		if(temp[0]!='0'||temp[0]!='0'||temp[0]!='0'||temp[0]!='0'||temp[0]!='0'||temp[0]!='0'||temp[0]!='0'||temp[0]!='0')
                    		{    
                     			int p=check(temp);  
                                        if(p==1)
                                        {
                                        	temp="constant";
                                                cout<<temp<<"\t\t"<<code[temp]<<"\t\t"<<value[temp]<<"\n";
                                        }
                               		else  
                               		{  
                               			temp="identifier";
                                  		cout<<temp<<"\t"<<code[temp]<<"\t\t"<<value[temp]<<"\n";
                                  	}
                    		}
               			else
                  			cout<<"invalid IDENTIFIERS\n";      
              		}        
 			temp="";          
        	}
                else
                {
        	        temp=temp+s[i];
        	}
       		i++;
        }
	return 0;
}
