#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,M;
int a[100005],shu[100005];
int lowbit(int x)
{
	return x&(-x);
}
int query(int x)
{
	int re=0;
	while(x)
	{
		re=max(re,shu[x]);
		x-=lowbit(x);
	}
	return re;
}
void add(int x,int sum)
{
	while(x<=M)
	{
		shu[x]=max(shu[x],sum);
		x+=lowbit(x);
	}
}
int main()
{
//	freopen("test.txt","r",stdin);
	int ans1=0;
	scanf("%d",&n);
	M=n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		int q=query(a[i])+1;
		add(a[i],q);
		ans1=max(ans1,q);
	}
	printf("%d\n",ans1);
	return 0;
}
