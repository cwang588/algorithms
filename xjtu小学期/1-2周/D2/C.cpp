#include<bits/stdc++.h>
using namespace std;
struct yk
{
	long long a,b;
}x[100005];
bool cmp(yk p,yk q)
{
	return (double)p.a/(double)p.b>(double)q.a/(double)q.b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&x[i].a,&x[i].b);
	sort(x+1,x+1+n,cmp);
	long long tot=0,ans=0;
	for(int i=1;i<=n;++i)
	{
		tot+=x[i].b;
		ans+=x[i].a*tot;
	}
	printf("%lld",ans);
	return 0;
}
