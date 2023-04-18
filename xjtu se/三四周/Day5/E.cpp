#include<cstdio>
#include<algorithm>
#define N 1000005
using namespace std;
const long long mod=998244353;
int n;
long long A[N],c[N],sum[N];
struct rr
{
	long long num;
	int note;
}a[N];
int lowbit(int x)
{
	return x&(-x);
}
struct rrr
{
	long long num;
	int note,ni;
}b[N];
bool cmp1(rr x,rr y)
{
	return x.num<y.num;
}
bool cmp2(rrr x,rrr y)
{
	return x.num<y.num;
}
bool cmp3(rrr x,rrr y)
{
	return x.note<y.note;
}
void add(int x)
{
	while(x<=n)
	{
		++c[x];
		x+=lowbit(x);
	}
}
long long q(int x)
{
	long long ret=0;
	while(x>0)
	{
		ret=(ret+c[x]);
		x-=lowbit(x);
	}
	return ret;
}
int main()
{
//	freopen("wch5.in","r",stdin);
//	freopen("wch5.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i].num);
		a[i].note=i;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&b[i].num);
		b[i].note=i;
	}
	long long ans=0;
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp2);
	long long tot=0;
	for(int i=1;i<=n;++i)
		tot=(tot+(a[i].num-b[i].num)*(a[i].num-b[i].num)%mod)%mod;
	for(int i=1;i<=n;++i)
		b[i].ni=a[i].note;
	sort(b+1,b+1+n,cmp3);
	for(int i=1;i<=n;++i)
		sum[i]=b[i].ni;
	for(int i=1;i<=n;++i)
	{
		ans=(ans+(long long)i-q(sum[i])-1);
		add(sum[i]);
	}
	printf("%lld %lld\n",tot,ans);
//	printf("%lld\n",ans);
	return 0;
}
