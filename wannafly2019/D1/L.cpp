#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int nxt[5005],tot[5005];
bool usd[5005]; 
void dfs(int s)
{
	int now=s;
	tot[now]=1;
	usd[now]=true;
	while(nxt[now])
	{
		if(usd[nxt[now]])
		{
			if(tot[now]-tot[nxt[now]]==2)
			{
				printf("YES");
				exit(0);
			}
			else
				return;
		}
		usd[now]=true;
		tot[nxt[now]]=tot[now]+1;
		now=nxt[now];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&nxt[i]);
	for(int i=1;i<=n;++i)
	{
		memset(usd,false,sizeof(usd));
		memset(tot,0,sizeof(tot));
		dfs(i);
	}
	printf("NO");
	return 0;
} 
