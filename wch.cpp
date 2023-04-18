#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000000;
struct matrix
{
	long long a[105][105];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
	inline void build()
	{
		for(int i=1;i<=2;++i)
			a[i][i]=1;
	}
}t;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=2;++k)
		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
int main()
{
	long long m;
	scanf("%lld",&m);
	if(m==1)return !printf("1\n");
	if(m==2)return !printf("7\n");
	matrix ans;
	ans.build();
	t.a[1][1]=7;
	t.a[1][2]=-12;
	t.a[2][1]=1;
	t.a[2][2]=0;
	m-=2;
	while(m)
	{
		if(m&1)
			ans=ans*t;
		t=t*t;
		m>>=1;
	}
	printf("%lld\n",(7*ans.a[1][1]+ans.a[1][2]+mod)%mod);
	return 0;
}
