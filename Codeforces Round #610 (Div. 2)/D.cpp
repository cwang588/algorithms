#include<bits/stdc++.h>
using namespace std;
struct problem
{
	bool easy;
	long long t;
}p[200005];
bool cmp(problem x,problem y)
{
	return x.t<y.t;
}
int tota[200005],totb[200005];
int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin>>m;
	while(m--)
	{
		memset(tota,0,sizeof(tota));
		memset(totb,0,sizeof(totb));
		int n;
		long long a,b,T;
		cin>>n>>T>>a>>b;
		int rea=0,reb=0;
		for(int i=1;i<=n;++i)
		{
			int tt;
			cin>>tt;
			if(!tt)p[i].easy=true,++rea;
			else p[i].easy=false,++reb;
		}
		for(int i=1;i<=n;++i)cin>>p[i].t;
		sort(p+1,p+1+n,cmp);
		p[n+1].t=T+1;
		p[n+2].t=0;
		for(int i=1;i<=n;++i)
		{
			tota[i]=tota[i-1];
			totb[i]=totb[i-1];
			if(!p[i].easy)++totb[i];
			else ++tota[i];
		}
		int now=0;
		long long tot=0;
		int ans=0;
		while(now<=n)
		{
			++now;
			int nowa=rea-tota[now],nowb=reb-totb[now];
			tot=nowa
		}
		printf("%d\n",ans);
	}
	
	return 0;
	
}
