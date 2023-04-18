#include<bits/stdc++.h>
using namespace std;
char s[25];
long long dp[25][25];
int main(){
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n+1;++i)dp[i][i-1]=1;
	for(int len=2;len<=n;++len){
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			for(int k=i+1;k<j;++k){
				if(s[i]=='?'&&s[k]=='?'){
					dp[i][j]+=4*dp[i+1][k-1]*dp[k+1][j];
				}else if(s[i]=='?'){
					if(s[k]==')'||s[k]=='}'||s[k]=='>'||s[k]==']')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
				}else if(s[k]=='?'){
					if(s[i]=='('||s[i]=='{'||s[i]=='<'||s[i]=='[')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
				}else{
					if(s[i]=='('&&s[k]==')')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
					if(s[i]=='{'&&s[k]=='}')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
					if(s[i]=='['&&s[k]==']')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
					if(s[i]=='<'&&s[k]=='>')dp[i][j]+=dp[i+1][k-1]*dp[k+1][j];
				}
			}
			if(s[i]=='?'&&s[j]=='?'){
				dp[i][j]+=4*dp[i+1][j-1];
			}else if(s[i]=='?'){
				if(s[j]==')'||s[j]=='}'||s[j]=='>'||s[j]==']')dp[i][j]+=dp[i+1][j-1];
			}else if(s[j]=='?'){
				if(s[i]=='('||s[i]=='{'||s[i]=='<'||s[i]=='[')dp[i][j]+=dp[i+1][j-1];
			}else{
				if(s[i]=='('&&s[j]==')')dp[i][j]+=dp[i+1][j-1];
				if(s[i]=='{'&&s[j]=='}')dp[i][j]+=dp[i+1][j-1];
				if(s[i]=='['&&s[j]==']')dp[i][j]+=dp[i+1][j-1];
				if(s[i]=='<'&&s[j]=='>')dp[i][j]+=dp[i+1][j-1];
			}
		}
	}
	cout<<dp[1][n]<<"\n";
	return 0;
}