#include<bits/stdc++.h>
using namespace std;
int a[200005];
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
int dp[200005][2];
void dfs(int now){
	dp[now][0]=dp[now][1]=0;
	int Min=2147483647,tot=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		dfs(to);
		dp[now][0]+=max(dp[to][0],dp[to][1]);
		tot+=dp[to][1];
		Min=min(Min,dp[to][1]-dp[to][0]);
	}
	if(Min<2147483647)dp[now][1]=tot-Min+1;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cnt=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],Head[i]=0;
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		queue<pair<int,int> >q1,q2;
		for(int i=2;i<=n;++i)q2.push(make_pair(a[i],i));
		q1.push(make_pair(a[1],1));
		while(!q1.empty()){
			auto now=q1.front();
			q1.pop();
			int num=now.first;
			while(num--){
				auto tmp=q2.front();
				q2.pop();
				add(now.second,tmp.second);
				if(tmp.first>1)q1.push(make_pair(tmp.first-1,tmp.second));
			}
		}
		dfs(1);
		cout<<max(dp[1][0],dp[1][1])<<"\n";
	}
	
	
	return 0;
}