#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n,t,ans,Min=999999;
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)
	{
		int s,d;
		scanf("%d%d",&s,&d);
		int now=ceil((double)(t-s)/(double)d);
		now=max(now,0);
		if(s+now*d<Min)
		{
			Min=s+now*d;
			ans=i;
		} 
	}
	printf("%d",ans);
	return 0;
}
