#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,value,nxt,col;
}e[200005];
int cnt,Head[50005];
void add(int x,int y,int z,int col){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].col=col;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int getid(int x,int y){
	return (x<<7)+y;
}
pair<int,int>getxy(int now){
	return make_pair(now>>7,now%128);
}
bool usd[50005];
int dis[50006];
int getcol(char t){
	if(t=='R')return 0;
	else if(t=='O')return 1;
	else if(t=='Y')return 2;
	else if(t=='G')return 3;
	else if(t=='B')return 4;
	else if(t=='I')return 5;
	else return 6;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int x,y,z;
		char t;
		cin>>x>>y>>z>>t;
		int col=getcol(t);
		add(x,y,z,col);
		add(y,x,z,col);
	}
	for(int i=0;i<=50000;++i)dis[i]=1e9;
	dis[128]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push(make_pair(0,getid(1,0)));
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(usd[now])continue;
		auto noww=getxy(now);
		int id=noww.first,col=noww.second;
		for(int i=Head[id];i;i=e[i].nxt){
			int to=getid(e[i].to,col|(1<<e[i].col));
			if(dis[now]+e[i].value<dis[to]){
				dis[to]=dis[now]+e[i].value;
				q.push(make_pair(dis[to],to));
			}
		}
		usd[now]=true;
	}
	cout<<dis[getid(1,127)]<<"\n";
	return 0;
}