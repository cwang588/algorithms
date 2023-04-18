#include<bits/stdc++.h>
#define md
#define ll long long
#define inf 1000000000000000LL
#define eps 1e-8
#define N 5000100
using namespace std;
int q[N];
ll dis[N];
bool vis[N];
int mn,n;
int a[20];
ll query(ll x)
{
    ll ans=0;
    for (int i=0;i<mn;i++)
        if (dis[i]<=x) ans+=(x-dis[i])/mn+1; 
    return ans;
}
int main()
{
    mn=(1e9);
    ll L,R;
    cin>>n>>L>>R;
    for(int i=1;i<=n;i++) 
	{ 
		scanf("%d",&a[i]); 
		if(a[i]==0) 
		{
			i--;
			n--;
			continue;
		} 
		mn=min(mn,a[i]);
	}
    for(int i=1;i<mn;i++) 
		dis[i]=inf;
    int h=0,w=1,x,y; 
	q[1]=0;
	vis[0]=1;
    while(h!=w)
    {
        h++; 
		if(h>mn+5) 
			h=1; 
		x=q[h];
        for(int i=1;i<=n;i++)
        {
            y=(x+a[i])%mn;
            if (dis[y]>dis[x]+a[i])
            {
                dis[y]=dis[x]+a[i];
                if (!vis[y])
                {
                    vis[y]=1;
                    w++; if (w>mn+5) w=1; q[w]=y;
                }
            }
        }
        vis[x]=0;
    }
    cout<<query(R)-query(L-1);
    return 0;
}

