#include<bits/stdc++.h>
using namespace std;
int a[2005],b[2005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int ans=2147483647;
	for(int i=1;i<=n;++i)
	{
		int x=(b[1]-a[i]+m)%m;
		bool ky=true;
		for(int j=2;j<=n;++j)
		{
			int now=i+j-1;
			if(now>n)now-=n;
			if((b[j]-a[now]+m)%m!=x)
			{
				ky=false;
				break;
			}
		}
		if(ky)ans=min(ans,x); 
	}
	printf("%d\n",ans);
	return 0;
}
