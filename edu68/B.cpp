#include<bits/stdc++.h>
using namespace std;
int a[400005];
char t[400005];
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int now=(i-1)*m+j;
				cin>>t[now];
				if(t[now]=='*')
					a[now]=1;
				if(t[now]>m)
					a[now]+=a[now-m];
				if(now%m!=1)
				{
					a[now]+=a[now-1];
					a[now]-=a[now-m-1];
				}
			}
		int ans=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int now=0;
				now+=a[i*m]-a[(i-1)*m];
				now+=a[(i-1)*m+j];
				if(j!=1)
					now-=a[(i-1)*m+j-1];
				if(t[(i-1)*m+j]=='*')
					--now;
				ans=min(ans,now); 
			}
		printf("%d\n",ans);
	}
	return 0;
}
