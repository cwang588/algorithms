#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int inf=2147483647;
int cntt=1,Headd[10005];
int N,M,S,T;
struct Node{
	int v,nxt;
	long long val;
}node[4000010];
inline void addedge(int u,int v,long long val){
	node[++cntt].v=v;
	node[cntt].val=val;
	node[cntt].nxt=Headd[u];
	Headd[u]=cntt;
}
int dep[100005],gap[100005];
void bfs(){
	memset(dep,-1,sizeof(dep));
	memset(gap,0,sizeof(gap));
	dep[T]=0;
	gap[0]=1;
	queue<int>q;
	q.push(T);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=Headd[u];i;i=node[i].nxt){
			int v=node[i].v;
			if(dep[v]!=-1)continue;
			q.push(v);;
			dep[v]=dep[u]+1;
			gap[dep[v]]++;
		}
	}
}
long long maxflow;
long long Dfs(int u,long long flow){
	if(u==T){
		maxflow+=flow;
		return flow;
	}
	int used=0;
	for(int i=Headd[u];i;i=node[i].nxt){
		int d=node[i].v;
		if(node[i].val&&dep[d]+1==dep[u]){
			long long mi=Dfs(d,min(node[i].val,flow-used));
			if(mi){
				node[i].val-=mi;
				node[i^1].val+=mi;
				used+=mi;
			}
			if(used==flow)return used;
		}
	}
	--gap[dep[u]];
	if(gap[dep[u]]==0)dep[S]=N+1;
	dep[u]++;
	gap[dep[u]]++;
	return used;
}
long long ISAP(){
	maxflow=0;
	bfs();
	while(dep[S]<N)Dfs(S,inf);
	return maxflow;
}
int x[10005],y[10005],n,r,m;
void add(int x,int y,int z){
	addedge(x,y,z);
	addedge(y,x,0);
//	addedge(y,x+2*m,1);
//	addedge(x+2*m,y,0);
}
signed main(){
	cin>>n>>r>>m;
	for(int i=1;i<=m;++i){
		cin>>x[i]>>y[i];
	}
	N=4*m+2,S=4*m+1,T=4*m+2; 
	for(int i=1;i<=m;++i){
		add(S,2*i-1,192608107);
		add(S,2*i,192608107);
		add(2*i-1+2*m,T,192608107);
		add(2*i+2*m,T,192608107);
		add(2*i-1,2*i+2*m,1);
		add(2*i,2*i-1+2*m,1);
	}
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			if(x[i]==x[j]){
//				if(abs(y[i]-y[j])+1<=r){
//					add(2*i,2*j-1);
//					add(2*i,2*j);
//					add(2*j,2*i-1);
//				}
//				else if(abs(y[i]-y[j])+1<2*r)add(2*i,2*j);
//				else;
				if(abs(y[i]-y[j])+1<2*r+2){
					add(2*i,2*j+2*m,1);
					add(2*j,2*i+2*m,1);						
				}
			}
			else if(y[i]==y[j]){
//				if(abs(y[i]-y[j])+1<=r){
//					add(2*i-1,2*j-1);
//					add(2*i-1,2*j);
//					add(2*i,2*j-1);
//				}
//				else if(abs(y[i]-y[j])+1<2*r)add(2*i-1,2*j-1);
//				else;
				if(abs(x[i]-x[j])+1<2*r+2){
					add(2*i-1,2*j-1+2*m,1);
					add(2*j-1,2*i-1+2*m,1);						
				}
			}
			else;
//			else{
//				if(max(abs(x[i]-x[j]),abs(y[i]-y[j]))+1<=r){
//					add(2*i,2*j-1);
//					add(2*i-1,2*j);
//				}
//			}
		}
	}
	long long ans=ISAP();
	//cout<<ans<<endl;
	if(ans/2<m*2)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
