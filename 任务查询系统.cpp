#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
struct rw
{
	int l,r,p;
}w[800005];
struct xg
{
	int pos,sum,c;
}xx[800005];
bool cmp(rw a,rw b)
{
	return a.p<b.p;
}
struct node
{
	int l,r;
	long long sum,num;
}T[16000005];
int root[800005],pos[800005];
int cnt;
int build(int l,int r)
{
	int node=++cnt;
	if(l==r)return node;
	int m=(l+r)>>1;
	T[node].l=build(l,m);
	T[node].r=build(m+1,r);
	return node;
}
int update(int l,int r,int node,int pos,int c)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		T[node].sum+=c*v[pos-1];
		T[node].num+=c;
	}
	else 
	{
		int m=(l+r)>>1;
		if(pos<=m)T[node].l=update(l,m,T[node].l,pos,c);
		else T[node].r=update(m+1,r,T[node].r,pos,c);
		T[node].num=T[T[node].l].num+T[T[node].r].num;
		T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	}
	return node;
}
long long pre=1;
long long getk(int a,int b,int c)
{
	return 1+(pre*a+b)%c;
}
long long query(int l,int r,int node,long long k)
{
	if(l==r)return k*T[node].sum/T[node].num;
	int m=(l+r)>>1;
	if(T[T[node].l].num>=k)return query(l,m,T[node].l,k);
	long long tot=0;
	tot+=T[T[node].l].sum;
	tot+=query(m+1,r,T[node].r,k-T[T[node].l].num);
	return tot;
}
bool cmp1(xg a,xg b)
{
	if(a.pos!=b.pos)return a.pos<b.pos;
	return a.c>b.c;
}
signed main()
{
	int n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld%lld",&w[i].l,&w[i].r,&w[i].p);
		v.push_back(w[i].p);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	sort(w+1,w+n+1,cmp);	
	root[0]=build(1,n);
	for(int i=1;i<=n;++i)
	{
		int poss=getid(w[i].p);
		xx[2*i-1].pos=w[i].l;
		xx[2*i-1].sum=poss;
		xx[2*i-1].c=1;
		xx[2*i].pos=w[i].r+1;
		xx[2*i].sum=poss;
		xx[2*i].c=-1;
	}
	sort(xx+1,xx+1+2*n,cmp1);
	for(int i=1;i<=2*n;++i)
	{
		root[i]=update(0,n,root[i-1],xx[i].sum,xx[i].c);
		pos[xx[i].pos]=max(i,pos[xx[i].pos]);
	}
	for(int i=1;i<=n+1;++i)if(pos[i]<pos[i-1])pos[i]=pos[i-1];
	for(int i=1;i<=m;++i)
	{
		int x,a,b,c;
		scanf("%lld%lld%lld%lld",&x,&a,&b,&c);
		long long k=getk(a,b,c);
		if(T[root[pos[x]]].num<=k)pre=T[root[pos[x]]].sum;
		else pre=query(0,n,root[pos[x]],k);
		printf("%lld\n",pre);
	}
	return 0;
}
