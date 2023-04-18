#include<bits/stdc++.h>
using namespace std;
bool judge(int x,int y,int t1,int t2)
{
	return (2*x+4*y<=t1)&&(3*x+y<=t2);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long x,y,ans;
		scanf("%lld%lld",&x,&y);
		if(x>=4*y)ans=y;
		else if(x*3<=2*y)ans=x/2;
		else 
		{
			long long xx=(4*y-x)/10,yy=(3*x-2*y)/10;
			ans=0;
			if(judge(xx+2,yy,x,y)||judge(xx,yy+2,x,y)||judge(xx+1,yy+1,x,y))ans=xx+yy+2;
			else if(judge(xx+1,yy,x,y)||judge(xx,yy+1,x,y))ans=xx+yy+1;
			else ans=xx+yy;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
