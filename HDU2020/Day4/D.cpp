#include<bits/stdc++.h>
using namespace std;
const long long INF=1145141919810;
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > > q;
long long dis[200005];
bool usd[100005];
int cnt;
struct edge
{
	int from,to,nxt;
	long long v;
}e[1600005];
int Head[200005];
char S[100005];
inline void add(int a,int b,long long c)
{
	++cnt;
	e[cnt].from=a;
	e[cnt].to=b;
	e[cnt].v=c;
	e[cnt].nxt=Head[a];
	Head[a]=cnt;
}
int ind[100005];
int main()
{
// 	ios::sync_with_stdio(false);
	int tt;
 	scanf("%d",&tt); 
	while(tt--)
 	{
 		cnt=0;
 		int n,m,s,t;
 		long long X;
 		//cin>>n>>m>>s>>t>>X;
 		scanf("%d%d%d%d%lld",&n,&m,&s,&t,&X);
		int tmpp=n;
 		scanf("%s",S+1);
 		for(int i=1;i<=tmpp;++i)
 			if(S[i]=='M')ind[i]=(++n);
 		for(int i=1;i<=m;++i)
 		{
 			int x,y;
 			long long z;
 			scanf("%d%d%lld",&x,&y,&z);
			if(S[x]=='M'&&S[y]=='M')
 			{
 				add(x,y,z);
 				add(y,x,z);
 				add(ind[y],x,z+X);
 				add(ind[x],y,z+X);
 				add(y,ind[x],z+X);
 				add(x,ind[y],z+X);
 				add(ind[x],ind[y],z);
 				add(ind[y],ind[x],z);
 			}
 			else if(S[x]=='M')
 			{
 				if(S[y]=='L')
 				{
 					add(x,y,z);
 					add(y,x,z);
 					add(y,ind[x],z+X);
 					add(ind[x],y,z+X);
 				}
 				else
 				{
 					add(x,y,z+X);
 					add(y,x,z+X);
 					add(y,ind[x],z);
 					add(ind[x],y,z);
 				}
 			}
 			else if(S[y]=='M')
 			{
 				if(S[x]=='L')
 				{
 					add(x,y,z);
 					add(y,x,z);
 					add(x,ind[y],z+X);
 					add(ind[y],x,z+X);
 				}
 				else
 				{
 					add(x,y,z+X);
 					add(y,x,z+X);
 					add(x,ind[y],z);
 					add(ind[y],x,z);
 				}
 			}
 			else
 			{
 				if(S[x]==S[y])
 				{
 					add(x,y,z);
 					add(y,x,z);
 				}
 				else
 				{
 					add(x,y,z+X);
 					add(y,x,z+X);
 				}
 			}
 		}
 		if(S[s]=='M')
 		{
 			int tmp=s;
 			s=(++n);
 			add(tmp,s,0);
 			add(ind[tmp],s,0);
 			add(s,tmp,0);
 			add(s,ind[tmp],0);
 		}
 		for(int i=1;i<=n;++i)dis[i]=INF;
 		dis[s]=0;
 		usd[s]=true;
 		q.push(make_pair(0,s));
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
			for(int i=Head[now];i;i=e[i].nxt)
			{
				if(dis[e[i].to]>dis[e[i].from]+e[i].v)
				{
					dis[e[i].to]=dis[e[i].from]+e[i].v;
					q.push(make_pair(dis[e[i].to],e[i].to));
				}
			}
		}
		if(S[t]=='M')printf("%lld\n",min(dis[t],dis[ind[t]]));
		else printf("%lld\n",dis[t]);
		for(int i=1;i<=n;++i)
		{
			usd[i]=false;
			ind[i]=0;
			Head[i]=0;
		}
	}
	return 0;
}
