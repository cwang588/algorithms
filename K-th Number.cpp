#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100005;
struct node
{
	int l,r,sum;
}T[N*40];
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[N],root[N],cnt;
int build(int l,int r,int node)
{
	node=++cnt;
	if(l==r)
	{
		T[node].sum=0;
		return node;
	}
	int m=(l+r)>>1;
	T[node].l=build(l,m,T[node].l);
	T[node].r=build(m+1,r,T[node].r);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;
}
int modify(int l,int r,int node,int pos)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		++T[node].sum;
		return node;
	}
	int m=(l+r)>>1;
	if(m>=pos)T[node].l=modify(l,m,T[node].l,pos);
	else T[node].r=modify(m+1,r,T[node].r,pos);
	T[node].sum=T[T[node].l].sum+T[T[node].r].sum;
	return node;
}
int query(int l,int r,int nodex,int nodey,int k)
{
	if(l==r)return l;
	int m=(l+r)>>1;
	int re=T[T[nodey].l].sum-T[T[nodex].l].sum;
	if(re>=k)return query(l,m,T[nodex].l,T[nodey].l,k);
	else return query(m+1,r,T[nodex].r,T[nodey].r,k-re);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	root[0]=build(1,n,0);
	for(int i=1;i<=n;++i)root[i]=modify(1,n,root[i-1],getid(a[i]));
	for(int i=1;i<=m;++i)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",v[query(1,n,root[l-1],root[r],k)-1]);
	}
	return 0;
}
