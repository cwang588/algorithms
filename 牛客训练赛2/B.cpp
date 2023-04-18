#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct xs
{
	string na;
	int ti[5];
	int tot[5];
	bool ac[5];
	bool cs;
	int num;
}cf[505];
bool cmp(xs a,xs b)
{
	return a.num>b.num;
}
int f[5]={500,1000,1500,2000,2500};
int Min[5]={150,300,450,600,750};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		cin>>cf[i].na;
	for(int i=1;i<=m;++i)
	{
		int t,tot;
		string ren,zt;
		char th;
		cin>>t>>ren>>th>>zt;
		for(int j=1;j<=n;++j)
		{
			if(ren==cf[j].na)
			{
				cf[j].cs=true;
				if(zt=="AC"||zt=="WA"||zt=="TLE")
				{
					int now=th-'A';
					cf[j].ti[now]=t;
					++cf[j].tot[now];
					if(zt=="AC")
						cf[j].ac[now]=true;
					else
						cf[j].ac[now]=false;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<=4;++j)
		{
			if(cf[i].ac[j])
			{
				int tep=f[j]-(cf[i].tot[j]-1)*50-cf[i].ti[j]*f[j]/250;
				cf[i].num+=max(tep,Min[j]);
			}
		}
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(cf[i].cs)
			++cnt;
	sort(cf+1,cf+1+n,cmp);
	int score;
	for(int i=1;i<=n;++i)
		if(cf[i].na=="cuber")
			score=cf[i].num;
	for(int i=1;i<=n;++i)
		if(cf[i].num==score)
			return !printf("%d\n%d/%d",cf[i].num,i,cnt);
	printf("-1");
	return 0;
}
