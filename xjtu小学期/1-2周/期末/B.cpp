#include<bits/stdc++.h>
using namespace std;
struct nfsq
{
	long long a,b;
}q[200005];
bool cmp(nfsq x,nfsq y)
{
	return x.b>y.b;
}
int main()
{
	long long v;
	int n;
	scanf("%lld%d",&v,&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&q[i].a,&q[i].b);
	sort(q+1,q+1+n,cmp);
	long long tot=0;
	for(int i=1;i<=n;++i)
	{
		if(v>=q[i].a)
		{
			v-=q[i].a;
			tot+=q[i].a*q[i].b;
		}
		else
		{
			tot+=v*q[i].b;
			break;
		}
	}
	printf("%lld",tot);
	return 0;
} 
