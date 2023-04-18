#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n,m,c;
int sum[100050*4],col[100050*4],Max[100005*4];
int a[100005];
vector<int>v[100005];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=col[rt]=Max[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	sum[rt]=col[rt]=Max[rt]=0;
	build(lson);
	build(rson);
}
void push_col(int l,int r,int rt)
{
	if(col[rt])
	{
		int m=(l+r)>>1;
		col[rt<<1]+=col[rt];
		col[rt<<1|1]+=col[rt];
		Max[rt<<1]+=col[rt];
		Max[rt<<1|1]+=col[rt];
		sum[rt<<1]+=(m-l+1)*col[rt];
		sum[rt<<1|1]+=(r-m)*col[rt];
		col[rt]=0;		
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long k)
{
	if(nowl>nowr)return;
	if(nowl<=l&&r<=nowr)
	{
		col[rt]+=k;
		sum[rt]+=(r-l+1)*k;
		Max[rt]+=k;
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr,k);
	if(nowr>m)modify(rson,nowl,nowr,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int query(int l,int r,int rt)
{
	if(l==r)return l;
	int m=(l+r)>>1;
	push_col(l,r,rt);
	if(Max[rt<<1]==c)return query(lson);
	else return query(rson);
}
int pos[100005];
int main()
{
	while(~scanf("%d%d%d",&n,&c,&m))
	{
		memset(pos,0,sizeof(pos));
		build(1,n,1);
		for(int i=1;i<=c;++i)v[i].clear(),v[i].push_back(0);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),v[a[i]].push_back(i);
		if(m==1)
		{
			printf("%d\n",n);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			modify(1,n,1,i,i,c-1);
			++pos[a[i]];
			if(a[i]!=a[i-1])
			{
			//	printf("%d %d\n",v[a[i]][pos[a[i]]-1]+1,i-1);
				modify(1,n,1,v[a[i]][pos[a[i]]-1]+1,i-1,-1);
			}
			if(pos[a[i]]>=m)modify(1,n,1,v[a[i]][pos[a[i]]-m]+1,v[a[i]][pos[a[i]]-m+1],1);
			if(Max[1]==c)ans=max(i-query(1,n,1)+1,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
