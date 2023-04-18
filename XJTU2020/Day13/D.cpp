#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1 
using namespace std;
long long a[200005],sum[200005],Maxnow[200005];
vector<long long>v;
int getid(long long x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int dp[200005];
int n,k;
int Max[400005*4];
void modify(int l,int r,int rt,int now,int k)
{
	if(l==r)
	{
		Max[rt]=max(Max[rt],k);
		return;
	}
	int m=(l+r)>>1;
	if(now<=m)modify(lson,now,k);
	else modify(rson,now,k);
	Max[rt]=max(Max[rt<<1],Max[rt<<1|1]);
}
int query(int l,int r,int rt,int Min)
{
	if(l>=Min)return Max[rt];
	int m=(l+r)>>1;
	int re=query(rson,Min);
	if(Min<=m)re=max(re,query(lson,Min));
	return re;
}
bool check(long long tot)
{
	memset(dp,0,sizeof(dp));
	memset(Max,0,sizeof(Max));
	v.clear();
	for(int i=1;i<=n;++i)
	{
		v.push_back(sum[i]);
		v.push_back(sum[i]-tot);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int nn=v.size();
	for(int i=1;i<=n;++i)
	{
		if(sum[i]<=tot)dp[i]=1;
		if(sum[i]-tot<=Maxnow[i-1])
		{
			int tmp=query(1,nn,1,getid(sum[i]-tot));
			if(tmp)dp[i]=tmp+1;
		} 
		modify(1,nn,1,getid(sum[i]),dp[i]);
		if(dp[i]>=k)return true;
	}
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		long long l=0,r=0;
		Maxnow[0]=-1145141919810114514;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
			Maxnow[i]=max(Maxnow[i-1],sum[i]);
			if(a[i]<0)l+=a[i];
			else r+=a[i];
		}
		while(l<r-1)
		{
			long long m=(l+r)>>1;
			if(check(m))r=m;
			else l=m;
		}
		if(check(l))printf("%lld\n",l);
		else printf("%lld\n",r);
	}
	return 0;
}
