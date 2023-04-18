#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+7;
struct node{int l,r,sum;}T[maxn*40];
int root[maxn],a[maxn],cnt;
int build(int l,int r,int node)
{
	node=++cnt;
	if(l==r)
	{
		T[node].sum=a[l];
		return node;
	}
	int mid=(l+r)>>1;
	T[node].l=build(l,mid,T[node].l);
	T[node].r=build(mid+1,r,T[node].r);
	return node;
}
int update(int l,int r,int node,int pos,int k)
{
	T[++cnt]=T[node];
	node=cnt;
	if(l==r)
	{
		T[node].sum=k;
		return node;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)T[node].l=update(l,mid,T[node].l,pos,k);
	else T[node].r=update(mid+1,r,T[node].r,pos,k);
	return node;
}
int query(int l,int r,int node,int pos)
{
	if(l==r)return T[node].sum;
	int mid=(l+r)>>1;
	if(pos<=mid)return query(l,mid,T[node].l,pos);
	else return query(mid+1,r,T[node].r,pos);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	root[0]=build(1,n,0);
	for(int i=1;i<=m;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(y==1)
		{
			int t;
			scanf("%d",&t);
			root[i]=update(1,n,root[x],z,t);	
		}
		else root[i]=root[x],printf("%d\n",query(1,n,root[x],z));
	}
	return 0; 
}
