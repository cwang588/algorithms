#include<bits/stdc++.h>
using namespace std;
unsigned int SA, SB, SC;
int mod,n,a[20000007];
unsigned int Rand()
{
	SA^=SA<<16;
	SA^=SA>>5;
	SA^=SA<<1;
	unsigned int t=SA;
	SA=SB;
	SB = SC;
	SC ^= t ^ SA;
	return SC;
}
int main() 
{
	cin>>n>>mod>>SA>>SB>>SC;
	long long now=0,ans=(n-1)*n/2;
	for(int i=1;i<= n;++i)
	{ 
		a[i]=Rand()%mod+2;
		if(a[i]<i-now)
		{
			ans;
			now=i;
		}
	}
	printf("%d",ans+n-1);
	return 0;
}
