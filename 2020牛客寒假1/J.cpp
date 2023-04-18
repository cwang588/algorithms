#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
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
}t,ans,anss;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=3;++k)
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%(mod-1))%(mod-1);
	return z;
}
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
int main()
{
	long long x,y,n,a,b;
	cin>>n>>x>>y>>a>>b;
	x%=mod;
	y%=mod;
	a%=mod;
	if(n==1)return !printf("%lld\n",x%mod);
	if(n==2)return !printf("%lld\n",y%mod);
	long long k=quickpower(a,b,mod);
	if(n==3)return !printf("%lld\n",(x*y%mod)*k%mod);
	if(a%mod==0||x%mod==0||y%mod==0)return !printf("0\n");
	t.a[1][1]=t.a[1][2]=t.a[2][1]=1;t.a[2][2]=0;
	ans.build();
	n-=3;
	while(n)
	{
		if(n&1)
			ans=ans*t;
		t=t*t;
		n>>=1;
	}
	long long ans1,ans2,ans3;
	ans1=quickpower(x,(ans.a[1][2]%(mod-1)+ans.a[2][2]%(mod-1))%(mod-1),mod);
	ans2=quickpower(y,(2*ans.a[1][2]%(mod-1)+ans.a[2][2]%(mod-1))%(mod-1),mod);
	ans3=quickpower(k%mod,(2*anss.a[1][2]%(mod-1)+ans.a[2][2]%(mod-1))%(mod-1),mod);
	long long ansss=1;
	ansss=ansss*ans1%mod;
	ansss=ansss*ans2%mod;
	ansss=ansss*ans3%mod;
	printf("%lld\n",anss);	
	return 0;
}
