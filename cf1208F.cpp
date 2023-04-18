#include<bits/stdc++.h>
using namespace std;
int a[2000005],sb[2000005];
void add(int sum,int num)
{
	if(sb[sum]>=2)return;
	if(num<0)
	{
		++sb[sum];
		return;
	}
	add(sum,num-1);
	if(sum&(1<<num))add(sum^(1<<num),num-1);
}
int work(int num)
{
	int re=0;
	for(int i=20;i>=0;--i)
	{
		int now=1<<i;
		if(!(num&now)&&sb[re|now]>1)re+=now;
	}
	return num|re;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0;
	for(int i=n;i>=1;--i)
	{
		if(i<=n-2)ans=max(ans,work(a[i]));
		add(a[i],20);
	}
	printf("%d\n",ans);
	return 0;
}
