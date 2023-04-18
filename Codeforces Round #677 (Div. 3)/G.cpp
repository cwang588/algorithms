#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long INF=214748364777777;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dis[1005][1005];
bool usd[1005];
struct edge{
	int from,to,nxt,v;
}e[2005];
int Head[1005],cnt;
int S[1005],E[1005];
void add(int a,int b,int c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].v=c;
	e[cnt].nxt=Head[a];
	Head[a]=cnt;
}
long long min(long long a,long long b,long long c){
	long long re=INF;
	re=min(re,a);
	re=min(re,b);
	re=min(re,c);
	return re;
}
signed main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=k;++i)cin>>S[i]>>E[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int num=1;num<=n;++num){
		for(int i=1;i<=n;++i)usd[i]=false;
		q.push(make_pair(0,num));
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
			if(!usd[now])
			{
				usd[now]=true;
				for(int i=Head[now];i;i=e[i].nxt)
				{
					if(dis[num][e[i].to]>dis[num][e[i].from]+e[i].v)
					{
						dis[num][e[i].to]=dis[num][e[i].from]+e[i].v;
						q.push(make_pair(dis[num][e[i].to],e[i].to));
					}
				}
			}	
		}
	}
	int ans=INF;
	for(int i=1;i<=cnt;++i){
		int tmp=0,x=e[i].from,y=e[i].to;
		for(int j=1;j<=k;++j){
			tmp+=min(dis[S[j]][E[j]],dis[S[j]][x]+dis[y][E[j]],dis[S[j]][y]+dis[x][E[j]]);
		}
		ans=min(ans,tmp);
	}
	printf("%I64d\n",ans);
	return 0;
}
