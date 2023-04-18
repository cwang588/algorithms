#include<bits/stdc++.h>
using namespace std;
const long long INF=19198101145140000;
struct edge{
	int from,to,nxt;
	long long value;
}ee[4000005];
int Head[600005],Headd[600005],cnt,cntt;
long long dis[600005],diss[600005],tdis[600005];
bool used[600005],usedd[600005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q,qq;
void addd(int x,int y,long long z){
	++cntt;
	ee[cntt].from=x;
	ee[cntt].to=y;
	ee[cntt].value=z;
	ee[cntt].nxt=Headd[x];
	Headd[x]=cntt;
}
int main(){
	int n,m,s;
	cin>>n>>m>>s;
	for(int i=1;i<=m;++i){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		addd(x,y,z);
	}
	for(int i=1;i<=n*3;++i)dis[i]=diss[i]=tdis[i]=INF;
	diss[s]=0;
	qq.push(make_pair(0,s));
	while(!qq.empty())
	{
		int now=qq.top().second;
		qq.pop();
		if(!usedd[now])
		{
			usedd[now]=true;
			for(int i=Headd[now];i;i=ee[i].nxt)
			{
				if(diss[ee[i].to]>diss[ee[i].from]+ee[i].value)
				{
					diss[ee[i].to]=diss[ee[i].from]+ee[i].value;
					qq.push(make_pair(diss[ee[i].to],ee[i].to));
				}
			}
		}	
	}
	for(int i=1;i<=n;++i)printf("%lld ",diss[i]);
	return 0;
}
