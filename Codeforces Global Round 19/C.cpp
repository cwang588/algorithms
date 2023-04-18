#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(n==3&&a[2]%2){
			cout<<"-1\n";
			continue;
		}
		bool ky=false;
		long long ans=0;
		for(int i=2;i<n;++i){
			if(a[i]>=2)ky=true;
			ans+=(a[i]+1)/2;
		}
		if(ky)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	
	return 0;
}