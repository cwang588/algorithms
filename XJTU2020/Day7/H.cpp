#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long mod=1000000007;
long long sum1[400005],sum2[400005],col1[400005],col2[400005];
int n,m;
void build(int l,int r,int rt)
{
	if(l==r)
	{
		sum2[rt]=1;
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	sum2[rt]=(sum2[rt<<1]+sum2[rt<<1|1])%mod;
}
void modify2(int l,int r,int rt,int nowl,int nowr)
{
	if(nowl<=l&&r<=nowr)
	{
		sum2[rt]=sum2[rt]*100%mod;
		col3[rt]=col3[rt]
	}
}
int cnt;
long long ans[100005];
int main()
{
	ios::sync_with_stdio(false);
	int t;	
	cin>>t;
	for(int Case=1;Case<=t;++Case)
	{
		memset(sum1,0,sizeof(sum1));
		memset(sum2,0,sizeof(sum2));
		memset(col1,0,sizeof(col1));
		memset(col2,0,sizeof(col2));
		cnt=0;
		cin>>n>>m;
		build(1,n,1);
		for(int i=1;i<=m;++i)
		{
			string tmp;
			cin>>tmp;
			if(tmp=="wrap")
			{
				int l,r,d;
				modify2(1,n,1,l,r);
				modify1(1,n,1,l,r,d);
			}
			else
			{
				int l,r;
				ans[++cnt]=query1(1,n,1,l,r);
			}
		}
		cout<<"Case "<<Case<<":\n";
		for(int i=1;i<=cnt;++i)cout<<ans[i]<<"\n";		
	}
	return 0;
}
