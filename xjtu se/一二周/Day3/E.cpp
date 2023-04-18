#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int n,k,t;
bool cmp(int x,int y)
{
	return x>y;
} 
int tot;
void dfs1(int now,int num,int last,long long Min)
{
	if(now==k)
	{
		if(num>=Min)++tot;
		return;
	}
//	for(int i=last+1;n-i>=k-now-1;++i)
	for(int i=last+1;i<=n;++i)
	{
		if(num+a[i]+b[i+k-now-1]-b[i]<Min)break;
		dfs1(now+1,num+a[i],i,Min);
		if(tot>=t)return;
	}
}
bool judge(long long x)
{
	tot=0;
	dfs1(0,0,0,x);
	return tot<t;
}
long long ans[200005],cnt;
void dfs2(int now,long long num,int last,long long Min)
{
	if(now==k)
	{
		if(num>=Min)ans[++cnt]=num;
		return;
	}
	for(int i=last+1;i<=n;++i)
	{
		if(num+a[i]+b[i+k-now-1]-b[i]<Min)break;
		dfs2(now+1,num+a[i],i,Min);
		//if(tot>=t)return;
	}
}
int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("ans.txt","w",stdout);
	scanf("%d%d%d",&n,&k,&t);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	long long l=b[n]-b[n-k],r=b[k]+1;
	while(l<r-1)
	{
		long long m=(l+r)>>1;
		if(judge(m))r=m;
		else l=m;
	}
	tot=0;
	dfs2(0,0,0,r);
	sort(ans+1,ans+1+cnt);
	for(int i=cnt;i>=1;--i)printf("%lld ",ans[i]);
	for(int i=1;i<=t-cnt;++i)printf("%lld",r-1);
	return 0;
}
