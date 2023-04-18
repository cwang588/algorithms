#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[150005];
int Head[70005],cnt;
vector<int>ans;
bool usd[70005],tag[70005];
void init(int n){
	cnt=0;
	int num=(1<<n);
	for(int i=0;i<num;++i)Head[i]=0,usd[i]=tag[i]=false;
	ans.clear();
}
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		init(n);
		int num=(1<<(n-1))*n;
		for(int i=1;i<=num;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		queue<pair<int,int> >q;
		q.push(e[1].from,e[1].to);
		usd[e[1].from],
		ans.push_back(make_pair(e[1].from,e[1].to));
		while(!q.empty()){
			int x=q.front().first,y=q.front().second;
			
		}
	}
	return 0;
}
