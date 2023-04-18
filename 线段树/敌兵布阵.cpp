#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int sum[2000005],m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		cin>>sum[rt];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt];
	int m=(l+r)>>1,re=0;
	if(m>=nowl)re+=query(lson,nowl,nowr);
	if(m<nowr)re+=query(rson,nowl,nowr);
	return re;
}
void modify(int l,int r,int rt,int pos,int k)
{
	if(l==r)
	{
		sum[rt]+=k;
		return;
	}
	int m=(l+r)>>1;
	if(m>=pos)modify(lson,pos,k);
	else modify(rson,pos,k);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case)
	{
		int n;
		cin>>n;
		build(1,n,1);
		string s;
		cin>>s;
		printf("Case %d:\n",Case);
		while(s!="End")
		{
			int x,y;
			cin>>x>>y;
			if(s=="Query")printf("%d\n",query(1,n,1,x,y));
			else if(s=="Add")modify(1,n,1,x,y);
			else modify(1,n,1,x,-y);
			cin>>s;
		}
	}
	return 0;
}
