#include<bits/stdc++.h>
using namespace std;
int s[10005],now;
struct point 
{
	double x,y;
}p[10005];
bool cmp1(point a,point b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
double r(point a)
{
	return sqrt((a.x-p[1].x)*(a.x-p[1].x)+(a.y-p[1].y)*(a.y-p[1].y));
}
bool cmp2(point a,point b)
{
	if((a.x-p[1].x)/r(a)!=(b.x-p[1].x)/r(b))
		return (a.x-p[1].x)/r(a)>(b.x-p[1].x)/r(b);
	return r(a)<r(b);
}
bool judge(int a,int b,int c)
{
	if(p[a].x*p[b].y+p[b].x*p[c].y+p[c].x*p[a].y-p[a].y*p[b].x-p[b].y*p[c].x-p[c].y*p[a].x>=0)
		return true;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,cmp1);
	sort(p+2,p+1+n,cmp2);
	s[++now]=1;
	s[++now]=2;
	int sum=3;
	while(s[now]!=n)
	{
		while(!judge(now-1,now,sum))
			--now;
		s[++now]=sum++;
	}
	double ans=0.0;
	for(int i=1;i<now;++i)
		ans+=sqrt((p[s[i]].x-p[s[i+1]].x)*(p[s[i]].x-p[s[i+1]].x)+(p[s[i]].y-p[s[i+1]].y)*(p[s[i]].y-p[s[i+1]].y));
	ans+=sqrt((p[s[1]].x-p[s[now]].x)*(p[s[1]].x-p[s[now]].x)+(p[s[now]].y-p[s[1]].y)*(p[s[now]].y-p[s[1]].y));	
	printf("%.2lf\n",ans);
	return 0;
}
