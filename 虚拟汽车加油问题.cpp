#include<bits/stdc++.h>
using namespace std;
int dis[100005],pos[100005];
int main()
{
	int n,k;
	scanf("%d%d",&k,&n);
	for(int i=1;i<=n+1;++i)scanf("%d",&dis[i]);
	for(int i=1;i<=n+1;++i)pos[i]=pos[i-1]+dis[i];
	int ans=0,now=0;
	while(now<n+1)
	{
		int l=now,r=n+1;
		while(l<r-1)
		{
			int m=(l+r)>>1;
			if(pos[m]-pos[now]<=k)l=m;
			else r=m;
		}
		if(pos[r]-pos[now]<=k)now=r;
		else now=l;
		if(now==n+1)return !printf("%d\n",ans);
		++ans;
	}
	return 0;
}
