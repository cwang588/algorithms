#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long k,tot=0;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i],tot+=a[i];
		if(tot<=k){
			cout<<"0\n";
			continue;
		}
		if(n==1){
			cout<<tot-k<<"\n";
			continue;
		}
		long long now=0;
		sort(a+1,a+1+n);
		long long ans=tot-k;
		for(int i=n;i>=2;--i){
			now+=a[i]-a[1];
			if(tot-k<=now)ans=min(ans,n-i+1ll);
			else ans=min(ans,max(0ll,(tot-k-now-1)/(n-i+2)+1)+n-i+1);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}