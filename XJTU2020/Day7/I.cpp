#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],sa[100005],sb[100005];
struct mons
{
	long long v;
	int type;
}tmp[200005],db[200005];
int ad[100005];
bool cmp(mons x,mons y)
{
	return x.v<y.v;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int Case=1;Case<=t;++Case)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]); 
		for(int i=1;i<=m;++i)scanf("%lld",&db[i].v); 
		for(int i=1;i<=m;++i)scanf("%lld",&db[i].type);
		sort(db+1,db+1+m,cmp);
		for(int i=1;i<=m;++i)b[i]=db[i].v,ad[i]=db[i].type;
		sort(a+1,a+1+n);
		if(n<=m)
		{
			int cnt=0;
			long long ans=0;
			for(int i=1;i<=n;++i)sa[i]=sa[i-1]+a[i];
			for(int i=1;i<=n;++i)
			{
				if(!ad[i])
				{
					++cnt;
					sb[cnt]=sb[cnt-1]+b[i];
				}
			}
			for(int i=1;i<=min(n,cnt);++i)ans=max(ans,sa[n]-sa[n-i]-sb[i]);
			printf("Case %d: %lld\n",Case,ans);
		} 
		else
		{
			int cnt=0;
			long long ans=0;
			for(int i=1;i<=n;++i)sa[i]=sa[i-1]+a[i];
			for(int i=1;i<=m;++i)
			{
				if(!ad[i])
				{
					++cnt;
					sb[cnt]=sb[cnt-1]+b[i];
				}
			}
			for(int i=1;i<=min(n,cnt);++i)ans=max(ans,sa[n]-sa[n-i]-sb[i]);
			cnt=0;
			for(int i=1;i<=n;++i)tmp[++cnt]={a[i],1};
			for(int i=1;i<=m;++i)tmp[++cnt]={b[i],-1};
			sort(tmp+1,tmp+cnt+1,cmp);
			int sum=0;
			for(int i=1;i<=cnt;++i)
			{
				if(tmp[i].type==-1)sum-=1;
				else
				{
					if(sum<0)++sum;
					else;
				}
			}
			if(sum<0)
			{
				printf("Case %d: %lld\n",Case,ans);
				continue;
			}
			cnt=0;
			long long rea=sa[n];
			for(int i=1;i<=n;++i)tmp[++cnt]={a[i],1};
			for(int i=1;i<=m;++i)if(ad[i])tmp[++cnt]={b[i],-1};
			sort(tmp+1,tmp+1+cnt,cmp);
			sum=0;
			for(int i=1;i<=cnt;++i)
			{
				if(tmp[i].type==-1)--sum;
				else
				{
					if(sum<0)
					{
						++sum;
						rea-=tmp[i].v;
					}
				}
			}
			long long tot=0;
			for(int i=1;i<=m;++i)if(!ad[i])tot+=b[i];
			ans=max(ans,rea-tot);
			printf("Case %d: %lld\n",Case,ans);
		}
	}
	return 0;
}
