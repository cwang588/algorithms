#include<bits/stdc++.h>
using namespace std;
char a[1005][1005],s[1005];
unordered_map<unsigned long long,tuple<int,int,int> >h;
unsigned long long Hash[1005],mi[1005];
tuple<int,int,int>dp[1005];
unsigned long long gethash(int l,int r){
	return Hash[r]-Hash[l-1]*mi[r-l+1];
}
unsigned long long gethash(int id,int l,int r){
	unsigned long long re=0;
	for(int i=l;i<=r;++i)re=re*19260817+a[id][i];
	return re;
}
int main(){
	mi[0]=1;
	dp[0]=make_tuple(0,0,-1);
	for(int i=1;i<=1000;++i)mi[i]=mi[i-1]*19260817;
	int t;
	cin>>t;
	while(t--){
		h.clear();
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>(a[i]+1);
		cin>>(s+1);
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j)h[gethash(i,j,j+1)]=make_tuple(j,j+1,i);
			for(int j=1;j<m-1;++j)h[gethash(i,j,j+2)]=make_tuple(j,j+2,i);
		}
		for(int i=1;i<=m;++i)Hash[i]=Hash[i-1]*19260817+s[i];
		for(int i=2;i<=m;++i){
			dp[i]=make_tuple(0,0,0);
			auto nowhash=gethash(i-1,i);
			if(get<2>(dp[i-2])&&h.count(nowhash))dp[i]=h[nowhash];
			nowhash=gethash(i-2,i);
			if(i>2&&get<2>(dp[i-3])&&h.count(nowhash))dp[i]=h[nowhash];
		}
		if(!get<2>(dp[m])){
			cout<<"-1\n";
			continue;
		}
		vector<tuple<int,int,int> > ans;
		int now=m;
		while(now){
			ans.push_back(dp[now]);
			now-=get<1>(dp[now])-get<0>(dp[now])+1;
		}
		cout<<ans.size()<<"\n";
		reverse(ans.begin(),ans.end());
		for(const auto&x:ans)cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<"\n";
	}
	
	
	return 0;
}