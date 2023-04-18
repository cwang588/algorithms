#include<bits/stdc++.h>
using namespace std;
struct point{
	long long x,y;
	int value;
}p[200005];
bool cmp(point a,point b){
	return a.x>b.x;
}
map<long long,int>dp;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		dp.clear();
		long long h;
		int n,m;
		cin>>h>>n;
		for(int i=1;i<=n;++i){
			cin>>p[i].x>>p[i].y;
			p[i].value=0;
		}
		cin>>m;
		for(int i=1;i<=m;++i){
			cin>>p[i+n].x>>p[i+n].y;
			p[i+n].value=1;
		}
		sort(p+1,p+1+n+m,cmp);
		int ans=0;
		h<<=1;
		for(int i=1;i<=n+m;++i){
			long long id1=((p[i].x-p[i].y)%h+h)%h,id2=((p[i].x+p[i].y)%h+h)%h;
			if(p[i].value==1){
				dp[id1]+=1;
				dp[id2]+=1;
			}
			else{
				int Max=max(dp[id1],dp[id2]);
				dp[id1]=dp[id2]=Max;
			}
		}
		cout<<dp[0]<<"\n";
	}
	
	
	
	return 0;
}