#include<bits/stdc++.h>
using namespace std;
set<int>s[100005];
struct edge
{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005],depth[100005],sz[100005],son[100005];
long long Max,sum;
long long ans[100005];
bool usd[100005];
void add(int x,int y)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs1(int now,int pre)
{
	depth[now]=depth[pre]+1;
	sz[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		dfs1(to,now);
		sz[now]+=sz[to];
		if(sz[to]>sz[son[now]])son[now]=to;
	}
}
void dfs2(int now,int pre)
{
	s[now].insert(now);
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre||to==son[now])continue;
		dfs2(to,now);
	}
	if(son[now])
	{
		int tmp=son[now];
		dfs2(son[now],now);
		ans[now]=ans[tmp];
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre||to==tmp)continue;
			auto ss=s[to].begin();
			while(ss!=s[to].end())
			{
				int t=*ss;
				++ss;
				auto s1=s[tmp].lower_bound(t),s2=s[tmp].upper_bound(t);
				if(s1==s[tmp].end())
				{
					auto stmp=s[tmp].end();
					--stmp;
					ans[now]+=(long long)(t-*stmp)*(t-*stmp);
				}
				else if(s2==s[tmp].begin())
				{
					auto stmp=s[tmp].begin();
					ans[now]+=(long long)(t-*stmp)*(t-*stmp); 
				}
				else
				{
					--s1;
					int t1=*s1,t2=*s2;
					ans[now]-=(long long)(t1-t2)*(t1-t2);
					ans[now]+=(long long)(t1-t)*(t1-t)+(long long)(t2-t)*(t2-t); 
				}
				s[tmp].insert(t);	
			}
			s[to].clear();
		}
		int t=now;
		auto s1=s[tmp].lower_bound(t),s2=s[tmp].upper_bound(t);
		if(s1==s[tmp].end())
		{
			auto stmp=s[tmp].end();
			--stmp;
			ans[now]+=(long long)(t-*stmp)*(t-*stmp);
		}
		else if(s2==s[tmp].begin())
		{
			auto stmp=s[tmp].begin();
			ans[now]+=(long long)(t-*stmp)*(t-*stmp); 
		}
		else
		{
			int t1=*s1,t2=*s2;
			ans[now]-=(long long)(t1-t2)*(t1-t2);
			ans[now]+=(long long)(t1-t)*(t1-t)+(long long)(t2-t)*(t2-t); 
		}
		s[tmp].insert(t);
		s[now].swap(s[tmp]);
	//	s[tmp].clear(); 
	}
}
int main()
{
//	freopen("6.in","r",stdin);
//	freopen("ans.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
		add(i,x);
	} 
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
	return 0;
}
