#include<bits/stdc++.h>
using namespace std;
int n;
int sum[100005];
struct point
{
	int x,y;
}p[100005];
int lowbit(int x)
{
	return x&(-x);
}
int query(int num)
{
	int ans=0;
	while(num)
	{
		ans+=num;
		num-=lowbit(num);
	}
	return ans;
}
void modify(int x,int y)
{
	while(x<=n)
	{
		sum[x]+=y;
		x+=lowbit(x);
	}
}
bool cmp(point a,point b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.y<b.y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;++i)
	{
		int ans=query()
	}
	return 0;
}
