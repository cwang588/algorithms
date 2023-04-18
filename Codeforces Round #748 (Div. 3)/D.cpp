#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
long long a[150];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		long long ans=0;
		for(int i=2;i<=n;++i)ans=gcd(ans,a[i]-a[1]);
		if(ans)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	
	
	return 0;
}