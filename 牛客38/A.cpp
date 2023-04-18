#include<cstdio>
#include<algorithm>
using namespace std;
int x[100005];
int main()
{
	int n,ans,now=0;
	scanf("%d%d",&n,&ans);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t>ans)
			x[++now]=t;
	}
	sort(x+1,x+1+now);
	double anss=(double)ans;
	for(int i=1;i<=now;++i)
		anss=(anss+x[i])/2;
	printf("%.3f",anss);
	return 0;
}
