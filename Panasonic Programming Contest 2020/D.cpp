#include<bits/stdc++.h>
using namespace std;
int n;
char s[10005];
void dfs(int now,int Max)
{
	if(now==n+1)
	{
		for(int i=1;i<=n;++i)putchar(s[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=Max;++i)
	{
		s[now]=('a'+i-1);
		dfs(now+1,Max);
	}
	s[now]=('a'+Max);
	dfs(now+1,Max+1);
}
int main()
{
	scanf("%d",&n);
	dfs(1,0);
	return 0;
}
