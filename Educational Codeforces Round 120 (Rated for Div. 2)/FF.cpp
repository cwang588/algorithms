#include<bits/stdc++.h>
using namespace std;
int n;
bool usd[15];
int ans;
vector<vector<int> >bkx;
long long f[15];
void dfs(int now,long long tot){
	if(now==n+1){
		if((long long)sqrt(tot)*(long long)sqrt(tot)!=tot)return;
		int cnt=0;
		for(int i=1;i<=n;++i)if(usd[i])++cnt;
		if(ans<cnt){
			bkx.clear();
			vector<int>tmp;
			for(int i=1;i<=n;++i)if(usd[i])tmp.push_back(i);
			ans=cnt;
			bkx.push_back(tmp);
		}
		else if(ans==cnt){
			vector<int>tmp;
			for(int i=1;i<=n;++i)if(usd[i])tmp.push_back(i);
			bkx.push_back(tmp);
		}
		else;
		return;
	}
	usd[now]=true;
	dfs(now+1,tot*f[now]);
	usd[now]=false;
	dfs(now+1,tot);
}
int main(){
	f[0]=1;
	for(int i=1;i<=10;++i)f[i]=f[i-1]*i;
	for(int i=1;i<=10;++i){
		n=i;
		ans=0;
		bkx.clear();
		dfs(1,1);
		cout<<i<<":"<<ans<<"\n";
		for(auto k:bkx){
			for(auto x:k)cout<<x<<" ";
			cout<<"\n";
		}
	}
	
	
	return 0;
}