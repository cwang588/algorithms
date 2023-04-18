#include<bits/stdc++.h>
using namespace std;
vector<long long>v;
long long f[100005];
int root[100005],cnt;
struct node
{
	int l,r,sum;
}T[100005*40];
int getid(long long x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void update(int l,int r,int &x,int y,int pos)
{
	T[++cnt]=T[y],T[cnt].sum++,x=cnt;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(mid>=pos)update(l,mid,T[x].l,T[y].l,pos);
	else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k)
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	int sum=T[T[y].l].sum-T[T[x].l].sum;
	if(sum>=k)return query(l,mid,T[x].l,T[y].l,k);
	else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;++i)root[i]=0;
		cnt=0;
		v.clear();
		for(int i=1;i<=n;++i)scanf("%lld",&f[i]),v.push_back(f[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=1;i<=n;++i)update(1,n,root[i],root[i-1],getid(f[i]));
		for(int i=1;i<=m;++i)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(r-l+1<3)
			{
				printf("-1\n");
				continue;
			}
			long long a,b,c;
			a=0,b=0,c=0;
			bool ky=false;
			for(int k=1;k<=r-l+1;++k)
			{
				a=b,b=c;
				c=v[query(1,n,root[l-1],root[r],r-l+2-k)-1];
				if(b+c>a&&b&&a)
				{
					ky=true;
					printf("%lld\n",a+b+c);
					break;
				}
			}
			if(!ky)printf("-1\n");
		}
	}
	return 0;
}
