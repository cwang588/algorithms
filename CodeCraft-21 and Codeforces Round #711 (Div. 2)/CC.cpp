#include<bits/stdc++.h>
using namespace std;
int tot,i,j;
void dfs(int n,int k,int to){
	if(n==0||k==1){
		++tot;
		return; 
	}
	if(to){
		dfs(n-1,k,to);
		dfs(i-n,k-1,1-to);
	}
	else{
		dfs(n-1,k,to);
		dfs(i-n,k-1,1-to);
	}
}
int dp[15][15];
int main(){
	for(i=1;i<=10;++i){
		for(j=1;j<=10;++j){
			tot=0;
			dfs(i,j,1);
			dp[i][j]=tot;
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	return 0;
}
