#include<bits/stdc++.h>
using namespace std;
char t[105];
int num[63];
int sum(int x)
{
	return x*(x-1)/2;
}
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		cin>>t;
		++num[t[0]-'a'];
	}
	int ans=0;
	for(int i=0;i<26;++i)
		if(num[i])
			ans+=sum(num[i]/2)+sum(num[i]-num[i]/2);
	printf("%d",ans);
	return 0;
}
