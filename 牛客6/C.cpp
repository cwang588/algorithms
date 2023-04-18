#include<cstdio>
#include<algorithm>
using namespace std;
struct color
{
	int a,b;
}c[100005];
bool cmp(color x,color y)
{
	return x.b>y.b;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&c[i].a);
	for(int i=1;i<=m;++i)
		scanf("%d",&c[i].b);
	sort(c+1,c+1+m,cmp);
	int now=1,tot=0;
	long long ans=0;
	for(int i=1;i<=m;++i)
	{
		if(tot+c[i].a>n)
		{
			ans+=(n-tot)*c[i].b;
			break;
		}
		tot+=c[i].a;
		ans+=c[i].a*c[i].b;
	}
	printf("%lld",ans);
	return 0;
}
