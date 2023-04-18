#include<bits/stdc++.h>
using namespace std;
int a[105][105],Max[75][75],f[75][75],dp[75][4905][40];
bool usd[75][75],ky[75][75][50];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;++i){
		memset(dp,0,sizeof(dp));
		memset(ky,0,sizeof(ky));
		ky[0][0][0]=true;
		for(int j=1;j<=m;++j){
			for(int sum=0;sum<k;++sum){
				for(int num=0;num<=m/2;++num){
					ky[j][sum][num]|=ky[j-1][sum][num];
					if(num>0)ky[j][sum][num]|=ky[j-1][(sum-(a[i][j]%k)+k)%k][num-1];	
				}
			}
		}	
		for(int j=1;j<=m;++j){
			for(int sum=0;sum<k;++sum){
				for(int num=0;num<=m/2;++num){
					dp[j][sum][num]=dp[j-1][sum][num];
					if(num>0&&ky[j-1][(sum-(a[i][j]%k)+k)%k][num-1]){
						dp[j][sum][num]=max(dp[j][sum][num],dp[j-1][(sum-(a[i][j]%k)+k)%k][num-1]+a[i][j]);
					}	
				}
			}
		}
		for(int j=0;j<k;++j){
			for(int num=0;num<=m/2;++num){
				Max[i][j]=max(Max[i][j],dp[m][j][num]);
			}
		}
	}
	usd[0][0]=true;
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			usd[i][j]|=usd[i-1][j];
			for(int o=0;o<k;++o){
				if(Max[i][o])usd[i][j]|=usd[i-1][(j-o+k)%k];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			f[i][j]=f[i-1][j];
			for(int o=0;o<k;++o){
				if(usd[i-1][(j-o+k)%k]&&Max[i][o])f[i][j]=max(f[i][j],f[i-1][(j-o+k)%k]+Max[i][o]);
			}
		}
	}
	printf("%d\n",f[n][0]); 
	return 0;
}
