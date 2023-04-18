#include<bits/stdc++.h>
using namespace std;
int sum[1000005];
vector<int>v;
int n;
inline int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	while(x<=n)
	{
		sum[x]=max(sum[x],y);
		x+=lowbit(x);
	}
}
int query(int x)
{
	int re=0;
	while(x)
	{
		re=max(re,sum[x]);
		x-=lowbit(x);
	}
	return re;
}
bool usd[1000006];
int a[1000006],maxn[1000006],ans[1000006],maxval[1000006],cnt[1000006];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int maxans=0;
	for(int i=1;i<=n;++i)
	{
		int now=getid(a[i]);
		maxn[i]=query(now)+1;
		maxans=max(maxans,maxn[i]);
		add(now,maxn[i]);
	}
	//printf("%d\n",maxans);
	for(int i=n;i>=1;--i)
	{
		if(maxn[i]==maxans)
		{
			++cnt[maxn[i]];
			maxval[maxn[i]]=max(maxval[maxn[i]],getid(a[i]));
			usd[i]=true;
		}
		else
		{
			int now=getid(a[i]);
			if(maxval[maxn[i]+1]>=now)
			{
				++cnt[maxn[i]];
				maxval[maxn[i]]=max(maxval[maxn[i]],getid(a[i]));
				usd[i]=true;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(usd[i]&&cnt[maxn[i]]==1)printf("%d ",maxans-1);
		else printf("%d ",maxans);
	}
	return 0;
}
