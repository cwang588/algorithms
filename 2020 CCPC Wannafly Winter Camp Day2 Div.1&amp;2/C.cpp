#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int sum[60];
int getmax(long long x)
{
	if(!x)return 0;
	long long now=1152921504606846976;
	int re=61;
	while(1)
	{
		if(now&x)return re;
		--re;
		now>>=1;
	}
}
void work(long long x)
{
	long long now=1,t=1;
	while(t<=60)
	{
		if(now&x)++sum[t];
		++t;
		now<<=1;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	long long now=0;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		now^=a[i];
		work(a[i]);
		printf("%d\n",sum[getmax(now)]);
	}
	return 0;
}
