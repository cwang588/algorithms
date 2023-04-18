#include<bits/stdc++.h>
using namespace std;
long long a[100006];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		long long tot=a[1]+n;
		for(int i=1;i<n;++i)tot+=a[i];
		if(tot>m)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}