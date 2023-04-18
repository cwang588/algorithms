	#include<cstdio>
	using namespace std;
	int d[105],a[105],f[105][105];
	int main()
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			scanf("%d",&d[i]);
		for(int i=1;i<=n;++i)
		{
			f[i][i]=1;
			if(i-d[i]>0)
				f[i][i-d[i]]=f[i-d[i]][i]=1;
			if(i+d[i]<=n)
				f[i][i+d[i]]=f[i+d[i]][i]=1;
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					f[i][j]=f[i][j]|(f[i][k]&f[k][j]);
		for(int i=1;i<=n;++i)
			if(!f[i][a[i]])
				return !printf("NO\n");
		printf("YES\n");
		return 0;
	}
