#include<bits/stdc++.h>
using namespace std;
char s[15];
const int mod=998244353;
struct matrix
{
	long long a[10][10];
	matrix()
	{
		memset(a,0,sizeof(a));
	}
	inline void build()
	{
		for(int i=1;i<=4;++i)
			a[i][i]=1;
	}
}t;
matrix operator *(const matrix &x,const matrix &y)
{
	matrix z;
	for(int k=1;k<=4;++k)
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mod)%mod;
	return z;
}
long long calc(int n,int tmp)
{
	if(n<=0)return 0;
	matrix ans,t;
	t.a[1][3]=1;
	t.a[2][1]=1;
	t.a[3][2]=1;
	t.a[3][4]=1;
	t.a[4][3]=1;
	t.a[4][4]=1;
	ans.build();
	while(n)
	{
		if(n&1)ans=ans*t;
		t=t*t;
		n>>=1;
	}
	int anss;
	if(tmp==1)anss=1;
	else if(tmp==2)anss=2;
	else if(tmp==4)anss=3;
	else anss=4;
	return ans.a[anss][1];
}
long long solve(int n,char a,char b)
{
	if(n==1)return 0;
	if(a=='1')
	{
		if(b=='6')return calc(n-1,4);
		else return 0;
	}
	if(a=='2')
	{
		if(b=='6')return calc(n-2,4);
		else return 0;
	}
	if(a=='4')
	{
		if(b=='1')return calc(n-2,6);
		else if(b=='2')return (solve(n-1,'2','1')+solve(n-1,'6','1'))%mod;
		else if(b=='4')return (solve(n-1,'2','2')+solve(n-1,'6','2'))%mod;
		else if(b=='6')return (solve(n-1,'2','6')+solve(n-1,'6','6'))%mod;
	}
	if(a=='6')
	{
		if(b=='1')return solve(n-1,'4','4');
		else if(b=='2')return solve(n-1,'4','1');
		else if(b=='4')return (solve(n-1,'4','2')+calc(n-1,6))%mod;
		else if(b=='6')return solve(n-1,'4','6')%mod;
	}
}
int main()
{
	int n;
	cin>>n>>(s+1);
	if(strlen(s+1)==1)printf("%lld\n",calc(n,s[1]-'0'));
	else printf("%lld\n",solve(n,s[1],s[2]));
	return 0;
}
