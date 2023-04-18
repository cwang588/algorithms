#include<bits/stdc++.h>
using namespace std;
long long mod;
int n=2;
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
	unsigned long long k,m;
	cin>>k>>mod;
	matrix ans;
	ans.build();
	t.a[1][1]=t.a[1][2]=t.a[2][1]=1; 
	while(k)
	{
		if(k&1)
			ans=ans*t;
		t=t*t;
		k>>=1;
	}
	cout<<ans.a[1][2]*2%mod;
	return 0;
}
