#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,k,x,y;
int first[N+5],nxt[2*N+5],to[2*N+5],len;
void add(int x,int y)
{
	nxt[len]=first[x];
	first[x]=len;
	to[len]=y;
	len++;
}
bool vis[N+5];
int depth[N+5],tox[N+5],toy[N+5];
int toward[N+5],lazy[N+5],Q[N+5];
int cnt,resp;
string ans[N+5];
void dfs(int t)
{
	if(cnt==k)return;
	if(m+2+resp<n+t)return;
	if(t==m+1)
	{
		if(resp==n-1)
		{
			cnt++;
			for(int i=1;i<=m;i++)
			{
				if(toward[i]==1)
					ans[cnt]+="1";
				else 
					ans[cnt]+="0";
			}
		}
		return;
	}
	if(toward[t]==-1)
	{
		dfs(t+1);
		return;
	}
	Q[tox[t]]--;
	if(lazy[tox[t]]==0&&toward[t]==0)
	{
		toward[t]=1;
		lazy[tox[t]]=1;
		resp++;
		dfs(t+1);
		resp--;
		lazy[tox[t]]=0;
		toward[t]=0;
	}
	if(Q[tox[t]]==0&&lazy[tox[t]]==0)
	{
		Q[tox[t]]++;
		return;
	}
	dfs(t+1);
	Q[tox[t]]++;
}
queue<int>q;
void bfs()
{
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		for(int i=first[tmp];;i=nxt[i])
		{
			if(i==-1) 
				break;
			int u=to[i];
			if(vis[u])
				continue;
			vis[u]=true;
			depth[u]=depth[tmp]+1;
			q.push(u);
		}
	}	
	
}
int main()
{
 	scanf("%d%d%d",&n,&m,&k);
	memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		tox[i]=x;
		toy[i]=y;
	}
	q.push(1),vis[1]=true;
	depth[1]=1;
	bfs();
	for(int i=1;i<=m;i++)
	{
		if(!(depth[tox[i]]>=depth[toy[i]]))
		{
			int tttt;
			tttt=tox[i];
			tox[i]=toy[i];
			toy[i]=tttt;
		}
		if(depth[tox[i]]==depth[toy[i]]+1)
			Q[tox[i]]++;
		if(depth[tox[i]]==depth[toy[i]])
		    toward[i]=-1;
	}
	dfs(1);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=0;j<m;j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
}

