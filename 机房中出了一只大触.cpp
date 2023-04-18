#include<cstdio>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,int>q;
char fc[50005];
void init()
{
	bool dh=false;
	int len=strlen(fc);
	int now=0;
	while(now<len)
	{
		if(fc[now]=='=')
		{
			dh=true;
			
		}
	}		
}
int main()
{
	cin>>fc;
	init();	
	
	
	return 0;
}
