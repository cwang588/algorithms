#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int Max=0;
		for(int i=1;i<=n;++i)cin>>a[i],Max=max(Max,a[i]);
		long long tot=0;
		for(int i=1;i<=n;++i)tot+=max(0,a[i]-a[i-1]);
		if(tot>Max)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	
	return 0;
}