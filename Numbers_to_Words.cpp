#include<iostream>
#include<string.h>
using namespace std;

string tenth[]={"Ten","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
string hundred[]={"One Hundred","Two Hundred","Three Hundred","Four Hundred","Five Hundred","Six Hundred","Seven Hundred","Eight Hundred","Nine Hundred"};
string unit[]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
string value[]={".","Thousand","Million","Billion","Trillion","Quadrillion","Quntillion","Sextillion","Septillion","Octillion","Nonillion","decillion"};
string Eleven_to_nineteen[]={"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

void toWords(char char1,char char2,char char3)
{
	int a=char3-48;
	int b=char2-48;
	int c=char1-48;
	
    if(a==0 && b==0 && c==0)
	{
		return;
	}
    if(a==0 && b!=0 && c==0)
	{
		cout<<tenth[b-1];
	}
	if(a==0 && (b!=0 && b!=1) && c!=0)
	{
		cout<<tenth[b-1]<<" "<<unit[c-1];
	}
	if(a!=0 && b==0 && c!=0)
	{
		cout<<hundred[a-1]<<" "<<unit[c-1];
	}
	if(a!=0 && b!=0 && c==0)
	{
		cout<<hundred[a-1]<<" "<<tenth[b-1];
	}
	if(a!=0 && b==0 && c==0)
	{
		cout<<hundred[a-1];
	}
	if(a==0 && b==0 && c!=0)
	{
		cout<<unit[c-1];
	}
	if(a!=0 && (b!=0 && b!=1) && c!=0)
	{
		cout<<hundred[a-1]<<" "<<tenth[b-1]<<""<<unit[c-1];
	}
	if(a!=0 && b==1 &&c!=0)
	{
		cout<<hundred[a-1]<<" "<<Eleven_to_nineteen[c-1];
	}
	if(a==0 && b==1 && c!=0)
	{
		cout<<Eleven_to_nineteen[c-1];
	}
	
}

int main()
{
    string num;  
	int flag=0;   
	int choice;
    int size,partition;  
	do
	{ 
	    cout<<"Enter number:"<<endl;
	    cin>>num;		
	    size=num.length();
	    
	    if((num[0]=='0') && (num[1]=='0'))
	    {
	    	num.erase(0,1);
	    	num.erase(0,1);
	    	size=num.length();
	    }
	    
	    if(num[0]=='0')
	    {
	    	num.erase(0,1);
	    	size=num.length();
		}
		
	    if(size%3==1)
	    {
	    	num.insert(0,"00");
	    	size=num.length();
	    }
		
		if(size%3==2)
		{
			num.insert(0,"0");
	    	size=num.length();
	    }
		
		
	    int i=0;
	    partition=size/3;
	    cout<<"Given number in words is :\n"<<endl;
		do
		{
			toWords(num[i+2],num[i+1],num[i]);
			cout<<" "<<value[partition-1];
			cout<<endl;
			i=i+3;
			
			partition=partition-1;
		}while(i<size && partition!=0);
		cout<<"\nTo enter another number press 1"<<endl;
        cout<<"press 0 for exit"<<endl;
		cin>>choice;
	}while(choice==1);
    return 0;
}