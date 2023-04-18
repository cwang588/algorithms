#include<bits/stdc++.h>
#define N 800010
using namespace std;
const long long INF=2147483647777777;
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > >q;
struct edge
{
	int from,to,nxt;
	long long v;
}e[N];
int Head[N],cnt;
int gas[105][105];
long long dis[N];
bool usd[N];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int n,K,A,B,C;
int mov[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int num(int i,int j,int k){return i+(j-1)*n+k*n*n;};
void Init()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;k<=K;++k)
			{
				if(k==0)
				{
					int tot=A;
					if(!gas[i][j])tot+=C;
					add(num(i,j,k),num(i,j,K),tot);
					continue;
				}
				if(gas[i][j]&&k!=K)
				{
					add(num(i,j,k),num(i,j,K),A);
					continue;
				}
				for(int o=0;o<4;++o)
				{
					int tox=i+mov[o][0],toy=j+mov[o][1];
					if(tox>n||tox<=0||toy>n||toy<=0)continue;
					int tot=0;
					if(mov[o][0]<0||mov[o][1]<0)tot+=B; 
					add(num(i,j,k),num(tox,toy,k-1),tot);
				}
			}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&K,&A,&B,&C);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&gas[i][j]);
	Init();
	for(int i=1;i<=n*n*(K+1);++i)
		dis[i]=INF;
	dis[num(1,1,K)]=0;
	q.push(make_pair(0,num(1,1,K)));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].v;
					q.push(make_pair(dis[e[i].to],e[i].to));
				}
			}
		}	
	}
	long long ans=INF;
	for(int i=0;i<=K;++i)ans=min(ans,dis[num(n,n,i)]);
	printf("%lld\n",ans);
	return 0;
} 
