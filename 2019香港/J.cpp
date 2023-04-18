#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long dp[5005][65][65];
char l[5005],r[5005];
int mi[5005];
int work(int x,int m){
	return (x%m+m)%m;
}
long long getans(int m){
	long long ans=0,ans1=0,ans2=0;
	int n=strlen(r+1),nowmod=0,nowtot1=0,nowtot2=0;
	for(int i=1;i<=n;++i){
		int now=r[i]-'0';
		for(int j=0;j<now;++j){
			for(int k=0;k<m;++k){
				int nowtot=((nowtot1+j)*(nowtot1+j)-(nowtot2+j*j))/2+(nowtot1+j)*k;
				nowtot%=m;
				ans1+=dp[n-i][work(nowtot-nowmod-mi[n-i]*j,m)][k];
				ans1%=mod;
			}
		}
		nowtot1=(nowtot1+now);
		nowtot2=(nowtot2+now*now);
		nowmod=(nowmod+mi[n-i]*now)%m;
	}
	long long tmp=0,sum1=0,sum2=0;
	for(int i=1;i<=n;++i){
		int now=r[i]-'0';
		tmp=tmp*10+now;
		tmp%=m;
		sum1+=now;
		sum2+=now*now;
	}
	if(tmp==(sum1*sum1-sum2)/2%m)++ans1;
	n=strlen(l+1),nowmod=0,nowtot1=0,nowtot2=0;
	for(int i=1;i<=n;++i){
		int now=l[i]-'0'; 
		for(int j=0;j<now;++j){
			for(int k=0;k<m;++k){
				int nowtot=((nowtot1+j)*(nowtot1+j)-(nowtot2+j*j))/2+(nowtot1+j)*k;
				nowtot%=m;
				ans2+=dp[n-i][work(nowtot-nowmod-mi[n-i]*j,m)][k];
				ans2%=mod;
			}
		}
		nowtot1=(nowtot1+now);
		nowtot2=(nowtot2+now*now);
		nowmod=(nowmod+mi[n-i]*now)%m;
	}
	tmp=0,sum1=0,sum2=0;
	ans+=ans1-ans2;
	return (ans%mod+mod)%mod;
}
int main(){
	//freopen("in.txt","r",stdin);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		//memset(dp,0,sizeof(dp));
		cin>>(l+1)>>(r+1);	
		int m,n=strlen(r+1);
		cin>>m;
		for(int i=0;i<=n;++i){
			for(int j=0;j<m;++j){
				for(int k=0;k<m;++k)dp[i][j][k]=0;
			}
		}
		mi[0]=1;
		for(int i=1;i<=n;++i)mi[i]=mi[i-1]*10%m;
		dp[0][0][0]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				for(int k=0;k<m;++k){
					for(int now=0;now<=9;++now){
						dp[i+1][work(j+mi[i]*now-now*k,m)][(k+now)%m]+=dp[i][j][k];
						dp[i+1][work(j+mi[i]*now-now*k,m)][(k+now)%m]%=mod;
					}
				}
			}
		}
		printf("%I64d\n",getans(m));
	}
	return 0;
}
