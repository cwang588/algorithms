#include<bits/stdc++.h>
using namespace std;
map<unsigned long long,int>mm;
int num;
struct edge{
	int from,to,nxt;
}e[1005];
int Head[1005],cnt,dp[1005];
bool usd[1005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int work(string now){
	int n=now.length();
	unsigned long long tmp=0;
	int last=1;
	for(int i=0;i<n;++i){
		if(now[i]=='/'){
			if(!mm[tmp]){
				mm[tmp]=++num;
				add(last,mm[tmp]);
			}
			last=mm[tmp];
			tmp=0;
			usd[last]=true;
		}
		else tmp=tmp*19260817+now[i];
	}
	if(!mm[tmp])mm[tmp]=++num;
	add(last,mm[tmp]);
	last=mm[tmp];
	return last;
}
void dfs(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to,now);
		usd[now]&=usd[to];
	}
	if(usd[now]&&now!=1)dp[now]=1;
	else{
		dp[now]=0;
		for(int i=Head[now];i;i=e[i].nxt)dp[now]+=dp[e[i].to];
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		num=1;
		cnt=0;
		mm.clear();
		memset(Head,0,sizeof(Head));
		memset(dp,0,sizeof(dp));
		memset(usd,0,sizeof(usd));
		for(int i=1;i<=n;++i){
			string tmp;
			cin>>tmp;
			int now=work(tmp);
			usd[now]=true;
		}
		for(int i=1;i<=m;++i){
			string tmp;
			cin>>tmp;
			int now=work(tmp);
			usd[now]=false;
		}
		usd[1]=false;
		dfs(1,0);
		printf("%d\n",dp[1]);
	}
	return 0;
}
