#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[105],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
long long tot;
int sz[105];
void dfs(int now,int pre){
	sz[now]=1;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
bool cmp(int x,int y){
	return sz[e[x].to]<sz[e[y].to];
}
int num;
void dfss(int now,int pre){
	tot+=num;
	vector<int>tmp;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		tmp.push_back(i);
	}
	sort(tmp.begin(),tmp.end());
	for(auto x:tmp){
		++num;
		dfss(e[x].to,now);
		++num;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		num=0;
		tot=0;
		memset(Head,0,sizeof(Head));
		memset(sz,0,sizeof(sz));
		cnt=0;
		tot=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		dfs(1,0);
		dfss(1,0);
		printf("%.10f\n",1.0*tot/(n-1));
	}
	
	
	return 0;
}