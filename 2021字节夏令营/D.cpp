#include<bits/stdc++.h>
using namespace std;
int dfs(int l,int r,int n){
	if(r<0||l>n)return 0;
	if(l==r)return 0;
	if(l==r-1){
		if(l==1||r==n)return 1;
		return 0;
	}
	int m=(l+r)>>1;
	return 1+dfs(l,m-1,n)+dfs(m+1,r,n);
}
int dp[40005];
int main(){
	dp[1]=1;
	for(int i=2;i<=10000;++i)dp[i]=dfs(1,i,i);
	for(int n=1;n<=500;++n){
		for(int i=1;i<=10000;++i){
			if(dp[i]==n){
				cout<<n<<":"<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
