#include<bits/stdc++.h>
using namespace std;
long long ans1,ans2,ans3;
long long dp[10005][3],num[10005][3];
const long long mod=1000000007;
struct edge
{
	int from,to,nxt,v;
}e[20005];
int Head[10005],cnt;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre)
{
	num[now][0]=1;
	bool ky=false;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		int to=e[i].to,l=e[i].v;
		dfs(to,now);
		ky=true;
		int m=l%3;
		if(!m)
		{
			num[now][0]+=num[to][0];
			num[now][1]+=num[to][1];
			num[now][2]+=num[to][2];
			ans1=(ans1+(dp[to][0]+num[to][0]*l%mod)*2%mod)%mod;
			ans2=(ans2+(dp[to][1]+num[to][1]*l%mod)*2%mod)%mod;
			ans3=(ans3+(dp[to][2]+num[to][2]*l%mod)*2%mod)%mod;	
			dp[now][0]+=(dp[to][0]+num[to][0]*l);
			dp[now][1]+=(dp[to][1]+num[to][1]*l);
			dp[now][2]+=(dp[to][2]+num[to][2]*l);		
		}
		else if(m==1)
		{
			num[now][0]+=num[to][2];
			num[now][1]+=num[to][0];
			num[now][2]+=num[to][1];
			ans1=(ans1+(dp[to][0]+num[to][2]*l%mod)*2%mod)%mod;
			ans2=(ans2+(dp[to][1]+num[to][0]*l%mod)*2%mod)%mod;
			ans3=(ans3+(dp[to][2]+num[to][1]*l%mod)*2%mod)%mod;	
			dp[now][0]+=(dp[to][2]+num[to][2]*l);
			dp[now][1]+=(dp[to][0]+num[to][0]*l);
			dp[now][2]+=(dp[to][1]+num[to][1]*l);			
		}
		else
		{
			num[now][0]+=num[to][1];
			num[now][1]+=num[to][2];
			num[now][2]+=num[to][0];
			ans1=(ans1+(dp[to][0]+num[to][1]*l%mod)*2%mod)%mod;
			ans2=(ans2+(dp[to][1]+num[to][2]*l%mod)*2%mod)%mod;
			ans3=(ans3+(dp[to][2]+num[to][0]*l%mod)*2%mod)%mod;
			dp[now][0]+=(dp[to][1]+num[to][1]*l);
			dp[now][1]+=(dp[to][2]+num[to][2]*l);
			dp[now][2]+=(dp[to][0]+num[to][0]*l);
		}
	}
	if(!ky)
	{
		return;
	}
	for(int i=Head[now];i;i=e[i].nxt)
	{
		if(e[i].to==pre)continue;
		int to=e[i].to,l=e[i].v;
		int m=l%3;
		if(!m)
		{
			ans1+=((dp[to][0]+num[to][0]*l%mod)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod)))*(num[now][0]-num[to][0]-1)%mod;
			ans1+=((dp[to][1]+num[to][1]*l%mod)%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod)))*(num[now][1]-num[to][1])%mod;
			ans1+=((dp[to][2]+num[to][2]*l%mod)%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod)))*(num[now][2]-num[to][2])%mod;
			ans2+=(dp[to][0]+num[to][0]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod;
			ans2+=(dp[to][1]+num[to][1]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod;
			ans2+=(dp[to][2]+num[to][2]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod;
			ans3+=(dp[to][0]+num[to][0]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod;
			ans3+=(dp[to][1]+num[to][1]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod;
			ans3+=(dp[to][2]+num[to][2]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod;
		}
		else if(m==1)
		{
			ans1+=((dp[to][0]+num[to][0]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
			ans1+=((dp[to][1]+num[to][1]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans1+=((dp[to][2]+num[to][2]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
			ans2+=((dp[to][0]+num[to][0]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
			ans2+=((dp[to][1]+num[to][1]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
			ans2+=((dp[to][2]+num[to][2]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans3+=((dp[to][0]+num[to][0]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans3+=((dp[to][1]+num[to][1]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
			ans3+=((dp[to][2]+num[to][2]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
		}
		else
		{
			ans1+=((dp[to][0]+num[to][0]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
			ans1+=((dp[to][1]+num[to][1]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
			ans1+=((dp[to][2]+num[to][2]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans2+=((dp[to][0]+num[to][0]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans2+=((dp[to][1]+num[to][1]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
			ans2+=((dp[to][2]+num[to][2]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
			ans3+=((dp[to][0]+num[to][0]*l%mod)*(num[now][2]-num[to][2])%mod+(dp[now][2]-(dp[to][2]+num[to][2]*l%mod))%mod)%mod;
			ans3+=((dp[to][1]+num[to][1]*l%mod)*(num[now][1]-num[to][1])%mod+(dp[now][1]-(dp[to][1]+num[to][1]*l%mod))%mod)%mod;
			ans3+=((dp[to][2]+num[to][2]*l%mod)*(num[now][0]-num[to][0]-1)%mod+(dp[now][0]-(dp[to][0]+num[to][0]*l%mod))%mod)%mod;
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
		ans1=ans2=ans3=0;
		memset(Head,0,sizeof(Head));
		for(int i=1;i<n;++i)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			++x,++y;
			add(x,y,z);
			add(y,x,z);
		}
		dfs(1,0);
		printf("%lld %lld %lld\n",ans1,ans2,ans3);
	}
	
	return 0; 
}
