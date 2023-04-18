#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
const int maxn = 1005;
const int mod = 10007;

char a[maxn];
int n,dp[maxn][maxn];

int solve(){
    memset(dp,0,sizeof(dp));
    for(int i = n-1 ; i >= 0 ;i--){
        for(int j = i ;j < n ; j++){
            dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + mod) % mod;
            if(a[i] == a[j]) dp[i][j] = (dp[i][j] + dp[i+1][j-1] + 1) % mod;
        }
    }
    return dp[0][n-1];
}

int main(){
    int cas;
    scanf("%d",&cas);
    for(int T = 1 ; T <= cas; T++){
        scanf("%s",a);
        n = strlen(a);
        printf("Case %d: %d\n",T,solve());
    }

    return 0;
}
