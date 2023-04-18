#include<cstdio>
#include<algorithm>
using namespace std;
int x[100005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	
		scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int t;
		scanf("%d",&t);
		int l=1,r=n;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(x[m]>t)
				r=(l+r)>>1;
			else
				l=(l+r)>>1;
		}
		if(abs(t-x[l])<=abs(x[r]-t))
			printf("%d\n",x[l]);
		else
			printf("%d\n",x[r]);
	}
	return 0;
}
