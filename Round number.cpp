#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int dp[35][75],a[35];
int dfs(int now,int gap,bool lead,bool limit){
	if(now==0)return gap>=32?1:0;
	if(!limit&&!lead&&dp[now][gap]!=-1)return dp[now][gap];
	int up=limit?a[now]:1,tmp=0;
	for(int i=0;i<=up;++i){
		if(i==0)tmp+=dfs(now-1,gap+(lead?0:1),lead,limit&&i==a[now]);
		else tmp+=dfs(now-1,gap-1,false,limit&&i==a[now]);
	}
	if(!lead&&!limit)dp[now][gap]=tmp;
	return tmp;
}
int calc(int x){
	int pos=0;
	while(x){
		a[++pos]=x&1;
		x>>=1;
	}
	return dfs(pos,32,true,true);
}
int main(){
	int l,r;
	cin>>l>>r;
	memset(dp,-1,sizeof(dp));
	cout<<calc(r)-calc(l-1)<<"\n";
	return 0;
}