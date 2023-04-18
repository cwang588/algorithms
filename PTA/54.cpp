#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int s[10005],now,n;
struct line
{
	int x,yy1,yy2;
}l[10005];
struct point
{
	int x,y,id;
}up[10005],down[10005];
bool judge1(int a,int b,int c)
{
	if(up[a].x*up[b].y+up[b].x*up[c].y+up[c].x*up[a].y-up[b].x*up[a].y-up[c].x*up[b].y-up[a].x*up[c].y>=0)
		return true;
	return false;
}
bool judge2(int a,int b,int c)
{
	if(down[a].x*down[b].y+down[b].x*down[c].y+down[c].x*down[a].y-down[b].x*down[a].y-down[c].x*down[b].y-down[a].x*down[c].y>=0)
		return true;
	return false;
}
bool cmp1(point a,point b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.x<b.x;
}
double r(point a)
{
	return sqrt((double)(a.x*a.x+a.y*a.y));
}
bool cmp2(point a,point b)
{
	if((double)a.x/r(a)!=(double)b.x/r(b))
	{
		return a.x/r(a)>b.x/r(b);
	}
	else
		return r(a)<r(b);
}
bool panduan(point a,point b)
{
	for(int i=1;i<=n;++i)
	{
		if((a.x*b.y+b.x*up[i].y+up[i].x*a.y-a.x*up[i].y-b.x*a.y-up[i].x*b.y)*(a.x*b.y+b.x*down[i].y+down[i].x*a.y-a.x*down[i].y-b.x*a.y-down[i].x*b.y)>0)
			return false;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&l[i].x,&l[i].yy1,&l[i].yy2);
		up[i].x=down[i].x=l[i].x;
		up[i].id=up[i].id=i;
		up[i].y=l[i].yy1;
		down[i].y=l[i].yy2;
	}
	sort(up+1,up+1+n,cmp1);
	sort(up+2,up+1+n,cmp2);
	s[++now]=1;
	s[++now]=2;
	int sum=3;
	while(s[now]!=n)
	{
		if(judge1(s[now],s[now-1],sum))
			s[++now]=sum;
		else
		{
			while(!judge1(s[now],s[now-1],sum))
				--now;
			s[++now]=sum;
		}
		++sum;
	}
	for(int i=1;i<now;++i)
		if(panduan(up[i],up[i+1]))
			return !printf("%d %d %d %d\n",up[i].x,up[i].y,up[i+1].x,up[i+1].y);
	memset(s,0,sizeof(s));
	now=0;
	sort(down+1,down+1+n,cmp1);
	sort(down+2,down+1+n,cmp2);
	s[++now]=1;
	s[++now]=2;
	sum=3;
	while(s[now]!=n)
	{
		if(judge2(s[now],s[now-1],sum))
			s[++now]=sum;
		else
		{
			while(!judge2(s[now],s[now-1],sum))
				--now;
			s[++now]=sum;
		}
		++sum;
	}
	for(int i=1;i<now;++i)
		if(panduan(down[i],down[i+1]))
			return !printf("%d %d %d %d\n",down[i].x,down[i].y,down[i+1].x,down[i+1].y);
	return 0;
}
