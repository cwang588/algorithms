#include<bits/stdc++.h>
using namespace std;
int a[305][305];
bool nb[305][305],usd[305];
struct edge{
	int from,to,nxt,value;
}e[200005];
int cnt,Head[2005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dis[20005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(a[i][j]&&a[j][k]&&a[k][i])nb[i][j]=nb[j][k]=nb[k][i]=true;
				if(a[k][j]&&a[j][i]&&a[i][k])nb[k][j]=nb[j][i]=nb[i][k]=true;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i][j]&&a[j][i])nb[i][j]=nb[j][i]=true;		
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(a[i][j]){
				if(nb[i][j])add(i,j,0);
				else add(i,j,1);
			}
		}
	}
	for(int i=1;i<=n;++i)dis[i]=19260817;
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(usd[now])continue;
		usd[now]=true;
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			if(dis[to]>dis[now]+e[i].value){
				dis[to]=dis[now]+e[i].value;
				q.push(make_pair(dis[to],to));
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dis[i]<19260817)cout<<dis[i]<<" ";
		else cout<<"-1 ";
	}
	return 0;
}
