#include<bits/stdc++.h>
using namespace std;
int dp[20][2],a[23];
int dfs(int now,int pre,int sta,bool limit){
	if(now==0)return 1;
	if(!limit&&dp[now][sta]!=-1)return dp[now][sta];
	int tmp=0,up=limit?a[now]:9;
	for(int i=0;i<=up;++i){
		if(pre==6&&i==2||i==4)continue;
		tmp+=dfs(now-1,i,i==6,limit&&i==a[now]);
	}
	if(!limit)dp[now][sta]=tmp;
	return tmp;
}
int calc(int n){
	int pos=0;
	while(n){
		a[++pos]=n%10;
		n/=10;
	}
	return dfs(pos,-1,0,true);
}
int main(){
	memset(dp,-1,sizeof(dp));
	int n,m;
	cin>>n>>m;
	while(n){
		cout<<calc(m)-calc(n-1)<<"\n";
		cin>>n>>m;
	}
	return 0;
}