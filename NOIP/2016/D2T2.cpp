#include<bits/stdc++.h>
using namespace std;
int dp[1<<20],n,line[25][25];
const double eps=0.00000001;
struct pig
{
	double x,y;
}p[25];
void gaoshi(int l,int r)
{
	if(p[l].x*p[r].y==p[l].y*p[r].x||p[l].x==p[r].x)
		return;
	double a,b,t1,t2,t3;
	t1=p[l].x*p[l].x*p[r].x-p[r].x*p[r].x*p[l].x;
	t2=p[l].x*p[l].x*p[r].y-p[r].x*p[r].x*p[l].y;
	t3=p[l].x*p[r].y-p[r].y*p[l].x;
	a=t2/t1;
	b=t3/t1;
	if(a>=0)
		return;
	line[l][r]=(1<<(l-1))+(1<<(r-1));
	for(int i=1;i<=n;++i)
		if(a*p[i].x*p[i].x+b*p[i].x*p[i].x-p[i].y<eps)
			line[l][r]|=(1<<(i-1));	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(line,0,sizeof(line));
		memset(dp,0xfffffff,sizeof(dp));
		int m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)		
			cin>>p[i].x>>p[i].y;
		for(int i=1;i<n;++i)
			for(int j=i+1;j<=n;++j)
				gaoshi(i,j);
		dp[0][0]=0;
		for(int i=0;i<(1<<(n-1));++i)
			
	}
	return 0;
}
