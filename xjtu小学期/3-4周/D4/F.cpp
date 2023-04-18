#include<cstdio>
#include<cstdlib>

int n,ln,st[105],use[35],x;
int cnt[35],head[3005],nx[3005][35];
void dfs(int now,int tot)
{
	if(now==n+1)
	{
		for(int i=1;i<=ln;i++)
			printf("%d ",st[i]);
		exit(0);
	}
	for(int i=head[tot];i;i=nx[tot][i])
	{
		if(use[i]<cnt[i])
		{
			use[i]++;
			st[++ln]=i;
			dfs(now+1,tot+i);
			use[i]--;
			st[ln--]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	for(int i=0;i<=3000;i++)
	{
		for(int j=1;j<=30;j++)
		{
			if(i%j==0)
			{
				nx[i][j]=head[i];
				head[i]=j;
			}
		}
	}
	dfs(1,0);
	printf("-1");
	return 0;
}

