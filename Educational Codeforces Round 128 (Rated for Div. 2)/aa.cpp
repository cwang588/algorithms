#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int a[10005];
long long dp[10005][2];
long long sum[10005];
pair<int,long long>value[10005][10005];
struct Q{
	long long sum=0;
	int gap=0,id=0;
	int start=1,end=0;
	void push(int pos,long long num){
		value[gap][++end]=make_pair(pos,num);
		sum=(sum+num)%mod;
	}
	long long get_sum(int pos){
		while(start<=end&&value[gap][start].first<pos-a[gap]*gap){
			sum=(sum-value[gap][start].second)%mod;
			++start;
		}
		return sum;
	}
	void clear(){
		start=1,end=0;
		sum=0;
	}
}q[10005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<i;++j){
			q[j].clear();
			q[j].
		}
		for(int j=0;j<=n;++j){
			dp[j][i&1]=(dp[j][1-(i&1)]+q[j%i].get_sum(j))%mod;
			q[j%i].push(j,dp[j][1-(i&1)]);
		}
	}
	cout<<(dp[n][n&1]+mod)%mod;
	return 0;
}