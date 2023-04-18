#include <cstdio>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
struct edge
{
	int u,v;
	long long cap;
}e[120010];
struct Dinic
{
	int tp,s,t,dis[1300],cur[1300],que[1300];
	vector<edge>e;vector<int>v[1300];
	void AddEdge(int x,int y,long long flw)
	{
		e.push_back(edge{x,y,flw});
		e.push_back(edge{y,x,0});
		v[x].push_back(e.size()-2);
	}
	int bfs()
	{
		memset(dis,0x3f,sizeof dis);
		int l=1,r=1;que[1]=s;dis[s]=0;
		while(l<=r)
		{
			int p=que[l++],to;
			for(int i:v[p])if(e[i].cap&&dis[to=e[i].v]>1e9)
				dis[to]=dis[p]+1,que[++r]=to;
		}
		return dis[t]<1e9;
	}
	long long dfs(int p,long long a)
	{
		if(p==t||!a)return a;
		int sf=0;
		long long flw;
		for(int &i=cur[p],to;i<(int)v[p].size();++i)
		{
			edge &E=e[v[p][i]];
			if(dis[to=E.v]==dis[p]+1 && (flw=dfs(to,min(a,E.cap))))
			{
				E.cap-=flw;e[v[p][i]^1].cap+=flw;
				a-=flw;sf+=flw;
				if(!a)break;
			}
		}
		return sf;
	}
	long long dinic(int s,int t,int tp=1){
		this->s=s;this->t=t;this->tp=tp;
		long long flw=0;
		while(bfs()){
			memset(cur,0,sizeof cur);
			flw+=dfs(s,1145141919810);
		}
		return flw;
	}
}sol;
int n,m,i,s,t;
long long ans;
int MaxFlow()
{
	sort(e,e+m,[](edge a,edge b){return a.cap>b.cap;});
	sol.e.clear();
	memset(sol.dis,0,sizeof(sol.dis));
	memset(sol.cur,0,sizeof(sol.cur));
	memset(sol.que,0,sizeof(sol.que));
	for(int i=0;i<=505;++i)sol.v[i].clear();
	for(int tp:{0,1})
        for(int p=1<<30,i=0;p;p/=2)
        {
            while(i<m && e[i].cap>=p)
            {
                if(tp)
                    sol.v[e[i].v].push_back(i*2+1);
                else
                    sol.AddEdge(e[i].u,e[i].v,e[i].cap);
                i++;
            }
		ans+=sol.dinic(s,t,tp);
	}
	return ans;
}
void add(int x,int y,long long z)
{
	++m;
	e[m]={x,y,z};
}
int main()
{
	int q;
	while(~scanf("%d%d",&n,&q))
	{
		ans=0;
		long long sum=0;
		s=n+1,t=n+2;
		for(int i=1;i<=q;++i)
		{
			int u,v,a,b,c;
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&c);
			add(s,u,a+b);
			add(s,v,a+b);
			add(u,t,b+c);
			add(v,t,b+c);
			add(u,v,a+c-2*b);
			add(v,u,a+c-2*b);
			sum+=2*a+2*c+2*b;
		}
		printf("%lld\n",(sum-MaxFlow())/2);
	}
	return 0;
}

