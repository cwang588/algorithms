#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	int n,m,d;
	scanf("%d%d%d",&n,&d,&m);
	int l1=0,l2=0;
	for(int i=1;i<=n;++i)
	{
		long long t;
		scanf("%lld",&t);
		if(t<=m)a[++l1]=t;
		else b[++l2]=t;
	}
	sort(a+1,a+1+l1);
	sort(b+1,b+1+l2,cmp);
	int now1=0,now2=0;
	long long ans=0;
	int i=1;
	while(i<=n)
	{
		if(now2>=l2-1)
		{
			ans+=b[l2];
			for(int j=now1+1;j<=l1;++j)ans+=a[j];
			break;
		}
		if(now1>=l1-1)
		{
			long long num=(n-i)/(d+1)+1;
			for(int j=1;j<=num;++j)ans+=b[j+now2];
			break;
		}
		ans+=b[++now2];
		for(int j=1;j<=d;++j)
		{
			++i;
			++now1;
		}
		++i;
	}
	printf("%lld\n",ans);
	return 0;
}
