#include<bits/stdc++.h>
#define ll long long
#define mid (l+r)/2
using namespace std;
const int N=2e5+10,M=50,lim=1e9+7;
int T,n,m,t;
int ax[N][2],mx[N][2],mn[N][2];
struct st
{
	int nxt,to;
}ed[N<<1]; int head[N],num;
void add(int from,int to)
{
	ed[++num].to=to;
	ed[num].nxt=head[from];
	head[from]=num;
}
int dfn[N]; bool qt;
void dfs(int x,bool pre)
{
	if(qt)return; dfn[x]=pre^1;
	mx[t][0]=max(mx[t][0],ax[x][dfn[x]]);
	mn[t][0]=min(mn[t][0],ax[x][dfn[x]]);
	mx[t][1]=max(mx[t][1],ax[x][dfn[x]^1]);
	mn[t][1]=min(mn[t][1],ax[x][dfn[x]^1]);
	for(int u,i=head[x];i;i=ed[i].nxt)
	{
		u=ed[i].to;
		if(~dfn[u])
		{
			if(dfn[u]==dfn[x])qt=1;
		}
		else dfs(u,dfn[x]);
		if(qt)return;
	}
}
int L[N*M],R[N*M],tag[N*M],tot,rt;
void change(int &nd,int l,int r,int lst,int rst,int v)
{
	if(lst>rst||l>r)return;
	if(!nd)nd=++tot,tag[nd]=lim;
	if(l>=lst&&r<=rst)
	{
		tag[nd]=min(tag[nd],v);
		return;
	}
	if(lst<=mid)change(L[nd],l,mid,lst,rst,v);
	if(rst>mid)change(R[nd],mid+1,r,lst,rst,v);
}
int as,str,ans;
void query(int nd,int l,int r,int pos)
{
	if(l>r)return;
	if(!nd)return;
	as=min(as,tag[nd]);
	if(l==r)return;
	if(pos<=mid)query(L[nd],l,mid,pos);
	else query(R[nd],mid+1,r,pos);
}
map<int,bool> mp;
void init()
{
	mp.clear(),rt=str=qt=num=t=tot=0;
	for(int i=1;i<=n;i++)dfn[i]=-1,head[i]=0;
	for(int i=1;i<=n;i++)mn[i][0]=mn[i][1]=lim;
	for(int i=1;i<=n;i++)mx[i][0]=mx[i][1]=0;
	for(int i=1;i<=n*M;i++)L[i]=R[i]=0;
}
int main()
{
	int u,v; scanf("%d",&T);
	for(int kk=1;kk<=T;kk++)
	{
		scanf("%d%d",&n,&m),init();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),add(u,v),add(v,u);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&ax[i][0],&ax[i][1]);
		for(int i=1;i<=n;i++)
			if(!(~dfn[i]))++t,dfs(i,0);
		if(qt){printf("Case %d: IMPOSSIBLE\n",kk);continue;}
		for(int i=1;i<=t;i++)
		{
			if(mx[i][0]>mx[i][1])
				swap(mx[i][0],mx[i][1]),swap(mn[i][0],mn[i][1]);
			if(mn[i][0]>=mn[i][1])change(rt,1,lim,mx[i][0],lim,mn[i][0]);
			else
			{
				change(rt,1,lim,mx[i][0],mx[i][1]-1,mn[i][0]);
				change(rt,1,lim,mx[i][1],lim,mn[i][1]);
			}
		}
		for(int i=1;i<=t;i++)
			str=max(str,mx[i][0]);
		as=lim,query(rt,1,lim,str);
		ans=str-as,mp[str]=1;
		for(int i=1;i<=t;i++)
		{
			as=lim;
			if(mx[i][1]>=str&&(!mp.count(mx[i][1])))
			{
				query(rt,1,lim,mx[i][1]);
				ans=min(ans,mx[i][1]-as);
				mp[mx[i][1]]=1;
			}
		}
		printf("Case %d: %d\n",kk,ans);
	}
	return 0;
}
/*
1
2 0
2 1
3 5
*/
