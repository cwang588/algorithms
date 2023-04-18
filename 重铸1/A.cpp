#include<bits/stdc++.h>
using namespace std;
struct op{
	int t,x,y;
}opt[1000005];
int dp[1000005],Min[1000005],ans[1000005],num[1000005];
int main(){
	ios::sync_with_stdio(false);
	int n,tot=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		ans[i]=Min[i]=dp[i]=19260817;
		cin>>opt[i].t;
		if(opt[i].t==1){
			cin>>opt[i].x;
			++tot;
		}
		else{
			cin>>opt[i].x>>opt[i].y;
			++num[opt[i].x];
		}
	}
	ans[1]=tot+num[1];
	Min[1]=tot+num[1];
	for(int i=1;i<=n;++i){
		if(opt[i].t==1){
			--tot;
			dp[i]=0;
			Min[opt[i].x]=min(Min[opt[i].x],tot+num[opt[i].x]);
			ans[opt[i].x]=min(ans[opt[i].x],dp[i]+tot+num[opt[i].x]);
		}
		else{
			--num[opt[i].x];
			if(Min[opt[i].x]==19260817)dp[i]=19260817;
			else{
				dp[i]=Min[opt[i].x]-tot-num[opt[i].x]-1;
				Min[opt[i].y]=min(Min[opt[i].y],dp[i]+tot+num[opt[i].y]);
				ans[opt[i].y]=min(ans[opt[i].y],dp[i]+tot+num[opt[i].y]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(ans[i]==19260817)cout<<"-1 ";
		else cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
