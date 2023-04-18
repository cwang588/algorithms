#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
	long long value;
}e[4000006];
int Head[4000005],cnt;
void add(int x,int y,long long z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct bian{
	int x,y;
	long long a,b;
	bool operator <(const bian &t){
		return a<t.a;
	}	
};
vector<bian>in[200005],out[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;++i){
			bian tmp;
			cin>>tmp.x>>tmp.y>>tmp.a>>tmp.b;
			in[tmp.x].push_back(tmp);
			out[tmp.y].push_back(tmp);
		}
		int num=n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<in[i].size()+out[i].size();++j)add(n+j,n+j+1,0);
			add(in[i].size()+out[i].size()+num,i,0);
			for(int )
		}
	}
	
	
	return 0;
}