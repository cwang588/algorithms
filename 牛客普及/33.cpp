#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define p 7
#define mod 233
using namespace std;
int q,f[2000005],m[1000005]={1};
char a[1000005],b[1000005],c[1000005];
void init()
{
	int l=strlen(b);
	for(int i=0;i<l;++i)	
		q=(q*p+b[i])%mod;
	l=strlen(a);
	for(int i=1;i<=l;++i)
		f[i]=(f[i-1]*p+a[i-1])%mod;
}
int mi(int x)
{
	if(m[x])
		return m[x];
	if(x%2)
		m[x]=((mi(x/2)*mi(x/2))%mod*p)%mod;
	else
		m[x]=(mi(x/2)*mi(x/2))%mod;
	return m[x];
}
int main()
{
	cin>>a;
	cin>>b;
	cin>>c;
	init();
	int L=strlen(a),l=strlen(b);
	int now=1;
	while(now<=L)
	{
		int tep=f[now+l-1]-(f[now-1]*mi(l+1))%mod;
		if(tep<0)
			tep+=((tep*-1)/mod+1)*mod;
		if(tep==q)
		{
			printf("%s",c);
			now+=l;
			q*=mi(l);
			q%=233;
		}
		else
		{
			printf("%c",a[now-1]);
			++now;
			q*=p;
		}
	}
	return 0;
}
