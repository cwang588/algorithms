#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const long long INF=214748364711451466;
int n,m;
struct graph{
	struct edge{
		int from,to,nxt;
		long long value;
	}e[200005];
	int cnt,Head[100005];
	bool usd[100005];
	long long dis[100005];
	graph(){
		cnt=0;
		memset(Head,0,sizeof(Head));
		memset(usd,0,sizeof(usd));
	}
	void add(int x,int y,long long z){
		++cnt;
		e[cnt].from=x;
		e[cnt].to=y;
		e[cnt].value=z;
		e[cnt].nxt=Head[x];
		Head[x]=cnt;
	}
	void dijsktra(int s){
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
		for(int i=1;i<=n;++i)dis[i]=INF;
		dis[s]=0;
		q.push(make_pair(0,s));
		while(!q.empty()){
			int now=q.top().second;
			q.pop();
			if(usd[now])continue;
			usd[now]=true;
			for(int i=Head[now];i;i=e[i].nxt){
				int to=e[i].to;
				if(dis[to]>dis[now]+e[i].value){
					dis[to]=dis[now]+e[i].value;
					if(!usd[to])q.push(make_pair(dis[to],to));
				}
			}
		}
	}
}g1,g2;
long long Min[100005<<2],a[100005];
void modify(int l,int r,int rt,int pos,long long k){
	if(l==r){
		Min[rt]=k;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)modify(lson,pos,k);
	else modify(rson,pos,k);
	Min[rt]=min(Min[rt<<1],Min[rt<<1|1]);
}
long long work(int pos){
	if(g2.dis[pos]==0)return 0;
	return (g2.dis[pos]-1)/a[pos]+1;
}
int main(){
	int q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i){
		int x,y;
		long long z,zz;
		scanf("%d%d%lld%lld",&x,&y,&z,&zz);
		g1.add(x,y,z);
		g2.add(y,x,zz);
	}
	g1.dijsktra(1);
	g2.dijsktra(n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i)modify(1,n,1,i,g1.dis[i]+work(i));
	for(int i=1;i<=q;++i){
		int pos;
		long long to;
		scanf("%d%lld",&pos,&to);
		a[pos]=to;
		modify(1,n,1,pos,g1.dis[pos]+work(pos));
		printf("%lld\n",Min[1]);
	}
	return 0;
}
