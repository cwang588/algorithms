#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		long long x;
		cin>>n>>k>>x;
		long long tot=0,Min1=0,Min2=0,ans=0;
		for(int i=1;i<=n;++i){
			long long now;
			cin>>now;
			tot+=now;
			if(i>=k)ans=max(ans,tot-Min1+k*x);
			ans=max(ans,tot-Min2+i*x);
			Min1=min(Min1,tot);
			Min2=min(Min2,tot+i*x);
		}
		cout<<ans<<"\n";
	}
	
	
	return 0;
}