#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[200005];
int cnt,Head[100005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int fir[100005],maxcnt[1000005],sec[100005],maxfrom[100005],fromup[100005],num[100005];
void dfs(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		if(fir[to]+1>fir[now]){
			sec[now]=fir[now];
			fir[now]=fir[to]+1;
			maxfrom[now]=to;
			maxcnt[now]=1;
		}else if(fir[to]+1==fir[now]){
			++maxcnt[now];
		}else if(fir[to]+1>sec[now]){
			sec[now]=fir[to]+1;
		}else;
	}
}
void dfss(int now,int pre){
	if(pre){
		fromup[now]=fromup[pre]+1;
		if(maxcnt[pre]>1||maxfrom[pre]!=now)fromup[now]=max(fromup[now],fir[pre]+1);
		else fromup[now]=max(fromup[now],sec[pre]+1);
	}
	int numnow=max(fir[now],fromup[now]);
	++num[numnow];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to!=pre)dfss(to,now);
	}
}
int ans[100005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	dfss(1,0);
	int now=n;
	for(int i=n;i>=1;--i){
		if(num[i]){
			if(now==n)now-=num[i]-1;
			else now-=num[i];
		}
		ans[i]=now;
	}
	for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
} 
