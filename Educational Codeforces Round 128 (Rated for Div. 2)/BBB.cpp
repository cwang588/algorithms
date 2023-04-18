#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int a[1005][1005];
long long dp[1005][1005];
int n,m,k,d;
struct Q{
	int start=1,end=0;
	pair<int,long long>value[2005];
	void push(int pos,long long now){
		while(start<=end&&value[end].second<=now)--end;
		value[++end]=make_pair(pos,now);
	}
	long long get_max(int pos){
		while(start<=end&&value[start].first<pos-d)++start;
		if(start>end)return -inf;
		return value[start].second;
	}
};
int main(){
	cin>>n>>m>>k>>d;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			dp[i][j]=-inf;
		}
	}
	Q q;
	dp[1][1]=a[1][1];
	for(int i=1;i<=n;++i){
		long long tmp=-inf;
		for(int j=1;j<=m;++j){
			if(i==1&&j==1)continue;
			if(j>k)tmp=max(tmp,dp[i][j-k]);
			dp[i][j]=max(q.get_max(i),tmp)+a[i][j];
		}
		for(int j=1;j<=m;++j)tmp=max(tmp,dp[i][j]);
		q.push(i,tmp);
	}
	cout<<dp[n][m];
	return 0;
}