#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef unsigned long long ull;
set<ull>s;
int n,m,q;
ull Hash[100005],base[100005];
int sum[100005*4],num[100005],pos[100005];
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum[rt]=n;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void modify(int l,int r,int rt,int pos,int k,int type)
{
	if(l==r)
	{
		if(type==1)++num[l];
		else --num[l];
		Hash[l]^=base[k];
		if(s.find(Hash[l])==s.end())sum[rt]=num[l];
		else sum[rt]=0;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k,type);
	else modify(rson,pos,k,type);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1;
	int re=0;
	if(m>=nowl)re+=query(lson,nowl,nowr);
	if(m<nowr)re+=query(rson,nowl,nowr);
	return re;
} 
int main()
{
	srand((unsigned)time(NULL));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)base[i]=(ull)65535*rand()+rand(),Hash[1]^=base[i],pos[i]=1;
	num[1]=n;
	build(1,m,1);
	for(int i=1;i<=q;++i)
	{
		char t;
		cin>>t;
		if(t=='C')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			modify(1,m,1,pos[x],x,-1);
			modify(1,m,1,y,x,1);
		}
		else 
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",query(1,m,1,x,y));
		}
	}
	return 0;
}
