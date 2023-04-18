#include<bits/stdc++.h>
using namespace std;
long long dp[200005][40],a[200005],b[200005];
vector<pair<long long,long long> >v;
vector<long long>vv;	
int n,m;
bool cmp(pair<long long,long long>a,pair<long long,long long>b){
	return a.second*b.first+b.first<a.first*b.second+a.first;
}
long long work(long long a,long long b){
	if(a==-1&&(b>m||b==-1))return -1;
	if(a==-1)return b;
	if(b>m||b==-1)return a;
	return min(a,b);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	v.push_back(make_pair(0,0));
	for(int i=1;i<=n;++i){
		if(!a[i])vv.push_back(b[i]);
		else v.push_back(make_pair(a[i],b[i]));
	}
	int cnt=v.size(),cntt=vv.size();
	sort(v.begin()+1,v.end(),cmp);
	for(int i=0;i<cnt;++i){
		for(int j=0;j<=35;++j)dp[i][j]=-1;
	}
	dp[0][0]=0;
	for(int i=0;i<cnt-1;++i){
		for(int j=0;j<=35;++j){
			if(dp[i][j]==-1)continue;
			dp[i+1][j]=work(dp[i][j],dp[i+1][j]);
			dp[i+1][j+1]=work(dp[i+1][j+1],dp[i][j]+1+v[i+1].first*(dp[i][j]+1)+v[i+1].second);
		//	else dp[i+1][j+1]=work(dp[i+1][j+1],(v[i+1].first+1)*dp[i][j]+v[i+1].second);
		}
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<cntt;++i)++vv[i];
	for(int i=1;i<cntt;++i)vv[i]+=vv[i-1];
	int ans=0;
	for(int i=0;i<=35;++i){
		if(dp[cnt-1][i]==-1)continue;
		if(cntt)ans=max(ans,i+upper_bound(vv.begin(),vv.end(),m-dp[cnt-1][i])-vv.begin());
		else ans=max(ans,i);
	}
	cout<<ans<<endl;
	return 0;
}
