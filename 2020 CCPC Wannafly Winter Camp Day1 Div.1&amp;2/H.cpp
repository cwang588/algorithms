#include<bits/stdc++.h>
using namespace std;
bool prime[50005];
void init()
{
	for(int i=2;i<=500;++i)
		if(!prime[i])
			for(int j=2;j*i<=500;++j)
				prime[i*j]=true;
}
long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	int t;
	scanf("%d",&t);
	init();
	while(t--)	
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long now=1;
		for(int i=1;i*k<=n;++i)
		{
			if(!prime[i])
			{
				long long tmp=(long long)(i*k);
				now=now*tmp/gcd(now,tmp);
			}
		}
		cout<<now<<endl;
	}
	
	return 0;
}
