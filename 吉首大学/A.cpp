#include<bits/stdc++.h>
using namespace std;
const int mod=1000000000+7;
char n[1000005];
struct matrix
{
	long long a[105][105];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
	inline void build()
	{
		for(int i=1;i<=3;++i)
			a[i][i]=1;
	}
}t;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=3;++k)
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
int main()
{
	while(cin>>(n+1))
	{
		int l=strlen(n+1);
		long long m=0;
		for(int i=1;i<=l;++i)
			m=(m*10+n[i]-'0')%mod;
		matrix ans;
		ans.build();
		t.a[1][1]=2;
		t.a[1][2]=1;
		t.a[1][3]=0;
		t.a[2][1]=2;
		t.a[2][2]=0;
		t.a[2][3]=2;
		t.a[3][1]=0;
		t.a[3][2]=1;
		t.a[3][3]=2;
		while(m)
		{
			if(m&1)
				ans=ans*t;
			t=t*t;
			m>>=1;
		}
		printf("%lld\n",ans.a[1][1]);
		memset(n,' ',sizeof(n));
	}
	return 0;
}
