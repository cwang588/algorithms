#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=998244353;
int m;
struct Node
{
	int l,r;
}node[300005];
long long sum[600005<<2],col[600005<<2];
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void push_col(int l,int r,int rt)
{
	if(col[rt])
	{
		col[rt<<1]+=col[rt];
		col[rt<<1]%=mod;
		col[rt<<1|1]+=col[rt];
		col[rt<<1|1]%=mod;
		int m=(l+r)>>1;
		sum[rt<<1]+=(m-l+1)*col[rt]%mod;
		sum[rt<<1|1]+=(r-m)*col[rt]%mod;
		col[rt]=0;
	}
} 
void modify(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)
	{
		sum[rt]+=r-l+1;
		sum[rt]%=mod;
		++col[rt];
		return;
	}
	push_col(l,r,rt);
	int m=(l+r)>>1;
	if(nowl<=m)modify(lson,nowl,nowr);
	if(nowr>m)modify(rson,nowl,nowr);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1]; 
}
long long query(int l,int r,int rt,int nowl,int nowr)
{
	if(l>=nowl&&r<=nowr)return sum[rt]; 
	push_col(l,r,rt);
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re+=query(lson,nowl,nowr)%mod;
	if(nowr>m)re+=query(rson,nowl,nowr)%mod;
	return re;
}
long long fac[300005],inv[300005];
long long quickpower(long long a,long long b,long long p)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)
			ans=(ans*base)%p;
		base=(base*base)%p;
		b>>=1;
	}
	return ans%p;
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=300000;++i)fac[i]=fac[i-1]*i%mod;
	inv[300000]=quickpower(fac[300000],mod-2,mod);
	for(int i=299999;i>=0;--i)inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int n,int m)
{
	long long re=1;
	re=re*fac[n]%mod;
	re=re*inv[m]%mod;
	re=re*inv[n-m]%mod;
	return re;
}
bool cmp(Node x,Node y)
{
	if(x.l!=y.l)return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	init();
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d%d",&node[i].l,&node[i].r),v.push_back(node[i].l),v.push_back(node[i].r);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int num=v.size();
	sort(node+1,node+1+n,cmp);
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int ll=getid(node[i].l),rr=getid(node[i].r);
		int tot=query(1,num,1,ll,ll);
		if(tot>=k-1)ans=(ans+C(tot,k-1))%mod;
//		if(rr!=ll)
//		{
//			int tmptot=query(1,num,1,rr,rr);
//			if(tmptot>=k-1)ans=(ans+C(tmptot,k-1))%mod;
//		}
		modify(1,num,1,ll,rr);
	}
	printf("%lld\n",ans);
	return 0;
}
