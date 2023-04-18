#include<bits/stdc++.h>
using namespace std;
int x[205],y[205],k[205];
int f[200005];
int main()
{
	int n,m; 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",&x[i],&y[i],&k[i]);
	for(int i=1;i<=n;++i)
	{
		if(k[i]==1)
		{
			for(int j=m;j>=x[i];--j)
				if(f[j]<f[j-x[i]]+y[i])
					f[j]=f[j-x[i]]+y[i];
		}
		else
		{
			for(int j=x[i];j<=m;++j)
				if(f[j]<f[j-x[i]]+y[i])
					f[j]=f[j-x[i]]+y[i];			
		}
	}
	printf("%d",f[m]);
	return 0;
}
