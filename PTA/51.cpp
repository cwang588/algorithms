#include<cstdio>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
struct zb
{
	long long x,y;
}d[5005];
struct fs
{
	long long x,y;
}xl[5005];
int n;
bool cmp(fs p,fs q)
{
	return q.x*p.y>q.y*p.x;
}
long long Min=9000000000000000000;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld%lld",&d[i].x,&d[i].y);
	for(int now=1;now<=n;++now)
	{
		int sum=0;
		for(int i=1;i<=n;++i)
			if(i!=now)
			{
				++sum;
				xl[sum].x=d[i].x-d[now].x;
				xl[sum].y=d[i].y-d[now].y;
			}
		sort(xl+1,xl+1+sum,cmp);
		for(int i=1;i<n-1;++i)
			Min=min(Min,abs(xl[i].x*xl[i+1].y-xl[i].y*xl[i+1].x));
		Min=min(Min,abs(xl[1].x*xl[n-1].y-xl[n-1].x*xl[1].y));	
	}
	if(Min%2)
		printf("%lld.500",Min/2);
	else
		printf("%lld.000",Min/2);
	return 0;
}
