#include<iostream>
#include<string.h>
/*
   TEST CASE : 
   1 :---------> regular expresion : /\/\/\/* 
      ---------> string is : \\\* -----> its true 
      
      
   2 :---------> REGULAR EXPRESION : /+/+/+/++/**
      ---------> string is : "++++++++++++++++++++++++" --------->its true 
   
    
 */
 
using  namespace std;
int main()
{
       cout<<" if you want to use SYMBOL before the symbol put '/'........ "<<endl;
	string reg,str;
	cout<<"enter the regex  :";cin>>reg;
	cout<<"enter the string :";cin>>str;
	int x =0,j=0,i=0;
	for( i =0;i<reg.size();i++)
	 {
               
	 	if((reg[i]>='a' && reg[i]<='z') || (reg[i]>='A' && reg[i]<='Z') || (reg[i]>='0' && reg[i]<='9') || reg[i]=='/')
	 	{
                        if(reg[i]=='/') i++;
                        if(reg[i+1]!='*' && reg[i+1]!='+' && reg[i+1]!='?')
	 		{
                                
	 			if(reg[i]==str[j])
	 			{
	 				j=j+1;
	 				x=0;
	 				continue;
				 }
				 else if(x==1)
				 {
				 	x =0;
				 	if(reg[i]==str[j-1])
					   continue;
				    else
				     {
				     	cout<<"error........";
				     	break;
					 }
				}
				else
				 {
				 	cout<<"error.........";
				 	break;
				 }
				
			 
			}
			else
			  continue;
			  
			 
		 }
		 else if(reg[i]=='*')
		 {
		 	x =1;
		 	while(reg[i-1]==str[j])
		 	{
		 		j=j+1;
                                
			 }
		 }
		 else if(reg[i]=='+')
		 {
		 	if(reg[i-1]==str[j]){
			 j++;
			 x=0;
			 
			
	     	}
		 	else if(x==1)
             {
             	x=0;
             	if(reg[i-1]==str[j-1]) x=0;
             	else {
				  cout<<"error.........";
             	  break;
               }
               
		    }
			else {
			  cout<<"error.......";
			  break;
	    	}

	    	while(reg[i-1]==str[j])
	    	 {
	    	 	j++;
	    	    if(reg[i+2]=='*' && reg[i+2]=='?' )	x=1;
			 }
			 
	 	  }
	 	  else if(reg[i]=='?')
	 	  {
	 	  	if(reg[i-1]==str[j])
	 	  	{
	 	  		x =1;
	 	  		j++;
	 	  		continue;
			}
			else continue;
		   }
                
	 	 
	 }
	 
	 if( i == reg.size() && j==str.size())
	    cout<<"success......";
	else 
	    cout<<"1 st error.....";
}