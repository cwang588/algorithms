#include<bits/stdc++.h>
using namespace std;
long long dp[200005],sum[200005];
int a[200005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		char t;
		cin>>t;
		a[i]=t-'0';
		sum[i]=sum[i-1]+i;
	}
	deque<pair<int,long long> >q;
	long long Min=0;
	for(int i=1;i<=n;++i){
		while(!q.empty()&&q.front().first+k*2+1<i){
			Min=min(Min,q.front().second-sum[min(n,q.front().first+k)]);
			q.pop_front();
		}
		if(!a[i])continue;
		if(i<=k+1)dp[i]=i;
		else{
			if(!q.empty())dp[i]=i+min(Min+sum[i-k-1],q.front().second);
			else dp[i]=i+Min+sum[i-k-1];
		}
		while(!q.empty()&&q.back().second>=dp[i])q.pop_back();
		q.push_back(make_pair(i,dp[i]));
	}
	long long ans=sum[n];
	for(int i=1;i<=n;++i){
		if(!a[i])continue;
		ans=min(ans,dp[i]+sum[n]-sum[min(n,i+k)]);	
	}
	cout<<ans;
	return 0;
}