#include<bits/stdc++.h>
using namespace std;
bool usd[105];
char ans[105];
void dfs(char s[],int now)
{
	if(now==strlen(s))
	{
		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<strlen(s);++i)
		if(!usd[i])
		{
			usd[i]=true;
			ans[now]=s[i];
			dfs(s,now+1);
			usd[i]=false;
		}
}
int main()
{
	char s[]="cat";
	dfs(s,0);
	return 0;
}
