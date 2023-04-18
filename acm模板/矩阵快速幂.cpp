//¾ØÕó¿ìËÙÃİ 
#include<bits/stdc++.h>
using namespace std;
const int mod=1000000000+7;
int n;
struct matrix
{
	long long a[105][105];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
	inline void build()
	{
		for(int i=1;i<=n;++i)
			a[i][i]=1;
	}
}t;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
int main()
{
	long long m;
	scanf("%d%lld",&n,&m);
	matrix ans;
	ans.build();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%lld",&t.a[i][j]); 
	while(m)
	{
		if(m&1)
			ans=ans*t;
		t=t*t;
		m>>=1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%lld ",ans.a[i][j]);
		printf("\n");
	}
	return 0;
}
