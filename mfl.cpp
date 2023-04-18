#include<bits/stdc++.h>
using namespace std;
const int INF=2147483647;
struct edge{
	int from,to,nxt;
}e[1000005];
int cnt,Head[707];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[707];
int dis[707];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		while(t--){
			int tmp;
			cin>>tmp;
			add(i,tmp);
			add(tmp,i);
		}
	}
	int ans=INF;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[j]=INF,usd[j]=false;
		queue<int>q;
		usd[i]=true;
		dis[i]=0;
		q.push(i);
		while(!q.empty()){
			int now=q.front();
			q.pop();
			for(int j=Head[now];j;j=e[j].nxt){
				int to=e[j].to;
				if(usd[to])continue;
				dis[to]=dis[now]+1;
				usd[to]=true;
				q.push(to);
			}
		}
		int nowans=0;
		for(int j=1;j<=n;++j)nowans=max(nowans,dis[j]);
		ans=min(ans,nowans);
	}
	cout<<(ans==INF?0:ans);
	return 0;
}