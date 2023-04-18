#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int from,to,nxt;
	long long v;
}e[400005];
int cnt,Head[50005];
void add(int x,int y,long long z)
{
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].v=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[100005],usdd[400005];
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > >q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		long long z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	usd[1]=true;
	for(int i=Head[1];i;i=e[i].nxt)
	{
		q.push(make_pair(e[i].v,i));
		usdd[i]=true;
		if(i%2)usdd[i+1]=true;
		else usdd[i-1]=true;
	}
	int cnt=0;
	long long tot=0;
	while(!q.empty()&&cnt<n-1)
	{
		int now=q.top().second;
		q.pop();
		int to=e[now].to;
		if(usd[to])continue;
		tot+=e[now].v;
		usd[to]=true;
		for(int i=Head[to];i;i=e[i].nxt)
		{
			if(!usdd[i]&&!usd[e[i].to])
			{
				q.push(make_pair(e[i].v,i));
				usdd[i]=true;
				if(i%2)usdd[i+1]=true;
				else usdd[i-1]=true;
			}
		} 
		++cnt;
	}
	if(cnt<n-1)printf("orz\n");
	else printf("%lld\n",tot);
	return 0;
}
