#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int N=2e5+6;
int L=0,R=0;
long long sum[N*4],col[N*4],Min[N*4];
int tot,kh[N],shu,ans[N];
int n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		++shu; 
		char c;
		cin>>c;
		if(c=='(')
		{
			kh[shu]=1;
			++tot;	
			++L;
		}
		else
		{
			kh[shu]=-1;
			--tot;	
			++R;
		}
		Min[rt]=sum[rt]=tot;		
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
void color(int l,int r,int rt,long long c)
{
	col[rt]+=c;
	sum[rt]+=(r-l+1)*c;
	Min[rt]+=c;
}
void push_col(int l,int r,int rt)
{
	if(col[rt])
	{
		int m=(l+r)>>1;
		color(lson,col[rt]);
		color(rson,col[rt]);
		col[rt]=0;
	}
}
void modify(int l,int r,int rt,int nowl,int nowr,long long c)
{
	if(nowl<=l&&r<=nowr)
	{
		color(l,r,rt,c);
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(m>=nowl)
		modify(lson,nowl,nowr,c);
	if(m<nowr)
		modify(rson,nowl,nowr,c);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl<=l&&nowr>=r)
		return Min[rt];
	push_col(l,r,rt);
	long long ans=999999;
	int m=(l+r)>>1;
	if(m>=nowl)
		ans=min(ans,query(lson,nowl,nowr));
	if(m<nowr)
		ans=min(ans,query(rson,nowl,nowr));
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	for(int i=1;i<=m;++i)
	{
		int t;
		scanf("%d",&t);
		if(kh[t]==1)
		{
			modify(1,n,1,t,n,-2);
			--L;
			++R;
			kh[t]=-1;
			if(query(1,n,1,1,n)>=0&&L==R)
				ans[i]=1;
		}
		else
		{
			modify(1,n,1,t,n,2);
			++L;
			--R;
			kh[t]=1;
			if(query(1,n,1,1,n)>=0&&L==R)
				ans[i]=1;
		}
	}
	for(int i=1;i<=m;++i)
		printf("%d",ans[i]);
	return 0;
} 
