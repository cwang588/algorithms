#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
const double inf=1000000.0;
struct edge{
	int from,to,nxt;
	double value;
}e[maxn<<1];
int cnt,Head[maxn];
void add(int x,int y,double z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;	
}
map<string,int>id;
int n;
bool usd[maxn];
double dis[maxn];
void spfa(int s){
	for(int i=1;i<=n;++i)dis[i]=inf;
	dis[s]=0,usd[s]=true;
	queue<int>q;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		usd[now]=false;
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			if(dis[now]+e[i].value<dis[to]){
				dis[to]=dis[now]+e[i].value;
				if(!usd[to]){
					q.push(to);
					usd[to]=true;
				}
			}
		}
	}
}
void work(string &data){
	string now;
	int now_from=0,now_to=0;
	for(auto &x:data){
		if(x==','){
			if(!id.count(now))id[now]=++n;
			if(!now_from)now_from=id[now];
			else now_to=id[now];
			now="";
		}
		else if(x==';'){
			add(now_from,now_to,-log(stod(now)));
			now="";
			now_from=now_to=0;
		}
		else now+=x;
	}
	add(now_from,now_to,-log(stod(now)));
	now="";
	now_from=now_to=0;
}
int main() {
	string data,origin,target;
	cin>>data>>origin>>target;
	work(data);
	spfa(id[origin]);
	if(dis[id[target]]==inf)cout<<"-1.0\n";
	else cout<<exp(-dis[id[target]])<<"\n";
	return 0;
}
