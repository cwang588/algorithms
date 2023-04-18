#include<bits/stdc++.h>
using namespace std;
struct print
{
	int num;
	double price;
}p[1005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&p[i].num);
	for(int i=1;i<=m;++i)
		cin>>p[i].price;
	double ans=9999999.0;
	for(int i=1;i<=m;++i)
	{
		if(n>p[i].num)
		{
			if(n<=p[i+1].num)
				ans=min(ans,(double)n*p[i].price);
			continue;
		}
		ans=min(ans,(double)p[i].num*p[i].price);
	}
	printf("%lf\n",ans);
	return 0;
}
