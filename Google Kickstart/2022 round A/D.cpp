#include<bits/stdc++.h>
using namespace std;
int a[15],n,mod;
long long dp[155][15][155][155],mi[15];
vector<int>num[155][155][155];
long long dfs(int now,int tot,int m,bool limit,bool lead){
	if(tot<0)return 0;
	if(now==n+1){
		if(tot==0&&(mod==1||m==1))return 1;
		else return 0;
	}
	if(!limit&&!lead&&dp[mod][n-now][tot][m]!=-1)return dp[mod][n-now][tot][m];
	int up=limit?a[now]:9;
	long long ans=0;
	for(int i=0;i<=up;++i){
		if(tot<i)break;
		if(i==0&&lead)ans=dfs(now+1,tot-i,m,limit&&i==up,true);
		else{
			for(auto j:num[mod][i%mod][m])
				ans+=dfs(now+1,tot-i,j,limit&&i==up,false);
		}
	}
	if(!limit&&!lead)dp[mod][n-now][tot][m]=ans;
	return ans;
}
long long calc(long long x){
	n=0;
	int tot=0;
	while(x){
		tot+=x%10;
		a[++n]=x%10;
		x/=10;
	}
	reverse(a+1,a+1+n);
	long long re=0;
	for(mod=1;mod<=99;++mod){
		re+=dfs(1,mod,0,true,true);
	}	
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp,-1,sizeof(dp));
	for(int k=1;k<=99;++k){
		for(int i=0;i<=9;++i){
			for(int j=0;j<k;++j)num[k][i][i*j%k].push_back(j);
		}
	}
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		long long l,r;
		cin>>l>>r;
		cout<<"Case #"<<Case<<": "<<calc(r)-calc(l-1)<<"\n";
	}
	return 0;
}