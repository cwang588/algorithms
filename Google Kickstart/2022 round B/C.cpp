#include<bits/stdc++.h>
using namespace std;
unordered_map<int,long long[405][405]>dp;
unordered_map<int,bool[405][405]>usd;
int n,m;
vector<int>a;
long long dfs(int l,int r,int gap){
	if(l>r)return 0;
	if(usd[gap][l][r])return dp[gap][l][r];
	usd[gap][l][r]=true;
	dp[gap][l][r]=1e18;
	if(a[l]!=a[r]){
		int num=min((a[l]+gap)%m,(m-(a[l]+gap)%m)%m);
		dp[gap][l][r]=min(dp[gap][l][r],dfs(l+1,r,(m-a[l])%m)+num);
		num=min((a[r]+gap)%m,(m-(a[r]+gap)%m)%m);
		dp[gap][l][r]=min(dp[gap][l][r],dfs(l,r-1,(m-a[r])%m)+num);
	}
	else{
		int num=min((a[l]+gap)%m,(m-(a[l]+gap)%m)%m);
		dp[gap][l][r]=min(dp[gap][l][r],dfs(l+1,r-1,(m-a[l])%m)+num);
	}
	return dp[gap][l][r];
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		dp.clear(),usd.clear(),a.clear();
		cin>>n>>m;
		int last=-1;
		for(int i=1;i<=n;++i){
			int tmp;
			cin>>tmp;
			if(tmp!=last){
				a.push_back(tmp);
				last=tmp;
			}
		}
		n=a.size();
		printf("Case #%d: %lld\n",Case,dfs(0,n-1,0));
	}
	
	return 0;
}