#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long val;
}e[1000005];
int Head[500005],cnt;
bool usd[500005];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;	
	e[cnt].to=y;	
	e[cnt].val=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int num[500005],summax[500005],sumson[500005];
/*
num:number of usd point below pointnow      
summax:maxdis below pointnow
sumson:index of the son which determine the maxdis of pointnow
*/
long long dismax[500005],ans[500005],distot[500005],distmp[500005],updis[500005];
/*
dismax:max distance of pointnow
ans:ans of pointnow
distot:the total distance bewteen pointnow and all the usd point
distmp:the second max distance below pointnow
*/
long long tot;
void dfs1(int now,int pre)
{
	if(usd[now])num[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		num[now]+=num[to];
		if(num[to])tot+=e[i].val;
	}
}
void dfs2(int now,int pre)
{
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		if(num[to])distot[to]=tot;
		else distot[to]=distot[now]+e[i].val;
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs2(to,now);
		if(num[to])
		{
			if(dismax[to]+e[i].val==dismax[now])++summax[now];
			else if(dismax[to]+e[i].val>dismax[now])
			{
				summax[now]=1;
				dismax[now]=dismax[to]+e[i].val;
				sumson[now]=to;
			}
			else;
		}
	}
	if(summax[now]>1)distmp[now]=dismax[now];
	else
	{
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre)continue;
			if(dismax[to]+e[i].val<dismax[now]&&num[to])distmp[now]=max(distmp[now],dismax[to]+e[i].val);
		}
	}
}
void dfs3(int now,int pre)
{
	ans[now]=2*distot[now];
	if(!num[now])ans[now]-=updis[now];
	else ans[now]-=max(updis[now],dismax[now]);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		updis[to]=updis[now]+e[i].val;
		if(summax[now]>1||sumson[now]!=to)updis[to]=max(updis[to],e[i].val+dismax[now]);
		else updis[to]=max(updis[to],e[i].val+distmp[now]);
		dfs3(to,now);
	}
}
int main()
{
//	freopen("datax.in","r",stdin);
//	freopen("try1.out","w",stdout);
//	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;++i)
	{
		int x,y;
		long long z;
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	int root;
	for(int i=1;i<=k;++i)
	{
		int t;
		scanf("%d",&t);
		usd[t]=true;
		root=t;
	}
	dfs1(root,0);
	distot[root]=tot;
	dfs2(root,0);
	dfs3(root,0);
	for(int i=1;i<=n;++i)cout<<ans[i]<<endl;
	return 0;
}
