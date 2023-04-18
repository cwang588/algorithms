#include<bits/stdc++.h>
using namespace std;
bool judge(int x,int y)
{
	return (x-y)%7==0;
}
int main()
{
	int n;
	scanf("%d",&n);
	int nowans=0,ans=0;
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(judge(t,1)||judge(t,2)||judge(t,3)||judge(t,5)||judge(t,6))++nowans;
		else ans=max(ans,nowans),nowans=0;
	}
	ans=max(ans,nowans);
	printf("%d",ans);
	return 0;
}
