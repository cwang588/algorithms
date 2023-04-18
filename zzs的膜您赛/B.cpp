#include<bits/stdc++.h>
using namespace std;
int a[1505][1505];
long long du[1505];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			char t;
			cin>>t;
			a[i][j]=t-'0';
			if(a[i][j])++du[i],++du[j];	
		}
	for(int i=1;i<=n;++i)du[i]/=2;
	long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			if(a[i][j])
			{
				ans+=(du[i]-1)*(du[j]-1);
				for(int k=1;k<=n;++k)
					if(a[i][k]&&a[j][k])
						--ans;
			}
		}
	printf("%lld\n",ans);
	return 0;
}
