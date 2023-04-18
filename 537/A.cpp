#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int x[1050];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	int tot=0;
	if(n%2)
	{
		for(int i=1;i<=n;++i)
			if(x[i]-x[(1+n)/2])
				tot+=abs(x[i]-x[(1+n)/2])-1;
		printf("%d %d",x[(1+n)/2],tot);
	}
	else
	{
		if(x[n/2+1]-x[n/2]<2)
		{
			for(int i=1;i<=n;++i)
				if(x[i]-x[(1+n)/2])
					tot+=abs(x[i]-x[(1+n)/2])-1;
			printf("%d %d",x[n/2],tot);	
		}
		else
		{
			for(int i=1;i<=n;++i)
				tot+=abs(x[i]-x[n/2]-1)-1;
			printf("%d %d",x[n/2]+1,tot);
		}
	}
	return 0;
}
