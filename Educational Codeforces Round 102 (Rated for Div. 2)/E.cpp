#include<bits/stdc++.h>
using namespace std;
const long long INF=19198101145140000;
struct edge{
	int from,to,nxt;
	long long value;
}e[4000005],ee[4000005];
int Head[600005],Headd[600005],cnt,cntt;
long long dis[600005],diss[600005],tdis[600005];
bool usd[600005],usdd[600005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
void add(int x,int y,long long z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void addd(int x,int y,long long z){
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].value=z;
	ee[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*3;++i)dis[i]=diss[i]=tdis[i]=INF;
	for(int i=1;i<=m;++i){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
		add(x,y+n,z*2);
		add(y,x+n,z*2);
		add(x+n,y+n,z);
		add(y+n,x+n,z);
		add(x+n,y+2*n,0);
		add(y+n,x+2*n,0);
		add(x+2*n,y+2*n,z);
		add(y+2*n,x+2*n,z);
		addd(x,y,z);
		addd(y,x,z);
		addd(x,y+n,0);
		addd(y,x+n,0);
		addd(x+n,y+n,z);
		addd(y+n,x+n,z);
		addd(x+n,y+2*n,2*z);
		addd(y+n,x+2*n,2*z);
		addd(x+2*n,y+2*n,z);
		addd(y+2*n,x+2*n,z);
		if(x==1)tdis[y]=min(tdis[y],z);
		if(y==1)tdis[x]=min(tdis[x],z);
	}

	dis[1]=diss[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usd[now])
		{
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].value)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].value;
					q.push(make_pair(dis[e[i].to],e[i].to));
				}
			}
		}	
	}
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int now=q.top().second;
		q.pop();
		if(!usdd[now])
		{
			usdd[now]=true;
			for(int i=Headd[now];i;i=ee[i].nxt)
			{
				if(diss[ee[i].to]>diss[ee[i].from]+ee[i].value)
				{
					diss[ee[i].to]=diss[ee[i].from]+ee[i].value;
					q.push(make_pair(diss[ee[i].to],ee[i].to));
				}
			}
		}	
	}
	for(int i=2;i<=n;++i)printf("%I64d ",min(min(dis[i+2*n],diss[i+2*n]),tdis[i]));
	printf("\n");
	return 0;
}
