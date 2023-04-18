#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
char s[100005],tt[100005],s1[100005],s2[100005],s3[100005],tmpp[100050];
bool usd[100005];
long long f[1005][10];
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
long long solve(int n)
{
	memset(usd,0,sizeof(usd));
	if(n==1)
	{
		if(strlen(s+1)>1)return 0;
		if(s[1]=='1')return 1;
		return 0;
	}	
	if(strlen(s+1)>=2)
	{
		if(s[1]=='6'&&s[2]!='4')
		{
			int tl=strlen(s+1);
			for(int i=tl+1;i>1;--i)s[i]=s[i-1];
			s[1]='1';
		}
		int tl=strlen(s+1);
		if(s[tl]=='1')s[++tl]='6';
		if(s[tl]=='6'&&s[tl-1]!='1')s[++tl]='4';
	}
	long long re=0;
	int l=strlen(s+1);
	int now=0;
	if(l>1)
	{
		for(int i=1;i<=l;++i)
		{
			if(usd[i])continue;
			if(s[i]=='1')
			{
				if(s[i+1]!='6')return 0;
				usd[i+1]=true;
				tt[++now]='4';
			}
			else if(s[i]=='2')tt[++now]='1';
			else if(s[i]=='6')
			{
				if(i+1<=l&&s[i+1]!='4')return 0;
				usd[i+1]=true;
				tt[++now]='6';
			}
			else tt[++now]='2';
		}
		memset(s,0,sizeof(s));
		for(int i=1;i<=now;++i)s[i]=tt[i];
		tot=(tot+solve(n-1))%mod;
	}
	int tmp=s[1]-'0';
	return calc(n,tmp);
}
int main()
{
	int n;
	scanf("%d",&n);
	cin>>(s+1);
	if(strlen(s+1)>=2)
	{
		if(s[1]=='6'&&s[2]!='4')
		{
			int tl=strlen(s+1);
			for(int i=tl+1;i>1;--i)s[i]=s[i-1];
			s[1]='1';
		}
		int tl=strlen(s+1);
		if(s[tl]=='1')s[++tl]='6';
		if(s[tl]=='6'&&s[tl-1]!='1')s[++tl]='4';
	}
	long long tot=0;
	int tl=strlen(s+1);	
	for(int i=1;i<=tl;++i)tmpp[i]=s[i];
	tot=(tot+solve(n))%mod;
	if(tmpp[1]=='4')
	{
		s1[1]='6';
		for(int i=1;i<=tl;++i)s1[i+1]=tmpp[i];
		for(int i=1;i<=tl+1;++i)s[i]=s1[i];
		tot=(tot+solve(n))%mod;
	}
	printf("%lld\n",tot);	
	return 0;
}
