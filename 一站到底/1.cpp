#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(a,0,sizeof(a));
		int n,k,s;
		scanf("%d%d%d",&n,&k,&s);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i*k<=n;++i)
			ans+=a[i*k];
		printf("%d\n",ans*s);
	}
	return 0;
}
