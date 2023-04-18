#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct dian
{
	long long x,y;
	int xid,yid;
}d[1005];
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
bool cmp1(dian a,dian b)
{
	return a.x<b.x;
}
bool cmp2(dian a,dian b)
{
	return a.y<b.y;
}
int he[1005][1005];
int main()
{
	long long tot=0;
	long long n;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&d[i].x,&d[i].y);
	sort(d+1,d+1+n,cmp1);
	for(int i=1;i<=n;++i)
		d[i].xid=i;
	sort(d+1,d+1+n,cmp2);
	for(int i=1;i<=n;++i)
		d[i].yid=i;
	for(int i=1;i<=n;++i)
		++he[d[i].xid][d[i].yid];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			he[i][j]+=he[i-1][j]+he[i][j-1]-he[i-1][j-1];
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		{
			int X1,X2,Y1,Y2; 
			X1=min(d[i].xid,d[j].xid);
			X2=max(d[i].xid,d[j].xid);
			Y1=min(d[i].xid,d[j].xid);
			Y2=max(d[i].xid,d[j].xid);
			int num1=2*he[X1][Y1]*(he[n][n]-he[X2-1][n]-he[n][Y2-1]+he[X2-1][Y2-1])-he[X1][Y1]-(he[n][n]-he[X2-1][n]-he[n][Y2-1]+he[X2-1][Y2-1]);
			int num2=2*(he[X2][n]-he[X1-1][n])*(he[n][Y2]-he[n][Y1-1])-(he[X2][n]-he[X1-1][n])-(he[n][Y2]-he[n][Y1-1]);
			long long s=(max(d[i].x,d[j].x)-min(d[i].x,d[j].x))*(max(d[i].y,d[j].y)-min(d[i].y,d[j].y));
			tot=(tot+(s%mod)*(long long)(num1+num2))%mod;
		}
	long long fm=(n*n*n*n-2*n*n*n-3*n*n+4*n)/8;
	fm=quickpower(fm,mod-2,mod);
	cout<<(fm*tot)%mod;
	return 0;
} 
