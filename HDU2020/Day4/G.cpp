#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
}e[200005];
int Head[500005],cnt,x[100005],y[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int mch[100005],vis[100005];
bool dfs(int now,int t)
{
	if(vis[now]==t)return false;
	vis[now]=t;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if((!mch[to])||dfs(mch[to],t))
		{
			mch[to]=now;
			return true;
		}
	}
	return false;
}
vector<int>l,r;
int getl(int x){return lower_bound(l.begin(),l.end(),x)-l.begin()+1;}
int getr(int x){return lower_bound(r.begin(),r.end(),x)-r.begin()+1;}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		l.clear();
		r.clear();
		memset(Head,0,sizeof(Head));
		memset(mch,0,sizeof(mch));
		memset(vis,0,sizeof(vis));
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			int tx,ty;
			scanf("%d%d",&tx,&ty);
			x[i]=tx+ty;
			y[i]=tx-ty;	
			l.push_back(x[i]);
			r.push_back(y[i]);
		}
		sort(l.begin(),l.end());
		sort(r.begin(),r.end());
		l.erase(unique(l.begin(),l.end()),l.end());
		r.erase(unique(r.begin(),r.end()),r.end());
		for(int i=1;i<=n;++i)add(getl(x[i]),getr(y[i]));
		int ans=0,tot=l.size();
		for(int i=1;i<=tot;++i)if(dfs(i,i))++ans;
		printf("%d\n",ans);
	}
	return 0;
}
