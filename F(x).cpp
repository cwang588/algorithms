#include<bits/stdc++.h>
using namespace std;
int Max;
int f(int x){
	int re=0,now=1;
	while(x){
		re+=now*(x%10);
		x/=10;
		now<<=1;
	}
	return re;
}
int a[35],dp[11][4705],mi[15];
int dfs(int now,int sum,bool limit){
	if(now==0)return sum<=Max?1:0;
	if(!limit&&dp[now][Max-sum]!=-1)return dp[now][Max-sum];
	int tmp=0,up=limit?a[now]:9;
	for(int i=0;i<=up;++i){
		if(sum+mi[now-1]*i>Max)continue;
		tmp+=dfs(now-1,sum+mi[now-1]*i,limit&&i==a[now]);
	}
	if(!limit)dp[now][Max-sum]=tmp;
	return tmp;
}
int calc(int x){
	int pos=0;
	while(x){
		a[++pos]=x%10;
		x/=10;
	}
	return dfs(pos,0,true);
}
int main(){
	mi[0]=1;
	for(int i=1;i<=10;++i)mi[i]=mi[i-1]*2;
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	for(int Case=1;Case<=t;++Case){
		int A,B;
		cin>>A>>B;
		Max=f(A);
		cout<<"Case #"<<Case<<": "<<calc(B)<<"\n";
	}
	
	return 0;
}