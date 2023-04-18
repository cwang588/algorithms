#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt,v;
}e[200005];
int Head[100005],cnt;
void add(int x,int y,int z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int ans;
bool ky;
bool usd1[100055],usd2[100005];
int fa[100005],num[100005][30],num1[100005],num2[100005],sz[100005],cf[100005];
void dfs1(int now,int pre)
{
	fa[now]=pre;
	sz[now]=1;
	for(int i=Head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if(to==pre)continue;
		++num[to][e[i].v];
		++num[now][e[i].v];
		dfs1(to,now);
		sz[now]+=sz[to];
		num1[now]+=num1[to];
		num2[now]+=num2[to];
	}
	for(int i=1;i<=26;++i)
	{
		if(num[now][i]>2)
		{
			ky=false;
			return;
		}
		if(num[now][i]==2)
		{
			if(cf[now])
			{
				ky=false;
				return;
			}		
			cf[now]=i;
		}
	}
	if(!cf[now])return;
	int tmpcnt=0;
	for(int i=Head[now];i;i=e[i].nxt)if(e[i].to!=pre&&e[i].v==cf[now])++tmpcnt;
	if(tmpcnt==1)
	{
		usd2[now]=true;
		++num2[now];
	}
	else 
	{
		usd1[now]=true; 
		++num1[now];
	}
}
void dfs2(int now,int pre)
{
	if(usd2[now])
	{
		int tmpnum=0,nnxt;
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre)continue;
			if(e[i].v==cf[now])
			{
				nnxt=to;
				continue;
			}
			else 
			{
				if(num1[to])
				{
					ky=false;
					return;
				}
				tmpnum+=sz[to];
			}
		}
		ans-=tmpnum+1;
		dfs2(nnxt,now);
	}
	else if(usd1[now])
	{
		int nnxt=0,nnxt1=0;
		int tmp=num1[now]-1;
		for(int i=Head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if(to==pre)continue;
			if(num1[to])
			{
				if(tmp!=num1[to])
				{
					ky=false;
					return;
				}
				if(e[i].v==cf[now])nnxt=to;
				else
				{
					ky=false;
					return;
				}
				ans=sz[nnxt];
				dfs2(nnxt,now);
				return;
			}
			else
			{
				if(e[i].v==cf[now])
				{
					if(!nnxt)nnxt=to;
					else nnxt1=to;
				}
			}
		}
		ans=sz[nnxt]+sz[nnxt1];
		dfs2(nnxt,now);
		dfs2(nnxt1,now);
	}
	else
	{
		if(num1[now])
		{
			int tmp=num1[now];
			for(int i=Head[now];i;i=e[i].nxt)
			{
				int to=e[i].to;
				if(to==pre)continue;
				if(num1[to])
				{
					if(tmp!=num1[to])
					{
						ky=false;
						return;
					}
					int nnxt=to;
					ans=sz[nnxt];
					dfs2(nnxt,now);
					return;
				}
			}
		}
		else
		{
			for(int i=Head[now];i;i=e[i].nxt)
			{
				int to=e[i].to;
				if(to==pre)continue;
				dfs2(to,now);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ky=true;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=26;++j)num[i][j]=0;
			Head[i]=0;
			cf[i]=0;
			usd1[i]=usd2[i]=false;
			num1[i]=num2[i]=0;
		}
		cnt=0;
		for(int i=1;i<n;++i)
		{
			int x,y;
			char z;
			cin>>x>>y>>z;
			add(x,y,z-'a'+1);
			add(y,x,z-'a'+1);
		} 
		dfs1(1,0);
		ans=n; 
		dfs2(1,0);
		if(!ky)
		{
			printf("0\n");
			continue;
		}
		else printf("%d\n",ans);
	}
	return 0;
}
