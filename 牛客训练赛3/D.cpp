#include<cstdio>
#include<algorithm>
using namespace std;
struct t
{
	int a,b;
}s[100005];
bool cmp(t x,t y)
{
	return x.a*y.b<y.a*x.b;
}
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
		scanf("%d%d",&s[i].a,&s[i].b);
	sort(s+1,s+1+n,cmp);
	long long ans=0;
	int now=0;
	for(int i=n;i;--i)
	{
		now+=s[i].b;
		ans+=now*s[i-1].a;
	}
	printf("%lld",ans);
	return 0;
}
