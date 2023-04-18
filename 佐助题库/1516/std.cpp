#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
long long Abs(long long x)
{
	return x>=0?x:-x;
}
int main()
{
//	freopen("in.in","r",stdin);
//	freopen("out9.out","w",stdout);
	int n,m;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)scanf("%lld",&b[i]);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(b+1,b+1+m);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int l=1,r=m;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(b[mid]>a[i])r=mid;
			else l=mid; 
		}
		ans+=min(Abs(a[i]-b[l]),Abs(b[r]-a[i]));
	}
	printf("%lld\n",ans);
	return 0;
}
