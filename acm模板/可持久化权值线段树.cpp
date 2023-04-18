#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+7;
struct node{int l,r,sum;}T[maxn*40];
int root[maxn],a[maxn],cnt;
vector<int>v;
int getid(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;};
int update(int l,int r,int node,int pos)
{
	T[++cnt]=T[node],T[cnt].sum++;
	node=cnt;
	if(l==r)return node;
	int mid=(l+r)>>1;
	if(pos<=mid)T[node].l=update(l,mid,T[node].l,pos);
	else T[node].r=update(mid+1,r,T[node].r,pos);
 return node;
}
int query(int l,int r,int nodel,int noder,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1,sum=T[T[noder].l].sum-T[T[nodel].l].sum;
	if(k<=sum)return query(l,mid,T[nodel].l,T[noder].l,k);
	else return query(mid+1,r,T[nodel].r,T[noder].r,k-sum);
}
int main()
{
	int	n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),v.push_back(a[i]);
	sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)root[i]=update(1,n,root[i-1],getid(a[i]));
	for(int i=1;i<=m;++i)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",v[query(1,n,root[l-1],root[r],k)-1]);
	} 
	return 0;
}
