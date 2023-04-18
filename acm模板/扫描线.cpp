//…®√Ëœﬂ 
#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define int long long
using namespace std;
struct line
{
	int l,r,h,f;
}ll[9000005];
int cnt,m;
struct point
{
	int xx1,xx2,yy1,yy2;
}p[9000005];
struct node
{
	int l,r,num;
	long long sum;
}T[9000005];
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
bool cmp(line a,line b)
{
	if(a.h!=b.h)return a.h<b.h;
	return a.f>b.f;
}
void build(int l,int r,int rt)
{
	T[rt].l=l;
	T[rt].r=r;
	T[rt].sum=0;
	T[rt].num=0;
	if(l==r)return;
	int m=(l+r)>>1;
	build(lson);
	build(rson);
}
void push_up(int rt,long long c)
{
	T[rt].sum=c;
}
void modify(int l,int r,int rt,int nowl,int nowr,int c)
{
	if(l>=nowl&&r<=nowr)
	{
		T[rt].num+=c;
		if(T[rt].num)push_up(rt,v[r]-v[l-1]);
		else T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;	
		return;	
	}
	int m=(l+r)>>1;
	if(m>=nowl)modify(lson,nowl,nowr,c);
	if(m<nowr)modify(rson,nowl,nowr,c);
	if(!T[rt].num)T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;
	else push_up(rt,v[r]-v[l-1]);
}
signed main()
{
	int n; 
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld%lld",&p[i].xx1,&p[i].yy1,&p[i].xx2,&p[i].yy2);
		v.push_back(p[i].xx1);
		v.push_back(p[i].xx2);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int N=v.size();
	for(int i=1;i<=n;++i)
	{
		++cnt;
		ll[cnt].l=getid(p[i].xx1);
		ll[cnt].r=getid(p[i].xx2);
		ll[cnt].h=p[i].yy1;
		ll[cnt].f=1;
		++cnt;
		ll[cnt].l=getid(p[i].xx1);
		ll[cnt].r=getid(p[i].xx2);
		ll[cnt].h=p[i].yy2;
		ll[cnt].f=-1;
	}
	sort(ll+1,ll+1+cnt,cmp);
	long long ans=0;
	--N;
	build(1,N,1);
	for(int i=1;i<=cnt;++i)
	{
		modify(1,N,1,ll[i].l,ll[i].r-1,ll[i].f);
		ans+=(ll[i+1].h-ll[i].h)*(T[1].sum);
	}
	cout<<ans;
	return 0;
}
