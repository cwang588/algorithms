#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[400005];
int Head[200005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int dp[200005][2],value[200005][2];
set<int>last[200005];
int sum[200005];
void dfs(int now,int pre){
	dp[now][1]=1;
	value[now][0]=1;
	int num=0;
	for(int i=Head[now];i;i=e[i].nxt)++num;
	sum[now]=value[now][1]=num;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		dp[now][1]+=dp[to][0];
		value[now][1]+=value[to][0];
		if(dp[to][0]>dp[to][1]){
			dp[now][0]+=dp[to][0];
			value[now][0]+=value[to][0];
		}
		else if(dp[to][1]>dp[to][0]){
			dp[now][0]+=dp[to][1];
			value[now][0]+=value[to][1];
			last[now].insert(to);
		}
		else{
			dp[now][0]+=dp[to][0];
			if(value[to][0]<=value[to][1])value[now][0]+=value[to][0];
			else{
				value[now][0]+=value[to][1];
				last[now].insert(to);
			}
		}
	}
}
void dfss(int now,int pre,int sta){
	if(sta==0){
		sum[now]=1;
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			if(to==pre)continue;
			if(last[now].count(to))dfss(to,now,1);
			else dfss(to,now,0);
		}
	}
	else{
		for(int i=Head[now];i;i=e[i].nxt){
			int to=e[i].to;
			if(to==pre)continue;
			dfss(to,now,0);	
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(n==2){
		cout<<"2 2\n1 1\n";
		return 0;
	}
	dfs(1,0);
	if((dp[1][0]>dp[1][1])||(dp[1][0]==dp[1][1]&&value[1][0]<value[1][1])){
		cout<<dp[1][0]<<" "<<value[1][0]<<"\n";
		dfss(1,0,0);
		for(int i=1;i<=n;++i)cout<<sum[i]<<" ";
		cout<<"\n";
	}
	else{
		cout<<dp[1][1]<<" "<<value[1][1]<<"\n";
		dfss(1,0,1);
		for(int i=1;i<=n;++i)cout<<sum[i]<<" ";
		cout<<"\n";
	}
	return 0;
}