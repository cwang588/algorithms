#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],nowtot[N],tot[N];
long long sum[N];
int lowbit(int x)
{
	return x&(-x);
}
long long query(int x)
{
	long long re=0;
	while(x)
	{
		re+=sum[x];
		x-=lowbit(x);
	}
	return re;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		++tot[a[i]];
	}
	for(int i=1;i<=n;++i)
	{
		++nowtot[a[i]];
		if(tot[a[i]]==2*nowtot[a[i]]);
		else if(tot[a[i]])
			
	}
	return 0;
}
