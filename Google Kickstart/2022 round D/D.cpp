#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		cnt=0;
		memset(Head,0,sizeof(Head));
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=m;++i){
			int x,y;
			cin>>x>>y;
			add(y,x);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			queue<int>q;
			vector<int>v;
			v.push_back(i);
			q.push(i);
			usd[i]=true;
			while(!q.empty()){
				int now=q.front();
				q.pop();
				for(int i=Head[now];i;i=e[i].nxt){
					int to=e[i].to;
					if(usd[to])continue;
					q.push(to);
					v.push_back(to);
					usd[to]=true;
					if(v.size()>k)break;
				}
				if(v.size()>k)break;
			}
			if(v.size()>k)++ans;
			for(auto x:v)usd[x]=false;
		}
		printf("Case #%d: %d\n",Case,ans);
	}
	return 0;
}