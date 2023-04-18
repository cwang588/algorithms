#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[100005],col[100005];
queue<int>q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	int num=0;
	for(int i=1;i<=n;++i)
	{
		if(!usd[i])
		{
			int tot=1,ans=1;
			usd[i]=col[i]=true;
			q.push(i);
			while(!q.empty())
			{
				int now=q.front();
				q.pop();
				for(int i=Head[now];i;i=e[i].nxt)
				{
					int to=e[i].to;
					if(usd[to])
					{
						if(col[to]^col[now])continue;
						else return !printf("Impossible\n");
					}
					usd[to]=true;
					col[to]=col[now]^true;
					if(col[to])++ans;
					++tot;
					q.push(to);
				}
			}
			num+=min(ans,tot-ans);
		}
	}
	printf("%d\n",num);
	return 0;
} 
