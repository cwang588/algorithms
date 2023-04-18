#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
long long d;
int m;
struct node
{
	int l,r;
	long long Max;
	node()
	{
		Max=0;
	}
}T[800005];
int num;
void update(int rt)
{
	T[rt].Max=max(T[rt<<1].Max,T[rt<<1|1].Max);
}
void modify(int l,int r,int rt,int pos,long long c)
{
	if(l==r)
	{
		T[rt].Max=c;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,c);
	else modify(rson,pos,c);
	update(rt);
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return T[rt].Max;
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re=max(query(lson,nowl,nowr),re);
	if(nowr>m)re=max(query(rson,nowl,nowr),re);
	return re;
}
int main()
{
	long long t=0; 
	scanf("%d%lld",&m,&d);
	for(int i=1;i<=m;++i)	
	{
		char tmp;
		cin>>tmp;
		if(tmp=='A')
		{
			long long sum;
			cin>>sum;
			sum=(sum+t)%d;
			modify(1,m,1,++num,sum);
		}
		else
		{
			int len;
			cin>>len;
			t=query(1,m,1,num-len+1,num);
			printf("%lld\n",t);
		}
	}
	return 0;
}
