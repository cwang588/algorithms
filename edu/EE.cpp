#include<iostream>
#include<cstring>
using namespace std;
const long long mod=998244353;
char a[1005],b[1005];
long long dp[1005][1005];
int main(){
	cin>>(a+1)>>(b+1);
	int n=strlen(a+1),m=strlen(b+1);
	dp[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i==0&&j==0)continue;
			if(a[i]!=b[j])dp[i][j]=dp[i-1][j]+dp[i][j-1];
			else{
				if(i-2>=0)dp[i][j]+=dp[i-2][j];
				if(j-2>=0)dp[i][j]+=dp[i][j-1];
			}	
		}
	}
	cout<<dp[n][m];
	return 0;
}
