#include<bits/stdc++.h>
using namespace std;
char s[105];
bool usd[10000005];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--)
	{
		cin>>(s+1);
		if(strlen(s+1)>7)continue;
		if(s[1]=='-')continue;
		int now=0,num=strlen(s+1);
		for(int i=1;i<=num;++i)now=now*10+s[i]-'0';
		usd[now]=true;
	}
	for(int i=0;i<=1000001;++i)if(!usd[i])return !printf("%d\n",i);
	return 0;
}
