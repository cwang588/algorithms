#include<bits/stdc++.h>
#define maxn 5000050
#define ll long long
using namespace std;
priority_queue<pair<ll,ll> >q; 
ll tou[maxn],nxt[maxn],to[maxn],va[maxn],cnt;
void add(int x,int y,int z)
{
	nxt[++cnt]=tou[x];
	tou[x]=cnt;
	to[cnt]=y;
	va[cnt]=z;
}
ll n,a[maxn]; 
ll l,r,len[maxn],ans;
int main()
{
	scanf("%lld%lld%lld",&n,&l,&r);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(!a[i]) 
		{
			--i;
			--n;
		}
	}
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j] == a[1]) 
				continue;
			add(i,(a[j]+i)%a[1],a[j]);
		}
	} 
	for(int i=0;i<=a[1];i++) 
		len[i]=10000000000000;
	q.push(make_pair(0,0));
	len[0]=0; 
	while(!q.empty())
	{
		int x = q.top().second; 
		q.pop();
		for(int i=tou[x];i;i=nxt[i])
		{
			int t=to[i]; 
			if(len[t] > len[x] + (ll)va[i]){
				len[t] = len[x] + (ll)va[i];
				q.push(make_pair(-len[t], t));
			} 
		}
	}
	for(int i=0;i<a[1];i++)
	{
		ll x=len[i];
		if(l>=x+1) 
			ans=ans-(l-x-1)/a[1]-1;
		if(r>=x) 
			ans=ans+(r-x)/a[1]+1;
	}
	cout<<ans; 
	return 0;
}
