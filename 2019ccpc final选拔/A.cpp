#include<bits/stdc++.h>
using namespace std;
string s; 
int main()
{
	int num1=0,num2=0;
	cin>>s;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='0')++num1;
		else ++num2;
	}
	if(num1>num2)
	{
		for(int i=0;i<s.length();++i)
			printf("1");
	}
	else if(num1<num2)
	{
		for(int i=0;i<s.length();++i)
			printf("0");		
	}
	else 
	{
		if(s[0]=='1')
		{
			printf("0");
			for(int i=1;i<s.length();++i)printf("1");
		}
		else
		{
			printf("1");
			for(int i=1;i<s.length();++i)printf("0");			
		}
	}
	return 0;
}
