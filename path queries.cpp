#include<bits/stdc++.h>
using namespace std;
struct query
{
	int k,id;
	long long ans;
}q[200005];
struct edge
{
	int from,to,v,nxt;
}e[400005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qq;
int cnt,Head[200005];
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int fa[200005],s[200005];
int getfa(int x)
{
	if(fa[x]==x)return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void merge(int a,int b)
{
	fa[b]=a;
}
bool cmp1(query x,query y)
{
	return x.k<y.k;
}
bool cmp2(query x,query y)
{
	return x.id<y.id;
}
long long calc(int x)
{
	long long t=x;
	return t*(t-1)/2;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
		qq.push(make_pair(z,cnt));
	}
	for(int i=1;i<=m;++i)scanf("%d",&q[i].k),q[i].id=i;
	sort(q+1,q+1+m,cmp1);
	for(int i=1;i<=n;++i)fa[i]=i,s[i]=1;
	long long ans=0;
	for(int i=1;i<=m;++i)
	{
		while(!qq.empty()&&qq.top().first<=q[i].k)
		{
			int now=qq.top().second;
			qq.pop();
			int x=e[now].from,y=e[now].to;
			int r1=getfa(x),r2=getfa(y);
			ans=ans-calc(s[r1])-calc(s[r2])+calc(s[r2]+s[r1]);
			merge(r1,r2);
			s[r1]+=s[r2];
		}
		q[i].ans=ans;
	}
	sort(q+1,q+1+m,cmp2);
	for(int i=1;i<=m;++i)
		printf("%lld ",q[i].ans);
	return 0;
} 
