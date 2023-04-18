#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],tot[500005],l[500005],r[500005],now[500005];
int lowbit(int x)
{
	return x&(-x);
}
void add(int x,long long c)
{
	while(x<=500000)
	{
		sum[x]+=c;
		x+=lowbit(x);
	}
}
long long query(int x)
{
	if(!x)
		return 0;
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
		scanf("%lld%lld%lld",&a[i],&l[i],&r[i]);
		++tot[a[i]];
	}
	for(int i=1;i<=n;++i)
	{
		add(a[i],-now[a[i]]);
		printf("%lld ",query(r[i])-query(l[i]-1));
		add(a[i],tot[a[i]]-now[a[i]]-1);
		++now[a[i]];
	}
	return 0;
}
