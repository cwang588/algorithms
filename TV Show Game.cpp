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
bool usd[200005];
vector<int>v;
void dfs(int now){
	v.push_back(now);
	usd[now]=true;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to])continue;
		dfs(to);
	}
}
int main(){
	int k,n;
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		int x,y,z;
		char a,b,c;
		cin>>x>>a>>y>>b>>z>>c;
		if(a=='R'){
			if(b=='R')add(x+n,y);
			else add(x+n,y+n);
			if(c=='R')add(x+n,z);
			else add(x+n,z+n);
		}
		else{
			if(b=='R')add(x,y);
			else add(x,y+n);
			if(c=='R')add(x,z);
			else add(x,z+n);
		}
		if(b=='R'){
			if(a=='R')add(y+n,x);
			else add(y+n,x+n);
			if(c=='R')add(y+n,z);
			else add(y+n,z+n);
		}
		else{
			if(a=='R')add(y,x);
			else add(y,x+n);
			if(c=='R')add(y,z);
			else add(y,z+n);
		}
		if(c=='R'){
			if(b=='R')add(z+n,y);
			else add(z+n,y+n);
			if(a=='R')add(z+n,x);
			else add(z+n,x+n);
		}
		else{
			if(b=='R')add(z,y);
			else add(z,y+n);
			if(a=='R')add(z,x);
			else add(z,x+n);
		}
	}
	bool ans=true;
	for(int i=1;i<=n;++i){
		if(usd[i]||usd[i+n])continue;
		dfs(i);
		bool ky=true;
		for(int j=1;j<=n;++j){
			if(usd[j]&&usd[j+n]){
				ky=false;
				break;
			}
		}
		if(!ky){
			for(auto x:v)usd[x]=false;
			v.clear();
			dfs(i+n);
			bool tmpky=true;
			for(int j=1;j<=n;++j){
				if(usd[j]&&usd[j+n]){
					tmpky=false;
					break;
				}
			}
			if(!tmpky){
				ans=false;
				break;
			}
		}
		v.clear();
	}
	if(!ans)return !printf("-1\n");
	for(int i=1;i<=n;++i){
		if(usd[i])printf("R");
		else printf("B");
	}
	printf("\n");
	return 0;
}
