#include<cstdio>
#include<algorithm>
using namespace std;
int shu[200005],a[200005];
int n;
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int re=0;
	while(x)
	{
		re=max(re,shu[x]);
		x-=lowbit(x);
	}
	return re;
}
void add(int x,int sum)
{
	while(x<=n)
	{
		shu[x]=max(shu[x],sum);
		x+=lowbit(x);
	}
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int l=0,r=i;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(a[m]*2<=a[i])
				l=m;
			else
				r=m;
		}	
		int ll=i+1,rr=n;
		while(ll<rr-1)
		{
			int mm=(ll+rr)>>1;
			if(a[mm]<=a[i]*2)
				ll=mm;
			else
				rr=mm;
		}	
		int q=query(r-1)+1;
		add(rr,q);
		ans=max(ans,q);
	}
	printf("%d",ans);
	return 0;
}
