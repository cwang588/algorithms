#include<cstdio>
using namespace std;
int x[1005],y[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]); 
	for(int i=1;i<=n;++i)
	{
		int ans=0;
		for(int j=1;j<=n;++j)
			if(x[j]>x[i]&&y[j]>y[i])
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}
