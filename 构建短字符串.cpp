#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int a[26],b[26];
int main()
{
	//freopen("test.txt","r",stdin);
    char line[1000001];
    while (cin.getline(line, 1000000)) 
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		bool qh=false;
		for(int i=0;i<strlen(line);++i)
		{
			if(line[i]==' ')
			{
				qh=true;
				continue;
			} 
			if(!qh)
				++a[line[i]-'a'];
			else
				++b[line[i]-'a'];
		}
		bool can=true;
		for(int i=0;i<26;++i)
			if(a[i]>b[i])
			{
				can=false;
				break;
			}
		if(can)
			printf("true\n");
		else
			printf("false\n");
    }
    
    return 0;
}
